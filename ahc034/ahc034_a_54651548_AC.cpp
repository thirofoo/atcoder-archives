/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc034/submissions/54651548
 * Submitted at: 2024-06-17 00:53:43
 * Problem URL: https://atcoder.jp/contests/ahc034/tasks/ahc034_a
 * Result: AC
 * Execution Time: 1403 ms
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

//-----------------以下から実装部分-----------------//
const ll INF = ((1LL << 62)-(1LL << 31));
const int BEAM_WIDTH = 8000;

// right | down | left | up
map<char, P> dir_char = {{'D', { 1, 0}}, {'R', { 0, 1}}, {'U', {-1, 0}}, {'L', { 0,-1}}};

inline char reverse_dir(char dir) {
    if(dir == 'R') return 'L';
    if(dir == 'D') return 'U';
    if(dir == 'L') return 'R';
    if(dir == 'U') return 'D';
    return 'X';
}

int now_id = 1;
inline int getId() {
    return now_id++;
}

struct Trace {
    vector<string> ops;
    int parend_id;
    Trace() : parend_id(0) {}
    explicit Trace(vector<string> ops, int parend_id) : ops(ops), parend_id(parend_id) {}
};

struct State{
    int id;
    int height, width, x, y, have;
    int x_cnt, y_cnt;
    ll score;
    vector<vector<int>> field;
    char next_dir1, next_dir2;

    State() : score(0) {}
    explicit State(vector<vector<int>> field, char next_dir1, char next_dir2) : field(field), next_dir1(next_dir1), next_dir2(next_dir2) {
        height = field.size();
        width = field[0].size();
        x = 0, y = 0;
        have = 0;
        score = 0;
        // それぞれの方向に何回探索したか
        x_cnt = 0, y_cnt = 0;
        id = 0;
    }

    inline vector<string> process(char dir) {
        vector<string> res_op;
        id = getId();
        auto [tdx, tdy] = dir_char[dir];
        if(outField(this->x+tdx, this->y+tdy)) {
            score = INF;
            return {};
        }
        
        char miss_dir = (dir == next_dir1) ? next_dir2 : next_dir1;
        auto [cdx, cdy] = dir_char[miss_dir];
        if(outField(this->x+cdx, this->y+cdy)) {
            miss_dir = dir;
        }

        // その方向にルールベースで移動
        ll border;
        if(dir == 'R' || dir == 'L') border = width-1-y_cnt;
        else border = height-1-x_cnt;

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
                    score += abs(field[x][y]);
                    have -= abs(field[x][y]);
                    field[x][y] = 0;
                }
                else {
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
                    score += abs(field[x][y]);
                    have -= abs(field[x][y]);
                    field[x][y] = 0;
                }
            }
            if(border == 0) break;

            // 移動 phase
            res_op.emplace_back(string(1, dir));
            auto [dx, dy] = dir_char[dir];
            x += dx, y += dy;
            // ダメな時は終了
            if(outField(x, y)) {
                score = INF;	
                return {};
            }
            score += 100 + have;
            border--;
        }

        // 最後に dir でないもう一方の方向に移動
        char last = (dir == next_dir1) ? next_dir2 : next_dir1;
        auto [dx, dy] = dir_char[last];
        if(outField(x+dx, y+dy)) return res_op;

        res_op.emplace_back(string(1, last));
        x += dx, y += dy;
        score += 100 + have;

        // 完了済みの行・列の数と next_dir の更新
        if(dir == next_dir1) {
            if(dir == 'R' || dir == 'L') x_cnt++;
            else y_cnt++;
            next_dir1 = reverse_dir(dir);
        }
        else {
            if(dir == 'R' || dir == 'L') x_cnt++;
            else y_cnt++;
            next_dir2 = reverse_dir(dir);
        }
        return res_op;
    }

    inline bool outField(int x, int y) {
        if(0 <= x && x < height && 0 <= y && y < width) return false;
        return true;
    }

    bool operator < (const State &s) const {
        return score < s.score;
    }
};

struct Solver{
    int n;
    ll best_score;
    vector<string> ans;
    vector<vector<int>> h;

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
        ll now_x = 0, now_y = 0, best_score = INF, best_id = 0;

        priority_queue<State> beam, next_beam; // スコアが小さい方が良い ⇒ 降順で持つ
        beam.push(State(field, 'R', 'D'));
        traces.emplace_back(Trace{vector<string>{}, 0});
        vector<string> op1, op2;

        State now, copy_s1, copy_s2;

        rep(turn, 2*n-1) {
            while(!beam.empty()) {
                now = beam.top(); beam.pop();

                copy_s1 = now;
                op1 = copy_s1.process(now.next_dir1);
                // 全てのマスが探索済みの時 ⇒ 答えの候補
                if(copy_s1.x_cnt == n || copy_s1.y_cnt == n) {
                    if(copy_s1.score < best_score) {
                        best_score = copy_s1.score;
                        best_id = copy_s1.id;
                    }
                }
                else if(copy_s1.score != INF) {
                    next_beam.push(copy_s1);
                    if(next_beam.size() > BEAM_WIDTH) next_beam.pop();
                }
                traces.emplace_back(Trace{op1, now.id});

                copy_s2 = now;
                op2 = copy_s2.process(now.next_dir2);

                // 全てのマスが探索済みの時 ⇒ 答えの候補
                if(copy_s2.x_cnt == n || copy_s2.y_cnt == n) {
                    if(copy_s2.score < best_score) {
                        best_score = copy_s2.score;
                        best_id = copy_s2.id;
                    }
                }
                else if(copy_s2.score != INF) {
                    next_beam.push(copy_s2);
                    if(next_beam.size() > BEAM_WIDTH) next_beam.pop();
                }
                traces.emplace_back(Trace{op2, now.id});
            }
            swap(beam, next_beam);
        }
        cerr << "Best Score : " << best_score << '\n';

        // Trace Back
        while(best_id > 0) {
            reverse(traces[best_id].ops.begin(), traces[best_id].ops.end());
            for(auto t : traces[best_id].ops) res.emplace_back(t);
            best_id = traces[best_id].parend_id;
        }
        reverse(res.begin(), res.end());
        while(res.back()[0] != '+' && res.back()[0] != '-') res.pop_back();
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