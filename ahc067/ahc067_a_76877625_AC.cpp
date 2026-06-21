/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc067/submissions/76877625
 * Submitted at: 2026-06-21 22:34:21
 * Problem URL: https://atcoder.jp/contests/ahc067/tasks/ahc067_a
 * Result: AC
 * Execution Time: 1241 ms
 */

#include <bits/stdc++.h>
using namespace std;

// AHC067 - Improved Chinese-rings / Gray-code counter.
// Improvements over the provided version:
//  1. Try many spanning trees, not only BFS tree.
//  2. Select branch stations by weighted beam DP instead of taking the first ones.
//  3. Evaluate only top estimated candidates by exact BFS.

static const int N = 20;
static const int RANDOM_TREES = 80;
static const int SNAKE_TREES = 48;
int M, K;
vector<string> C;

const int DI[4] = {1, -1, 0, 0};
const int DJ[4] = {0, 0, 1, -1};

int id(int i, int j) {
    return i * N + j;
}

bool freec(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N && C[i][j] == '.';
}

long long ekey(int a, int b) {
    if (a > b) swap(a, b);
    return 1LL * a * 1000 + b;
}

struct Door {
    int d, i, j, g;
};

struct Sw {
    int i, j, k;
};

struct Edge {
    int u, v;
};

struct Tree {
    vector<int> par;
    vector<int> depth;
    vector<int> order;
};

struct Branch {
    int station; // index on start-goal path
    int child;   // child of path[station]
    int leaf;    // deepest node in this child subtree
    int len;     // distance from station to leaf
};

struct Cand {
    vector<Door> doors;
    vector<Sw> sws;
    long long est = 0;
    int nbits = 0;
    int tree_id = -1;
    int exact = -1;
};

vector<Edge> edges;
vector<vector<int>> adjCell;

Door edgeDoor(int a, int b, int g) {
    int ai = a / N, aj = a % N;
    int bi = b / N, bj = b % N;

    if (ai == bi) {
        return {1, ai, min(aj, bj), g};
    } else {
        return {0, min(ai, bi), aj, g};
    }
}

// exact BFS over (cell, mask)
int evalT(const vector<Door>& doors, const vector<Sw>& sws) {
    static vector<int> dh, dv, sw;
    dh.assign(N * N, -1);
    dv.assign(N * N, -1);
    sw.assign(N * N, -1);

    for (auto& D : doors) {
        if (D.d == 0) dh[id(D.i, D.j)] = D.g;
        else dv[id(D.i, D.j)] = D.g;
    }

    for (auto& S : sws) {
        sw[id(S.i, S.j)] = S.k;
    }

    int MASK = 1 << K;

    static vector<unsigned char> vis;
    vis.assign((size_t)N * N * MASK, 0);

    auto isopen = [&](int g, int mask) {
        return g < 0 || (((mask >> (g / 2)) & 1) == (g & 1));
    };

    struct St {
        int i, j, mask, d;
    };

    deque<St> q;
    vis[(size_t)id(0, 0) * MASK + 0] = 1;
    q.push_back({0, 0, 0, 0});

    while (!q.empty()) {
        St s = q.front();
        q.pop_front();

        if (s.i == N - 1 && s.j == N - 1) {
            return s.d;
        }

        for (int dir = 0; dir < 4; dir++) {
            int ni = s.i + DI[dir];
            int nj = s.j + DJ[dir];

            if (!freec(ni, nj)) continue;

            int g;

            if (s.i == ni) {
                g = dv[id(s.i, min(s.j, nj))];
            } else {
                g = dh[id(min(s.i, ni), s.j)];
            }

            if (isopen(g, s.mask)) {
                size_t key = (size_t)id(ni, nj) * MASK + s.mask;

                if (!vis[key]) {
                    vis[key] = 1;
                    q.push_back({ni, nj, s.mask, s.d + 1});
                }
            }
        }

        int sk = sw[id(s.i, s.j)];

        if (sk >= 0) {
            int nm = s.mask ^ (1 << sk);
            size_t key = (size_t)id(s.i, s.j) * MASK + nm;

            if (!vis[key]) {
                vis[key] = 1;
                q.push_back({s.i, s.j, nm, s.d + 1});
            }
        }
    }

    return -1;
}

vector<int> bfsDist(int s) {
    vector<int> dist(N * N, 1e9);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : adjCell[v]) {
            if (dist[to] != (int)1e9) continue;
            dist[to] = dist[v] + 1;
            q.push(to);
        }
    }

    return dist;
}

Tree buildBfsTree(int START) {
    Tree t;
    t.par.assign(N * N, -2);
    t.depth.assign(N * N, 0);
    t.order.clear();

    deque<int> q;
    t.par[START] = -1;
    q.push_back(START);

    while (!q.empty()) {
        int v = q.front();
        q.pop_front();

        t.order.push_back(v);

        for (int to : adjCell[v]) {
            if (t.par[to] != -2) continue;

            t.par[to] = v;
            t.depth[to] = t.depth[v] + 1;
            q.push_back(to);
        }
    }

    return t;
}

Tree buildDfsTree(
    int START,
    int mode,
    uint32_t seed,
    const vector<int>& distS,
    const vector<int>& distG
) {
    Tree t;
    t.par.assign(N * N, -2);
    t.depth.assign(N * N, 0);
    t.order.clear();

    mt19937 rng(seed);

    function<void(int)> dfs = [&](int v) {
        t.order.push_back(v);

        vector<int> ns = adjCell[v];

        if (mode == 0) {
            // Far from goal first: often makes start->goal path longer.
            sort(ns.begin(), ns.end(), [&](int a, int b) {
                if (distG[a] != distG[b]) return distG[a] > distG[b];
                return a < b;
            });
        } else if (mode == 1) {
            // Far from start first.
            sort(ns.begin(), ns.end(), [&](int a, int b) {
                if (distS[a] != distS[b]) return distS[a] > distS[b];
                return a < b;
            });
        } else if (mode == 2) {
            // Toward goal first.
            sort(ns.begin(), ns.end(), [&](int a, int b) {
                if (distG[a] != distG[b]) return distG[a] < distG[b];
                return a < b;
            });
        } else {
            shuffle(ns.begin(), ns.end(), rng);
        }

        for (int to : ns) {
            if (t.par[to] != -2) continue;

            t.par[to] = v;
            t.depth[to] = t.depth[v] + 1;
            dfs(to);
        }
    };

    t.par[START] = -1;
    dfs(START);

    return t;
}

bool reachableWithBlocked(int s, int g, const vector<unsigned char>& blocked) {
    if (blocked[s] || blocked[g]) return false;

    vector<unsigned char> vis(N * N, 0);
    deque<int> q;
    vis[s] = 1;
    q.push_back(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        if (v == g) return true;

        for (int to : adjCell[v]) {
            if (vis[to] || blocked[to]) continue;
            vis[to] = 1;
            q.push_back(to);
        }
    }

    return false;
}

bool reachableAfterStep(
    int s,
    int g,
    const vector<unsigned char>& used,
    const vector<unsigned char>& reserved
) {
    if (reserved[s] || reserved[g]) return false;

    vector<unsigned char> vis(N * N, 0);
    deque<int> q;
    vis[s] = 1;
    q.push_back(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        if (v == g) return true;

        for (int to : adjCell[v]) {
            if (vis[to] || reserved[to]) continue;
            if (used[to] && to != g) continue;
            vis[to] = 1;
            q.push_back(to);
        }
    }

    return false;
}

vector<int> shortestUnusedPath(
    int s,
    int g,
    const vector<unsigned char>& used,
    const vector<unsigned char>& reserved
) {
    vector<int> par(N * N, -2);
    deque<int> q;
    par[s] = -1;
    q.push_back(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        if (v == g) break;

        for (int to : adjCell[v]) {
            if (par[to] != -2 || reserved[to]) continue;
            if (used[to] && to != g) continue;
            par[to] = v;
            q.push_back(to);
        }
    }

    vector<int> path;
    if (par[g] == -2) return path;

    for (int v = g; v != -1; v = par[v]) {
        path.push_back(v);
    }
    reverse(path.begin(), path.end());
    return path;
}

Tree buildTreeFromPath(const vector<int>& path, int START) {
    Tree t;
    t.par.assign(N * N, -2);
    t.depth.assign(N * N, 0);
    t.order.clear();

    if (path.empty() || path[0] != START) return t;

    for (int i = 0; i < (int)path.size(); i++) {
        int v = path[i];
        t.par[v] = (i == 0 ? -1 : path[i - 1]);
        t.depth[v] = i;
        t.order.push_back(v);
    }

    deque<int> q;
    for (int v : path) q.push_back(v);

    while (!q.empty()) {
        int v = q.front();
        q.pop_front();

        vector<int> ns = adjCell[v];
        sort(ns.begin(), ns.end(), [&](int a, int b) {
            int da = (int)adjCell[a].size();
            int db = (int)adjCell[b].size();
            if (da != db) return da < db;
            return a < b;
        });

        for (int to : ns) {
            if (t.par[to] != -2) continue;
            t.par[to] = v;
            t.depth[to] = t.depth[v] + 1;
            t.order.push_back(to);
            q.push_back(to);
        }
    }

    return t;
}

Tree buildSnakeTree(
    int START,
    int GOAL,
    uint32_t seed,
    int reserveTarget,
    int mode,
    const vector<int>& distS,
    const vector<int>& distG
) {
    mt19937 rng(seed);

    vector<int> cells;
    for (int v = 0; v < N * N; v++) {
        if (freec(v / N, v % N) && v != START && v != GOAL) {
            cells.push_back(v);
        }
    }

    shuffle(cells.begin(), cells.end(), rng);

    vector<unsigned char> reserved(N * N, 0);
    for (int v : cells) {
        if ((int)count(reserved.begin(), reserved.end(), 1) >= reserveTarget) break;
        reserved[v] = 1;
        if (!reachableWithBlocked(START, GOAL, reserved)) {
            reserved[v] = 0;
        }
    }

    vector<unsigned char> used(N * N, 0);
    vector<int> path;
    int cur = START;
    used[cur] = 1;
    path.push_back(cur);

    while (cur != GOAL) {
        struct Step {
            int v;
            int score;
            int jitter;
        };
        vector<Step> cand;
        bool hasNonGoal = false;

        for (int to : adjCell[cur]) {
            if (used[to] || reserved[to]) continue;
            if (to != GOAL) hasNonGoal = true;
        }

        for (int to : adjCell[cur]) {
            if (used[to] || reserved[to]) continue;
            if (to == GOAL && hasNonGoal) continue;

            used[to] = 1;
            bool ok = (to == GOAL) || reachableAfterStep(to, GOAL, used, reserved);
            used[to] = 0;
            if (!ok) continue;

            int onward = 0;
            int forced = 0;
            for (int nb : adjCell[to]) {
                if (used[nb] || reserved[nb]) continue;
                onward++;

                int deg2 = 0;
                for (int nn : adjCell[nb]) {
                    if ((!used[nn] || nn == to) && !reserved[nn]) deg2++;
                }
                if (deg2 <= 1) forced++;
            }

            int score = 0;
            if (mode == 0) {
                score = onward * 1000 - distG[to] * 25 - forced * 150;
            } else if (mode == 1) {
                score = onward * 1000 - distS[to] * 20 - forced * 150;
            } else {
                score = onward * 1000 - (distG[to] + distS[to]) * 10 - forced * 180;
            }
            if (to == GOAL) score += 1000000;

            cand.push_back({to, score, (int)(rng() & 1023)});
        }

        if (cand.empty()) {
            vector<int> tail = shortestUnusedPath(cur, GOAL, used, reserved);
            for (int i = 1; i < (int)tail.size(); i++) {
                path.push_back(tail[i]);
                used[tail[i]] = 1;
            }
            break;
        }

        sort(cand.begin(), cand.end(), [](const Step& a, const Step& b) {
            if (a.score != b.score) return a.score < b.score;
            return a.jitter < b.jitter;
        });

        int pickLim = min(3, (int)cand.size());
        int pick = (mode == 2 && pickLim > 1) ? (int)(rng() % pickLim) : 0;
        cur = cand[pick].v;
        used[cur] = 1;
        path.push_back(cur);
    }

    if (path.empty() || path.back() != GOAL) {
        return buildBfsTree(START);
    }

    return buildTreeFromPath(path, START);
}

string signatureCandidate(const vector<Door>& doors, const vector<Sw>& sws) {
    vector<tuple<int,int,int,int>> ds;

    for (auto d : doors) {
        ds.push_back({d.d, d.i, d.j, d.g});
    }

    sort(ds.begin(), ds.end());

    vector<tuple<int,int,int>> ss;

    for (auto s : sws) {
        ss.push_back({s.i, s.j, s.k});
    }

    sort(ss.begin(), ss.end());

    string sig;

    for (auto [d, i, j, g] : ds) {
        sig += to_string(d) + "," + to_string(i) + "," + to_string(j) + "," + to_string(g) + ";";
    }

    sig += "|";

    for (auto [i, j, k] : ss) {
        sig += to_string(i) + "," + to_string(j) + "," + to_string(k) + ";";
    }

    return sig;
}

void collectCandidatesFromTree(
    const Tree& t,
    int tree_id,
    vector<Cand>& allCands,
    unordered_set<string>& seen
) {
    int GOAL = id(N - 1, N - 1);

    if (t.par[GOAL] == -2) return;

    vector<vector<int>> ch(N * N);

    for (int v : t.order) {
        if (t.par[v] >= 0) {
            ch[t.par[v]].push_back(v);
        }
    }

    // deepest descendant in each subtree
    vector<int> deepNode(N * N), deepDep(N * N);

    for (int v : t.order) {
        deepNode[v] = v;
        deepDep[v] = t.depth[v];
    }

    for (int idx = (int)t.order.size() - 1; idx >= 0; idx--) {
        int v = t.order[idx];

        for (int c : ch[v]) {
            if (deepDep[c] > deepDep[v]) {
                deepDep[v] = deepDep[c];
                deepNode[v] = deepNode[c];
            }
        }
    }

    // start -> goal tree path
    vector<int> path;
    {
        int x = GOAL;

        while (x != -1) {
            path.push_back(x);
            x = t.par[x];
        }

        reverse(path.begin(), path.end());
    }

    int D = (int)path.size() - 1;

    if (D <= 1) return;

    vector<int> pathPos(N * N, -1);
    vector<int> nearestPathPos(N * N, -1);
    deque<int> pq;

    for (int i = 0; i < (int)path.size(); i++) {
        pathPos[path[i]] = i;
        nearestPathPos[path[i]] = i;
        pq.push_back(path[i]);
    }

    while (!pq.empty()) {
        int v = pq.front();
        pq.pop_front();

        for (int to : adjCell[v]) {
            if (nearestPathPos[to] != -1) continue;
            nearestPathPos[to] = nearestPathPos[v];
            pq.push_back(to);
        }
    }

    // non-tree edges
    vector<pair<int,int>> nonTree;

    for (auto e : edges) {
        bool isTree = (t.par[e.u] == e.v) || (t.par[e.v] == e.u);

        if (!isTree) {
            nonTree.push_back({e.u, e.v});
        }
    }

    sort(nonTree.begin(), nonTree.end(), [&](const pair<int,int>& a, const pair<int,int>& b) {
        int da = abs(nearestPathPos[a.first] - nearestPathPos[a.second]);
        int db = abs(nearestPathPos[b.first] - nearestPathPos[b.second]);
        int ta = abs(t.depth[a.first] - t.depth[a.second]);
        int tb = abs(t.depth[b.first] - t.depth[b.second]);
        if (da != db) return da > db;
        if (ta != tb) return ta > tb;
        return ekey(a.first, a.second) < ekey(b.first, b.second);
    });

    // Branch candidates along start-goal path.
    vector<Branch> branches;

    for (int i = 0; i + 1 < D; i++) {
        int u = path[i];
        int nxt = path[i + 1];

        vector<Branch> local;

        for (int c : ch[u]) {
            if (c == nxt) continue;

            int len = deepDep[c] - t.depth[u];

            if (len <= 0) continue;

            local.push_back({
                i,
                c,
                deepNode[c],
                len
            });
        }

        sort(local.begin(), local.end(), [](const Branch& a, const Branch& b) {
            return a.len > b.len;
        });

        // One station can only be used once, but keeping top few choices
        // helps if the deepest branch is bad due to geometry.
        int keep = min(3, (int)local.size());

        for (int j = 0; j < keep; j++) {
            branches.push_back(local[j]);
        }
    }

    if (branches.empty()) return;

    sort(branches.begin(), branches.end(), [](const Branch& a, const Branch& b) {
        if (a.station != b.station) return a.station < b.station;
        return a.len > b.len;
    });

    int nmax = min(K, (int)branches.size() + 1);
    int sealDoorType = 2 * K - 1;

    const int BEAM = 40;

    struct Partial {
        vector<int> ids; // indices into branches
        long long score = 0;
        int lastStation = -1;
    };

    int lastRt0 = 0;  // bit0 arm length of the most recent build()
    auto build = [&](int n, const vector<int>& chosen) -> pair<vector<Door>, vector<Sw>> {
        vector<Door> doors;
        vector<Sw> sws;

        if (n < 2) return {doors, sws};
        if ((int)chosen.size() != n - 1) return {doors, sws};

        vector<int> sIdx;
        vector<int> sChild;
        vector<int> sLeaf;

        for (int ci : chosen) {
            sIdx.push_back(branches[ci].station);
            sChild.push_back(branches[ci].child);
            sLeaf.push_back(branches[ci].leaf);
        }

        sIdx.push_back(D - 1);
        sChild.push_back(-1);
        sLeaf.push_back(-1);

        for (int j = 0; j + 1 < n; j++) {
            if (sIdx[j] >= sIdx[j + 1]) {
                doors.clear();
                sws.clear();
                return {doors, sws};
            }
        }

        // switch 0 placed below (deep) after gates are known.

        // Spine gates:
        // leaving station s_j requires bit_j = 0.
        set<long long> gated;
        for (int j = 0; j < n - 1; j++) {
            int u = path[sIdx[j]];
            int nxt = path[sIdx[j] + 1];
            doors.push_back(edgeDoor(u, nxt, 2 * j));
            gated.insert(ekey(u, nxt));
        }

        // Branch gates and higher switches:
        // branch from s_{b-1} is open iff bit_{b-1}=1,
        // and contains switch b.
        for (int b = 1; b < n; b++) {
            int u = path[sIdx[b - 1]];
            int c = sChild[b - 1];
            int swcell = sLeaf[b - 1];

            // At the hub (b==1) reserve the DEEPEST off-spine subtree for bit0
            // (ungated; bit0 is pressed 2^(n-1) times). switch_1 takes the next.
            if (b == 1) {
                int spineNext = path[sIdx[0] + 1];
                vector<pair<int,int>> kids;
                for (int cc : ch[u]) {
                    if (cc == spineNext) continue;
                    kids.push_back({deepDep[cc], cc});
                }
                sort(kids.rbegin(), kids.rend());
                if ((int)kids.size() >= 2) {
                    c = kids[1].second;        // gated branch for switch_1
                    swcell = deepNode[c];
                    // kids[0] (deepest) is left ungated -> becomes the bit0 arm
                }
            }

            doors.push_back(edgeDoor(u, c, 2 * (b - 1) + 1));
            gated.insert(ekey(u, c));
            sws.push_back({swcell / N, swcell % N, b});
        }

        // Goal gate: open iff bit_{n-1}=1.
        doors.push_back(edgeDoor(path[D - 1], path[D], 2 * (n - 1) + 1));
        gated.insert(ekey(path[D - 1], path[D]));

        // switch 0 (bit 0) is pressed 2^(n-1) times - the dominant term.
        // Place it at the farthest cell reachable from hub s0 using only
        // ungated (no-door) tree edges, so every press costs a long round trip.
        {
            int hub = path[sIdx[0]];
            vector<int> dist(N * N, -1);
            deque<int> q;
            dist[hub] = 0;
            q.push_back(hub);
            int far = hub;

            while (!q.empty()) {
                int v = q.front();
                q.pop_front();
                if (dist[v] > dist[far]) far = v;

                vector<int> nb = ch[v];
                if (t.par[v] >= 0) nb.push_back(t.par[v]);

                for (int u : nb) {
                    if (dist[u] != -1) continue;
                    if (gated.count(ekey(v, u))) continue;
                    dist[u] = dist[v] + 1;
                    q.push_back(u);
                }
            }

            lastRt0 = dist[far];
            sws.push_back({far / N, far % N, 0});
        }

        // Seal high-impact non-tree edges first. Full sealing is ideal, but
        // requiring it discards many n=10 candidates on cyclic maps.
        for (auto e : nonTree) {
            if ((int)doors.size() >= M) break;
            doors.push_back(edgeDoor(e.first, e.second, sealDoorType));
        }

        return {doors, sws};
    };

    for (int n = nmax; n >= 2; n--) {
        int requiredDoors = 2 * n - 1;

        if (requiredDoors > M) continue;

        vector<Partial> beam;
        beam.push_back(Partial());

        for (int pos = 0; pos < n - 1; pos++) {
            vector<Partial> nb;

            for (auto& p : beam) {
                for (int bi = 0; bi < (int)branches.size(); bi++) {
                    const Branch& br = branches[bi];

                    if (br.station <= p.lastStation) continue;

                    int remaining = (n - 1) - (pos + 1);

                    // Cheap feasibility pruning:
                    // need at least 'remaining' later stations.
                    int laterStations = 0;
                    int lastSeen = -1;

                    for (int bj = bi + 1; bj < (int)branches.size(); bj++) {
                        if (branches[bj].station > br.station && branches[bj].station != lastSeen) {
                            laterStations++;
                            lastSeen = branches[bj].station;
                        }
                    }

                    if (laterStations < remaining) continue;

                    // In Gray/Chinese-ring behavior, lower-index switches are used many times.
                    // So early selected branches get exponentially larger weights.
                    long long weight = 1LL << max(0, (n - 2 - pos));

                    // Branch length is very important.
                    long long sc = p.score;
                    sc += weight * (long long)(2 * br.len + 1) * 100;

                    // Also reward spacing along the spine a little.
                    int gap = br.station - p.lastStation;
                    sc += weight * (long long)gap * 8;

                    // bit0 (switch_0) is pressed 2^(n-1) times - the dominant
                    // term. Its round trip uses the no-door start side, which is
                    // longer when the first station s0 is deeper. Reward that.
                    if (pos == 0) {
                        sc += (1LL << (n - 1)) * 2LL * (long long)br.station * 100;
                    }

                    Partial np = p;
                    np.ids.push_back(bi);
                    np.score = sc;
                    np.lastStation = br.station;
                    nb.push_back(np);
                }
            }

            sort(nb.begin(), nb.end(), [](const Partial& a, const Partial& b) {
                return a.score > b.score;
            });

            if ((int)nb.size() > BEAM) {
                nb.resize(BEAM);
            }

            beam.swap(nb);

            if (beam.empty()) break;
        }

        for (auto& p : beam) {
            if ((int)p.ids.size() != n - 1) continue;

            auto [doors, sws] = build(n, p.ids);

            if (doors.empty()) continue;
            if ((int)doors.size() > M) continue;

            string sig = signatureCandidate(doors, sws);

            if (seen.count(sig)) continue;
            seen.insert(sig);

            long long est = p.score;

            // Actual bit0 arm length dominates T (bit0 pressed 2^(n-1) times).
            est += (1LL << (n - 1)) * 2LL * (long long)lastRt0 * 100;

            // Longer start-goal tree path usually helps.
            est += (1LL << n) * (long long)D * 20;

            // Prefer more bits, but not too blindly.
            est += 50000LL * n;

            // Slight penalty for many walls.
            est -= 100LL * (long long)doors.size();

            allCands.push_back({
                doors,
                sws,
                est,
                n,
                tree_id,
                -1
            });
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n_;
    cin >> n_ >> M >> K;

    C.resize(N);

    for (auto& r : C) cin >> r;

    int START = id(0, 0);
    int GOAL = id(N - 1, N - 1);

    adjCell.assign(N * N, {});
    edges.clear();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!freec(i, j)) continue;

            int v = id(i, j);

            for (int d = 0; d < 4; d++) {
                int ni = i + DI[d];
                int nj = j + DJ[d];

                if (!freec(ni, nj)) continue;

                int u = id(ni, nj);

                adjCell[v].push_back(u);

                if (v < u) {
                    edges.push_back({v, u});
                }
            }
        }
    }

    int baseT = evalT({}, {});

    vector<int> distS = bfsDist(START);
    vector<int> distG = bfsDist(GOAL);

    if (distS[GOAL] >= (int)1e9) {
        cout << 0 << '\n';
        cout << 0 << '\n';
        return 0;
    }

    vector<Cand> allCands;
    unordered_set<string> seen;

    int tree_id = 0;

    // 1. Original BFS tree.
    {
        Tree t = buildBfsTree(START);
        collectCandidatesFromTree(t, tree_id++, allCands, seen);
    }

    // 2. Deterministic DFS variants.
    for (int mode = 0; mode < 3; mode++) {
        Tree t = buildDfsTree(START, mode, 1234567 + mode, distS, distG);
        collectCandidatesFromTree(t, tree_id++, allCands, seen);
    }

    // 3. Random DFS variants.
    // N=20 and exact BFS is small, so this is still usually okay.
    for (int it = 0; it < RANDOM_TREES; it++) {
        uint32_t seed = 998244353u + 10007u * it;
        Tree t = buildDfsTree(START, 3, seed, distS, distG);
        collectCandidatesFromTree(t, tree_id++, allCands, seen);
    }

    // 4. Long start-goal snake variants.
    // Keep a few cells out of the snake so they become off-spine teeth for
    // higher counter bits, while the long start side can serve as bit0 arm.
    for (int it = 0; it < SNAKE_TREES; it++) {
        int reserveTarget = 4 + 4 * (it % 5);
        int mode = (it / 5) % 3;
        uint32_t seed = 42424243u + 104729u * it;
        Tree t = buildSnakeTree(START, GOAL, seed, reserveTarget, mode, distS, distG);
        collectCandidatesFromTree(t, tree_id++, allCands, seen);
    }

    if (allCands.empty()) {
        cerr << "baseT=" << baseT
             << " bestT=" << baseT
             << " candidates=0"
             << " trees=" << tree_id
             << "\n";

        cout << 0 << '\n';
        cout << 0 << '\n';
        return 0;
    }

    auto betterOldCand = [&](int ai, int bi) {
        const Cand& a = allCands[ai];
        const Cand& b = allCands[bi];
        if (a.nbits != b.nbits) return a.nbits > b.nbits;
        return a.est > b.est;
    };

    auto betterEstCand = [&](int ai, int bi) {
        const Cand& a = allCands[ai];
        const Cand& b = allCands[bi];
        if (a.est != b.est) return a.est > b.est;
        return a.nbits > b.nbits;
    };

    vector<int> oldIds;
    vector<int> n10Ids;
    oldIds.reserve(allCands.size());
    n10Ids.reserve(allCands.size());

    for (int i = 0; i < (int)allCands.size(); i++) {
        if (allCands[i].nbits < K) oldIds.push_back(i);
        else n10Ids.push_back(i);
    }

    sort(oldIds.begin(), oldIds.end(), betterOldCand);
    sort(n10Ids.begin(), n10Ids.end(), betterEstCand);

    vector<int> evalIds;
    const int N10_EVAL_LIMIT = 60;
    const int OLD_EVAL_LIMIT = 100;

    for (int i = 0; i < (int)n10Ids.size() && i < N10_EVAL_LIMIT; i++) {
        evalIds.push_back(n10Ids[i]);
    }

    for (int i = 0; i < (int)oldIds.size() && i < OLD_EVAL_LIMIT; i++) {
        evalIds.push_back(oldIds[i]);
    }

    int bestT = baseT;
    vector<Door> bestDoors;
    vector<Sw> bestSws;
    int bestN = 0;
    int bestTree = -1;

    for (int idx : evalIds) {
        int T = evalT(allCands[idx].doors, allCands[idx].sws);

        allCands[idx].exact = T;

        if (T > bestT) {
            bestT = T;
            bestDoors = allCands[idx].doors;
            bestSws = allCands[idx].sws;
            bestN = allCands[idx].nbits;
            bestTree = allCands[idx].tree_id;
        }
    }

    cerr << "baseT=" << baseT
         << " bestT=" << bestT
         << " candidates=" << allCands.size()
         << " eval=" << evalIds.size()
         << " trees=" << tree_id
         << " bestN=" << bestN
         << " bestTree=" << bestTree
         << " doors=" << bestDoors.size()
         << "\n";

    if (bestT <= baseT) {
        cout << 0 << '\n';
        cout << 0 << '\n';
        return 0;
    }

    cout << bestDoors.size() << '\n';

    for (auto& d : bestDoors) {
        cout << d.d << ' ' << d.i << ' ' << d.j << ' ' << d.g << '\n';
    }

    cout << bestSws.size() << '\n';

    for (auto& s : bestSws) {
        cout << s.i << ' ' << s.j << ' ' << s.k << '\n';
    }

    return 0;
}
