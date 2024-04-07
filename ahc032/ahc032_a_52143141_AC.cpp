/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc032/submissions/52143141
 * Submitted at: 2024-04-07 19:32:11
 * Problem URL: https://atcoder.jp/contests/ahc032/tasks/ahc032_a
 * Result: AC
 * Execution Time: 1 ms
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

struct Answer {
    long long score;
    vector<tuple<int,int,int>> stamps;

    Answer() {}
    explicit Answer(long long score, vector<tuple<int,int,int>> stamps) : score(score), stamps(stamps) {}

    bool operator < (const Answer &a) const {return score < a.score;}
    bool operator <= (const Answer &a) const {return score <= a.score;}
    bool operator > (const Answer &a) const {return score > a.score;}
    bool operator >= (const Answer &a) const {return score >= a.score;}
    bool operator == (const Answer &a) const {return score == a.score;}
};

struct Solver{
    int n, m, k;
    vector<vector<int>> a;
    vector<vector<vector<int>>> stamp;
    priority_queue<Answer> pq;

    Solver() {
        this->input();
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
        // 貪欲解法
        utility::mytm.CodeStart();

        int rest = k;
        Answer now = Answer(0, {});
        rep(i,n) rep(j,n) now.score += a[i][j];
        pq.push(now);

        while( utility::mytm.elapsed() < TIME_LIMIT ) {
            bool flag = true;
            rep(i,n-2) {
                rep(j,n-2) {
                    int max_v = a[i][j], op = -1;
                    rep(idx,m) {
                        if( max_v < (a[i][j] + stamp[idx][0][0]) % MOD ) {
                            max_v = (a[i][j] + stamp[idx][0][0]) % MOD;
                            op = idx;
                        }
                    }
                    if( op == -1 ) continue;
                    rest--;
                    flag = false;
                    now.stamps.emplace_back(tuple(op,i,j));
                    rep(x,3) rep(y,3) {
                        now.score -= a[i+x][j+y];
                        a[i+x][j+y] += stamp[op][x][y];
                        a[i+x][j+y] %= MOD;
                        now.score += a[i+x][j+y];
                    }
                    pq.push(now);
                    if( rest == 0 ) return;
                }
            }
            if( flag ) break;
        }
        return;
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