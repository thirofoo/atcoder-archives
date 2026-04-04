/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc063/submissions/74697837
 * Submitted at: 2026-04-05 01:30:34
 * Problem URL: https://atcoder.jp/contests/ahc063/tasks/ahc063_a
 * Result: RE
 * Execution Time: 78 ms
 */

#include <bits/stdc++.h>
using namespace std;

// ============================================================
// AHC063 - Full-path planning with strict food avoidance
//
// For each target, enumerate ALL candidate food cells of the
// right color. For each candidate, run time-aware Dijkstra
// blocking ALL food except that specific goal cell.
// Pick the candidate with shortest clean path.
// ============================================================

const int DR[4] = {-1, 1, 0, 0};
const int DC[4] = {0, 0, -1, 1};
const char DCHAR[4] = {'U', 'D', 'L', 'R'};

int N, M, C;
vector<int> desired;
vector<vector<int>> grid;

deque<pair<int,int>> body;
deque<int> colors;
string moves;
mt19937 rng(42);

bool inBounds(int r, int c) { return 0 <= r && r < N && 0 <= c && c < N; }

bool doMove(int d) {
    auto [hr, hc] = body.front();
    int nr = hr + DR[d], nc = hc + DC[d];
    moves.push_back(DCHAR[d]);
    body.push_front({nr, nc});

    if (grid[nr][nc] != 0) {
        colors.push_back(grid[nr][nc]);
        grid[nr][nc] = 0;
        return true;
    }

    body.pop_back();
    int k = (int)body.size();
    for (int h = 1; h <= k - 2; h++) {
        if (body[0] == body[h]) {
            while ((int)body.size() > h + 1) {
                auto [tr, tc] = body.back();
                grid[tr][tc] = colors.back();
                body.pop_back();
                colors.pop_back();
            }
            break;
        }
    }
    return false;
}

int recomputeProgress() {
    int lim = min((int)colors.size(), M);
    int p = 0;
    while (p < lim && colors[p] == desired[p]) p++;
    return p;
}

// ============================================================
// Time-aware Dijkstra to a SPECIFIC goal cell.
// Blocks ALL food cells except the goal itself.
// Returns direction sequence, or {} if unreachable.
// ============================================================
vector<int> findPathToCell(int gr, int gc) {
    int k = (int)body.size();
    auto [hr, hc] = body.front();
    pair<int,int> neck = k >= 2 ? body[1] : make_pair(-1, -1);

    vector<vector<int>> avail(N, vector<int>(N, 0));
    for (int i = 1; i < k; i++) {
        auto [r, c] = body[i];
        avail[r][c] = max(avail[r][c], k - i);
    }

    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
    vector<vector<int>> from_dir(N, vector<int>(N, -1));
    vector<vector<pair<int,int>>> from_cell(N, vector<pair<int,int>>(N, {-1,-1}));

    using T3 = tuple<int,int,int>;
    priority_queue<T3, vector<T3>, greater<T3>> pq;
    dist[hr][hc] = 0;
    pq.push({0, hr, hc});

    while (!pq.empty()) {
        auto [d, r, c] = pq.top(); pq.pop();
        if (d > dist[r][c]) continue;
        if (r == gr && c == gc) break;

        for (int dir = 0; dir < 4; dir++) {
            int nr = r + DR[dir], nc = c + DC[dir];
            if (!inBounds(nr, nc)) continue;
            if (r == hr && c == hc && nr == neck.first && nc == neck.second) continue;

            // Block ALL food except goal
            if (grid[nr][nc] != 0 && !(nr == gr && nc == gc)) continue;

            int t = max(d + 1, avail[nr][nc]);
            if (t < dist[nr][nc]) {
                dist[nr][nc] = t;
                from_dir[nr][nc] = dir;
                from_cell[nr][nc] = {r, c};
                pq.push({t, nr, nc});
            }
        }
    }

    if (dist[gr][gc] == INT_MAX) return {};

    vector<int> path;
    pair<int,int> cur = {gr, gc};
    while (from_dir[cur.first][cur.second] != -1) {
        path.push_back(from_dir[cur.first][cur.second]);
        cur = from_cell[cur.first][cur.second];
    }
    reverse(path.begin(), path.end());
    return path;
}

// ============================================================
// Find best path: try all candidates of targetColor,
// pick the one with shortest clean path.
// ============================================================
vector<int> findBestPath(int targetColor) {
    // Collect candidates
    vector<pair<int,int>> cands;
    auto [hr, hc] = body.front();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (grid[i][j] == targetColor)
                cands.push_back({i, j});

    // Sort by Manhattan distance (try nearest first)
    sort(cands.begin(), cands.end(), [&](auto& a, auto& b) {
        return abs(a.first-hr)+abs(a.second-hc) < abs(b.first-hr)+abs(b.second-hc);
    });

    // Try each candidate, return shortest path found
    vector<int> bestPath;
    int bestLen = INT_MAX;

    // Limit candidates to avoid TLE on dense grids
    int limit = min((int)cands.size(), 10);
    for (int ci = 0; ci < limit; ci++) {
        auto [gr, gc] = cands[ci];
        auto path = findPathToCell(gr, gc);
        if (!path.empty() && (int)path.size() < bestLen) {
            bestLen = (int)path.size();
            bestPath = path;
        }
    }

    return bestPath;
}

// ============================================================
// Wander: one step avoiding food and body
// ============================================================
int chooseWanderMove() {
    auto [hr, hc] = body.front();
    pair<int,int> neck = body.size() >= 2 ? body[1] : make_pair(-1, -1);

    vector<pair<int,int>> cands;
    for (int d = 0; d < 4; d++) {
        int nr = hr + DR[d], nc = hc + DC[d];
        if (!inBounds(nr, nc) || (nr == neck.first && nc == neck.second)) continue;
        if (grid[nr][nc] != 0) continue;
        bool bites = false;
        for (int i = 1; i < (int)body.size() - 1; i++)
            if (body[i].first == nr && body[i].second == nc) { bites = true; break; }
        if (bites) continue;

        int score = 0;
        for (int d2 = 0; d2 < 4; d2++) {
            int nnr = nr + DR[d2], nnc = nc + DC[d2];
            if (inBounds(nnr, nnc)) {
                bool isBody = false;
                for (auto& bp : body)
                    if (bp.first == nnr && bp.second == nnc) { isBody = true; break; }
                if (!isBody) score += 10;
            }
        }
        score += (int)(rng() % 5);
        cands.push_back({score, d});
    }

    if (!cands.empty()) {
        sort(cands.rbegin(), cands.rend());
        return cands[0].second;
    }

    // Fallback: allow eating but avoid bite
    for (int d = 0; d < 4; d++) {
        int nr = hr + DR[d], nc = hc + DC[d];
        if (!inBounds(nr, nc) || (nr == neck.first && nc == neck.second)) continue;
        bool bites = false;
        for (int i = 1; i < (int)body.size() - 1; i++)
            if (body[i].first == nr && body[i].second == nc) { bites = true; break; }
        if (bites) continue;
        return d;
    }

    for (int d = 0; d < 4; d++) {
        int nr = hr + DR[d], nc = hc + DC[d];
        if (inBounds(nr, nc) && !(nr == neck.first && nc == neck.second)) return d;
    }
    return -1;
}

// ============================================================
// Main
// ============================================================
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> C;
    desired.resize(M);
    for (auto& x : desired) cin >> x;
    grid.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> grid[i][j];

    body = {{4,0},{3,0},{2,0},{1,0},{0,0}};
    colors = {1,1,1,1,1};

    int p = recomputeProgress();
    int wanderBudget = 0;

    while (p < M && (int)moves.size() < 5000) {
        int targetColor = desired[p];

        // Check food exists
        bool exists = false;
        for (int i = 0; i < N && !exists; i++)
            for (int j = 0; j < N && !exists; j++)
                if (grid[i][j] == targetColor) exists = true;
        if (!exists) break;

        auto path = findBestPath(targetColor);

        if (path.empty()) {
            int wd = chooseWanderMove();
            if (wd == -1) break;
            doMove(wd);
            p = recomputeProgress();
            wanderBudget++;
            if (wanderBudget > 5000) break;
            continue;
        }

        wanderBudget = 0;

        // Execute path
        for (int i = 0; i < (int)path.size(); i++) {
            if ((int)moves.size() >= 5000) break;

            int d = path[i];
            auto [hr, hc] = body.front();
            int nr = hr + DR[d], nc = hc + DC[d];
            pair<int,int> neck = body.size() >= 2 ? body[1] : make_pair(-1, -1);

            if (!inBounds(nr, nc) || (nr == neck.first && nc == neck.second)) break;

            int szBefore = (int)body.size();
            bool ate = doMove(d);

            if (ate && i < (int)path.size() - 1) break;
            if ((int)body.size() < szBefore) break;
        }

        p = recomputeProgress();
    }

    if (p != M) return 1;
    for (char c : moves) cout << c << '\n';
    return 0;
}
