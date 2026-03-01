/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/masters2026-qual/submissions/73747125
 * Submitted at: 2026-03-01 16:53:08
 * Problem URL: https://atcoder.jp/contests/masters2026-qual/tasks/masters2026_qual_b
 * Result: AC
 * Execution Time: 113 ms
 */

#include <algorithm>
#include <array>
#include <climits>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int N = 20;
int AK, AM, AW;
string vwalls[N];
string hwalls[N - 1];

// U=0, R=1, D=2, L=3
const int DI[] = {-1, 0, 1, 0};
const int DJ[] = {0, 1, 0, -1};
const char DIR_CHAR[] = {'U', 'R', 'D', 'L'};

// 壁判定の事前計算テーブル
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

// ロボット出力用構造体
// trans[s] = {壁なし行動, 壁なし遷移先, 壁あり行動, 壁あり遷移先}
// 行動: 0=F(前進), 1=R(右回転), 2=L(左回転)
struct RobotOut {
    int m, si, sj;
    char sd;
    vector<array<int, 4>> trans;
};

// ヘルパー: ロボット出力を生成
RobotOut make_robot(const int tmpl[][4], int m, int si, int sj, int sd) {
    RobotOut r;
    r.m = m;
    r.si = si;
    r.sj = sj;
    r.sd = DIR_CHAR[sd];
    r.trans.resize(m);
    for (int s = 0; s < m; s++)
        r.trans[s] = {tmpl[s][0], tmpl[s][1], tmpl[s][2], tmpl[s][3]};
    return r;
}

long long calc_total_cost(int k, int m) {
    return 1LL * AK * max(0, k - 1) + 1LL * AM * m;
}

long long calc_fallback_cost(int k, int m) {
    return 1LL * AK * k + 1LL * AM * m;
}

// セグメント分解: 壁で区切られた行/列ごとに往復ロボットを配置
// 行分解と列分解のうちコストが小さい方を採用
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
                        r.si = start; r.sj = j; r.sd = 'D';
                        if (len == 1) { r.m = 1; r.trans = {{1, 0, 1, 0}}; }
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
                        int len = j - start + 1;
                        RobotOut r;
                        r.si = i; r.sj = start; r.sd = 'R';
                        if (len == 1) { r.m = 1; r.trans = {{1, 0, 1, 0}}; }
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
    long long rcost = calc_total_cost((int)rr.size(), rm);
    long long ccost = calc_total_cost((int)cr.size(), cm);
    if (rcost < ccost || (rcost == ccost && rm <= cm)) { robots = rr; return rm; }
    robots = cr; return cm;
}

pair<int, int> segment_uncovered_mk(const bool covered[N][N]) {
    int row_m = 0, row_k = 0;
    for (int i = 0; i < N; i++) {
        int start = 0;
        for (int j = 0; j < N; j++) {
            bool is_end = (j == N - 1) || (vwalls[i][j] == '1');
            if (is_end) {
                bool need = false;
                for (int jj = start; jj <= j; jj++)
                    if (!covered[i][jj]) { need = true; break; }
                if (need) {
                    row_m += (j - start + 1 == 1) ? 1 : 2;
                    row_k++;
                }
                start = j + 1;
            }
        }
    }

    int col_m = 0, col_k = 0;
    for (int j = 0; j < N; j++) {
        int start = 0;
        for (int i = 0; i < N; i++) {
            bool is_end = (i == N - 1) || (hwalls[i][j] == '1');
            if (is_end) {
                bool need = false;
                for (int ii = start; ii <= i; ii++)
                    if (!covered[ii][j]) { need = true; break; }
                if (need) {
                    col_m += (i - start + 1 == 1) ? 1 : 2;
                    col_k++;
                }
                start = i + 1;
            }
        }
    }

    long long row_cost = calc_fallback_cost(row_k, row_m);
    long long col_cost = calc_fallback_cost(col_k, col_m);
    if (row_cost < col_cost || (row_cost == col_cost && row_m <= col_m)) return {row_m, row_k};
    return {col_m, col_k};
}

// 未カバーマスのセグメント分解コスト (M合計のみ返す高速版)
int segment_uncovered_cost(const bool covered[N][N]) {
    auto [m, _k] = segment_uncovered_mk(covered);
    return m;
}

// 未カバーマスのセグメント分解 (ロボットも構築する版)
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
                            RobotOut r;
                            r.si = start; r.sj = j; r.sd = 'D';
                            int len = i - start + 1;
                            if (len == 1) { r.m = 1; r.trans = {{1, 0, 1, 0}}; }
                            else { r.m = 2; r.trans = {{0, 0, 1, 1}, {1, 0, 1, 0}}; }
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
                            RobotOut r;
                            r.si = i; r.sj = start; r.sd = 'R';
                            int len = j - start + 1;
                            if (len == 1) { r.m = 1; r.trans = {{1, 0, 1, 0}}; }
                            else { r.m = 2; r.trans = {{0, 0, 1, 1}, {1, 0, 1, 0}}; }
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
    long long rcost = calc_fallback_cost((int)rr.size(), rm);
    long long ccost = calc_fallback_cost((int)cr.size(), cm);
    if (rcost < ccost || (rcost == ccost && rm <= cm)) { robots = rr; return rm; }
    robots = cr; return cm;
}

// オートマトンシミュレーション
// 周期サイクルに入ったマスのみをカバーとしてカウントする
// タイムスタンプ方式で毎回のクリアを不要にしている
static int sim_vis[N * N * 4 * 1601];
static int sim_ts = 0;

int simulate(const int trans[][4], int m, int si, int sj, int sd, bool cov[N][N]) {
    int total = N * N * 4 * m;
    sim_ts++;
    int ts = sim_ts;
    int ci = si, cj = sj, cd = sd, cs = 0;

    static int route_i[N * N * 4 * 1601 + 1];
    static int route_j[N * N * 4 * 1601 + 1];
    int rlen = 0;

    for (int t = 0; t <= total; t++) {
        int key = ((ci * N + cj) * 4 + cd) * m + cs;
        if (sim_vis[key] == ts) {
            // サイクル検出: 再シミュレーションでサイクル開始位置を特定
            int ci2 = si, cj2 = sj, cd2 = sd, cs2 = 0;
            int cycle_start = 0;
            for (int k = 0; k < t; k++) {
                int k2 = ((ci2 * N + cj2) * 4 + cd2) * m + cs2;
                if (k2 == key) { cycle_start = k; break; }
                int w = wall_cache[ci2][cj2][cd2] ? 1 : 0;
                int a = trans[cs2][w * 2], ns = trans[cs2][w * 2 + 1];
                if (a == 0) { ci2 += DI[cd2]; cj2 += DJ[cd2]; }
                else if (a == 1) cd2 = (cd2 + 1) % 4;
                else cd2 = (cd2 + 3) % 4;
                cs2 = ns;
            }
            // サイクル部分のカバーマスを集計
            int cnt = 0;
            memset(cov, 0, sizeof(bool) * N * N);
            for (int k = cycle_start; k < rlen; k++)
                if (!cov[route_i[k]][route_j[k]]) {
                    cov[route_i[k]][route_j[k]] = true;
                    cnt++;
                }
            return cnt;
        }
        sim_vis[key] = ts;
        route_i[rlen] = ci;
        route_j[rlen] = cj;
        rlen++;

        int w = wall_cache[ci][cj][cd] ? 1 : 0;
        int a = trans[cs][w * 2], ns = trans[cs][w * 2 + 1];
        if (a == 0) { ci += DI[cd]; cj += DJ[cd]; }
        else if (a == 1) cd = (cd + 1) % 4;
        else cd = (cd + 3) % 4;
        cs = ns;
    }
    memset(cov, 0, sizeof(bool) * N * N);
    return 0;
}

int simulate_with_cycle_id(const int trans[][4], int m, int si, int sj, int sd, bool cov[N][N], int& cycle_id) {
    int total = N * N * 4 * m;
    sim_ts++;
    int ts = sim_ts;
    int ci = si, cj = sj, cd = sd, cs = 0;

    static int route_i[N * N * 4 * 1601 + 1];
    static int route_j[N * N * 4 * 1601 + 1];
    static int route_d[N * N * 4 * 1601 + 1];
    static int route_s[N * N * 4 * 1601 + 1];
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
                if (a == 0) { ci2 += DI[cd2]; cj2 += DJ[cd2]; }
                else if (a == 1) cd2 = (cd2 + 1) % 4;
                else cd2 = (cd2 + 3) % 4;
                cs2 = ns;
            }

            int cnt = 0;
            memset(cov, 0, sizeof(bool) * N * N);
            cycle_id = INT_MAX;
            for (int k = cycle_start; k < rlen; k++) {
                int ckey = ((route_i[k] * N + route_j[k]) * 4 + route_d[k]) * m + route_s[k];
                cycle_id = min(cycle_id, ckey);
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
        route_d[rlen] = cd;
        route_s[rlen] = cs;
        rlen++;

        int w = wall_cache[ci][cj][cd] ? 1 : 0;
        int a = trans[cs][w * 2], ns = trans[cs][w * 2 + 1];
        if (a == 0) { ci += DI[cd]; cj += DJ[cd]; }
        else if (a == 1) cd = (cd + 1) % 4;
        else cd = (cd + 3) % 4;
        cs = ns;
    }
    memset(cov, 0, sizeof(bool) * N * N);
    cycle_id = -1;
    return 0;
}

int dir_to_idx(char d) {
    if (d == 'U') return 0;
    if (d == 'R') return 1;
    if (d == 'D') return 2;
    return 3;
}

int simulate_robot(const RobotOut& r, bool cov[N][N]) {
    int m = r.m;
    int total = N * N * 4 * m;
    sim_ts++;
    int ts = sim_ts;
    int ci = r.si, cj = r.sj, cd = dir_to_idx(r.sd), cs = 0;

    static int route_i[N * N * 4 * 1601 + 1];
    static int route_j[N * N * 4 * 1601 + 1];
    int rlen = 0;

    for (int t = 0; t <= total; t++) {
        int key = ((ci * N + cj) * 4 + cd) * m + cs;
        if (sim_vis[key] == ts) {
            int ci2 = r.si, cj2 = r.sj, cd2 = dir_to_idx(r.sd), cs2 = 0;
            int cycle_start = 0;
            for (int k = 0; k < t; k++) {
                int k2 = ((ci2 * N + cj2) * 4 + cd2) * m + cs2;
                if (k2 == key) { cycle_start = k; break; }
                int w = wall_cache[ci2][cj2][cd2] ? 1 : 0;
                int a = r.trans[cs2][w * 2], ns = r.trans[cs2][w * 2 + 1];
                if (a == 0) { ci2 += DI[cd2]; cj2 += DJ[cd2]; }
                else if (a == 1) cd2 = (cd2 + 1) % 4;
                else cd2 = (cd2 + 3) % 4;
                cs2 = ns;
            }

            int cnt = 0;
            memset(cov, 0, sizeof(bool) * N * N);
            for (int k = cycle_start; k < rlen; k++)
                if (!cov[route_i[k]][route_j[k]]) {
                    cov[route_i[k]][route_j[k]] = true;
                    cnt++;
                }
            return cnt;
        }
        sim_vis[key] = ts;
        route_i[rlen] = ci;
        route_j[rlen] = cj;
        rlen++;

        int w = wall_cache[ci][cj][cd] ? 1 : 0;
        int a = r.trans[cs][w * 2], ns = r.trans[cs][w * 2 + 1];
        if (a == 0) { ci += DI[cd]; cj += DJ[cd]; }
        else if (a == 1) cd = (cd + 1) % 4;
        else cd = (cd + 3) % 4;
        cs = ns;
    }

    memset(cov, 0, sizeof(bool) * N * N);
    return 0;
}

void prune_redundant_robots(vector<RobotOut>& robots) {
    while ((int)robots.size() > 1) {
        int k = (int)robots.size();
        vector<array<unsigned long long, 7>> bits(k);
        vector<int> cnt(N * N, 0);

        for (int i = 0; i < k; i++) {
            bits[i].fill(0ULL);
            bool cov[N][N];
            simulate_robot(robots[i], cov);
            for (int r = 0; r < N; r++)
                for (int c = 0; c < N; c++)
                    if (cov[r][c]) {
                        int idx = r * N + c;
                        bits[i][idx >> 6] |= 1ULL << (idx & 63);
                        cnt[idx]++;
                    }
        }

        int remove_idx = -1;
        int remove_m = -1;
        for (int i = 0; i < k; i++) {
            bool has_unique = false;
            for (int idx = 0; idx < N * N; idx++) {
                if (((bits[i][idx >> 6] >> (idx & 63)) & 1ULL) && cnt[idx] == 1) {
                    has_unique = true;
                    break;
                }
            }
            if (!has_unique && robots[i].m > remove_m) {
                remove_m = robots[i].m;
                remove_idx = i;
            }
        }

        if (remove_idx < 0) break;
        robots.erase(robots.begin() + remove_idx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n_unused;
    cin >> n_unused >> AK >> AM >> AW;
    for (int i = 0; i < N; i++) cin >> vwalls[i];
    for (int i = 0; i < N - 1; i++) cin >> hwalls[i];
    precompute_walls();

    long long best_cost = (1LL << 62);
    vector<RobotOut> best_robots;
    {
        vector<RobotOut> seg;
        int seg_m = segment_solve(seg);
        best_cost = calc_total_cost((int)seg.size(), seg_m);
        best_robots = seg;
    }

    // ジグザグ4状態オートマトン
    // 動作: 直進→壁で折り返し→隣の列/行へ移動→逆向き直進 を繰り返す
    // 鏡像 (R↔L入替) で左右反転パターンも試す
    // 開始方向を4通り試すことで縦横の蛇行を全てカバー
    int zigzag_base[4][4] = {
        {1, 1, 1, 1},  // S0: 常にR → S1 (方向転換の起点)
        {0, 3, 2, 2},  // S1: 壁なし→F,S3 / 壁あり→L,S2 (直進 or 折り返し)
        {0, 0, 1, 2},  // S2: 壁なし→F,S0 / 壁あり→R,S2 (隣の列へ移動)
        {2, 2, 2, 1},  // S3: 壁なし→L,S2 / 壁あり→L,S1 (方向調整)
    };

    // 鏡像: R(1)↔L(2) を入れ替え
    int zigzag_mirror[4][4];
    for (int s = 0; s < 4; s++)
        for (int k = 0; k < 4; k += 2) {
            int a = zigzag_base[s][k];
            if (a == 1) a = 2; else if (a == 2) a = 1;
            zigzag_mirror[s][k] = a;
            zigzag_mirror[s][k + 1] = zigzag_base[s][k + 1];
        }

    int variants[2][4][4];
    memcpy(variants[0], zigzag_base, sizeof(zigzag_base));
    memcpy(variants[1], zigzag_mirror, sizeof(zigzag_mirror));

    // ジグザグ5状態オートマトン (縦1横2 / 横1縦2 相当)
    // 折り返し後のオフセット移動を2マスまで許す
    int zigzag_stride2_base[5][4] = {
        {1, 1, 1, 1},
        {0, 3, 2, 2},
        {0, 4, 1, 2},
        {2, 2, 2, 1},
        {0, 0, 1, 4},
    };

    int zigzag_stride2_mirror[5][4];
    for (int s = 0; s < 5; s++)
        for (int k = 0; k < 4; k += 2) {
            int a = zigzag_stride2_base[s][k];
            if (a == 1) a = 2; else if (a == 2) a = 1;
            zigzag_stride2_mirror[s][k] = a;
            zigzag_stride2_mirror[s][k + 1] = zigzag_stride2_base[s][k + 1];
        }

    auto eval_single = [&](const int trans[][4], int m) {
        for (int sd = 0; sd < 4; sd++)
            for (int si = 0; si < N; si++)
                for (int sj = 0; sj < N; sj++) {
                    bool cov[N][N];
                    int cover = simulate(trans, m, si, sj, sd, cov);
                    if (cover == N * N) {
                        long long cand_cost = calc_total_cost(1, m);
                        if (cand_cost < best_cost) {
                            best_cost = cand_cost;
                            best_robots = {make_robot(trans, m, si, sj, sd)};
                        }
                    } else {
                        auto [fb_m, fb_k] = segment_uncovered_mk(cov);
                        long long cand_cost = calc_total_cost(1 + fb_k, m + fb_m);
                        if (cand_cost < best_cost) {
                            best_cost = cand_cost;
                            best_robots = {make_robot(trans, m, si, sj, sd)};
                            bool cov2[N][N];
                            memcpy(cov2, cov, sizeof(cov));
                            vector<RobotOut> fb_r;
                            segment_for_uncovered(cov2, fb_r);
                            for (auto& fr : fb_r) best_robots.push_back(fr);
                        }
                    }
                }
    };

    // 1台で全マスカバーを試みる (M=4)
    for (int v = 0; v < 2; v++) eval_single(variants[v], 4);
    eval_single(zigzag_stride2_base, 5);
    eval_single(zigzag_stride2_mirror, 5);

    // 2台ペアで補完を試みる (M=8)
    // 1台目は全探索し、2台目は「同じ周期に入る候補」を除外して探索
    if (best_cost > calc_total_cost(2, 8)) {
        struct ZigzagCand {
            int v, sd, si, sj;
            array<unsigned long long, 7> bits;
            int cover;
            int cycle_id;
        };

        vector<ZigzagCand> cands;
        cands.reserve(2 * 4 * N * N);

        for (int v = 0; v < 2; v++)
            for (int sd = 0; sd < 4; sd++)
                for (int si = 0; si < N; si++)
                    for (int sj = 0; sj < N; sj++) {
                        bool cov[N][N];
                        int cycle_id = -1;
                        int cover = simulate_with_cycle_id(variants[v], 4, si, sj, sd, cov, cycle_id);
                        ZigzagCand cand;
                        cand.v = v;
                        cand.sd = sd;
                        cand.si = si;
                        cand.sj = sj;
                        cand.cover = cover;
                        cand.cycle_id = cycle_id;
                        cand.bits.fill(0ULL);
                        for (int i = 0; i < N; i++)
                            for (int j = 0; j < N; j++)
                                if (cov[i][j]) {
                                    int idx = i * N + j;
                                    cand.bits[idx >> 6] |= 1ULL << (idx & 63);
                                }
                        cands.push_back(cand);
                    }

        int best_i = -1, best_j = -1;
        int best_pair_cover = -1;

        for (int i = 0; i < (int)cands.size(); i++) {
            int local_best_j = -1;
            int local_best_cover = -1;
            for (int j = 0; j < (int)cands.size(); j++) {
                if (cands[i].v == cands[j].v && cands[i].cycle_id == cands[j].cycle_id) continue;

                int pc = 0;
                for (int b = 0; b < 7; b++) {
                    unsigned long long u = cands[i].bits[b] | cands[j].bits[b];
                    pc += __builtin_popcountll(u);
                }
                if (pc > local_best_cover) {
                    local_best_cover = pc;
                    local_best_j = j;
                }
            }
            if (local_best_j >= 0 && local_best_cover > best_pair_cover) {
                best_pair_cover = local_best_cover;
                best_i = i;
                best_j = local_best_j;
            }
        }

        if (best_i >= 0) {
            bool combined[N][N];
            memset(combined, 0, sizeof(combined));
            for (int idx = 0; idx < N * N; idx++) {
                int b = idx >> 6;
                int o = idx & 63;
                bool covered = ((cands[best_i].bits[b] >> o) & 1ULL) || ((cands[best_j].bits[b] >> o) & 1ULL);
                if (covered) combined[idx / N][idx % N] = true;
            }

            auto [fb_m, fb_k] = segment_uncovered_mk(combined);
            long long cand_cost = calc_total_cost(2 + fb_k, 8 + fb_m);
            if (cand_cost < best_cost) {
                best_cost = cand_cost;
                best_robots = {
                    make_robot(variants[cands[best_i].v], 4, cands[best_i].si, cands[best_i].sj, cands[best_i].sd),
                    make_robot(variants[cands[best_j].v], 4, cands[best_j].si, cands[best_j].sj, cands[best_j].sd),
                };
                vector<RobotOut> fb_r;
                segment_for_uncovered(combined, fb_r);
                for (auto& fr : fb_r) best_robots.push_back(fr);
            }
        }
    }

    prune_redundant_robots(best_robots);

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