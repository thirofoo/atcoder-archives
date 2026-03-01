/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/masters2026-qual/submissions/73749528
 * Submitted at: 2026-03-01 17:56:02
 * Problem URL: https://atcoder.jp/contests/masters2026-qual/tasks/masters2026_qual_b
 * Result: AC
 * Execution Time: 1912 ms
 */

#include <algorithm>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <string>
#include <vector>
#include <array>
using namespace std;

const int N = 20;
int AK, AM, AW;
string vwalls[N];
string hwalls[N - 1];

const int DI[] = {-1, 0, 1, 0};
const int DJ[] = {0, 1, 0, -1};
const char DIR_CHAR[] = {'U', 'R', 'D', 'L'};

// Precomputed wall info for fast access
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
                        int len = i - start + 1;
                        RobotOut r;
                        r.si = start;
                        r.sj = j;
                        r.sd = 'D';
                        if (len == 1) {
                            r.m = 1;
                            r.trans = {{1, 0, 1, 0}};
                        } else {
                            r.m = 2;
                            r.trans = {{0, 0, 1, 1}, {1, 0, 1, 0}};
                        }
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
                        int len = j - start + 1;
                        RobotOut r;
                        r.si = i;
                        r.sj = start;
                        r.sd = 'R';
                        if (len == 1) {
                            r.m = 1;
                            r.trans = {{1, 0, 1, 0}};
                        } else {
                            r.m = 2;
                            r.trans = {{0, 0, 1, 1}, {1, 0, 1, 0}};
                        }
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
    if (rm <= cm) {
        robots = rr;
        return rm;
    }
    robots = cr;
    return cm;
}

// Fast uncovered segment cost including AK penalty for required straight robots
// Now accepts added walls to correctly compute segments on the modified grid
long long segment_uncovered_cost(const bool covered[N][N],
                                 const vector<pair<int, int>>& added_hwalls = {},
                                 const vector<pair<int, int>>& added_vwalls = {}) {
    // Build effective wall maps
    bool eff_vw[N][N] = {false};
    bool eff_hw[N][N] = {false};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N - 1; j++)
            if (vwalls[i][j] == '1') eff_vw[i][j] = true;
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N; j++)
            if (hwalls[i][j] == '1') eff_hw[i][j] = true;
    for (auto& p : added_vwalls) eff_vw[p.first][p.second] = true;
    for (auto& p : added_hwalls) eff_hw[p.first][p.second] = true;
    int row_m = 0;
    int row_robots = 0;
    for (int i = 0; i < N; i++) {
        int start = 0;
        for (int j = 0; j < N; j++) {
            bool is_end = (j == N - 1) || eff_vw[i][j];
            if (is_end) {
                bool need = false;
                for (int jj = start; jj <= j; jj++)
                    if (!covered[i][jj]) {
                        need = true;
                        break;
                    }
                if (need) {
                    int len = j - start + 1;
                    row_m += (len == 1) ? 1 : 2;
                    row_robots++;
                }
                start = j + 1;
            }
        }
    }
    int col_m = 0;
    int col_robots = 0;
    for (int j = 0; j < N; j++) {
        int start = 0;
        for (int i = 0; i < N; i++) {
            bool is_end = (i == N - 1) || eff_hw[i][j];
            if (is_end) {
                bool need = false;
                for (int ii = start; ii <= i; ii++)
                    if (!covered[ii][j]) {
                        need = true;
                        break;
                    }
                if (need) {
                    int len = i - start + 1;
                    col_m += (len == 1) ? 1 : 2;
                    col_robots++;
                }
                start = i + 1;
            }
        }
    }
    long long cost_row = row_m + (long long)AK * row_robots;
    long long cost_col = col_m + (long long)AK * col_robots;
    return min(cost_row, cost_col);
}
int segment_for_uncovered(const bool covered[N][N], vector<RobotOut>& robots,
                          const vector<pair<int, int>>& added_hwalls = {},
                          const vector<pair<int, int>>& added_vwalls = {}) {
    // Build effective wall maps
    bool eff_vw[N][N] = {false};
    bool eff_hw[N][N] = {false};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N - 1; j++)
            if (vwalls[i][j] == '1') eff_vw[i][j] = true;
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N; j++)
            if (hwalls[i][j] == '1') eff_hw[i][j] = true;
    for (auto& p : added_vwalls) eff_vw[p.first][p.second] = true;
    for (auto& p : added_hwalls) eff_hw[p.first][p.second] = true;
    auto try_dir = [&](bool col) -> pair<int, vector<RobotOut>> {
        vector<RobotOut> result;
        int total = 0;
        bool cov[N][N];
        memcpy(cov, covered, sizeof(cov));
        if (col) {
            for (int j = 0; j < N; j++) {
                int start = 0;
                for (int i = 0; i < N; i++) {
                    bool is_end = (i == N - 1) || eff_hw[i][j];
                    if (is_end) {
                        bool need = false;
                        for (int ii = start; ii <= i; ii++)
                            if (!cov[ii][j]) need = true;
                        if (need) {
                            int len = i - start + 1;
                            RobotOut r;
                            r.si = start;
                            r.sj = j;
                            r.sd = 'D';
                            if (len == 1) {
                                r.m = 1;
                                r.trans = {{1, 0, 1, 0}};
                            } else {
                                r.m = 2;
                                r.trans = {{0, 0, 1, 1}, {1, 0, 1, 0}};
                            }
                            total += r.m;
                            result.push_back(r);
                            for (int ii = start; ii <= i; ii++) cov[ii][j] = true;
                        }
                        start = i + 1;
                    }
                }
            }
        } else {
            for (int i = 0; i < N; i++) {
                int start = 0;
                for (int j = 0; j < N; j++) {
                    bool is_end = (j == N - 1) || eff_vw[i][j];
                    if (is_end) {
                        bool need = false;
                        for (int jj = start; jj <= j; jj++)
                            if (!cov[i][jj]) need = true;
                        if (need) {
                            int len = j - start + 1;
                            RobotOut r;
                            r.si = i;
                            r.sj = start;
                            r.sd = 'R';
                            if (len == 1) {
                                r.m = 1;
                                r.trans = {{1, 0, 1, 0}};
                            } else {
                                r.m = 2;
                                r.trans = {{0, 0, 1, 1}, {1, 0, 1, 0}};
                            }
                            total += r.m;
                            result.push_back(r);
                            for (int jj = start; jj <= j; jj++) cov[i][jj] = true;
                        }
                        start = j + 1;
                    }
                }
            }
        }
        return {total, result};
    };
    auto [rm, rr] = try_dir(false);
    auto [cm, cr] = try_dir(true);
    if (rm <= cm) {
        robots = rr;
        return rm;
    }
    robots = cr;
    return cm;
}

// Fast simulation that returns covered cell count and fills coverage array
// Uses static arrays with timestamp to avoid clearing
static int sim_vis[N * N * 4 * 1601];
static int sim_ts = 0;

int simulate(const int trans[][4], int m, int si, int sj, int sd, bool cov[N][N], 
             const vector<pair<int, int>>& added_hwalls = {}, 
             const vector<pair<int, int>>& added_vwalls = {}) {
    
    // Quick local cache for added walls
    bool has_added = !added_hwalls.empty() || !added_vwalls.empty();
    bool lhw[N][N] = {false};
    bool lvw[N][N] = {false};
    if (has_added) {
        for (auto& p : added_hwalls) lhw[p.first][p.second] = true;
        for (auto& p : added_vwalls) lvw[p.first][p.second] = true;
    }

    auto is_wall = [&](int i, int j, int d) {
        if (wall_cache[i][j][d]) return true;
        if (!has_added) return false;
        int ni = i + DI[d], nj = j + DJ[d];
        if (ni < 0 || ni >= N || nj < 0 || nj >= N) return true;
        if (i == ni) return lvw[i][min(j, nj)];
        else return lhw[min(i, ni)][j];
    };

    int total = N * N * 4 * m;
    sim_ts++;
    int ts = sim_ts;
    int ci = si, cj = sj, cd = sd, cs = 0;

    // We need to find cycle and track cells in cycle only
    // Use two arrays: one for state visitation, one for route
    static int route_i[N * N * 4 * 1601 + 1];
    static int route_j[N * N * 4 * 1601 + 1];
    int rlen = 0;

    for (int t = 0; t <= total; t++) {
        int key = ((ci * N + cj) * 4 + cd) * m + cs;
        if (sim_vis[key] == ts) {
            // Find cycle start by re-simulating
            int ci2 = si, cj2 = sj, cd2 = sd, cs2 = 0;
            int cycle_start = 0;
            for (int k = 0; k < t; k++) {
                int k2 = ((ci2 * N + cj2) * 4 + cd2) * m + cs2;
                if (k2 == key) {
                    cycle_start = k;
                    break;
                }
                int w = is_wall(ci2, cj2, cd2) ? 1 : 0;
                int a, ns;
                if (w == 0) {
                    a = trans[cs2][0];
                    ns = trans[cs2][1];
                } else {
                    a = trans[cs2][2];
                    ns = trans[cs2][3];
                }
                if (a == 0) {
                    ci2 += DI[cd2];
                    cj2 += DJ[cd2];
                } else if (a == 1)
                    cd2 = (cd2 + 1) % 4;
                else
                    cd2 = (cd2 + 3) % 4;
                cs2 = ns;
            }
            int cnt = 0;
            memset(cov, 0, sizeof(bool) * N * N);
            for (int k = cycle_start; k < rlen; k++) {
                if (!cov[route_i[k]][route_j[k]]) {
                    cov[route_i[k]][route_j[k]] = true;
                    cnt++;
                }
            }
            return cnt;
        }

        sim_vis[key] = ts;
        route_i[rlen] = ci;
        route_j[rlen] = cj;
        rlen++;

        int w = is_wall(ci, cj, cd) ? 1 : 0;
        int a, ns;
        if (w == 0) {
            a = trans[cs][0];
            ns = trans[cs][1];
        } else {
            a = trans[cs][2];
            ns = trans[cs][3];
        }
        if (a == 0) {
            ci += DI[cd];
            cj += DJ[cd];
        } else if (a == 1)
            cd = (cd + 1) % 4;
        else
            cd = (cd + 3) % 4;
        cs = ns;
    }
    memset(cov, 0, sizeof(bool) * N * N);
    return 0;
}

struct FRule {
    char a0;
    int b0;
    char a1;
    int b1;
};

struct FRectRegion {
    int entry;
    vector<int> local_walk;
};

struct FRectBox {
    int r0, c0, r1, c1;
};

struct FastGreedyFallbackSolver {
    int n = N;
    int A_K = 0, A_M = 0, A_W = 0;
    vector<string> v, h;

    vector<FRule> best_rules;
    int start_r = 0;
    int start_c = 0;
    char best_start_dir = 'R';

    FastGreedyFallbackSolver(int AK_, int AM_, int AW_) : A_K(AK_), A_M(AM_), A_W(AW_) {
        v.assign(n, string(n - 1, '0'));
        h.assign(n - 1, string(n, '0'));
        for (int i = 0; i < n; i++) v[i] = vwalls[i];
        for (int i = 0; i < n - 1; i++) h[i] = hwalls[i];
    }

    int id(int r, int c) const { return r * n + c; }
    pair<int, int> rc(int idx) const { return {idx / n, idx % n}; }

    int dir_id(char d) const {
        if (d == 'U') return 0;
        if (d == 'R') return 1;
        if (d == 'D') return 2;
        return 3;
    }

    char dir_char(int d) const {
        static const char dc[4] = {'U', 'R', 'D', 'L'};
        return dc[d];
    }

    bool can_move(int r, int c, int dir) const {
        if (dir == 0) return (r > 0 && h[r - 1][c] == '0');
        if (dir == 1) return (c + 1 < n && v[r][c] == '0');
        if (dir == 2) return (r + 1 < n && h[r][c] == '0');
        return (c > 0 && v[r][c - 1] == '0');
    }

    int step_dir(int a, int b) const {
        auto [r, c] = rc(a);
        auto [nr, nc] = rc(b);
        if (nr == r - 1 && nc == c) return 0;
        if (nr == r && nc == c + 1) return 1;
        if (nr == r + 1 && nc == c) return 2;
        return 3;
    }

    vector<pair<int, int>> neighbors(int r, int c) const {
        vector<pair<int, int>> out;
        if (can_move(r, c, 0)) out.push_back({0, id(r - 1, c)});
        if (can_move(r, c, 1)) out.push_back({1, id(r, c + 1)});
        if (can_move(r, c, 2)) out.push_back({2, id(r + 1, c)});
        if (can_move(r, c, 3)) out.push_back({3, id(r, c - 1)});
        return out;
    }

    vector<int> bfs_path(int src, int dst) const {
        if (src == dst) return {src};
        int V = n * n;
        vector<int> prev(V, -1);
        queue<int> q;
        q.push(src);
        prev[src] = src;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            auto [r, c] = rc(cur);
            for (auto [dir, nxt] : neighbors(r, c)) {
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

    vector<int> bfs_path_restricted(int src, int dst, const vector<char>& allowed) const {
        if (src == dst) return {src};
        if (!allowed[src] || !allowed[dst]) return {};

        int V = n * n;
        vector<int> prev(V, -1);
        queue<int> q;
        q.push(src);
        prev[src] = src;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            auto [r, c] = rc(cur);
            for (auto [dir, nxt] : neighbors(r, c)) {
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

    bool rect_cells_unassigned(const FRectBox& bx, const vector<char>& assigned) const {
        for (int r = bx.r0; r <= bx.r1; r++)
            for (int c = bx.c0; c <= bx.c1; c++)
                if (assigned[id(r, c)]) return false;
        return true;
    }

    bool rect_fully_open(const FRectBox& bx) const {
        for (int r = bx.r0; r <= bx.r1; r++)
            for (int c = bx.c0; c < bx.c1; c++)
                if (v[r][c] != '0') return false;
        for (int r = bx.r0; r < bx.r1; r++)
            for (int c = bx.c0; c <= bx.c1; c++)
                if (h[r][c] != '0') return false;
        return true;
    }

    vector<int> build_local_rect_walk(const FRectBox& bx) {
        vector<int> order;
        for (int r = bx.r0; r <= bx.r1; r++) {
            int dr = r - bx.r0;
            if ((dr & 1) == 0)
                for (int c = bx.c0; c <= bx.c1; c++) order.push_back(id(r, c));
            else
                for (int c = bx.c1; c >= bx.c0; c--) order.push_back(id(r, c));
        }

        vector<int> walk;
        walk.push_back(order[0]);
        for (int i = 1; i < (int)order.size(); i++) walk.push_back(order[i]);

        vector<char> allowed(n * n, 0);
        for (int r = bx.r0; r <= bx.r1; r++)
            for (int c = bx.c0; c <= bx.c1; c++) allowed[id(r, c)] = 1;

        auto back = bfs_path_restricted(order.back(), order[0], allowed);
        if (back.empty()) back = bfs_path(order.back(), order[0]);
        for (int i = 1; i < (int)back.size(); i++) walk.push_back(back[i]);
        return walk;
    }

    vector<FRectRegion> build_rect_regions() {
        vector<FRectRegion> regs;
        vector<char> assigned(n * n, 0);
        int remaining = n * n;

        while (remaining > 0) {
            FRectBox best{-1, -1, -1, -1};
            int best_area = 0;

            for (int r0 = 0; r0 < n; r0++) {
                for (int c0 = 0; c0 < n; c0++) {
                    if (assigned[id(r0, c0)]) continue;
                    for (int r1 = r0; r1 < n; r1++) {
                        for (int c1 = c0; c1 < n; c1++) {
                            FRectBox cand{r0, c0, r1, c1};
                            int area = (r1 - r0 + 1) * (c1 - c0 + 1);
                            if (area < best_area) continue;
                            if (!rect_cells_unassigned(cand, assigned)) continue;
                            if (!rect_fully_open(cand)) continue;
                            if (area > best_area) {
                                best_area = area;
                                best = cand;
                            }
                        }
                    }
                }
            }

            if (best_area <= 0) break;

            FRectRegion reg;
            reg.entry = id(best.r0, best.c0);
            reg.local_walk = build_local_rect_walk(best);
            regs.push_back(move(reg));

            for (int r = best.r0; r <= best.r1; r++) {
                for (int c = best.c0; c <= best.c1; c++) {
                    int cell = id(r, c);
                    if (!assigned[cell]) {
                        assigned[cell] = 1;
                        remaining--;
                    }
                }
            }
        }

        for (int cell = 0; cell < n * n; cell++) {
            if (assigned[cell]) continue;
            FRectRegion reg;
            reg.entry = cell;
            reg.local_walk = {cell};
            regs.push_back(move(reg));
        }

        return regs;
    }

    vector<int> build_rect_route_walk(bool& ok) {
        ok = true;
        auto regs = build_rect_regions();
        if (regs.empty()) {
            ok = false;
            return {};
        }

        int root = id(0, 0);
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
                auto path = bfs_path(cur, regs[i].entry);
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
            auto path = bfs_path(cur, regs[idx].entry);
            if (path.empty()) {
                ok = false;
                return {};
            }
            for (int i = 1; i < (int)path.size(); i++) walk.push_back(path[i]);
            for (int i = 1; i < (int)regs[idx].local_walk.size(); i++) walk.push_back(regs[idx].local_walk[i]);
            cur = regs[idx].entry;
        }

        auto back = bfs_path(cur, root);
        if (back.empty()) {
            ok = false;
            return {};
        }
        for (int i = 1; i < (int)back.size(); i++) walk.push_back(back[i]);
        return walk;
    }

    pair<vector<FRule>, char> build_rules_from_walk(const vector<int>& walk) {
        vector<int> move_dirs;
        for (int i = 0; i + 1 < (int)walk.size(); i++) move_dirs.push_back(step_dir(walk[i], walk[i + 1]));

        if (move_dirs.empty()) return {{{'R', 0, 'R', 0}}, 'U'};

        int init_dir = move_dirs[0];
        char start_dir = dir_char(init_dir);

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
            } else if (diff == 3)
                acts.push_back('L');
            return acts;
        };

        vector<FRule> rules;
        vector<int> seg_start(segs.size(), -1);
        struct PendingEdge {
            int rule_idx;
            bool wall_branch;
            int target_seg;
        };
        vector<PendingEdge> pending;
        vector<pair<int, int>> seg_edge_cell;
        seg_edge_cell.reserve(segs.size());
        for (const auto& sg : segs) {
            int endpoint = walk[sg.r + 1];
            seg_edge_cell.push_back({endpoint, sg.dir});
        }

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
            auto [er, ec] = rc(endpoint);
            bool wall_at_end = !can_move(er, ec, dir);

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
                if (cur == -1) {
                    int idx = add_rule('R', -1, 'R', -1);
                    cur = idx;
                }
                pending.push_back({cur, false, next_si});
                pending.push_back({cur, true, next_si});
            }
        }

        for (const auto& e : pending) {
            int target = seg_start[e.target_seg];
            if (e.wall_branch)
                rules[e.rule_idx].b1 = target;
            else
                rules[e.rule_idx].b0 = target;
        }

        for (auto& rl : rules) {
            if (rl.b0 < 0) rl.b0 = 0;
            if (rl.b1 < 0) rl.b1 = 0;
            if (rl.a1 == 'F') rl.a1 = 'R';
        }

        return {rules, start_dir};
    }

    pair<vector<FRule>, int> minimize_rules(const vector<FRule>& rules, int start_state) {
        int nst = (int)rules.size();
        if (nst == 0) return {{}, 0};

        vector<int> cls(nst, 0);
        {
            map<pair<char, char>, int> mp;
            int nxt = 0;
            for (int i = 0; i < nst; i++) {
                pair<char, char> key = {rules[i].a0, rules[i].a1};
                if (!mp.count(key)) mp[key] = nxt++;
                cls[i] = mp[key];
            }
        }

        while (true) {
            vector<int> ncls(nst, 0);
            map<tuple<char, int, char, int>, int> mp;
            int nxt = 0;
            for (int i = 0; i < nst; i++) {
                auto sig = make_tuple(rules[i].a0, cls[rules[i].b0], rules[i].a1, cls[rules[i].b1]);
                if (!mp.count(sig)) mp[sig] = nxt++;
                ncls[i] = mp[sig];
            }
            if (ncls == cls) break;
            cls.swap(ncls);
        }

        int cnum = *max_element(cls.begin(), cls.end()) + 1;
        vector<int> repr(cnum, -1);
        for (int i = 0; i < nst; i++)
            if (repr[cls[i]] == -1) repr[cls[i]] = i;

        vector<FRule> comp(cnum);
        for (int c = 0; c < cnum; c++) {
            int r = repr[c];
            comp[c] = {rules[r].a0, cls[rules[r].b0], rules[r].a1, cls[rules[r].b1]};
        }

        int cstart = cls[start_state];
        vector<int> remap(cnum, -1);
        vector<int> q;
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

        vector<FRule> out(q.size());
        for (int i = 0; i < (int)q.size(); i++) {
            int old = q[i];
            out[i] = {comp[old].a0, remap[comp[old].b0], comp[old].a1, remap[comp[old].b1]};
        }
        return {out, 0};
    }

    int simulate_covered(const vector<FRule>& rules, char start_dir) const {
        int M = (int)rules.size();
        if (M == 0) return 0;

        int r = start_r, c = start_c, d = dir_id(start_dir), s = 0;
        vector<vector<char>> visited(n, vector<char>(n, 0));
        visited[r][c] = 1;
        int covered = 1;

        vector<char> seen(n * n * 4 * M, 0);
        auto key = [&](int rr, int cc, int dd, int ss) {
            return (((rr * n + cc) * 4 + dd) * M + ss);
        };

        while (true) {
            bool wall = !can_move(r, c, d);
            int nr = r + DI[d], nc = c + DJ[d];

            const FRule& rule = rules[s];
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
            } else if (act == 'R')
                d = (d + 1) & 3;
            else
                d = (d + 3) & 3;
            s = ns;

            int k = key(r, c, d, s);
            if (seen[k]) break;
            seen[k] = 1;
        }

        return covered;
    }

    void try_candidate(const vector<int>& walk, long long& best_cost) {
        auto [rules, sd] = build_rules_from_walk(walk);
        auto [min_rules, min_start] = minimize_rules(rules, 0);
        (void)min_start;

        if (simulate_covered(min_rules, sd) != n * n) return;

        long long cost = 1LL * A_K + 1LL * A_M * (int)min_rules.size();
        if (cost < best_cost) {
            best_cost = cost;
            best_rules = min_rules;
            best_start_dir = sd;
        }
    }

    tuple<bool, long long, vector<FRule>, char> build_best() {
        long long best_cost = (1LL << 62);

        bool ok_rect = false;
        auto rect_walk = build_rect_route_walk(ok_rect);
        if (ok_rect && !rect_walk.empty()) try_candidate(rect_walk, best_cost);

        if (best_rules.empty()) return {false, (1LL << 62), {}, 'U'};
        return {true, best_cost, best_rules, best_start_dir};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_unused;
    cin >> n_unused >> AK >> AM >> AW;
    for (int i = 0; i < N; i++) cin >> vwalls[i];
    for (int i = 0; i < N - 1; i++) cin >> hwalls[i];
    precompute_walls();

    auto start_time = chrono::steady_clock::now();
    mt19937 rng(42);
    auto elapsed_ms = [&]() {
        return chrono::duration_cast<chrono::milliseconds>(
                   chrono::steady_clock::now() - start_time)
            .count();
    };

    long long best_M = 1e18;
    vector<RobotOut> best_robots;
    {
        vector<RobotOut> seg;
        int seg_m = segment_solve(seg);
        // Total cost = sum of states + AK * (num_robots - 1)
        best_M = seg_m + (long long)AK * max(0, (int)seg.size() - 1);
        best_robots = seg;
    }

    // ============================================================
    // Phase 1: Try zigzag automaton variants with all start positions
    // The base zigzag: go straight, bounce at wall, shift one column, repeat
    // ============================================================
    {
        // Base zigzag: S0=turn, S1=go straight, S2=shift+corner, S3=transition
        // Original (vertical zigzag, shift right):
        //   S0: w0→R,1  w1→R,1
        //   S1: w0→F,3  w1→L,2
        //   S2: w0→F,0  w1→R,2
        //   S3: w0→L,2  w1→L,1
        // We generate 8 variants: 4 rotations x 2 mirrors (shift left vs right)

        // Action encoding: 0=F, 1=R, 2=L
        // To rotate an automaton by 90 degrees CW, we swap R<->L in actions
        // and rotate the start direction.
        // Actually rotation doesn't change the automaton itself - it only changes
        // the start direction. Mirror (swap R<->L) gives shift-left variant.

        int zigzag_base[4][4] = {
            {1, 1, 1, 1},  // S0: always R, goto S1
            {0, 3, 2, 2},  // S1: w0→F,S3  w1→L,S2
            {0, 0, 1, 2},  // S2: w0→F,S0  w1→R,S2
            {2, 2, 2, 1},  // S3: w0→L,S2  w1→L,S1
        };

        // Mirror variant: swap R(1)<->L(2) in actions
        int zigzag_mirror[4][4];
        for (int s = 0; s < 4; s++) {
            for (int k = 0; k < 4; k += 2) {
                int a = zigzag_base[s][k];
                if (a == 1)
                    a = 2;
                else if (a == 2)
                    a = 1;
                zigzag_mirror[s][k] = a;
                zigzag_mirror[s][k + 1] = zigzag_base[s][k + 1];
            }
        }

        int variants[2][4][4];
        memcpy(variants[0], zigzag_base, sizeof(zigzag_base));
        memcpy(variants[1], zigzag_mirror, sizeof(zigzag_mirror));

        for (int v = 0; v < 2; v++) {
            for (int sd = 0; sd < 4; sd++) {
                for (int si = 0; si < N; si++) {
                    for (int sj = 0; sj < N; sj++) {
                        bool cov[N][N];
                        int cover = simulate(variants[v], 4, si, sj, sd, cov);
                        if (cover == N * N) {
                            // 1 robot, 0 fallback. Cost = 4 + AK*0 = 4
                            if (4 < best_M) {
                                best_M = 4;
                                best_robots.clear();
                                RobotOut r;
                                r.m = 4;
                                r.si = si;
                                r.sj = sj;
                                r.sd = DIR_CHAR[sd];
                                r.trans.resize(4);
                                for (int s = 0; s < 4; s++)
                                    r.trans[s] = {variants[v][s][0], variants[v][s][1],
                                                  variants[v][s][2], variants[v][s][3]};
                                best_robots = {r};
                            }
                        } else {
                            long long fb = segment_uncovered_cost(cov);
                            // 1 zigzag robot + fallback robots
                            // fb already includes AK * fallback_robot_count
                            // Total = 4 + fb
                            if (4 + fb < best_M) {
                                best_M = 4 + fb;
                                best_robots.clear();
                                RobotOut r;
                                r.m = 4;
                                r.si = si;
                                r.sj = sj;
                                r.sd = DIR_CHAR[sd];
                                r.trans.resize(4);
                                for (int s = 0; s < 4; s++)
                                    r.trans[s] = {variants[v][s][0], variants[v][s][1],
                                                  variants[v][s][2], variants[v][s][3]};
                                best_robots = {r};
                                bool cov2[N][N];
                                memcpy(cov2, cov, sizeof(cov));
                                vector<RobotOut> fb_r;
                                segment_for_uncovered(cov2, fb_r);
                                for (auto& fr : fb_r) best_robots.push_back(fr);
                            }
                        }
                    }
                }
            }
        }
    }

    // ============================================================
    // Phase 1.5: Two zigzag robots with different start positions (M=8)
    // When single zigzag can't cover all, try pairs
    // ============================================================
    if (best_M > 8) {
        int zigzag_base[4][4] = {
            {1, 1, 1, 1},
            {0, 3, 2, 2},
            {0, 0, 1, 2},
            {2, 2, 2, 1},
        };
        int zigzag_mirror[4][4];
        for (int s = 0; s < 4; s++) {
            for (int k = 0; k < 4; k += 2) {
                int a = zigzag_base[s][k];
                if (a == 1)
                    a = 2;
                else if (a == 2)
                    a = 1;
                zigzag_mirror[s][k] = a;
                zigzag_mirror[s][k + 1] = zigzag_base[s][k + 1];
            }
        }
        int vars[2][4][4];
        memcpy(vars[0], zigzag_base, sizeof(zigzag_base));
        memcpy(vars[1], zigzag_mirror, sizeof(zigzag_mirror));

        // Precompute coverage for all (variant, dir, i, j)
        // Store which cells each config covers
        struct ZConfig {
            int v, sd, si, sj;
            bool cov[N][N];
            int cover;
        };

        // Too many configs to store all, so use greedy:
        // Find best single zigzag, then find best complement
        int best1_v = -1, best1_sd = -1, best1_si = -1, best1_sj = -1, best1_cover = 0;
        bool best1_cov[N][N];

        for (int v = 0; v < 2; v++)
            for (int sd = 0; sd < 4; sd++)
                for (int si = 0; si < N; si++)
                    for (int sj = 0; sj < N; sj++) {
                        bool cov[N][N];
                        int cover = simulate(vars[v], 4, si, sj, sd, cov);
                        if (cover > best1_cover) {
                            best1_cover = cover;
                            best1_v = v;
                            best1_sd = sd;
                            best1_si = si;
                            best1_sj = sj;
                            memcpy(best1_cov, cov, sizeof(cov));
                        }
                    }

        // Now find best second robot to complement
        if (best1_cover < N * N) {
            int best_pair_uncov = N * N;
            int b2_v = -1, b2_sd = -1, b2_si = -1, b2_sj = -1;

            for (int v = 0; v < 2; v++)
                for (int sd = 0; sd < 4; sd++)
                    for (int si = 0; si < N; si++)
                        for (int sj = 0; sj < N; sj++) {
                            bool cov[N][N];
                            simulate(vars[v], 4, si, sj, sd, cov);
                            // Count uncovered cells (not covered by either robot)
                            int uncov = 0;
                            for (int i = 0; i < N; i++)
                                for (int j = 0; j < N; j++)
                                    if (!best1_cov[i][j] && !cov[i][j]) uncov++;
                            if (uncov < best_pair_uncov) {
                                best_pair_uncov = uncov;
                                b2_v = v;
                                b2_sd = sd;
                                b2_si = si;
                                b2_sj = sj;
                            }
                        }

            // Compute actual M for this pair
            bool combined[N][N];
            {
                bool cov2[N][N];
                simulate(vars[b2_v], 4, b2_si, b2_sj, b2_sd, cov2);
                for (int i = 0; i < N; i++)
                    for (int j = 0; j < N; j++)
                        combined[i][j] = best1_cov[i][j] || cov2[i][j];
            }
            long long fb = segment_uncovered_cost(combined);
            // 2 zigzag robots + fallback robots
            // fb includes AK * fallback_robot_count
            // Total = 8 + AK*(2-1 extra robots from zigzags) + fb
            //       = 8 + AK + fb
            long long total = 8 + AK + fb;

            if (total < best_M) {
                best_M = total;
                best_robots.clear();

                RobotOut r1;
                r1.m = 4;
                r1.si = best1_si;
                r1.sj = best1_sj;
                r1.sd = DIR_CHAR[best1_sd];
                r1.trans.resize(4);
                for (int s = 0; s < 4; s++)
                    r1.trans[s] = {vars[best1_v][s][0], vars[best1_v][s][1],
                                   vars[best1_v][s][2], vars[best1_v][s][3]};
                best_robots.push_back(r1);

                RobotOut r2;
                r2.m = 4;
                r2.si = b2_si;
                r2.sj = b2_sj;
                r2.sd = DIR_CHAR[b2_sd];
                r2.trans.resize(4);
                for (int s = 0; s < 4; s++)
                    r2.trans[s] = {vars[b2_v][s][0], vars[b2_v][s][1],
                                   vars[b2_v][s][2], vars[b2_v][s][3]};
                best_robots.push_back(r2);

                vector<RobotOut> fb_r;
                segment_for_uncovered(combined, fb_r);
                for (auto& fr : fb_r) best_robots.push_back(fr);
            }

            // ============================================================
            // Phase 1.7: Three zigzag robots (M=12)
            // ============================================================
            if (best_M > 12 && best_pair_uncov > 0) {
                int best_triple_uncov = N * N;
                int b3_v = -1, b3_sd = -1, b3_si = -1, b3_sj = -1;

                for (int v = 0; v < 2; v++)
                    for (int sd = 0; sd < 4; sd++)
                        for (int si = 0; si < N; si++)
                            for (int sj = 0; sj < N; sj++) {
                                bool cov[N][N];
                                simulate(vars[v], 4, si, sj, sd, cov);
                                int uncov = 0;
                                for (int i = 0; i < N; i++)
                                    for (int j = 0; j < N; j++)
                                        if (!combined[i][j] && !cov[i][j]) uncov++;
                                if (uncov < best_triple_uncov) {
                                    best_triple_uncov = uncov;
                                    b3_v = v; b3_sd = sd; b3_si = si; b3_sj = sj;
                                }
                            }

                bool combined3[N][N];
                {
                    bool cov3[N][N];
                    simulate(vars[b3_v], 4, b3_si, b3_sj, b3_sd, cov3);
                    for (int i = 0; i < N; i++)
                        for (int j = 0; j < N; j++)
                            combined3[i][j] = combined[i][j] || cov3[i][j];
                }

                long long fb3 = segment_uncovered_cost(combined3);
                // 3 zigzag robots + fallback robots
                // Total = 12 + AK*2 + fb3
                long long total3 = 12 + (long long)AK * 2 + fb3;

                if (total3 < best_M) {
                    best_M = total3;
                    best_robots.clear();

                    RobotOut r1;
                    r1.m = 4; r1.si = best1_si; r1.sj = best1_sj; r1.sd = DIR_CHAR[best1_sd];
                    r1.trans.resize(4);
                    for (int s = 0; s < 4; s++)
                        r1.trans[s] = {vars[best1_v][s][0], vars[best1_v][s][1], vars[best1_v][s][2], vars[best1_v][s][3]};
                    best_robots.push_back(r1);

                    RobotOut r2;
                    r2.m = 4; r2.si = b2_si; r2.sj = b2_sj; r2.sd = DIR_CHAR[b2_sd];
                    r2.trans.resize(4);
                    for (int s = 0; s < 4; s++)
                        r2.trans[s] = {vars[b2_v][s][0], vars[b2_v][s][1], vars[b2_v][s][2], vars[b2_v][s][3]};
                    best_robots.push_back(r2);

                    RobotOut r3;
                    r3.m = 4; r3.si = b3_si; r3.sj = b3_sj; r3.sd = DIR_CHAR[b3_sd];
                    r3.trans.resize(4);
                    for (int s = 0; s < 4; s++)
                        r3.trans[s] = {vars[b3_v][s][0], vars[b3_v][s][1], vars[b3_v][s][2], vars[b3_v][s][3]};
                    best_robots.push_back(r3);

                    vector<RobotOut> fb_r3;
                    segment_for_uncovered(combined3, fb_r3);
                    for (auto& fr : fb_r3) best_robots.push_back(fr);
                }
            }
        }
    }

    // ============================================================
    // Phase 2: Dedicated "1 zigzag + wall-only SA" for Problem B
    // Fix the automaton to zigzag, only mutate walls + start position.
    // Walls are cheap (AW=1), robots are expensive (AK=10).
    // ============================================================
    int aut_trans[1600][4];
    vector<pair<int, int>> global_best_hwalls, global_best_vwalls;
    {
        int zigzag_base[4][4] = {
            {1, 1, 1, 1},
            {0, 3, 2, 2},
            {0, 0, 1, 2},
            {2, 2, 2, 1},
        };
        int zigzag_mirror[4][4];
        for (int s = 0; s < 4; s++) {
            for (int k = 0; k < 4; k += 2) {
                int a = zigzag_base[s][k];
                if (a == 1) a = 2;
                else if (a == 2) a = 1;
                zigzag_mirror[s][k] = a;
                zigzag_mirror[s][k + 1] = zigzag_base[s][k + 1];
            }
        }
        int vars[2][4][4];
        memcpy(vars[0], zigzag_base, sizeof(zigzag_base));
        memcpy(vars[1], zigzag_mirror, sizeof(zigzag_mirror));
        for (int base_var = 0; base_var < 2 && elapsed_ms() < 1800; base_var++) {
            for (int restart = 0; restart < 50 && elapsed_ms() < 1800; restart++) {
                int si = rng() % N, sj = rng() % N, sd = rng() % 4;
                vector<pair<int, int>> hwalls_list, vwalls_list;
                // Seed with a few random walls
                int init_walls = rng() % 10;
                for (int w = 0; w < init_walls; w++) {
                    int wi = rng() % (N - 1), wj = rng() % N;
                    if (rng() % 2) hwalls_list.push_back({wi, wj});
                    else { wj = rng() % (N - 1); vwalls_list.push_back({rng() % N, wj}); }
                }
                bool cov[N][N];
                simulate(vars[base_var], 4, si, sj, sd, cov, hwalls_list, vwalls_list);
                long long fb = segment_uncovered_cost(cov, hwalls_list, vwalls_list);
                long long wall_cost = (long long)(hwalls_list.size() + vwalls_list.size()) * AW;
                long long total_m = 4 + fb + wall_cost;
                int bsi = si, bsj = sj, bsd = sd;
                long long best_total = total_m;
                vector<pair<int, int>> best_hw = hwalls_list, best_vw = vwalls_list;
                double temp = 10.0;
                for (int it = 0; it < 20000 && elapsed_ms() < 1800; it++) {
                    int osi = si, osj = sj, osd = sd;
                    auto ohw = hwalls_list;
                    auto ovw = vwalls_list;
                    int mv = rng() % 10;
                    if (mv < 3) {
                        // Add wall at boundary of uncovered cell
                        // Find uncovered cells
                        vector<pair<int, int>> uncov_cells;
                        for (int i = 0; i < N; i++)
                            for (int j = 0; j < N; j++)
                                if (!cov[i][j]) uncov_cells.push_back({i, j});
                        if (!uncov_cells.empty()) {
                            auto cell = uncov_cells[rng() % uncov_cells.size()];
                            int dir = rng() % 4;
                            int i = cell.first, j = cell.second;
                            int ni = i + DI[dir], nj = j + DJ[dir];
                            if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                                if (i == ni) vwalls_list.push_back({i, min(j, nj)});
                                else hwalls_list.push_back({min(i, ni), j});
                            }
                        }
                    } else if (mv < 5) {
                        // Add wall at random position
                        if (rng() % 2) {
                            hwalls_list.push_back({(int)(rng() % (N - 1)), (int)(rng() % N)});
                        } else {
                            vwalls_list.push_back({(int)(rng() % N), (int)(rng() % (N - 1))});
                        }
                    } else if (mv < 7) {
                        // Remove a wall
                        if (rng() % 2 == 0 && !hwalls_list.empty()) {
                            hwalls_list.erase(hwalls_list.begin() + (rng() % hwalls_list.size()));
                        } else if (!vwalls_list.empty()) {
                            vwalls_list.erase(vwalls_list.begin() + (rng() % vwalls_list.size()));
                        }
                    } else if (mv < 9) {
                        // Change start position
                        si = rng() % N;
                        sj = rng() % N;
                        sd = rng() % 4;
                    } else {
                        // Toggle: remove one wall + add one wall
                        if (!hwalls_list.empty() || !vwalls_list.empty()) {
                            if (rng() % 2 == 0 && !hwalls_list.empty())
                                hwalls_list.erase(hwalls_list.begin() + (rng() % hwalls_list.size()));
                            else if (!vwalls_list.empty())
                                vwalls_list.erase(vwalls_list.begin() + (rng() % vwalls_list.size()));
                        }
                        if (rng() % 2) hwalls_list.push_back({(int)(rng() % (N - 1)), (int)(rng() % N)});
                        else vwalls_list.push_back({(int)(rng() % N), (int)(rng() % (N - 1))});
                    }
                    bool nc[N][N];
                    simulate(vars[base_var], 4, si, sj, sd, nc, hwalls_list, vwalls_list);
                    long long nfb = segment_uncovered_cost(nc, hwalls_list, vwalls_list);
                    long long nwc = (long long)(hwalls_list.size() + vwalls_list.size()) * AW;
                    long long nt = 4 + nfb + nwc;
                    double delta = (double)nt - (double)total_m;
                    if (delta < 0 || (rng() % 10000 < 10000 * exp(-delta / temp))) {
                        total_m = nt;
                        memcpy(cov, nc, sizeof(cov));
                        if (nt < best_total) {
                            best_total = nt;
                            bsi = si; bsj = sj; bsd = sd;
                            best_hw = hwalls_list;
                            best_vw = vwalls_list;
                        }
                    } else {
                        si = osi; sj = osj; sd = osd;
                        hwalls_list = ohw;
                        vwalls_list = ovw;
                    }
                    temp *= 0.9998;
                }
                if (best_total < best_M) {
                    best_M = best_total;
                    bool fcov[N][N];
                    simulate(vars[base_var], 4, bsi, bsj, bsd, fcov, best_hw, best_vw);
                    best_robots.clear();
                    RobotOut mr;
                    mr.m = 4;
                    mr.si = bsi; mr.sj = bsj; mr.sd = DIR_CHAR[bsd];
                    mr.trans.resize(4);
                    for (int s = 0; s < 4; s++)
                        mr.trans[s] = {vars[base_var][s][0], vars[base_var][s][1],
                                       vars[base_var][s][2], vars[base_var][s][3]};
                    best_robots = {mr};
                    vector<RobotOut> fbrob;
                    segment_for_uncovered(fcov, fbrob, best_hw, best_vw);
                    for (auto& r : fbrob) best_robots.push_back(r);
                    global_best_hwalls = best_hw;
                    global_best_vwalls = best_vw;
                }
            }
        }
    }

    // Phase 3: Random SA (remaining time)
    for (int num_states = 2; num_states <= 30 && elapsed_ms() < 1900; num_states++) {
        int max_restarts = (num_states <= 10) ? 100 : 30;
        for (int restart = 0; restart < max_restarts && elapsed_ms() < 1900; restart++) {
            int aut_trans[1600][4];
            // Random init
            for (int s = 0; s < num_states; s++) {
                aut_trans[s][0] = rng() % 3;
                aut_trans[s][1] = rng() % num_states;
                aut_trans[s][2] = 1 + rng() % 2;
                aut_trans[s][3] = rng() % num_states;
            }
            int si = rng() % N, sj = rng() % N, sd = rng() % 4;
            vector<pair<int, int>> hwalls_list, vwalls_list;
            vector<pair<int, int>> best_hwalls, best_vwalls;
            bool cov[N][N];
            int cover = simulate(aut_trans, num_states, si, sj, sd, cov);
            long long fb_m = segment_uncovered_cost(cov, hwalls_list, vwalls_list);
            long long total_m = num_states + fb_m;
            int best_trans[1600][4];
            memcpy(best_trans, aut_trans, sizeof(int) * 4 * num_states);
            int bsi = si, bsj = sj, bsd = sd;
            long long best_total = total_m;

            double temp = 5.0;
            int iters = (num_states <= 5) ? 5000 : 2000;

            for (int it = 0; it < iters && elapsed_ms() < 1900; it++) {
                int old_trans[1600][4];
                memcpy(old_trans, aut_trans, sizeof(int) * 4 * num_states);
                int osi = si, osj = sj, osd = sd;
                auto ohw = hwalls_list;
                auto ovw = vwalls_list;

                int mv = rng() % 28;
                if (mv < 5) {
                    // Single entry change
                    int s = rng() % num_states, w = rng() % 2;
                    if (w == 0) {
                        if (rng() % 2)
                            aut_trans[s][0] = rng() % 3;
                        else
                            aut_trans[s][1] = rng() % num_states;
                    } else {
                        if (rng() % 2)
                            aut_trans[s][2] = 1 + rng() % 2;
                        else
                            aut_trans[s][3] = rng() % num_states;
                    }
                } else if (mv < 8) {
                    // Reinitialize one state completely
                    int s = rng() % num_states;
                    aut_trans[s][0] = rng() % 3;
                    aut_trans[s][1] = rng() % num_states;
                    aut_trans[s][2] = 1 + rng() % 2;
                    aut_trans[s][3] = rng() % num_states;
                } else if (mv < 10) {
                    // Change multiple entries (2-3)
                    int cnt = 2 + rng() % 2;
                    for (int c = 0; c < cnt; c++) {
                        int s = rng() % num_states, w = rng() % 2;
                        if (w == 0) {
                            if (rng() % 2)
                                aut_trans[s][0] = rng() % 3;
                            else
                                aut_trans[s][1] = rng() % num_states;
                        } else {
                            if (rng() % 2)
                                aut_trans[s][2] = 1 + rng() % 2;
                            else
                                aut_trans[s][3] = rng() % num_states;
                        }
                    }
                } else if (mv < 13) {
                    // Change start position
                    si = rng() % N;
                    sj = rng() % N;
                    sd = rng() % 4;
                } else if (mv < 15 && num_states >= 2) {
                    // Swap two states
                    int s1 = rng() % num_states, s2 = rng() % num_states;
                    int tmp[4];
                    memcpy(tmp, aut_trans[s1], sizeof(tmp));
                    memcpy(aut_trans[s1], aut_trans[s2], sizeof(tmp));
                    memcpy(aut_trans[s2], tmp, sizeof(tmp));
                    for (int s = 0; s < num_states; s++)
                        for (int idx : {1, 3}) {
                            if (aut_trans[s][idx] == s1)
                                aut_trans[s][idx] = s2;
                            else if (aut_trans[s][idx] == s2)
                                aut_trans[s][idx] = s1;
                        }
                } else if (mv < 17) {
                    // Redirect all transitions pointing to state X to state Y
                    int x = rng() % num_states, y = rng() % num_states;
                    for (int s = 0; s < num_states; s++) {
                        if (aut_trans[s][1] == x) aut_trans[s][1] = y;
                        if (aut_trans[s][3] == x) aut_trans[s][3] = y;
                    }
                } else if (mv < 19) {
                    // Reinitialize 2-3 states
                    int cnt = 2 + rng() % 2;
                    for (int c = 0; c < cnt; c++) {
                        int s = rng() % num_states;
                        aut_trans[s][0] = rng() % 3;
                        aut_trans[s][1] = rng() % num_states;
                        aut_trans[s][2] = 1 + rng() % 2;
                        aut_trans[s][3] = rng() % num_states;
                    }
                } else if (mv < 25) {
                    // Mutate walls based on visited path! This is the new logic for Problem B.
                    // We will simulate to get the path, then place a wall randomly.
                    bool tc[N][N];
                    simulate(aut_trans, num_states, si, sj, sd, tc, hwalls_list, vwalls_list);
                    vector<pair<int, int>> path_cells;
                    for(int i = 0; i < N; i++) for(int j = 0; j < N; j++) if(tc[i][j]) path_cells.push_back({i, j});
                    
                    // Add a wall
                    if (!path_cells.empty() && rng() % 2 == 0) {
                        auto cell = path_cells[rng() % path_cells.size()];
                        int dir = rng() % 4; // Add wall on one of its 4 sides
                        int i = cell.first, j = cell.second;
                        int ni = i + DI[dir], nj = j + DJ[dir];
                        if (ni >= 0 && ni < N && nj >= 0 && nj < N) {
                            if (i == ni) vwalls_list.push_back({i, min(j, nj)});
                            else hwalls_list.push_back({min(i, ni), j});
                        }
                    } else {
                        // Remove a wall
                        if (rng() % 2 == 0 && !hwalls_list.empty()) {
                            hwalls_list.erase(hwalls_list.begin() + (rng() % hwalls_list.size()));
                        } else if (!vwalls_list.empty()) {
                            vwalls_list.erase(vwalls_list.begin() + (rng() % vwalls_list.size()));
                        }
                    }
                } else {
                    // Start position + one entry change multiple entries (2-3)
                    int cnt = 2 + rng() % 2;
                    for (int c = 0; c < cnt; c++) {
                        int s = rng() % num_states, w = rng() % 2;
                        if (w == 0) {
                            if (rng() % 2)
                                aut_trans[s][0] = rng() % 3;
                            else
                                aut_trans[s][1] = rng() % num_states;
                        } else {
                            if (rng() % 2)
                                aut_trans[s][2] = 1 + rng() % 2;
                            else
                                aut_trans[s][3] = rng() % num_states;
                        }
                    }
                }

                bool nc[N][N];
                simulate(aut_trans, num_states, si, sj, sd, nc, hwalls_list, vwalls_list);
                long long nfb = segment_uncovered_cost(nc, hwalls_list, vwalls_list);
                long long nt = num_states + nfb + (hwalls_list.size() + vwalls_list.size()) * AW;

                double delta = (double)nt - (double)total_m;
                if (delta < 0 || (rng() % 10000 < 10000 * exp(-delta / temp))) {
                    total_m = nt;
                    memcpy(cov, nc, sizeof(cov));
                    if (nt < best_total) {
                        best_total = nt;
                        memcpy(best_trans, aut_trans, sizeof(int) * 4 * num_states);
                        bsi = si;
                        bsj = sj;
                        bsd = sd;
                        best_hwalls = hwalls_list;
                        best_vwalls = vwalls_list;
                    }
                } else {
                    memcpy(aut_trans, old_trans, sizeof(int) * 4 * num_states);
                    si = osi;
                    sj = osj;
                    sd = osd;
                    hwalls_list = ohw;
                    vwalls_list = ovw;
                }

                temp *= 0.9995;
            }

            if (best_total < best_M) {
                best_M = best_total;
                // Reconstruct robots
                bool fcov[N][N];
                simulate(best_trans, num_states, bsi, bsj, bsd, fcov, best_hwalls, best_vwalls);
                best_robots.clear();
                RobotOut mr;
                mr.m = num_states;
                mr.si = bsi;
                mr.sj = bsj;
                mr.sd = DIR_CHAR[bsd];
                mr.trans.resize(num_states);
                for (int s = 0; s < num_states; s++)
                    mr.trans[s] = {best_trans[s][0], best_trans[s][1], best_trans[s][2], best_trans[s][3]};
                best_robots = {mr};
                vector<RobotOut> fb;
                segment_for_uncovered(fcov, fb, best_hwalls, best_vwalls);
                for (auto& r : fb) best_robots.push_back(r);
                
                global_best_hwalls = best_hwalls;
                global_best_vwalls = best_vwalls;
            }
        }
    }

    auto calc_existing_score = [&]() -> pair<bool, long long> {
        if (best_robots.empty()) return {false, (1LL << 62)};

        bool all_cov[N][N] = {false};
        int sum_m = 0;
        for (auto& r : best_robots) {
            if ((int)r.trans.size() != r.m || r.m <= 0) return {false, (1LL << 62)};
            int sd = 0;
            if (r.sd == 'U') sd = 0;
            else if (r.sd == 'R') sd = 1;
            else if (r.sd == 'D') sd = 2;
            else if (r.sd == 'L') sd = 3;
            else return {false, (1LL << 62)};

            static int tr[1600][4];
            for (int s = 0; s < r.m; s++) {
                tr[s][0] = r.trans[s][0];
                tr[s][1] = r.trans[s][1];
                tr[s][2] = r.trans[s][2];
                tr[s][3] = r.trans[s][3];
            }
            bool cov[N][N];
            simulate(tr, r.m, r.si, r.sj, sd, cov, global_best_hwalls, global_best_vwalls);
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    all_cov[i][j] = all_cov[i][j] || cov[i][j];
            sum_m += r.m;
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (!all_cov[i][j]) return {false, (1LL << 62)};

        int K = (int)best_robots.size();
        int W = (int)global_best_hwalls.size() + (int)global_best_vwalls.size();
        long long score = 1LL * AK * K + 1LL * AM * sum_m + 1LL * AW * W;
        return {true, score};
    };

    auto [existing_ok, existing_score] = calc_existing_score();

    FastGreedyFallbackSolver fast_fb(AK, AM, AW);
    auto [fb_ok, fb_score, fb_rules, fb_sd] = fast_fb.build_best();

    if (fb_ok && (!existing_ok || fb_score < existing_score)) {
        best_robots.clear();
        global_best_hwalls.clear();
        global_best_vwalls.clear();

        RobotOut r;
        r.m = (int)fb_rules.size();
        r.si = 0;
        r.sj = 0;
        r.sd = fb_sd;
        r.trans.resize(r.m);
        auto conv = [](char a) {
            if (a == 'F') return 0;
            if (a == 'R') return 1;
            return 2;
        };
        for (int i = 0; i < r.m; i++) {
            r.trans[i] = {conv(fb_rules[i].a0), fb_rules[i].b0, conv(fb_rules[i].a1), fb_rules[i].b1};
        }
        best_robots.push_back(r);
    }

    const char* as[] = {"F", "R", "L"};
    cout << best_robots.size() << "\n";
    for (auto& r : best_robots) {
        cout << r.m << " " << r.si << " " << r.sj << " " << r.sd << "\n";
        for (int s = 0; s < r.m; s++)
            cout << as[r.trans[s][0]] << " " << r.trans[s][1] << " "
                 << as[r.trans[s][2]] << " " << r.trans[s][3] << "\n";
    }
    
    // Output added walls
    bool thw[N][N] = {false};
    bool tvw[N][N] = {false};
    for (auto& p : global_best_hwalls) thw[p.first][p.second] = true;
    for (auto& p : global_best_vwalls) tvw[p.first][p.second] = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (tvw[i][j] && vwalls[i][j] == '0') cout << '1';
            else cout << '0';
        }
        cout << "\n";
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            if (thw[i][j] && hwalls[i][j] == '0') cout << '1';
            else cout << '0';
        }
        cout << "\n";
    }
    return 0;
}
