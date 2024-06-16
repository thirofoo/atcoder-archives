/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc034/submissions/54645147
 * Submitted at: 2024-06-16 20:32:41
 * Problem URL: https://atcoder.jp/contests/ahc034/tasks/ahc034_a
 * Result: RE
 * Execution Time: 1159 ms
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
const int BEAM_WIDTH = 5000;

// right | down | left | up
map<char, P> dir_char = {{'D', { 1, 0}}, {'R', { 0, 1}}, {'U', {-1, 0}}, {'L', { 0,-1}}};

inline char reverse_dir(char dir) {
    if(dir == 'R') return 'L';
    if(dir == 'D') return 'U';
    if(dir == 'L') return 'R';
    if(dir == 'U') return 'D';
    return 'X';
}

ll now_id = 1;
inline ll getId() {
    return now_id++;
}

struct Trace {
    vector<string> ops;
    int parend_id;
    Trace() : parend_id(0) {} // 初期化
    explicit Trace(vector<string> ops, int parend_id) : ops(ops), parend_id(parend_id) {}
};

struct State{
    int id;
    int n, x, y, have;
    int left, right, up, down;
    ll score;
    vector<vector<int>> field;
    char next_dir1, next_dir2;

    State() : n(0), score(0) {}
    explicit State(int n, vector<vector<int>> field, char next_dir1, char next_dir2) : n(n), field(field), next_dir1(next_dir1), next_dir2(next_dir2) {
        x = 0, y = 0;
        have = 0;
        score = 0;
        // それぞれ端から何番目まで探索済みか
        left = 0, right = 0, up = 0, down = 0;
        id = 0;
    }

    inline vector<string> process(char dir) {
        vector<string> res_op;
        char miss_dir = (dir == next_dir1) ? next_dir2 : next_dir1;
        auto [cdx, cdy] = dir_char[miss_dir];
        if(outField(this->x+cdx, this->y+cdy)) {
            miss_dir = dir;
        }

        // その方向にルールベースで移動
        ll border;
        if(dir == 'R' || dir == 'L') border = n-1-left-right;
        else border = n-1-up-down;

        // cerr << "Start !!\n";
        while(border >= 0) {
            // 現在マスが超過してる時 ⇒ 持つ
            if(field[x][y] > 0) {
                res_op.emplace_back("+" + to_string(field[x][y]));
                score += field[x][y];
                have += field[x][y];
                field[x][y] = 0;
            }
            else if(field[x][y] < 0) {
                // 現在マスが不足してる時 ⇒ 補充
                if(abs(field[x][y]) <= this->have) {
                    // 持っているもので足りる時
                    res_op.emplace_back("-" + to_string(abs(field[x][y])));
                    score += field[x][y];
                    have -= abs(field[x][y]);
                    field[x][y] = 0;
                }
                else {
                    // 持っているもので足りない時 ⇒ 下から補充
                    // miss_dir を文字列に変換して res_op に追加

                    // 最後 1 行が端で配列外参照してる時に注意
                    res_op.emplace_back(string(1, miss_dir) );
                    auto [dx, dy] = dir_char[miss_dir];
                    x += dx, y += dy;
                    score += 100 + have;

                    ll shortage = abs(field[x-dx][y-dy]) - have;
                    res_op.emplace_back("+" + to_string(shortage));
                    score += shortage;
                    have += shortage;
                    field[x][y] -= shortage;

                    res_op.emplace_back(string(1, reverse_dir(miss_dir)));
                    x -= dx, y -= dy;
                    score += 100 + have;

                    res_op.emplace_back("-" + to_string(abs(field[x][y])));
                    score += field[x][y];
                    have -= abs(field[x][y]);
                    field[x][y] = 0;
                }
            }
            if(border == 0) break;

            // 移動 phase
            res_op.emplace_back(string(1, dir));
            auto [dx, dy] = dir_char[dir];
            x += dx, y += dy;
            score += 100 + have;
            border--;
        }
        // cerr << "End !!\n";

        // 最後に dir でないもう一方の方向に移動
        id = getId();
        char last = (dir == next_dir1) ? next_dir2 : next_dir1;
        auto [dx, dy] = dir_char[last];
        if(outField(x+dx, y+dy)) return res_op;

        res_op.emplace_back(string(1, last));
        x += dx, y += dy;
        score += 100 + have;

        // if(x < 0 || y < 0) {
        //     cerr << "Error !!\n";
        //     cerr << "dir: " << dir << '\n';
        //     cerr << "x: " << x << " y: " << y << '\n';
        //     cerr << "next_dir1: " << next_dir1 << " next_dir2: " << next_dir2 << '\n';
        //     rep(i, n) {
        //         rep(j, n) cerr << field[i][j] << ' ';
        //         cerr << '\n';
        //     }
        // }

        // 完了済みの数と next_dir の更新
        if((next_dir1 == 'R' && next_dir2 == 'D') || (next_dir1 == 'D' && next_dir2 == 'R')) {
            if(dir == 'R') {
                up++;
                next_dir1 = 'D';
                next_dir2 = 'L';
            }
            else if(dir == 'D') {
                left++;
                next_dir1 = 'R';
                next_dir2 = 'U';
            }
        }
        else if((next_dir1 == 'D' && next_dir2 == 'L') || (next_dir1 == 'L' && next_dir2 == 'D')) {
            if(dir == 'D') {
                right++;
                next_dir1 = 'U';
                next_dir2 = 'L';
            }
            else if(dir == 'L') {
                up++;
                next_dir1 = 'R';
                next_dir2 = 'D';
            }
        }
        else if((next_dir1 == 'L' && next_dir2 == 'U') || (next_dir1 == 'U' && next_dir2 == 'L')) {
            if(dir == 'L') {
                down++;
                next_dir1 = 'R';
                next_dir2 = 'U';
            }
            else if(dir == 'U') {
                right++;
                next_dir1 = 'D';
                next_dir2 = 'L';
            }
        }
        else if((next_dir1 == 'U' && next_dir2 == 'R') || (next_dir1 == 'R' && next_dir2 == 'U')) {
            if(dir == 'U') {
                left++;
                next_dir1 = 'R';
                next_dir2 = 'D';
            }
            else if(dir == 'R') {
                down++;
                next_dir1 = 'U';
                next_dir2 = 'L';
            }
        }
        return res_op;
    }

    bool operator < (const State &s) const {
        return score < s.score;
    }

    inline bool outField(int x, int y) {
        if(0 <= x && x < n && 0 <= y && y < n) return false;
        return true;
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
        for(auto s : ans) cout << s << '\n';
        return;
    }

    void solve() {
        // Beam Search
        ans = beam_search(h);
        return;
    }

    vector<string> beam_search(const vector<vector<int>> &field) {
        vector<Trace> traces;
        vector<string> res;
        ll now_x = 0, now_y = 0;
        // ここをビームサーチで 2 方向近傍でやってみる
        priority_queue<State> beam; // スコアが小さい方が良い ⇒ 降順で持つ
        beam.push(State(n, field, 'R', 'D'));
        traces.emplace_back(Trace{vector<string>{}, 0});

        ll best_score = INF, best_id = 0;
        rep(turn, 2*n-2) {
            // cerr << "turn: " << turn << '\n';
            priority_queue<State> next_beam;
            while(!beam.empty()) {
                State s = beam.top(); beam.pop();
                // cerr << "s.id: " << s.id << " next_dir1: " << s.next_dir1 << " next_dir2: " << s.next_dir2 << '\n';

                State copy_s1 = s;
                vector<string> op1 = copy_s1.process(s.next_dir1);
                // 全てのマスが探索済みの時
                bool ok = true;
                rep(i, n) rep(j, n) if(copy_s1.field[i][j] != 0) ok = false;
                if(ok) {
                    if(copy_s1.score < best_score) {
                        best_score = copy_s1.score;
                        best_id = copy_s1.id;
                    }
                }
                else {
                    next_beam.push(copy_s1);
                    if(next_beam.size() > BEAM_WIDTH) next_beam.pop();
                }
                traces.emplace_back(Trace{op1, s.id});

                State copy_s2 = s;
                vector<string> op2 = copy_s2.process(s.next_dir2);
                ok = true;
                rep(i, n) rep(j, n) if(copy_s2.field[i][j] != 0) ok = false;
                if(ok) {
                    if(copy_s2.score < best_score) {
                        best_score = copy_s2.score;
                        best_id = copy_s2.id;
                    }
                }
                else {
                    next_beam.push(copy_s2);
                    if(next_beam.size() > BEAM_WIDTH) next_beam.pop();
                }
                traces.emplace_back(Trace{op2, s.id});
            }
            swap(beam, next_beam);
        }

        // トレースバック
        while(best_id > 0) {
            reverse(traces[best_id].ops.begin(), traces[best_id].ops.end());
            for(auto t : traces[best_id].ops) res.emplace_back(t);
            best_id = traces[best_id].parend_id;
        }
        reverse(res.begin(), res.end());
        return res;
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