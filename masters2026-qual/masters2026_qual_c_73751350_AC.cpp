/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/masters2026-qual/submissions/73751350
 * Submitted at: 2026-03-01 18:38:08
 * Problem URL: https://atcoder.jp/contests/masters2026-qual/tasks/masters2026_qual_c
 * Result: AC
 * Execution Time: 1913 ms
 */

// C問題: 周期巡回オートマトン - SA解法
#include <algorithm>
#include <array>
#include <chrono>
#include <climits>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

const int N = 20;
int AK, AM, AW;
string vwalls[N];
string hwalls[N - 1];

const int DI[] = {-1, 0, 1, 0};
const int DJ[] = {0, 1, 0, -1};
const char DIR_CHAR[] = {'U', 'R', 'D', 'L'};

bool wall_cache[N][N][4];

void precompute_walls() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int d = 0; d < 4; d++) {
                int ni = i + DI[d], nj = j + DJ[d];
                if (ni < 0 || ni >= N || nj < 0 || nj >= N) {
                    wall_cache[i][j][d] = true;
                    continue;
                }
                if (i == ni)
                    wall_cache[i][j][d] = vwalls[i][min(j, nj)] == '1';
                else
                    wall_cache[i][j][d] = hwalls[min(i, ni)][j] == '1';
            }
}

static int sim_vis[N * N * 4 * 17];
static int sim_ts = 0;

int simulate(const int trans[][4], int m, int si, int sj, int sd, uint32_t cov[N]) {
    int total = N * N * 4 * m;
    sim_ts++;
    int ts = sim_ts;
    int ci = si, cj = sj, cd = sd, cs = 0;

    static int route_i[N * N * 4 * 17 + 1];
    static int route_j[N * N * 4 * 17 + 1];
    int rlen = 0;

    for (int t = 0; t <= total; t++) {
        int key = ((ci * N + cj) * 4 + cd) * m + cs;
        if (sim_vis[key] == ts) {
            int ci2 = si, cj2 = sj, cd2 = sd, cs2 = 0;
            int cycle_start = 0;
            for (int k = 0; k < t; k++) {
                int k2 = ((ci2 * N + cj2) * 4 + cd2) * m + cs2;
                if (k2 == key) { cycle_start = k; break; }
                int w = wall_cache[ci2][cj2][cd2] ? 1 : 0;
                int a = trans[cs2][w * 2], ns = trans[cs2][w * 2 + 1];
                if (a == 0 && !w) { ci2 += DI[cd2]; cj2 += DJ[cd2]; }
                else if (a == 1) cd2 = (cd2 + 1) % 4;
                else if (a == 2) cd2 = (cd2 + 3) % 4;
                cs2 = ns;
            }
            memset(cov, 0, sizeof(uint32_t) * N);
            int cnt = 0;
            for (int k = cycle_start; k < rlen; k++) {
                uint32_t bit = 1u << route_j[k];
                if (!(cov[route_i[k]] & bit)) {
                    cov[route_i[k]] |= bit;
                    cnt++;
                }
            }
            return cnt;
        }
        sim_vis[key] = ts;
        route_i[rlen] = ci;
        route_j[rlen] = cj;
        rlen++;

        int w = wall_cache[ci][cj][cd] ? 1 : 0;
        int a = trans[cs][w * 2], ns = trans[cs][w * 2 + 1];
        if (a == 0 && !w) { ci += DI[cd]; cj += DJ[cd]; }
        else if (a == 1) cd = (cd + 1) % 4;
        else if (a == 2) cd = (cd + 3) % 4;
        cs = ns;
    }
    memset(cov, 0, sizeof(uint32_t) * N);
    return 0;
}

struct RobotOut {
    int m, si, sj;
    char sd;
    vector<array<int, 4>> trans;
};

int segment_solve(vector<RobotOut>& robots) {
    auto try_dir = [](bool col) -> pair<int, vector<RobotOut>> {
        vector<RobotOut> result;
        int total = 0;
        if (col) {
            for (int j = 0; j < N; j++) {
                int start = 0;
                for (int i = 0; i < N; i++) {
                    bool is_end = (i == N - 1) || (hwalls[i][j] == '1');
                    if (is_end) {
                        RobotOut r;
                        r.si = start; r.sj = j; r.sd = 'D';
                        if (i - start + 1 == 1) { r.m = 1; r.trans = {{1, 0, 1, 0}}; }
                        else { r.m = 2; r.trans = {{0, 0, 1, 1}, {1, 0, 1, 0}}; }
                        total += r.m;
                        result.push_back(r);
                        start = i + 1;
                    }
                }
            }
        } else {
            for (int i = 0; i < N; i++) {
                int start = 0;
                for (int j = 0; j < N; j++) {
                    bool is_end = (j == N - 1) || (vwalls[i][j] == '1');
                    if (is_end) {
                        RobotOut r;
                        r.si = i; r.sj = start; r.sd = 'R';
                        if (j - start + 1 == 1) { r.m = 1; r.trans = {{1, 0, 1, 0}}; }
                        else { r.m = 2; r.trans = {{0, 0, 1, 1}, {1, 0, 1, 0}}; }
                        total += r.m;
                        result.push_back(r);
                        start = j + 1;
                    }
                }
            }
        }
        return {total, result};
    };
    auto [rm, rr] = try_dir(false);
    auto [cm, cr] = try_dir(true);
    if (rm <= cm) { robots = rr; return rm; }
    robots = cr; return cm;
}

const int MAX_ROBOTS = 5;
const int MAX_M = 8;

struct Robot {
    int m;
    int trans[MAX_M][4];
    int si, sj, sd;
    uint32_t cov[N];
    int cover;
};

mt19937 g_rng(42);

void resim(Robot& r) {
    r.cover = simulate(r.trans, r.m, r.si, r.sj, r.sd, r.cov);
}

Robot rand_robot(int m) {
    Robot r;
    r.m = m;
    for (int s = 0; s < m; s++) {
        r.trans[s][0] = g_rng() % 3;
        r.trans[s][1] = g_rng() % m;
        r.trans[s][2] = 1 + g_rng() % 2;
        r.trans[s][3] = g_rng() % m;
    }
    r.si = g_rng() % N;
    r.sj = g_rng() % N;
    r.sd = g_rng() % 4;
    resim(r);
    return r;
}

bool expand_state(Robot& r, mt19937& rng) {
    if (r.m >= MAX_M) return false;
    int old_m = r.m;
    int ins = rng() % (old_m + 1);
    int src = (ins == old_m) ? (old_m - 1) : ins;
    int nt[MAX_M][4];
    for (int s = 0; s < old_m; s++) {
        int ns = (s >= ins) ? (s + 1) : s;
        nt[ns][0] = r.trans[s][0];
        nt[ns][1] = (r.trans[s][1] >= ins) ? (r.trans[s][1] + 1) : r.trans[s][1];
        nt[ns][2] = r.trans[s][2];
        nt[ns][3] = (r.trans[s][3] >= ins) ? (r.trans[s][3] + 1) : r.trans[s][3];
    }
    int src2 = (src >= ins) ? (src + 1) : src;
    nt[ins][0] = nt[src2][0];
    nt[ins][1] = nt[src2][1];
    nt[ins][2] = nt[src2][2];
    nt[ins][3] = nt[src2][3];
    int tweak = rng() % 4;
    if (tweak == 0) nt[ins][0] = rng() % 3;
    else if (tweak == 1) nt[ins][1] = rng() % (old_m + 1);
    else if (tweak == 2) nt[ins][2] = 1 + rng() % 2;
    else nt[ins][3] = rng() % (old_m + 1);
    r.m = old_m + 1;
    memcpy(r.trans, nt, sizeof(int) * MAX_M * 4);
    resim(r);
    return true;
}

bool shrink_state(Robot& r, mt19937& rng) {
    if (r.m <= 1) return false;
    int old_m = r.m;
    int del = rng() % old_m;
    int repl_old = (del == old_m - 1) ? (del - 1) : (del + 1);
    int nt[MAX_M][4];
    for (int s = 0; s < old_m; s++) {
        if (s == del) continue;
        int ns = (s > del) ? (s - 1) : s;
        nt[ns][0] = r.trans[s][0];
        int t1 = r.trans[s][1];
        if (t1 == del) t1 = repl_old;
        if (t1 > del) t1--;
        nt[ns][1] = t1;
        nt[ns][2] = r.trans[s][2];
        int t3 = r.trans[s][3];
        if (t3 == del) t3 = repl_old;
        if (t3 > del) t3--;
        nt[ns][3] = t3;
    }
    r.m = old_m - 1;
    memcpy(r.trans, nt, sizeof(int) * MAX_M * 4);
    resim(r);
    return true;
}

bool split_state(Robot& r, mt19937& rng) {
    if (r.m >= MAX_M) return false;
    int src = rng() % r.m;
    int old_m = r.m;
    int nt[MAX_M][4];
    for (int s = 0; s < old_m; s++)
        for (int k = 0; k < 4; k++) nt[s][k] = r.trans[s][k];
    int new_idx = old_m;
    for (int k = 0; k < 4; k++) nt[new_idx][k] = nt[src][k];
    r.m = old_m + 1;
    memcpy(r.trans, nt, sizeof(int) * MAX_M * 4);
    int lane = (rng() % 2) ? 1 : 3;
    r.trans[src][lane] = new_idx;
    int lane2 = (lane == 1) ? 3 : 1;
    if (rng() % 2) r.trans[new_idx][lane2] = src;
    int tweak = rng() % 2;
    if (tweak == 0) r.trans[new_idx][0] = rng() % 3;
    else r.trans[new_idx][2] = 1 + rng() % 2;
    resim(r);
    return true;
}

bool merge_state(Robot& r, mt19937& rng) {
    if (r.m <= 1) return false;
    int old_m = r.m;
    int a = rng() % old_m;
    int b = rng() % old_m;
    while (b == a) b = rng() % old_m;
    int keep = min(a, b);
    int del = max(a, b);
    int nt[MAX_M][4];
    for (int s = 0; s < old_m; s++) {
        if (s == del) continue;
        int ns = (s > del) ? (s - 1) : s;
        nt[ns][0] = r.trans[s][0];
        int t1 = r.trans[s][1];
        if (t1 == del) t1 = keep;
        if (t1 > del) t1--;
        nt[ns][1] = t1;
        nt[ns][2] = r.trans[s][2];
        int t3 = r.trans[s][3];
        if (t3 == del) t3 = keep;
        if (t3 > del) t3--;
        nt[ns][3] = t3;
    }
    int keep2 = keep;
    int del2 = del - 1;
    if (rng() % 2) {
        nt[keep2][0] = nt[del2][0];
        nt[keep2][2] = nt[del2][2];
    }
    if (rng() % 2) nt[keep2][1] = nt[del2][1];
    if (rng() % 2) nt[keep2][3] = nt[del2][3];
    r.m = old_m - 1;
    memcpy(r.trans, nt, sizeof(int) * MAX_M * 4);
    resim(r);
    return true;
}

int calc_cost_v(const vector<Robot>& robots) {
    int total_m = 0;
    for (const auto& r : robots) total_m += r.m;
    return AK * ((int)robots.size() - 1) + AM * total_m; // W=0
}

// 評価関数 (未カバーを強く罰し、その上でVを最小化)
int evaluate(vector<Robot>& robots) {
    uint32_t global[N];
    memset(global, 0, sizeof(global));
    for (auto& r : robots) {
        for (int i = 0; i < N; i++) global[i] |= r.cov[i];
    }
    int uncov = 0;
    const uint32_t FULL = (1u << N) - 1;
    for (int i = 0; i < N; i++)
        uncov += __builtin_popcount(FULL & ~global[i]);
    return uncov * 1000000 + calc_cost_v(robots);
}

// best解の更新
void update_best(vector<Robot>& state, int& best_V, vector<RobotOut>& best_robots) {
    uint32_t global[N];
    memset(global, 0, sizeof(global));
    for (auto& r : state) {
        for (int i = 0; i < N; i++) global[i] |= r.cov[i];
    }
    const uint32_t FULL = (1u << N) - 1;
    for (int i = 0; i < N; i++)
        if ((global[i] & FULL) != FULL) return;
    int v = calc_cost_v(state);
    if (v < best_V) {
        best_V = v;
        best_robots.clear();
        for (auto& r : state) {
            RobotOut ro;
            ro.m = r.m; ro.si = r.si; ro.sj = r.sj; ro.sd = DIR_CHAR[r.sd];
            ro.trans.resize(r.m);
            for (int s = 0; s < r.m; s++)
                ro.trans[s] = {r.trans[s][0], r.trans[s][1], r.trans[s][2], r.trans[s][3]};
            best_robots.push_back(ro);
        }
    }
}

// SA1回分を実行
void run_sa(vector<Robot> state, int& best_V, vector<RobotOut>& best_robots,
            mt19937& rng, chrono::steady_clock::time_point t0, double deadline_s) {
    auto elapsed_ms = [&]() {
        return chrono::duration_cast<chrono::milliseconds>(
            chrono::steady_clock::now() - t0).count();
    };

    int cur_score = evaluate(state);
    update_best(state, best_V, best_robots);

    const double T_START = 50.0;
    const double T_END = 0.1;
    double start_ms = elapsed_ms();
    double total_ms = deadline_s * 1000 - start_ms;
    if (total_ms <= 0) return;

    while (true) {
        double ms = elapsed_ms();
        if (ms > deadline_s * 1000) break;
        double progress = (ms - start_ms) / total_ms;
        double temp = T_START * pow(T_END / T_START, progress);

        bool is_covered = (cur_score < 1000000); // 未カバー罰が無い状態

        int op = rng() % 100;
        int ri = rng() % state.size();

        Robot backup = state[ri];
        int old_size = state.size();

        if (is_covered && op < 20 && (int)state.size() > 1) {
            // 全カバー済み: ロボット削除を積極的に試す
            state.erase(state.begin() + ri);
        } else if (is_covered && op < 35) {
            // 全カバー済み: M-1を試す
            int new_m = state[ri].m - 1;
            if (new_m >= 1) {
                state[ri].m = new_m;
                for (int s = 0; s < new_m; s++) {
                    state[ri].trans[s][1] %= new_m;
                    state[ri].trans[s][3] %= new_m;
                }
                resim(state[ri]);
            }
        } else if (op < 50) {
            // 遷移テーブルの1要素を変更
            int s = rng() % state[ri].m;
            int k = rng() % 4;
            if (k == 0) state[ri].trans[s][0] = rng() % 3;
            else if (k == 1) state[ri].trans[s][1] = rng() % state[ri].m;
            else if (k == 2) state[ri].trans[s][2] = 1 + rng() % 2;
            else state[ri].trans[s][3] = rng() % state[ri].m;
            resim(state[ri]);
        } else if (op < 65) {
            // 開始位置を局所変動 (±2)
            int di = (int)(rng() % 5) - 2;
            int dj = (int)(rng() % 5) - 2;
            state[ri].si = max(0, min(N - 1, state[ri].si + di));
            state[ri].sj = max(0, min(N - 1, state[ri].sj + dj));
            resim(state[ri]);
        } else if (op < 75) {
            // 開始方向変更
            state[ri].sd = rng() % 4;
            resim(state[ri]);
        } else if (op < 82) {
            // ロボットをランダムに置き換え
            int m = 1 + rng() % MAX_M;
            state[ri] = rand_robot(m);
        } else if (op < 88 && (int)state.size() < MAX_ROBOTS) {
            // ロボット追加
            int m = 1 + rng() % MAX_M;
            state.push_back(rand_robot(m));
        } else if (op < 93 && (int)state.size() > 1) {
            // ロボット削除
            state.erase(state.begin() + ri);
        } else if (op < 97) {
            // M構造近傍: expand/shrink/split/merge
            int mv = rng() % 4;
            if (mv == 0) expand_state(state[ri], rng);
            else if (mv == 1) shrink_state(state[ri], rng);
            else if (mv == 2) split_state(state[ri], rng);
            else merge_state(state[ri], rng);
        } else {
            // 開始位置を完全ランダム
            state[ri].si = rng() % N;
            state[ri].sj = rng() % N;
            state[ri].sd = rng() % 4;
            resim(state[ri]);
        }

        int new_score = evaluate(state);
        int diff = new_score - cur_score;

        if (diff <= 0 || (temp > 0 && exp(-diff / temp) > (rng() % 10000) / 10000.0)) {
            cur_score = new_score;
        } else {
            if ((int)state.size() != old_size) {
                if ((int)state.size() > old_size) state.pop_back();
                else state.insert(state.begin() + ri, backup);
            } else {
                state[ri] = backup;
            }
        }

        update_best(state, best_V, best_robots);
    }
}

struct OneRule {
    char a0;
    int b0;
    char a1;
    int b1;
};

struct RectRegionC {
    int entry;
    vector<int> local_walk;
};

struct RectBoxC {
    int r0, c0, r1, c1;
};

struct OneRobotCandidate {
    bool valid = false;
    int v = INT_MAX;
    RobotOut robot;
};

int c_id(int r, int c) { return r * N + c; }

pair<int, int> c_rc(int idx) { return {idx / N, idx % N}; }

int c_can_move(int r, int c, int dir) {
    if (dir == 0) return (r > 0 && hwalls[r - 1][c] == '0');
    if (dir == 1) return (c + 1 < N && vwalls[r][c] == '0');
    if (dir == 2) return (r + 1 < N && hwalls[r][c] == '0');
    return (c > 0 && vwalls[r][c - 1] == '0');
}

int c_step_dir(int a, int b) {
    auto [r, c] = c_rc(a);
    auto [nr, nc] = c_rc(b);
    if (nr == r - 1 && nc == c) return 0;
    if (nr == r && nc == c + 1) return 1;
    if (nr == r + 1 && nc == c) return 2;
    return 3;
}

vector<pair<int, int>> c_neighbors(int r, int c) {
    vector<pair<int, int>> out;
    if (c_can_move(r, c, 0)) out.push_back({0, c_id(r - 1, c)});
    if (c_can_move(r, c, 1)) out.push_back({1, c_id(r, c + 1)});
    if (c_can_move(r, c, 2)) out.push_back({2, c_id(r + 1, c)});
    if (c_can_move(r, c, 3)) out.push_back({3, c_id(r, c - 1)});
    return out;
}

vector<int> c_bfs_path(int src, int dst) {
    if (src == dst) return {src};
    int V = N * N;
    vector<int> prev(V, -1);
    queue<int> q;
    q.push(src);
    prev[src] = src;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        auto [r, c] = c_rc(cur);
        for (auto [dir, nxt] : c_neighbors(r, c)) {
            (void)dir;
            if (prev[nxt] != -1) continue;
            prev[nxt] = cur;
            if (nxt == dst) break;
            q.push(nxt);
        }
    }

    if (prev[dst] == -1) return {};
    vector<int> path;
    for (int cur = dst; cur != src; cur = prev[cur]) path.push_back(cur);
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}

vector<int> c_bfs_path_restricted(int src, int dst, const vector<char>& allowed) {
    if (src == dst) return {src};
    if (!allowed[src] || !allowed[dst]) return {};

    int V = N * N;
    vector<int> prev(V, -1);
    queue<int> q;
    q.push(src);
    prev[src] = src;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        auto [r, c] = c_rc(cur);
        for (auto [dir, nxt] : c_neighbors(r, c)) {
            (void)dir;
            if (!allowed[nxt]) continue;
            if (prev[nxt] != -1) continue;
            prev[nxt] = cur;
            if (nxt == dst) break;
            q.push(nxt);
        }
    }

    if (prev[dst] == -1) return {};
    vector<int> path;
    for (int cur = dst; cur != src; cur = prev[cur]) path.push_back(cur);
    path.push_back(src);
    reverse(path.begin(), path.end());
    return path;
}

bool c_rect_cells_unassigned(const RectBoxC& bx, const vector<char>& assigned) {
    for (int r = bx.r0; r <= bx.r1; r++)
        for (int c = bx.c0; c <= bx.c1; c++)
            if (assigned[c_id(r, c)]) return false;
    return true;
}

bool c_rect_fully_open(const RectBoxC& bx) {
    for (int r = bx.r0; r <= bx.r1; r++)
        for (int c = bx.c0; c < bx.c1; c++)
            if (vwalls[r][c] != '0') return false;
    for (int r = bx.r0; r < bx.r1; r++)
        for (int c = bx.c0; c <= bx.c1; c++)
            if (hwalls[r][c] != '0') return false;
    return true;
}

vector<int> c_build_local_rect_walk(const RectBoxC& bx) {
    vector<int> order;
    for (int r = bx.r0; r <= bx.r1; r++) {
        int dr = r - bx.r0;
        if ((dr & 1) == 0) {
            for (int c = bx.c0; c <= bx.c1; c++) order.push_back(c_id(r, c));
        } else {
            for (int c = bx.c1; c >= bx.c0; c--) order.push_back(c_id(r, c));
        }
    }

    vector<int> walk;
    walk.push_back(order[0]);
    for (int i = 1; i < (int)order.size(); i++) walk.push_back(order[i]);

    vector<char> allowed(N * N, 0);
    for (int r = bx.r0; r <= bx.r1; r++)
        for (int c = bx.c0; c <= bx.c1; c++) allowed[c_id(r, c)] = 1;

    auto back = c_bfs_path_restricted(order.back(), order[0], allowed);
    if (back.empty()) back = c_bfs_path(order.back(), order[0]);
    for (int i = 1; i < (int)back.size(); i++) walk.push_back(back[i]);
    return walk;
}

vector<RectRegionC> c_build_rect_regions() {
    vector<RectRegionC> regs;
    vector<char> assigned(N * N, 0);
    int remaining = N * N;

    while (remaining > 0) {
        RectBoxC best{-1, -1, -1, -1};
        int best_area = 0;

        for (int r0 = 0; r0 < N; r0++) {
            for (int c0 = 0; c0 < N; c0++) {
                if (assigned[c_id(r0, c0)]) continue;
                for (int r1 = r0; r1 < N; r1++) {
                    for (int c1 = c0; c1 < N; c1++) {
                        RectBoxC cand{r0, c0, r1, c1};
                        int area = (r1 - r0 + 1) * (c1 - c0 + 1);
                        if (area < best_area) continue;
                        if (!c_rect_cells_unassigned(cand, assigned)) continue;
                        if (!c_rect_fully_open(cand)) continue;
                        if (area > best_area) {
                            best_area = area;
                            best = cand;
                        }
                    }
                }
            }
        }

        if (best_area <= 0) break;

        RectRegionC reg;
        reg.entry = c_id(best.r0, best.c0);
        reg.local_walk = c_build_local_rect_walk(best);
        regs.push_back(move(reg));

        for (int r = best.r0; r <= best.r1; r++) {
            for (int c = best.c0; c <= best.c1; c++) {
                int cell = c_id(r, c);
                if (!assigned[cell]) {
                    assigned[cell] = 1;
                    remaining--;
                }
            }
        }
    }

    for (int cell = 0; cell < N * N; cell++) {
        if (assigned[cell]) continue;
        RectRegionC reg;
        reg.entry = cell;
        reg.local_walk = {cell};
        regs.push_back(move(reg));
    }
    return regs;
}

vector<int> c_build_rect_route_walk(bool& ok) {
    ok = true;
    auto regs = c_build_rect_regions();
    if (regs.empty()) {
        ok = false;
        return {};
    }

    int root = c_id(0, 0);
    int R = (int)regs.size();
    vector<char> used(R, 0);
    vector<int> order;
    order.reserve(R);

    int cur = root;
    for (int step = 0; step < R; step++) {
        int best_idx = -1;
        int best_dist = INT_MAX;
        for (int i = 0; i < R; i++) {
            if (used[i]) continue;
            auto path = c_bfs_path(cur, regs[i].entry);
            if (path.empty()) continue;
            int dist = (int)path.size();
            if (dist < best_dist) {
                best_dist = dist;
                best_idx = i;
            }
        }
        if (best_idx == -1) {
            ok = false;
            return {};
        }
        used[best_idx] = 1;
        order.push_back(best_idx);
        cur = regs[best_idx].entry;
    }

    vector<int> walk;
    walk.push_back(root);
    cur = root;
    for (int idx : order) {
        auto path = c_bfs_path(cur, regs[idx].entry);
        if (path.empty()) {
            ok = false;
            return {};
        }
        for (int i = 1; i < (int)path.size(); i++) walk.push_back(path[i]);
        for (int i = 1; i < (int)regs[idx].local_walk.size(); i++) walk.push_back(regs[idx].local_walk[i]);
        cur = regs[idx].entry;
    }

    auto back = c_bfs_path(cur, root);
    if (back.empty()) {
        ok = false;
        return {};
    }
    for (int i = 1; i < (int)back.size(); i++) walk.push_back(back[i]);
    return walk;
}

pair<vector<OneRule>, int> c_build_rules_from_walk(const vector<int>& walk) {
    vector<int> move_dirs;
    for (int i = 0; i + 1 < (int)walk.size(); i++) move_dirs.push_back(c_step_dir(walk[i], walk[i + 1]));
    if (move_dirs.empty()) return {{{'R', 0, 'R', 0}}, 0};

    struct Segment {
        int l, r;
        int dir;
    };

    vector<Segment> segs;
    for (int l = 0; l < (int)move_dirs.size();) {
        int r = l;
        while (r + 1 < (int)move_dirs.size() && move_dirs[r + 1] == move_dirs[l]) r++;
        segs.push_back({l, r, move_dirs[l]});
        l = r + 1;
    }

    auto turn_actions = [&](int from, int to) {
        vector<char> acts;
        int diff = (to - from + 4) % 4;
        if (diff == 1) acts.push_back('R');
        else if (diff == 2) {
            acts.push_back('R');
            acts.push_back('R');
        } else if (diff == 3) acts.push_back('L');
        return acts;
    };

    vector<OneRule> rules;
    vector<int> seg_start(segs.size(), -1);
    struct PendingEdge {
        int rule_idx;
        bool wall_branch;
        int target_seg;
    };
    vector<PendingEdge> pending;
    vector<pair<int, int>> seg_edge_cell;
    for (const auto& sg : segs) seg_edge_cell.push_back({walk[sg.r + 1], sg.dir});

    auto add_rule = [&](char a0, int b0, char a1, int b1) {
        rules.push_back({a0, b0, a1, b1});
        return (int)rules.size() - 1;
    };

    for (int si = 0; si < (int)segs.size(); si++) {
        seg_start[si] = (int)rules.size();
        const auto& sg = segs[si];
        int next_si = (si + 1) % (int)segs.size();
        auto tacts = turn_actions(sg.dir, segs[next_si].dir);
        auto [endpoint, dir] = seg_edge_cell[si];
        auto [er, ec] = c_rc(endpoint);
        bool wall_at_end = !c_can_move(er, ec, dir);

        if (wall_at_end) {
            int run_idx = add_rule('F', -1, 'R', -1);
            rules[run_idx].b0 = run_idx;
            if (tacts.empty()) {
                rules[run_idx].a1 = 'R';
                pending.push_back({run_idx, true, next_si});
            } else if ((int)tacts.size() == 1) {
                rules[run_idx].a1 = tacts[0];
                pending.push_back({run_idx, true, next_si});
            } else {
                rules[run_idx].a1 = tacts[0];
                int turn2 = add_rule(tacts[1], -1, tacts[1], -1);
                rules[run_idx].b1 = turn2;
                pending.push_back({turn2, false, next_si});
                pending.push_back({turn2, true, next_si});
            }
        } else {
            int cur = -1;
            for (int k = sg.l; k <= sg.r; k++) {
                int idx = add_rule('F', -1, 'R', -1);
                if (cur != -1) rules[cur].b0 = idx, rules[cur].b1 = idx;
                cur = idx;
            }
            for (char t : tacts) {
                int idx = add_rule(t, -1, t, -1);
                if (cur != -1) rules[cur].b0 = idx, rules[cur].b1 = idx;
                cur = idx;
            }
            if (cur == -1) cur = add_rule('R', -1, 'R', -1);
            pending.push_back({cur, false, next_si});
            pending.push_back({cur, true, next_si});
        }
    }

    for (const auto& e : pending) {
        int target = seg_start[e.target_seg];
        if (e.wall_branch) rules[e.rule_idx].b1 = target;
        else rules[e.rule_idx].b0 = target;
    }

    for (auto& rl : rules) {
        if (rl.b0 < 0) rl.b0 = 0;
        if (rl.b1 < 0) rl.b1 = 0;
        if (rl.a1 == 'F') rl.a1 = 'R';
    }

    return {rules, move_dirs[0]};
}

pair<vector<OneRule>, int> c_minimize_rules(const vector<OneRule>& rules, int start_state) {
    int n = (int)rules.size();
    if (n == 0) return {{}, 0};

    vector<int> cls(n, 0);
    {
        map<pair<char, char>, int> mp;
        int nxt = 0;
        for (int i = 0; i < n; i++) {
            pair<char, char> key = {rules[i].a0, rules[i].a1};
            if (!mp.count(key)) mp[key] = nxt++;
            cls[i] = mp[key];
        }
    }

    while (true) {
        vector<int> ncls(n, 0);
        map<tuple<char, int, char, int>, int> mp;
        int nxt = 0;
        for (int i = 0; i < n; i++) {
            auto sig = make_tuple(rules[i].a0, cls[rules[i].b0], rules[i].a1, cls[rules[i].b1]);
            if (!mp.count(sig)) mp[sig] = nxt++;
            ncls[i] = mp[sig];
        }
        if (ncls == cls) break;
        cls.swap(ncls);
    }

    int cnum = *max_element(cls.begin(), cls.end()) + 1;
    vector<int> repr(cnum, -1);
    for (int i = 0; i < n; i++) if (repr[cls[i]] == -1) repr[cls[i]] = i;

    vector<OneRule> comp(cnum);
    for (int c = 0; c < cnum; c++) {
        int r = repr[c];
        comp[c] = {rules[r].a0, cls[rules[r].b0], rules[r].a1, cls[rules[r].b1]};
    }

    int cstart = cls[start_state];
    vector<int> remap(cnum, -1), q;
    q.push_back(cstart);
    remap[cstart] = 0;
    for (int qi = 0; qi < (int)q.size(); qi++) {
        int vtx = q[qi];
        int to0 = comp[vtx].b0, to1 = comp[vtx].b1;
        if (remap[to0] == -1) {
            remap[to0] = (int)q.size();
            q.push_back(to0);
        }
        if (remap[to1] == -1) {
            remap[to1] = (int)q.size();
            q.push_back(to1);
        }
    }

    vector<OneRule> out(q.size());
    for (int i = 0; i < (int)q.size(); i++) {
        int old = q[i];
        out[i] = {comp[old].a0, remap[comp[old].b0], comp[old].a1, remap[comp[old].b1]};
    }
    return {out, 0};
}

int c_simulate_covered(const vector<OneRule>& rules, int start_dir) {
    int M = (int)rules.size();
    if (M == 0) return 0;

    int r = 0, c = 0, d = start_dir, s = 0;
    vector<vector<char>> visited(N, vector<char>(N, 0));
    visited[r][c] = 1;
    int covered = 1;

    vector<char> seen(N * N * 4 * M, 0);
    auto key = [&](int rr, int cc, int dd, int ss) { return (((rr * N + cc) * 4 + dd) * M + ss); };

    while (true) {
        bool wall = !c_can_move(r, c, d);
        int nr = r + DI[d], nc = c + DJ[d];
        const OneRule& rule = rules[s];
        char act = wall ? rule.a1 : rule.a0;
        int ns = wall ? rule.b1 : rule.b0;

        if (act == 'F') {
            if (!wall) {
                r = nr;
                c = nc;
                if (!visited[r][c]) {
                    visited[r][c] = 1;
                    covered++;
                }
            }
        } else if (act == 'R') d = (d + 1) & 3;
        else d = (d + 3) & 3;
        s = ns;

        int k = key(r, c, d, s);
        if (seen[k]) break;
        seen[k] = 1;
    }
    return covered;
}

OneRobotCandidate build_rect_single_robot_candidate() {
    OneRobotCandidate cand;
    bool ok = false;
    auto walk = c_build_rect_route_walk(ok);
    if (!ok || walk.empty()) return cand;

    auto [rules, start_dir] = c_build_rules_from_walk(walk);
    auto [min_rules, min_start] = c_minimize_rules(rules, 0);
    (void)min_start;
    if (c_simulate_covered(min_rules, start_dir) != N * N) return cand;

    RobotOut out;
    out.m = (int)min_rules.size();
    out.si = 0;
    out.sj = 0;
    out.sd = DIR_CHAR[start_dir];
    out.trans.resize(out.m);

    auto act_to_int = [](char a) {
        if (a == 'F') return 0;
        if (a == 'R') return 1;
        return 2;
    };
    for (int i = 0; i < out.m; i++) {
        out.trans[i] = {act_to_int(min_rules[i].a0), min_rules[i].b0,
                        act_to_int(min_rules[i].a1), min_rules[i].b1};
    }

    cand.valid = true;
    cand.v = AM * out.m;
    cand.robot = move(out);
    return cand;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    auto t0 = chrono::steady_clock::now();

    int n_unused;
    cin >> n_unused >> AK >> AM >> AW;
    for (int i = 0; i < N; i++) cin >> vwalls[i];
    for (int i = 0; i < N - 1; i++) cin >> hwalls[i];
    precompute_walls();

    int best_V = INT_MAX;
    vector<RobotOut> best_robots;
    {
        vector<RobotOut> seg;
        segment_solve(seg);
        best_robots = seg;
        // segment解のVを計算
        int msum = 0;
        for (auto& r : seg) msum += r.m;
        best_V = AK * ((int)seg.size() - 1) + AM * msum;
    }

    // 初期解構築: ジグザグ base + mirror で最良配置
    auto make_initial = [&](mt19937& rng) -> vector<Robot> {
        int zigzag[4][4] = {{1,1,1,1},{0,3,2,2},{0,0,1,2},{2,2,2,1}};
        int zigzag_m[4][4];
        for (int s = 0; s < 4; s++)
            for (int k = 0; k < 4; k += 2) {
                int a = zigzag[s][k];
                if (a == 1) a = 2; else if (a == 2) a = 1;
                zigzag_m[s][k] = a;
                zigzag_m[s][k+1] = zigzag[s][k+1];
            }

        int* tables[] = {(int*)zigzag, (int*)zigzag_m};
        vector<Robot> state;
        uint32_t global[N];
        memset(global, 0, sizeof(global));

        // 1台のみを最良配置で初期化して、M構造近傍で拡張する
        Robot best_r;
        int best_added = -1;
        for (int v = 0; v < 2; v++)
            for (int sd = 0; sd < 4; sd++)
                for (int si = 0; si < N; si++)
                    for (int sj = 0; sj < N; sj++) {
                        uint32_t tmp[N];
                        simulate((const int(*)[4])tables[v], 4, si, sj, sd, tmp);
                        int added = 0;
                        for (int i = 0; i < N; i++)
                            added += __builtin_popcount(tmp[i] & ~global[i]);
                        if (added > best_added) {
                            best_added = added;
                            Robot r;
                            r.m = 4;
                            memcpy(r.trans, tables[v], sizeof(int) * 4 * 4);
                            r.si = si; r.sj = sj; r.sd = sd;
                            memcpy(r.cov, tmp, sizeof(tmp));
                            r.cover = added;
                            best_r = r;
                        }
                    }
        state.push_back(best_r);
        for (int i = 0; i < N; i++) global[i] |= best_r.cov[i];
        return state;
    };

    // 多スタートSA
    const int NUM_STARTS = 3;
    for (int s = 0; s < NUM_STARTS; s++) {
        mt19937 rng(42 + s * 12345);
        vector<Robot> init = make_initial(rng);
        run_sa(init, best_V, best_robots, rng, t0, 1.9 * (s + 1) / NUM_STARTS);
    }

    {
        OneRobotCandidate one = build_rect_single_robot_candidate();
        if (one.valid && one.v < best_V) {
            best_V = one.v;
            best_robots.clear();
            best_robots.push_back(move(one.robot));
        }
    }

    fprintf(stderr, "best_V: %d\n", best_V);

    // 出力
    const char* act_str[] = {"F", "R", "L"};
    cout << best_robots.size() << "\n";
    for (auto& r : best_robots) {
        cout << r.m << " " << r.si << " " << r.sj << " " << r.sd << "\n";
        for (int s = 0; s < r.m; s++)
            cout << act_str[r.trans[s][0]] << " " << r.trans[s][1] << " "
                 << act_str[r.trans[s][2]] << " " << r.trans[s][3] << "\n";
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) cout << '0';
        cout << "\n";
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) cout << '0';
        cout << "\n";
    }
    return 0;
}
