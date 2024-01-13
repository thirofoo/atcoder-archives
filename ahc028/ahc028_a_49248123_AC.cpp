/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc028/submissions/49248123
 * Submitted at: 2024-01-13 16:16:18
 * Problem URL: https://atcoder.jp/contests/ahc028/tasks/ahc028_a
 * Result: AC
 * Execution Time: 1804 ms
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
#define TIME_LIMIT 1800
inline double temp(double start) {
    double start_temp = 100,end_temp = 1;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int best,int now,int start) {
    return exp((double)(now - best) / temp(start));
}

//-----------------以下から実装部分-----------------//

struct State{

    State(){

    }
};

struct Solver{
    int n, m, sx, sy;
    vector<string> key;
    vector<string> word;
    vector<vector<P>> place;
    vector<P> ans;
    vector<vector<int>> score;

    Solver() {
        // timer start
        utility::mytm.CodeStart();

        this->input();
        place.assign(26,{});
        rep(i,n) rep(j,n) place[key[i][j]-'A'].push_back({i,j});
        score.assign(m, vector<int>(m, 0));

        int cnt = 0;
        rep(i,m) rep(j,m) {
            // 先頭と尻の一致度合いを計算
            for(int k=5; k>=1; k--) {
                bool flag = true;
                for(int l=0; l<k; l++) flag &= (word[i][5-k+l] == word[j][l]);
                if( flag ) {
                    score[i][j] = k;
                    break;
                }
            }
        }
        return;
    }

    void input() {
        cin >> n >> m >> sx >> sy;
        key.assign(n, "");
        word.assign(m, "");
        rep(i,n) cin >> key[i];
        rep(i,m) cin >> word[i];
        return;
    }

    void output() {
        rep(i,ans.size()) {
            auto [x, y] = ans[i];
            cout << x << " " << y << endl;
        }
        return;
    }

    void solve() {
        // 文字生成 part
        // 1. Start 地点全探索
        // 2. そこを先頭として、頭と尻を交互に繋げる

        // 初期解生成
        string ans_str = "";
        rep(i,m) ans_str += word[i];
        auto first = calcScore(ans_str);
        int best_score = first.first;
        ans = first.second;
        cerr << "First Score: " << 10000-best_score << endl;

        rep(start,m) {
            vector<bool> used(m, false);
            string best_str = word[start];
            used[start] = true;
            int now = start;
            rep(i,m-1) {
                int best = -1;
                rep(j,m) {
                    if( used[j] ) continue;
                    if( best == -1 || score[now][j] > score[now][best]) best = j;
                }
                used[best] = true;
                // 重なりを考慮して修正
                rep(j,score[now][best]) best_str.pop_back();
                best_str += word[best];
                now = best;
            }

            // 打ち込み part
            auto [cand_score, cand] = calcScore(best_str);
            if( best_score > cand_score ) {
                best_score = cand_score;
                ans_str = best_str;
                ans = cand;
            }
        }
        cerr << "Middle Score: " << 10000-best_score << endl;

        // 山登り法 ( 打ち込み part の改善 )
        while( utility::mytm.elapsed() <= TIME_LIMIT ) {
            // 近傍: 特定の1文字を違う場所の同じ文字に変更
            int r1 = rand_int()%ans.size();
            while( place[ans_str[r1]-'A'].size() == 1 ) {
                r1 = rand_int()%ans.size();
            }
            int r2 = rand_int()%place[ans_str[r1]-'A'].size();
            while( ans[r1] == place[ans_str[r1]-'A'][r2] ) {
                r2 = rand_int()%place[ans_str[r1]-'A'].size();
            }

            // best_score との差分を計算
            auto [px, py] = ans[r1];
            auto [nx, ny] = place[ans_str[r1]-'A'][r2];
            int cand_score = best_score;
            if( r1 != 0 ) {
                auto [x2, y2] = ans[r1-1];
                cand_score -= abs(x2-px) + abs(y2-py);
                cand_score += abs(x2-nx) + abs(y2-ny);
            }
            if( r1 != ans.size()-1 ) {
                auto [x2, y2] = ans[r1+1];
                cand_score -= abs(x2-px) + abs(y2-py);
                cand_score += abs(x2-nx) + abs(y2-ny);
            }
            if( cand_score < best_score ) {
                best_score = cand_score;
                ans[r1] = {nx, ny};
            }
        }
        cerr << "Last Score: " << 10000-best_score << endl;
        return;
    }

    inline pair<int, vector<P>> calcScore(const string &str) {
        int cand_score = 0;
        int tsx = sx, tsy = sy;
        vector<P> cand;
        rep(i,str.size()) {
            int dis = 1e9, best_x, best_y;
            for(auto [x,y]: place[str[i]-'A']) {
                if(dis > abs(x-tsx) + abs(y-tsy)) {
                    dis = abs(x-tsx) + abs(y-tsy);
                    best_x = x;
                    best_y = y;
                }
            }
            tsx = best_x, tsy = best_y;
            cand.push_back({tsx, tsy});
            cand_score += dis + 1;
        }
        return {cand_score, cand};
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