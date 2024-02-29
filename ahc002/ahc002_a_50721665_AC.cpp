/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc002/submissions/50721665
 * Submitted at: 2024-02-29 18:17:47
 * Problem URL: https://atcoder.jp/contests/ahc002/tasks/ahc002_a
 * Result: AC
 * Execution Time: 1803 ms
 */

#include <bits/stdc++.h>
using namespace std;
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

const int N = 50;

// right | down | left | up
#define DIR_NUM 4
const vector<int> dx = { 0, 1, 0,-1};
const vector<int> dy = { 1, 0,-1, 0};
const vector<char> dir_to_char = {'R', 'D', 'L', 'U'};
map<char, P> char_to_delta = {{'R', { 1, 0}}, {'D', { 0, 1}}, {'L', {-1, 0}}, {'U', { 0,-1}}};
map<P, char> delta_to_char = {{{ 1, 0}, 'R'}, {{ 0, 1}, 'D'}, {{-1, 0}, 'L'}, {{ 0,-1}, 'U'}};

struct State{

    State() {

    }
};

struct Solver{
    int sx, sy;
    vector<vector<int>> tile, point;
    vector<vector<bool>> used;
    vector<vector<P>> group;

    int ans_score;
    string ans_str, now_str;

    int back_cnt;

    Solver() {
        this->input();
        used.resize(N, vector<bool>(N, false));
    }

    void input() {
        cin >> sx >> sy;
        tile.resize(N, vector<int>(N));
        point.resize(N, vector<int>(N));
        group.resize(N*N, {});
        rep(i,N) rep(j,N) {
            cin >> tile[i][j];
            group[tile[i][j]].emplace_back(P(i,j));
        }
        rep(i,N) rep(j,N) cin >> point[i][j];
        return;
    }

    void output() {
        cout << ans_str << endl;
        return;
    }

    void solve() {
        // 1. dfs で貪欲解生成
        utility::mytm.CodeStart();
        ans_score = 0;
        now_str = "";
        for(auto &&[i, j] : group[tile[sx][sy]]) used[i][j] = true;
        greedyDFS(sx, sy, 0, now_str);

        return;
    }

    inline void greedyDFS(int x, int y, int score, string &path) {
        score += point[x][y];

        // dx, dy を壁に近い順に変更
        vector<ll> perm(DIR_NUM); // 訪問順序
        iota(perm.begin(), perm.end(), 0);
        sort(perm.begin(), perm.end(), [&](int a, int b) {
            int dis1 = abs(N/2 - (x+dx[a])) + abs(N/2 - (y+dy[a]));
            int dis2 = abs(N/2 - (x+dx[b])) + abs(N/2 - (y+dy[b]));
            return dis1 > dis2;
        });

        rep(d,DIR_NUM) {
            int nx = x + dx[perm[d]], ny = y + dy[perm[d]];
            if( outField(nx, ny, N, N) || used[nx][ny] ) continue;

            path += dir_to_char[perm[d]];
            for(auto &&[i, j] : group[tile[nx][ny]]) used[i][j] = true;

            greedyDFS(nx, ny, score, path);
            if( utility::mytm.elapsed() > TIME_LIMIT ) return;

            path.pop_back();
            for(auto &&[i, j] : group[tile[nx][ny]]) used[i][j] = false;

            if( back_cnt ) {
                back_cnt--;
                return;
            }
        }
        score -= point[x][y];
        if( score > ans_score ) {
            cerr << "score: " << score << endl;
            ans_score = score;
            ans_str = path;
        }
        // 経路に多様性を持たせる ⇒ 行き止まりがある時に min(path.size() / 300) ターン逆流
        back_cnt = path.size() / 300; // 人力パラメータ調整
        return;
    }

    inline bool outField(int x,int y,int h,int w) {
        if(0 <= x && x < h && 0 <= y && y < w)return false;
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