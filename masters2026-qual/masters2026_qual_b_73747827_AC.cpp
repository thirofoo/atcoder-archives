/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/masters2026-qual/submissions/73747827
 * Submitted at: 2026-03-01 17:12:28
 * Problem URL: https://atcoder.jp/contests/masters2026-qual/tasks/masters2026_qual_b
 * Result: AC
 * Execution Time: 1912 ms
 */

#include <algorithm>
#include <array>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
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

long long solution_cost(const vector<RobotOut>& robots) {
    int sum_m = 0;
    for (const auto& r : robots) sum_m += r.m;
    return 1LL * AK * max(0, (int)robots.size() - 1) + 1LL * AM * sum_m;
}

int fb_id(int r, int c) { return r * N + c; }
pair<int, int> fb_rc(int idx) { return {idx / N, idx % N}; }

bool fb_can_move(int r, int c, int dir) {
    if (dir == 0) return (r > 0 && hwalls[r - 1][c] == '0');
    if (dir == 1) return (c + 1 < N && vwalls[r][c] == '0');
    if (dir == 2) return (r + 1 < N && hwalls[r][c] == '0');
    return (c > 0 && vwalls[r][c - 1] == '0');
}

vector<pair<int, int>> fb_neighbors(int r, int c) {
    vector<pair<int, int>> out;
    if (fb_can_move(r, c, 0)) out.push_back({0, fb_id(r - 1, c)});
    if (fb_can_move(r, c, 1)) out.push_back({1, fb_id(r, c + 1)});
    if (fb_can_move(r, c, 2)) out.push_back({2, fb_id(r + 1, c)});
    if (fb_can_move(r, c, 3)) out.push_back({3, fb_id(r, c - 1)});
    return out;
}

vector<int> fb_bfs_path(int src, int dst) {
    if (src == dst) return {src};
    int V = N * N;
    vector<int> prev(V, -1);
    queue<int> q;
    q.push(src);
    prev[src] = src;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        auto [r, c] = fb_rc(cur);
        for (auto [dir, nxt] : fb_neighbors(r, c)) {
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

vector<int> fb_bfs_path_restricted(int src, int dst, const vector<char>& allowed) {
    if (src == dst) return {src};
    if (!allowed[src] || !allowed[dst]) return {};
    int V = N * N;
    vector<int> prev(V, -1);
    queue<int> q;
    q.push(src);
    prev[src] = src;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        auto [r, c] = fb_rc(cur);
        for (auto [dir, nxt] : fb_neighbors(r, c)) {
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

bool fb_rect_cells_unassigned(const FRectBox& bx, const vector<char>& assigned) {
    for (int r = bx.r0; r <= bx.r1; r++)
        for (int c = bx.c0; c <= bx.c1; c++)
            if (assigned[fb_id(r, c)]) return false;
    return true;
}

bool fb_rect_fully_open(const FRectBox& bx) {
    for (int r = bx.r0; r <= bx.r1; r++)
        for (int c = bx.c0; c < bx.c1; c++)
            if (vwalls[r][c] != '0') return false;
    for (int r = bx.r0; r < bx.r1; r++)
        for (int c = bx.c0; c <= bx.c1; c++)
            if (hwalls[r][c] != '0') return false;
    return true;
}

vector<int> fb_build_local_rect_walk(const FRectBox& bx) {
    vector<int> order;
    for (int r = bx.r0; r <= bx.r1; r++) {
        int dr = r - bx.r0;
        if ((dr & 1) == 0) {
            for (int c = bx.c0; c <= bx.c1; c++) order.push_back(fb_id(r, c));
        } else {
            for (int c = bx.c1; c >= bx.c0; c--) order.push_back(fb_id(r, c));
        }
    }
    vector<int> walk;
    walk.push_back(order[0]);
    for (int i = 1; i < (int)order.size(); i++) walk.push_back(order[i]);
    vector<char> allowed(N * N, 0);
    for (int r = bx.r0; r <= bx.r1; r++)
        for (int c = bx.c0; c <= bx.c1; c++)
            allowed[fb_id(r, c)] = 1;
    auto back = fb_bfs_path_restricted(order.back(), order[0], allowed);
    if (back.empty()) back = fb_bfs_path(order.back(), order[0]);
    for (int i = 1; i < (int)back.size(); i++) walk.push_back(back[i]);
    return walk;
}

vector<FRectRegion> fb_build_rect_regions() {
    vector<FRectRegion> regs;
    vector<char> assigned(N * N, 0);
    int remaining = N * N;
    while (remaining > 0) {
        FRectBox best{-1, -1, -1, -1};
        int best_area = 0;
        for (int r0 = 0; r0 < N; r0++)
            for (int c0 = 0; c0 < N; c0++) {
                if (assigned[fb_id(r0, c0)]) continue;
                for (int r1 = r0; r1 < N; r1++)
                    for (int c1 = c0; c1 < N; c1++) {
                        FRectBox cand{r0, c0, r1, c1};
                        int area = (r1 - r0 + 1) * (c1 - c0 + 1);
                        if (area < best_area) continue;
                        if (!fb_rect_cells_unassigned(cand, assigned)) continue;
                        if (!fb_rect_fully_open(cand)) continue;
                        if (area > best_area) {
                            best_area = area;
                            best = cand;
                        }
                    }
            }
        if (best_area <= 0) break;
        FRectRegion reg;
        reg.entry = fb_id(best.r0, best.c0);
        reg.local_walk = fb_build_local_rect_walk(best);
        regs.push_back(move(reg));
        for (int r = best.r0; r <= best.r1; r++)
            for (int c = best.c0; c <= best.c1; c++) {
                int cell = fb_id(r, c);
                if (!assigned[cell]) {
                    assigned[cell] = 1;
                    remaining--;
                }
            }
    }
    for (int cell = 0; cell < N * N; cell++) {
        if (assigned[cell]) continue;
        FRectRegion reg;
        reg.entry = cell;
        reg.local_walk = {cell};
        regs.push_back(move(reg));
    }
    return regs;
}

vector<int> fb_build_rect_route_walk(bool& ok) {
    ok = true;
    auto regs = fb_build_rect_regions();
    if (regs.empty()) {
        ok = false;
        return {};
    }
    int root = fb_id(0, 0);
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
            auto path = fb_bfs_path(cur, regs[i].entry);
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
        auto path = fb_bfs_path(cur, regs[idx].entry);
        if (path.empty()) {
            ok = false;
            return {};
        }
        for (int i = 1; i < (int)path.size(); i++) walk.push_back(path[i]);
        for (int i = 1; i < (int)regs[idx].local_walk.size(); i++) walk.push_back(regs[idx].local_walk[i]);
        cur = regs[idx].entry;
    }
    auto back = fb_bfs_path(cur, root);
    if (back.empty()) {
        ok = false;
        return {};
    }
    for (int i = 1; i < (int)back.size(); i++) walk.push_back(back[i]);
    return walk;
}

int fb_step_dir(int a, int b) {
    auto [r, c] = fb_rc(a);
    auto [nr, nc] = fb_rc(b);
    if (nr == r - 1 && nc == c) return 0;
    if (nr == r && nc == c + 1) return 1;
    if (nr == r + 1 && nc == c) return 2;
    return 3;
}

char fb_dir_char(int d) {
    static const char dc[4] = {'U', 'R', 'D', 'L'};
    return dc[d];
}

pair<vector<FRule>, char> fb_build_rules_from_walk(const vector<int>& walk) {
    vector<int> move_dirs;
    for (int i = 0; i + 1 < (int)walk.size(); i++) move_dirs.push_back(fb_step_dir(walk[i], walk[i + 1]));
    if (move_dirs.empty()) return {{{'R', 0, 'R', 0}}, 'U'};
    char start_dir = fb_dir_char(move_dirs[0]);
    struct Segment { int l, r, dir; };
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
        else if (diff == 2) { acts.push_back('R'); acts.push_back('R'); }
        else if (diff == 3) acts.push_back('L');
        return acts;
    };
    vector<FRule> rules;
    vector<int> seg_start(segs.size(), -1);
    struct PEdge { int rule_idx; bool wall_branch; int target_seg; };
    vector<PEdge> pending;
    vector<pair<int, int>> seg_edge_cell;
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
        auto [er, ec] = fb_rc(endpoint);
        bool wall_at_end = !fb_can_move(er, ec, dir);
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
    return {rules, start_dir};
}

pair<vector<FRule>, int> fb_minimize_rules(const vector<FRule>& rules, int start_state) {
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
    vector<FRule> comp(cnum);
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
        if (remap[to0] == -1) { remap[to0] = (int)q.size(); q.push_back(to0); }
        if (remap[to1] == -1) { remap[to1] = (int)q.size(); q.push_back(to1); }
    }
    vector<FRule> out(q.size());
    for (int i = 0; i < (int)q.size(); i++) {
        int old = q[i];
        out[i] = {comp[old].a0, remap[comp[old].b0], comp[old].a1, remap[comp[old].b1]};
    }
    return {out, 0};
}

int fb_dir_id(char d) {
    if (d == 'U') return 0;
    if (d == 'R') return 1;
    if (d == 'D') return 2;
    return 3;
}

int fb_simulate_covered(const vector<FRule>& rules, char start_dir) {
    int M = (int)rules.size();
    if (M == 0) return 0;
    int r = 0, c = 0, d = fb_dir_id(start_dir), s = 0;
    vector<vector<char>> visited(N, vector<char>(N, 0));
    visited[r][c] = 1;
    int covered = 1;
    vector<char> seen(N * N * 4 * M, 0);
    auto key = [&](int rr, int cc, int dd, int ss) { return (((rr * N + cc) * 4 + dd) * M + ss); };
    static const int dr[4] = {-1, 0, 1, 0};
    static const int dc[4] = {0, 1, 0, -1};
    while (true) {
        bool wall = !fb_can_move(r, c, d);
        int nr = r + dr[d], nc = c + dc[d];
        const FRule& rule = rules[s];
        char act = wall ? rule.a1 : rule.a0;
        int ns = wall ? rule.b1 : rule.b0;
        if (act == 'F') {
            if (!wall) {
                r = nr; c = nc;
                if (!visited[r][c]) { visited[r][c] = 1; covered++; }
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

bool build_rect_fallback_robot(RobotOut& out) {
    bool ok = false;
    auto walk = fb_build_rect_route_walk(ok);
    if (!ok || walk.empty()) return false;
    auto [rules, sd] = fb_build_rules_from_walk(walk);
    auto [min_rules, min_start] = fb_minimize_rules(rules, 0);
    (void)min_start;
    if (fb_simulate_covered(min_rules, sd) != N * N) return false;

    out.m = (int)min_rules.size();
    out.si = 0;
    out.sj = 0;
    out.sd = sd;
    out.trans.resize(out.m);
    auto act_id = [&](char a) {
        if (a == 'F') return 0;
        if (a == 'R') return 1;
        return 2;
    };
    for (int i = 0; i < out.m; i++) {
        out.trans[i] = {act_id(min_rules[i].a0), min_rules[i].b0,
                        act_id(min_rules[i].a1), min_rules[i].b1};
    }
    return true;
}

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

// Fast uncovered segment count (just returns M cost, no robot construction)
int segment_uncovered_cost(const bool covered[N][N]) {
    // Try both row and col, return min
    int row_m = 0;
    for (int i = 0; i < N; i++) {
        int start = 0;
        for (int j = 0; j < N; j++) {
            bool is_end = (j == N - 1) || (vwalls[i][j] == '1');
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
                }
                start = j + 1;
            }
        }
    }
    int col_m = 0;
    for (int j = 0; j < N; j++) {
        int start = 0;
        for (int i = 0; i < N; i++) {
            bool is_end = (i == N - 1) || (hwalls[i][j] == '1');
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
                }
                start = i + 1;
            }
        }
    }
    return min(row_m, col_m);
}

int segment_for_uncovered(const bool covered[N][N], vector<RobotOut>& robots) {
    auto try_dir = [&](bool col) -> pair<int, vector<RobotOut>> {
        vector<RobotOut> result;
        int total = 0;
        bool cov[N][N];
        memcpy(cov, covered, sizeof(cov));
        if (col) {
            for (int j = 0; j < N; j++) {
                int start = 0;
                for (int i = 0; i < N; i++) {
                    bool is_end = (i == N - 1) || (hwalls[i][j] == '1');
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
                    bool is_end = (j == N - 1) || (vwalls[i][j] == '1');
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

int simulate(const int trans[][4], int m, int si, int sj, int sd, bool cov[N][N]) {
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
                int w = wall_cache[ci2][cj2][cd2] ? 1 : 0;
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

        int w = wall_cache[ci][cj][cd] ? 1 : 0;
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

    int best_M = INT_MAX;
    vector<RobotOut> best_robots;
    {
        vector<RobotOut> seg;
        best_M = segment_solve(seg);
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
                            int fb = segment_uncovered_cost(cov);
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
            int fb = segment_uncovered_cost(combined);
            int total = 8 + fb;  // 4 states x 2 robots + fallback

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
        }
    }

    // ============================================================
    // Phase 2: SA starting from zigzag base (4-6 states) to handle wall cases
    // Also try pure random SA for larger state counts
    // ============================================================
    int aut_trans[1600][4];

    // SA with zigzag seed for small state counts (4-8)
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
                if (a == 1)
                    a = 2;
                else if (a == 2)
                    a = 1;
                zigzag_mirror[s][k] = a;
                zigzag_mirror[s][k + 1] = zigzag_base[s][k + 1];
            }
        }

        for (int num_states = 4; num_states <= 8 && elapsed_ms() < 1000; num_states++) {
            for (int restart = 0; restart < 200 && elapsed_ms() < 1000; restart++) {
                // Init with zigzag base + random extra states
                int base_var = restart % 2;
                for (int s = 0; s < 4; s++) {
                    if (base_var == 0)
                        memcpy(aut_trans[s], zigzag_base[s], sizeof(int) * 4);
                    else
                        memcpy(aut_trans[s], zigzag_mirror[s], sizeof(int) * 4);
                }
                for (int s = 4; s < num_states; s++) {
                    aut_trans[s][0] = rng() % 3;
                    aut_trans[s][1] = rng() % num_states;
                    aut_trans[s][2] = 1 + rng() % 2;
                    aut_trans[s][3] = rng() % num_states;
                }
                int si = rng() % N, sj = rng() % N, sd = rng() % 4;

                bool cov[N][N];
                simulate(aut_trans, num_states, si, sj, sd, cov);
                int fb_m = segment_uncovered_cost(cov);
                int total_m = num_states + fb_m;

                int best_trans[1600][4];
                memcpy(best_trans, aut_trans, sizeof(int) * 4 * num_states);
                int bsi = si, bsj = sj, bsd = sd;
                int best_total = total_m;

                double temp = 3.0;
                for (int it = 0; it < 3000 && elapsed_ms() < 1000; it++) {
                    int old_trans[1600][4];
                    memcpy(old_trans, aut_trans, sizeof(int) * 4 * num_states);
                    int osi = si, osj = sj, osd = sd;

                    int mv = rng() % 15;
                    if (mv < 5) {
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
                        int s = rng() % num_states;
                        aut_trans[s][0] = rng() % 3;
                        aut_trans[s][1] = rng() % num_states;
                        aut_trans[s][2] = 1 + rng() % 2;
                        aut_trans[s][3] = rng() % num_states;
                    } else if (mv < 11) {
                        si = rng() % N;
                        sj = rng() % N;
                        sd = rng() % 4;
                    } else {
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
                    simulate(aut_trans, num_states, si, sj, sd, nc);
                    int nfb = segment_uncovered_cost(nc);
                    int nt = num_states + nfb;

                    double delta = nt - total_m;
                    if (delta < 0 || (rng() % 10000 < 10000 * exp(-delta / temp))) {
                        total_m = nt;
                        if (nt < best_total) {
                            best_total = nt;
                            memcpy(best_trans, aut_trans, sizeof(int) * 4 * num_states);
                            bsi = si;
                            bsj = sj;
                            bsd = sd;
                        }
                    } else {
                        memcpy(aut_trans, old_trans, sizeof(int) * 4 * num_states);
                        si = osi;
                        sj = osj;
                        sd = osd;
                    }
                    temp *= 0.999;
                }

                if (best_total < best_M) {
                    best_M = best_total;
                    bool fcov[N][N];
                    simulate(best_trans, num_states, bsi, bsj, bsd, fcov);
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
                    segment_for_uncovered(fcov, fb);
                    for (auto& r : fb) best_robots.push_back(r);
                }
            }
        }
    }

    // Phase 3: Random SA (remaining time)
    for (int num_states = 2; num_states <= 30 && elapsed_ms() < 1900; num_states++) {
        int max_restarts = (num_states <= 10) ? 100 : 30;
        for (int restart = 0; restart < max_restarts && elapsed_ms() < 1900; restart++) {
            // Random init
            for (int s = 0; s < num_states; s++) {
                aut_trans[s][0] = rng() % 3;
                aut_trans[s][1] = rng() % num_states;
                aut_trans[s][2] = 1 + rng() % 2;
                aut_trans[s][3] = rng() % num_states;
            }
            int si = rng() % N, sj = rng() % N, sd = rng() % 4;

            bool cov[N][N];
            int cover = simulate(aut_trans, num_states, si, sj, sd, cov);
            int fb_m = segment_uncovered_cost(cov);
            int total_m = num_states + fb_m;

            int best_trans[1600][4];
            memcpy(best_trans, aut_trans, sizeof(int) * 4 * num_states);
            int bsi = si, bsj = sj, bsd = sd;
            int best_total = total_m;

            double temp = 5.0;
            int iters = (num_states <= 5) ? 5000 : 2000;

            for (int it = 0; it < iters && elapsed_ms() < 1900; it++) {
                int old_trans[1600][4];
                memcpy(old_trans, aut_trans, sizeof(int) * 4 * num_states);
                int osi = si, osj = sj, osd = sd;

                int mv = rng() % 20;
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
                } else {
                    // Start position + one entry change
                    si = rng() % N;
                    sj = rng() % N;
                    sd = rng() % 4;
                    int s = rng() % num_states;
                    aut_trans[s][0] = rng() % 3;
                    aut_trans[s][1] = rng() % num_states;
                    aut_trans[s][2] = 1 + rng() % 2;
                    aut_trans[s][3] = rng() % num_states;
                }

                bool nc[N][N];
                simulate(aut_trans, num_states, si, sj, sd, nc);
                int nfb = segment_uncovered_cost(nc);
                int nt = num_states + nfb;

                double delta = nt - total_m;
                if (delta < 0 || (rng() % 10000 < 10000 * exp(-delta / temp))) {
                    total_m = nt;
                    memcpy(cov, nc, sizeof(cov));
                    if (nt < best_total) {
                        best_total = nt;
                        memcpy(best_trans, aut_trans, sizeof(int) * 4 * num_states);
                        bsi = si;
                        bsj = sj;
                        bsd = sd;
                    }
                } else {
                    memcpy(aut_trans, old_trans, sizeof(int) * 4 * num_states);
                    si = osi;
                    sj = osj;
                    sd = osd;
                }

                temp *= 0.9995;
            }

            if (best_total < best_M) {
                best_M = best_total;
                // Reconstruct robots
                bool fcov[N][N];
                simulate(best_trans, num_states, bsi, bsj, bsd, fcov);
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
                segment_for_uncovered(fcov, fb);
                for (auto& r : fb) best_robots.push_back(r);
            }
        }
    }

    {
        RobotOut one_robot;
        if (build_rect_fallback_robot(one_robot)) {
            vector<RobotOut> cand = {one_robot};
            if (solution_cost(cand) < solution_cost(best_robots)) {
                best_robots = cand;
                best_M = one_robot.m;
            }
        }
    }

    const char* as[] = {"F", "R", "L"};
    cout << best_robots.size() << "\n";
    for (auto& r : best_robots) {
        cout << r.m << " " << r.si << " " << r.sj << " " << r.sd << "\n";
        for (int s = 0; s < r.m; s++)
            cout << as[r.trans[s][0]] << " " << r.trans[s][1] << " "
                 << as[r.trans[s][2]] << " " << r.trans[s][3] << "\n";
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
