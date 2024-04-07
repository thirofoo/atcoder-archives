/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc032/submissions/52148417
 * Submitted at: 2024-04-07 21:04:47
 * Problem URL: https://atcoder.jp/contests/ahc032/tasks/ahc032_a
 * Result: AC
 * Execution Time: 726 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int, int> T;
#define rep(i, n) for(int i = 0; i < n; i++)

namespace utility {
    struct timer {
        chrono::system_clock::time_point start;
        // 開始時間を記録
        void CodeStart() {
            start = chrono::system_clock::now();
        }
        // 経過時間 (ms) を返す
        double elapsed() const {
        using namespace std::chrono;
            return (double)duration_cast<milliseconds>(system_clock::now() - start).count();
        }
    } mytm;
}

inline unsigned int rand_int() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}

inline double rand_double() {
    return (double)(rand_int()%(int)1e9)/1e9;
}

inline double gaussian(double mean, double stddev) {
    // 標準正規分布からの乱数生成（Box-Muller変換
    double z0 = sqrt(-2.0 * log(rand_double())) * cos(2.0 * M_PI * rand_double());
    // 平均と標準偏差の変換
    return mean + z0 * stddev;
}

//温度関数
#define TIME_LIMIT 2950
inline double temp(double start) {
    double start_temp = 100,end_temp = 1;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int best,int now,int start) {
    return exp((double)(now - best) / temp(start));
}

//-----------------以下から実装部分-----------------//

static constexpr int MOD = 998244353;
int n, m, k;

struct Answer {
    long long score;
    vector<tuple<int,int,int>> stamps;

    Answer() : score(0), stamps({}) {}
    explicit Answer(long long score, vector<tuple<int,int,int>> stamps) : score(score), stamps(stamps) {}

    bool operator < (const Answer &a) const {return score < a.score;}
    bool operator <= (const Answer &a) const {return score <= a.score;}
    bool operator > (const Answer &a) const {return score > a.score;}
    bool operator >= (const Answer &a) const {return score >= a.score;}
    bool operator == (const Answer &a) const {return score == a.score;}
};

struct Stamp {
    int op, op_num;
    vector<int> stamp_idx;
    vector<vector<int>> stamp;

    Stamp() : op(-1), stamp({}) {}
    Stamp(int op, vector<vector<int>> stamp) : op(op), stamp(stamp) { 
        op_num = __builtin_popcount(op);
        rep(i,m) {
            if( !((op >> i) & 1) ) continue;
            stamp_idx.emplace_back(i);
        }
    }
};

struct Solver{
    int rest;
    vector<vector<int>> a;
    vector<vector<vector<int>>> stamp;

    vector<Stamp> all_stamps;
    priority_queue<Answer> pq;

    Answer now;

    Solver() {
        this->input();
        rest = k;
        Answer now = Answer(0, {});
        vector<vector<int>> s(3, vector<int>(3));

        // Stamp を重ねたものを全列挙
        rep(i, (1LL << m)) {
            s.assign(3, vector<int>(3, 0));
            rep(j,m) {
                if( !(i & (1LL << j)) ) continue;
                rep(x,3) rep(y,3) {
                    s[x][y] += stamp[j][x][y];
                    s[x][y] %= MOD;
                }
            }
            all_stamps.emplace_back(Stamp(i, s));
        }
    }

    void input() {
        cin >> n >> m >> k;  
        a.resize(n, vector<int>(n));      
        rep(i,n) rep(j,n) cin >> a[i][j];
        rep(i,m) {
            vector<vector<int>> s(3, vector<int>(3));
            rep(j,3) rep(k,3) cin >> s[j][k];
            stamp.emplace_back(s);
        }
        return;
    }

    void output() {
        Answer ans = pq.top();
        cout << ans.stamps.size() << endl;
        for(auto [x,y,z] : ans.stamps) cout << x << " " << y << " " << z << endl;
        return;
    }

    void solve() {
        utility::mytm.CodeStart();

        // ==================== 貪欲解法 ====================
        // 1. 左上から 1 Stamp で一番スコアが高くなるものを押す
        // 2. 右と下の 3 列を最小化するように Stamp を押す
        // 3. 一番右下の 3x3 を最大化する Stamp を置く
        // =================================================

        // op1 は綺麗ではあるが、visualizer がぼちぼち黄色
        // ⇒ op1 の最適化処理をビームサーチっぽくやってみる ?
        // ※ 必ずしも左上最小化が最適なわけではない為 (左上が少し弱くなるが以降が強くなったり?)
        op1();
        if( rest == 0 ) return;
        
        op2();
        if( rest == 0 ) return;

        // op3 は難しいが一番 loss が出てる場所でもある
        // ⇒ 右下から 1 個左と 1 個上の塗り方全探索してみる ?
        op3();

        return;
    }

    void op1() {
        // 1. 左上から 1 Stamp で一番スコアが高くなるものを押す
        rep(i,n) rep(j,n) now.score += a[i][j];
        pq.push(now);
        rep(i,n-3) rep(j,n-3) {
            int max_v = a[i][j], op = -1;
            rep(idx,m) {
                if( max_v < (a[i][j] + stamp[idx][0][0]) % MOD ) {
                    max_v = (a[i][j] + stamp[idx][0][0]) % MOD;
                    op = idx;
                }
            }
            if( op == -1 ) continue;
            rest--;
            now.stamps.emplace_back(tuple(op,i,j));
            rep(x,3) rep(y,3) {
                now.score -= a[i+x][j+y];
                a[i+x][j+y] += stamp[op][x][y];
                a[i+x][j+y] %= MOD;
                now.score += a[i+x][j+y];
            }
            if( rest == 0 ) return;
        }
        pq.push(now);
        return;
    }

    void op2() {
        // 2. 右と下の最適化

        // 右 3 列の最適化
        rep(i,n-3) {
            long long max_v = 0;
            rep(y,3) max_v += a[i][n-3+y];
            Stamp best_stp = Stamp();

            for(auto &&stp: all_stamps) {
                if( stp.op_num > 3 ) continue;

                long long tmp = 0;
                rep(y,3) tmp += (a[i][n-3+y] + stp.stamp[0][y]) % MOD;
                if( max_v < tmp ) {
                    max_v = tmp;
                    best_stp = stp;
                }
            }
            if( best_stp.op == -1 ) continue;
            for(auto stp_idx: best_stp.stamp_idx) {
                now.stamps.emplace_back(tuple(stp_idx,i,n-3));
                rep(x,3) rep(y,3) {
                    now.score -= a[i+x][n-3+y];
                    a[i+x][n-3+y] += stamp[stp_idx][x][y];
                    a[i+x][n-3+y] %= MOD;
                    now.score += a[i+x][n-3+y];
                }
                rest--;
                if( rest == 0 ) return;
            }
            pq.push(now);
        }

        // 下 3 列の最適化
        rep(j,n-3) {
            long long max_v = 0;
            rep(x,3) max_v += a[n-3+x][j];
            Stamp best_stp = Stamp();

            for(auto &&stp: all_stamps) {
                if( stp.op_num > 3 ) continue;

                long long tmp = 0;
                rep(x,3) tmp += (a[n-3+x][j] + stp.stamp[x][0]) % MOD;
                if( max_v < tmp ) {
                    max_v = tmp;
                    best_stp = stp;
                }
            }
            if( best_stp.op == -1 ) continue;
            for(auto stp_idx: best_stp.stamp_idx) {
                now.stamps.emplace_back(tuple(stp_idx,n-3,j));
                rep(x,3) rep(y,3) {
                    now.score -= a[n-3+x][j+y];
                    a[n-3+x][j+y] += stamp[stp_idx][x][y];
                    a[n-3+x][j+y] %= MOD;
                    now.score += a[n-3+x][j+y];
                }
                rest--;
                if( rest == 0 ) return;
            }
            pq.push(now);
        }

        return;
    }

    void op3() {
        // 3. 一番右下の 3x3 を最大化する Stamp を置く
        long long max_v = 0;
        rep(x,3) rep(y,3) max_v += a[n-3+x][n-3+y];
        Stamp best_stp = Stamp();

        for(auto &&stp: all_stamps) {
            if( rest < stp.op_num ) continue;

            long long tmp = 0;
            rep(x,3) rep(y,3) tmp += (a[n-3+x][n-3+y] + stp.stamp[x][y]) % MOD;
            if( max_v < tmp ) {
                max_v = tmp;
                best_stp = stp;
            }
        }
        if( best_stp.op != -1 ) {
            rest -= best_stp.op_num;
            for(auto stp_idx: best_stp.stamp_idx) {
                now.stamps.emplace_back(tuple(stp_idx,n-3,n-3));
                rep(x,3) rep(y,3) {
                    now.score -= a[n-3+x][n-3+y];
                    a[n-3+x][n-3+y] += stamp[stp_idx][x][y];
                    a[n-3+x][n-3+y] %= MOD;
                    now.score += a[n-3+x][n-3+y];
                }
            }
            pq.push(now);
        }
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Solver solver;
    solver.solve();
    solver.output();
    
    return 0;
}