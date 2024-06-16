/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc034/submissions/54636434
 * Submitted at: 2024-06-16 16:54:51
 * Problem URL: https://atcoder.jp/contests/ahc034/tasks/ahc034_a
 * Result: AC
 * Execution Time: 3 ms
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
const ll INF = ((1LL << 62)-(1LL << 31));

// right | down | left | up
#define DIR_NUM 4
vector<int> dx = { 0, 1, 0,-1};
vector<int> dy = { 1, 0,-1, 0};

struct State{

    State() {

    }
};

struct Solver{
    int n;
    ll best_score;
    vector<vector<int>> h;
    vector<string> ans;

    Solver() {
        this->input();
        this->best_score = INF;
    }

    void input() {
        cin >> n;
        h.resize(n, vector<int>(n));
        rep(i, n) rep(j, n) cin >> h[i][j];
        return;
    }

    void output() {
        for(auto s : ans) cout << s << endl;
        return;
    }

    void solve() {
        // 貪欲解法
        // - 下のマスから不足分を埋める or 余分を渡す方針
        // ※ 最終的な高さのみが評価されるので、途中凸凹でも良いという理論

        // 移動パターンを複数用意して最も良いものを選択
        vector<vector<int>> base = h;

        vector<vector<int>> field = base;
        vector<string> res = greedy(field);
        ll score = calcScore(res);
        if(score < best_score) {
            best_score = score;
            ans = res;
        }

        rep(i, n) rep(j, n) {
            field[i][j] = base[j][i];
        }
        res = greedy(field);
        rep(i, res.size()) {
            if(res[i][0] == 'R') res[i][0] = 'D';
            else if(res[i][0] == 'D') res[i][0] = 'R';
            else if(res[i][0] == 'L') res[i][0] = 'U';
            else if(res[i][0] == 'U') res[i][0] = 'L';
        }
        score = calcScore(res);
        if(score < best_score) {
            best_score = score;
            ans = res;
        }

        // base を 90 度回転
        vector<vector<int>> next_base = base;
        rep(i, n) rep(j, n) {
            next_base[i][j] = base[j][n-i-1];
        }
        swap(base, next_base);
        field = base;
        res = greedy(field);
        rep(i, res.size()) {
            if(res[i][0] == 'L') res[i][0] = 'U';
            else if(res[i][0] == 'U') res[i][0] = 'R';
            else if(res[i][0] == 'R') res[i][0] = 'D';
            else if(res[i][0] == 'D') res[i][0] = 'L';
        }
        reverse(res.begin(), res.end());
        rep(i, n-1) res.emplace_back("R");
        reverse(res.begin(), res.end());
        score = calcScore(res);
        if(score < best_score) {
            best_score = score;
            ans = res;
        }
        
        rep(i, n) rep(j, n) {
            field[i][j] = base[j][i];
        }
        res = greedy(field);
        rep(i, res.size()) {
            if(res[i][0] == 'L') res[i][0] = 'R';
            else if(res[i][0] == 'U') res[i][0] = 'U';
            else if(res[i][0] == 'R') res[i][0] = 'L';
            else if(res[i][0] == 'D') res[i][0] = 'D';
        }
        reverse(res.begin(), res.end());
        rep(i, n-1) res.emplace_back("R");
        reverse(res.begin(), res.end());
        score = calcScore(res);
        if(score < best_score) {
            best_score = score;
            ans = res;
        }

        // base を 90 度回転
        next_base = base;
        rep(i, n) rep(j, n) {
            next_base[i][j] = base[j][n-i-1];
        }
        swap(base, next_base);
        field = base;
        res = greedy(field);
        rep(i, res.size()) {
            if(res[i][0] == 'L') res[i][0] = 'R';
            else if(res[i][0] == 'U') res[i][0] = 'D';
            else if(res[i][0] == 'R') res[i][0] = 'L';
            else if(res[i][0] == 'D') res[i][0] = 'U';
        }
        reverse(res.begin(), res.end());
        rep(i, n-1) res.emplace_back("R");
        rep(i, n-1) res.emplace_back("D");
        reverse(res.begin(), res.end());
        score = calcScore(res);
        if(score < best_score) {
            best_score = score;
            ans = res;
        }
        
        rep(i, n) rep(j, n) {
            field[i][j] = base[j][i];
        }
        res = greedy(field);
        rep(i, res.size()) {
            if(res[i][0] == 'L') res[i][0] = 'D';
            else if(res[i][0] == 'U') res[i][0] = 'R';
            else if(res[i][0] == 'R') res[i][0] = 'U';
            else if(res[i][0] == 'D') res[i][0] = 'L';
        }
        reverse(res.begin(), res.end());
        rep(i, n-1) res.emplace_back("R");
        rep(i, n-1) res.emplace_back("D");
        reverse(res.begin(), res.end());
        score = calcScore(res);
        if(score < best_score) {
            best_score = score;
            ans = res;
        }

        // base を 90 度回転
        next_base = base;
        rep(i, n) rep(j, n) {
            next_base[i][j] = base[j][n-i-1];
        }
        swap(base, next_base);
        field = base;
        res = greedy(field);
        rep(i, res.size()) {
            if(res[i][0] == 'L') res[i][0] = 'D';
            else if(res[i][0] == 'U') res[i][0] = 'L';
            else if(res[i][0] == 'R') res[i][0] = 'U';
            else if(res[i][0] == 'D') res[i][0] = 'R';
        }
        reverse(res.begin(), res.end());
        rep(i, n-1) res.emplace_back("D");
        reverse(res.begin(), res.end());
        score = calcScore(res);
        if(score < best_score) {
            best_score = score;
            ans = res;
        }
        
        rep(i, n) rep(j, n) {
            field[i][j] = base[j][i];
        }
        res = greedy(field);
        rep(i, res.size()) {
            if(res[i][0] == 'L') res[i][0] = 'L';
            else if(res[i][0] == 'U') res[i][0] = 'D';
            else if(res[i][0] == 'R') res[i][0] = 'R';
            else if(res[i][0] == 'D') res[i][0] = 'U';
        }
        reverse(res.begin(), res.end());
        rep(i, n-1) res.emplace_back("D");
        reverse(res.begin(), res.end());
        score = calcScore(res);
        if(score < best_score) {
            best_score = score;
            ans = res;
        }

        return;
    }

    vector<string> greedy(vector<vector<int>> &field) {
        vector<string> res;
        ll now_x = 0, now_y = 0, have = 0;
        while(now_x < n-1) {
            if(field[now_x][now_y] > 0) {
                // 現在マスが超過してる時 ⇒ 持つ
                res.emplace_back("+" + to_string(field[now_x][now_y]));
                have += field[now_x][now_y];
                field[now_x][now_y] = 0;
            }
            else if(field[now_x][now_y] < 0) {
                // 現在マスが不足してる時 ⇒ 下 or 持ってるものから補充
                if(abs(field[now_x][now_y]) <= have) {
                    // 持っているもので足りる時
                    res.emplace_back("-" + to_string(abs(field[now_x][now_y])));
                    have -= abs(field[now_x][now_y]);
                    field[now_x][now_y] = 0;
                }
                else {
                    // 持っているもので足りない時 ⇒ 下から補充
                    res.emplace_back("D");
                    now_x++;

                    ll shortage = abs(field[now_x-1][now_y]) - have;
                    res.emplace_back("+" + to_string(shortage));
                    have += shortage;
                    field[now_x][now_y] -= shortage;

                    res.emplace_back("U");
                    now_x--;

                    res.emplace_back("-" + to_string(abs(field[now_x][now_y])));
                    have -= abs(field[now_x][now_y]);
                    field[now_x][now_y] = 0;
                }
            }

            // 移動 phase
            if((now_y == 0 && now_x%2 == 1) || (now_y == n-1 && now_x%2 == 0)) {
                res.emplace_back("D");
                now_x++;
            } else {
                if(now_x%2 == 0) {
                    res.emplace_back("R");
                    now_y++;
                }
                else {
                    res.emplace_back("L");
                    now_y--;
                }
            }
        }

        // 最後の一行は左に流す漢字で処理
        while(now_y > 0) {
            if(field[now_x][now_y] > 0) {
                // 現在マスが超過してる時 ⇒ 持つ
                res.emplace_back("+" + to_string(field[now_x][now_y]));
                have += field[now_x][now_y];
                field[now_x][now_y] = 0;
            }
            else if(field[now_x][now_y] < 0) {
                // 現在マスが不足してる時 ⇒ 左 or 持ってるものから補充
                if(abs(field[now_x][now_y]) <= have) {
                    // 持っているもので足りる時
                    res.emplace_back("-" + to_string(abs(field[now_x][now_y])));
                    have -= abs(field[now_x][now_y]);
                    field[now_x][now_y] = 0;
                }
                else {
                    // 持っているもので足りない時 ⇒ 左から補充
                    res.emplace_back("L");
                    now_y--;

                    ll shortage = abs(field[now_x][now_y+1]) - have;
                    res.emplace_back("+" + to_string(shortage));
                    have += shortage;
                    field[now_x][now_y] -= shortage;

                    res.emplace_back("R");
                    now_y++;

                    res.emplace_back("-" + to_string(abs(field[now_x][now_y])));
                    have -= abs(field[now_x][now_y]);
                    field[now_x][now_y] = 0;
                }
            }
            res.emplace_back("L");
            now_y--;
        }
        // 最後のマスの分を処理
        if(have > 0) {
            res.emplace_back("-" + to_string(have));
        }
        return res;
    }

    inline ll calcScore(const vector<string> &res) {
        ll score = 0;
        ll now_x = 0, now_y = 0, have = 0;
        for(auto s : res) {
            if(s[0] == '+') {
                have += stoll(s.substr(1));
                score += stoll(s.substr(1));
            }
            else if(s[0] == '-') {
                have -= stoll(s.substr(1));
                score += stoll(s.substr(1));
            }
            else score += 100 + have;
        }
        return score;
    }

    inline bool outField(int x, int y) {
        if(0 <= x && x < x && 0 <= y && y < x) return false;
        return true;
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