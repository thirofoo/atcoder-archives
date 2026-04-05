/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc063/submissions/74718833
 * Submitted at: 2026-04-05 23:32:18
 * Problem URL: https://atcoder.jp/contests/ahc063/tasks/ahc063_a
 * Result: AC
 * Execution Time: 1825 ms
 */

#pragma GCC target("avx2,bmi,bmi2,popcnt,sse4.2")
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;

namespace {

constexpr int MAXN = 16;
constexpr int MAXBODY = 256;
constexpr int BODY_MASK = MAXBODY - 1;
constexpr int DR[4] = {-1, 1, 0, 0};
constexpr int DC[4] = {0, 0, -1, 1};
constexpr char DCHAR[4] = {'U', 'D', 'L', 'R'};
constexpr int MAX_TURN_LIMIT = 100000;
constexpr int INITIAL_GREEDY_TURN_LIMIT = 100;
constexpr int BEAM_WIDTH = 5;
constexpr int WANDER_LEN = 2;
constexpr int SEARCH_TIME_LIMIT_MS = 1800;
constexpr int BEAM_CANDIDATE_TOP_K = 10;
constexpr int MAX_COLOR_VAL = 8;
constexpr uint64_t BODY_BASE = 11400714819323198485ULL;
constexpr uint64_t COLOR_BASE = 14029467366897019727ULL;

inline uint8_t packPos(int r, int c) { return (uint8_t)((r << 4) | c); }
inline int posR(uint8_t p) { return p >> 4; }
inline int posC(uint8_t p) { return p & 15; }

uint64_t GRID_ZOB[MAXN][MAXN][MAX_COLOR_VAL];
uint64_t POW_BODY[MAXBODY + 1];
uint64_t POW_COLOR[MAXBODY + 1];
bool HASH_READY = false;

inline uint64_t splitmix64_next(uint64_t& x) {
    x += 0x9e3779b97f4a7c15ULL;
    uint64_t z = x;
    z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9ULL;
    z = (z ^ (z >> 27)) * 0x94d049bb133111ebULL;
    return z ^ (z >> 31);
}

inline void initHashTables() {
    if (HASH_READY) return;
    HASH_READY = true;
    uint64_t seed = 0x123456789abcdef0ULL;
    for (int r = 0; r < MAXN; ++r) {
        for (int c = 0; c < MAXN; ++c) {
            for (int v = 0; v < MAX_COLOR_VAL; ++v) {
                GRID_ZOB[r][c][v] = splitmix64_next(seed);
            }
        }
    }
    POW_BODY[0] = 1;
    POW_COLOR[0] = 1;
    for (int i = 1; i <= MAXBODY; ++i) {
        POW_BODY[i] = POW_BODY[i - 1] * BODY_BASE;
        POW_COLOR[i] = POW_COLOR[i - 1] * COLOR_BASE;
    }
}

struct DirList {
    int8_t d[4];
    int8_t n = 0;
};

struct MoveResult {
    bool ok = false;
    bool ate = false;
    bool bite = false;
    int8_t eatenColor = 0;
};

struct SnakeState {
    int8_t N = 0;
    int8_t grid[MAXN][MAXN] = {};
    uint8_t bodyBuf[MAXBODY];
    int8_t colorBuf[MAXBODY];
    int16_t bodyHead = 0, bodyLen = 0;
    int16_t colorHead = 0, colorLen = 0;
    int turn = 0;
    int16_t foodCount = 0;
    uint64_t hGrid = 0, hBody = 0, hColor = 0;

    uint8_t bodyAt(int i) const { return bodyBuf[(bodyHead + i) & BODY_MASK]; }
    int8_t colorAt(int i) const { return colorBuf[(colorHead + i) & BODY_MASK]; }

    void bodyPushFront(uint8_t v) {
        bodyHead = (bodyHead - 1) & BODY_MASK;
        bodyBuf[bodyHead] = v;
        ++bodyLen;
    }
    void bodyPopBack() { --bodyLen; }
    uint8_t bodyFront() const { return bodyBuf[bodyHead]; }
    uint8_t bodyBack() const { return bodyBuf[(bodyHead + bodyLen - 1) & BODY_MASK]; }

    void colorPushBack(int8_t v) {
        colorBuf[(colorHead + colorLen) & BODY_MASK] = v;
        ++colorLen;
    }

    void recomputeSeqHashes() {
        hBody = 0;
        for (int i = 0; i < bodyLen; ++i) {
            hBody += (uint64_t)(bodyAt(i) + 1U) * POW_BODY[i];
        }
        hColor = 0;
        for (int i = 0; i < colorLen; ++i) {
            hColor += (uint64_t)((uint8_t)colorAt(i) + 1U) * POW_COLOR[i];
        }
    }

    void recomputeGridHash() {
        hGrid = 0;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < N; ++c) {
                hGrid ^= GRID_ZOB[r][c][(uint8_t)grid[r][c]];
            }
        }
    }

    void recomputeAllHashes() {
        recomputeGridHash();
        recomputeSeqHashes();
    }

    bool inBounds(int r, int c) const {
        return (unsigned)r < (unsigned)N && (unsigned)c < (unsigned)N;
    }

    int prefixLen(const int8_t* desired, int desiredLen) const {
        int lim = min((int)colorLen, desiredLen);
        if (lim == 0) return 0;
        int p = 0;
        int start = colorHead & BODY_MASK;
        if (start + lim <= MAXBODY) {
            const int8_t* cols = colorBuf + start;
#ifdef __SSE2__
            while (p + 16 <= lim) {
                __m128i a = _mm_loadu_si128((const __m128i*)(cols + p));
                __m128i b = _mm_loadu_si128((const __m128i*)(desired + p));
                __m128i cmp = _mm_cmpeq_epi8(a, b);
                int mask = _mm_movemask_epi8(cmp);
                if (mask != 0xFFFF) {
                    return p + __builtin_ctz(~mask);
                }
                p += 16;
            }
#endif
            while (p < lim && cols[p] == desired[p]) ++p;
        } else {
            while (p < lim && colorAt(p) == desired[p]) ++p;
        }
        return p;
    }

    DirList legalDirs() const {
        DirList dl;
        if (bodyLen == 0) return dl;
        uint8_t head = bodyFront();
        int hr = posR(head), hc = posC(head);
        uint8_t neck = 255;
        if (bodyLen >= 2) neck = bodyAt(1);
        for (int d = 0; d < 4; ++d) {
            int nr = hr + DR[d], nc = hc + DC[d];
            if ((unsigned)nr >= (unsigned)N || (unsigned)nc >= (unsigned)N) continue;
            if (packPos(nr, nc) == neck) continue;
            dl.d[dl.n++] = (int8_t)d;
        }
        return dl;
    }

    MoveResult apply(int d) {
        MoveResult ret;
        if (bodyLen == 0) return ret;

        uint8_t head = bodyFront();
        int hr = posR(head), hc = posC(head);
        int nr = hr + DR[d], nc = hc + DC[d];

        if ((unsigned)nr >= (unsigned)N || (unsigned)nc >= (unsigned)N) return ret;
        uint8_t npos = packPos(nr, nc);
        if (bodyLen >= 2 && npos == bodyAt(1)) return ret;

        bodyPushFront(npos);
        hBody = (uint64_t)(npos + 1U) + hBody * BODY_BASE;

        if (grid[nr][nc] != 0) {
            ret.ate = true;
            ret.eatenColor = grid[nr][nc];
            int oldColorLen = colorLen;
            int8_t prev = grid[nr][nc];
            hGrid ^= GRID_ZOB[nr][nc][(uint8_t)prev];
            grid[nr][nc] = 0;
            hGrid ^= GRID_ZOB[nr][nc][0];
            colorPushBack(ret.eatenColor);
            hColor += (uint64_t)((uint8_t)ret.eatenColor + 1U) * POW_COLOR[oldColorLen];
            --foodCount;
        } else {
            uint8_t tailPos = bodyAt(bodyLen - 1);
            hBody -= (uint64_t)(tailPos + 1U) * POW_BODY[bodyLen - 1];
            bodyPopBack();
        }

        int k = bodyLen;
        for (int h = 1; h <= k - 2; ++h) {
            if (bodyAt(h) == npos) {
                for (int p = h + 1; p < k; ++p) {
                    uint8_t bp = bodyAt(p);
                    int rr = posR(bp), cc = posC(bp);
                    int8_t oldv = grid[rr][cc];
                    int8_t newv = colorAt(p);
                    if (oldv != newv) {
                        hGrid ^= GRID_ZOB[rr][cc][(uint8_t)oldv];
                        grid[rr][cc] = newv;
                        hGrid ^= GRID_ZOB[rr][cc][(uint8_t)newv];
                    } else {
                        grid[rr][cc] = newv;
                    }
                    ++foodCount;
                }
                bodyLen = (int16_t)(h + 1);
                colorLen = (int16_t)(h + 1);
                recomputeSeqHashes();
                ret.bite = true;
                break;
            }
        }

        ++turn;
        ret.ok = true;
        return ret;
    }
};

struct CutCandidate {
    int8_t seq[3];
    int8_t seqLen = 0;
    SnakeState after;
    int biteTurn = 0;
    int prefixAfter = 0;
    int anchorLen = 0;
    bool adjacentToPrefix = false;
    int directPathLen = INT_MAX;
    int loosePathLen = INT_MAX;
};

struct Solver {
    int N = 0, M = 0, C = 0;
    vector<int8_t> desired;

    SnakeState state;
    string moves;
    mt19937 rng;
    deque<int> recoveryMoves;
    int wanderBudget = 0;
    int activeTurnLimit = MAX_TURN_LIMIT;

    struct BeamNode {
        SnakeState st;
        string path;  // move ids (0..3)
        int curPrefix = 0;
        int maxPrefix = 0;
        long long eval = (long long)4e18;
    };

    vector<vector<BeamNode>> beamLayersPool;
    vector<unordered_map<uint64_t, int>> beamIndexPool;
    vector<int> beamLayerGen;
    int beamGen = 1;
    mutable unordered_map<uint64_t, vector<vector<int>>> strictPathsCache;
    mutable unordered_map<uint64_t, vector<int>> orderedPathCache;
    static constexpr size_t PATH_CACHE_LIMIT = 1u << 15;

    Solver() {
        initHashTables();
        uint64_t seed = (uint64_t)chrono::steady_clock::now().time_since_epoch().count();
        seed ^= (uint64_t)(uintptr_t)this;
        rng.seed((uint32_t)(seed ^ (seed >> 32)));
    }

    void readInput() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> N >> M >> C;
        desired.resize(M);
        for (int i = 0; i < M; ++i) {
            int x; cin >> x;
            desired[i] = (int8_t)x;
        }

        state.N = (int8_t)N;
        memset(state.grid, 0, sizeof(state.grid));
        state.foodCount = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                int x; cin >> x;
                state.grid[i][j] = (int8_t)x;
                if (x != 0) ++state.foodCount;
            }
        }

        state.bodyHead = 0;
        state.bodyLen = 5;
        state.bodyBuf[0] = packPos(4, 0);
        state.bodyBuf[1] = packPos(3, 0);
        state.bodyBuf[2] = packPos(2, 0);
        state.bodyBuf[3] = packPos(1, 0);
        state.bodyBuf[4] = packPos(0, 0);

        state.colorHead = 0;
        state.colorLen = 5;
        for (int i = 0; i < 5; ++i) state.colorBuf[i] = 1;

        state.turn = 0;
        state.recomputeAllHashes();
        moves.clear();
        recoveryMoves.clear();
        wanderBudget = 0;
        activeTurnLimit = MAX_TURN_LIMIT;
        strictPathsCache.clear();
        orderedPathCache.clear();
    }

    int dirBetween(uint8_t a, uint8_t b) const {
        int ar = posR(a), ac = posC(a), br = posR(b), bc = posC(b);
        for (int d = 0; d < 4; ++d) {
            if (ar + DR[d] == br && ac + DC[d] == bc) return d;
        }
        return -1;
    }

    vector<int> buildRecoveryPathByOldBody(
        const SnakeState& beforeBite,
        const SnakeState& afterBite,
        int prefixBefore
    ) const {
        int lenAfter = afterBite.bodyLen;
        if (prefixBefore <= lenAfter) return {};
        if (beforeBite.bodyLen == 0 || afterBite.bodyLen == 0) return {};

        int startIdx = lenAfter - 1;
        int endIdx = prefixBefore - 2;
        if (startIdx < 0 || endIdx < startIdx || endIdx >= beforeBite.bodyLen) return {};

        vector<int> plan;
        uint8_t cur = afterBite.bodyFront();
        for (int idx = startIdx; idx <= endIdx; ++idx) {
            uint8_t nxt = beforeBite.bodyAt(idx);
            int d = dirBetween(cur, nxt);
            if (d < 0) return {};
            plan.push_back(d);
            cur = nxt;
        }
        return plan;
    }

    bool executeDir(int d) {
        SnakeState before = state;
        int prefixBefore = before.prefixLen(desired.data(), M);
        MoveResult ret = state.apply(d);
        if (!ret.ok) return false;
        moves.push_back(DCHAR[d]);
        if (ret.bite) {
            auto recovery = buildRecoveryPathByOldBody(before, state, prefixBefore);
            recoveryMoves.clear();
            for (int mv : recovery) recoveryMoves.push_back(mv);
        }
        return true;
    }

    int manhattanToNearestTarget(const SnakeState& st, int targetColor) const {
        if (st.bodyLen == 0) return INT_MAX;
        uint8_t head = st.bodyFront();
        int hr = posR(head), hc = posC(head);
        int best = INT_MAX;
        for (int i = 0; i < st.N; ++i) {
            for (int j = 0; j < st.N; ++j) {
                if (st.grid[i][j] == targetColor) {
                    best = min(best, abs(i - hr) + abs(j - hc));
                }
            }
        }
        return best;
    }

    uint64_t stateShapeKey(const SnakeState& st) const {
        uint64_t h = 1469598103934665603ULL;
        auto mix = [&](uint64_t x) { h ^= x + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2); };
        mix(st.hGrid);
        mix(st.hBody);
        mix(st.hColor);
        mix((uint64_t)st.bodyLen);
        mix((uint64_t)st.colorLen);
        return h;
    }

    vector<vector<int>> findDynamicStrictPathsToTarget(
        const SnakeState& st,
        int targetColor,
        int topK
    ) const {
        if (st.bodyLen == 0) return {};
        topK = max(1, topK);

        uint64_t cacheKey = stateShapeKey(st);
        cacheKey ^= (uint64_t)(uint8_t)targetColor * 0x9e3779b97f4a7c15ULL;
        cacheKey ^= (uint64_t)(uint8_t)topK * 0xbf58476d1ce4e5b9ULL;
        if (auto it = strictPathsCache.find(cacheKey); it != strictPathsCache.end()) {
            return it->second;
        }

        const int n = st.N;
        const int INF = 0x3f3f3f3f;

        int release[MAXN][MAXN] = {};
        for (int i = 1; i < st.bodyLen; ++i) {
            uint8_t bp = st.bodyAt(i);
            int r = posR(bp), c = posC(bp);
            release[r][c] = max(release[r][c], (int)st.bodyLen - i);
        }

        int dist[MAXN][MAXN];
        uint8_t parentPacked[MAXN][MAXN];
        int8_t pdir[MAXN][MAXN];
        memset(dist, 0x3f, sizeof(dist));
        memset(pdir, -1, sizeof(pdir));

        uint8_t head = st.bodyFront();
        int hr = posR(head), hc = posC(head);
        uint8_t neck = 255;
        if (st.bodyLen >= 2) neck = st.bodyAt(1);

        // Bucket queue — all edge weights are 1, max dist = N*N
        constexpr int MAX_DIST = MAXN * MAXN + 1;
        pair<int8_t,int8_t> buckets_arr[MAX_DIST][MAXN * MAXN];
        int bucket_sz[MAX_DIST] = {};
        dist[hr][hc] = 0;
        buckets_arr[0][0] = {(int8_t)hr, (int8_t)hc};
        bucket_sz[0] = 1;

        for (int t = 0; t < MAX_DIST; ++t) {
            for (int bi = 0; bi < bucket_sz[t]; ++bi) {
                auto [r, c] = buckets_arr[t][bi];
                if (dist[r][c] != t) continue;
                for (int d = 0; d < 4; ++d) {
                    int nr = r + DR[d], nc = c + DC[d];
                    if ((unsigned)nr >= (unsigned)n || (unsigned)nc >= (unsigned)n) continue;
                    if (r == hr && c == hc && packPos(nr, nc) == neck) continue;
                    int food = st.grid[nr][nc];
                    if (food != 0 && food != targetColor) continue;
                    int nt = t + 1;
                    if (nt < release[nr][nc]) continue;
                    if (nt < dist[nr][nc]) {
                        dist[nr][nc] = nt;
                        parentPacked[nr][nc] = packPos(r, c);
                        pdir[nr][nc] = (int8_t)d;
                        if (nt < MAX_DIST) {
                            buckets_arr[nt][bucket_sz[nt]++] = {(int8_t)nr, (int8_t)nc};
                        }
                    }
                }
            }
        }

        struct Goal { int dist, r, c; };
        vector<Goal> goals;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == hr && j == hc) continue;
                if (st.grid[i][j] != targetColor) continue;
                if (dist[i][j] >= INF) continue;
                goals.push_back({dist[i][j], i, j});
            }
        }
        sort(goals.begin(), goals.end(), [](const Goal& a, const Goal& b) { return a.dist < b.dist; });
        if (goals.empty()) return {};

        int take = min(topK, (int)goals.size());
        vector<vector<int>> out;
        out.reserve(take);
        for (int gi = 0; gi < take; ++gi) {
            vector<int> path;
            int cr = goals[gi].r, cc = goals[gi].c;
            while (!(cr == hr && cc == hc)) {
                path.push_back(pdir[cr][cc]);
                uint8_t pp = parentPacked[cr][cc];
                cr = posR(pp); cc = posC(pp);
            }
            reverse(path.begin(), path.end());
            if (!path.empty()) out.push_back(move(path));
        }
        if (strictPathsCache.size() > PATH_CACHE_LIMIT) strictPathsCache.clear();
        strictPathsCache.emplace(cacheKey, out);
        return out;
    }

    vector<int> findDynamicStrictPathToTargetWithDirOrder(
        const SnakeState& st,
        int targetColor,
        const array<int, 4>& dirOrder
    ) const {
        if (st.bodyLen == 0) return {};
        uint64_t ord = (uint64_t)dirOrder[0] |
                       ((uint64_t)dirOrder[1] << 3) |
                       ((uint64_t)dirOrder[2] << 6) |
                       ((uint64_t)dirOrder[3] << 9);
        uint64_t cacheKey = stateShapeKey(st);
        cacheKey ^= (uint64_t)(uint8_t)targetColor * 0x94d049bb133111ebULL;
        cacheKey ^= ord * 0xbf58476d1ce4e5b9ULL;
        if (auto it = orderedPathCache.find(cacheKey); it != orderedPathCache.end()) {
            return it->second;
        }

        const int n = st.N;
        const int INF = 0x3f3f3f3f;

        int release[MAXN][MAXN] = {};
        for (int i = 1; i < st.bodyLen; ++i) {
            uint8_t bp = st.bodyAt(i);
            release[posR(bp)][posC(bp)] = max(release[posR(bp)][posC(bp)], (int)st.bodyLen - i);
        }

        int dist[MAXN][MAXN];
        uint8_t parentPacked[MAXN][MAXN];
        int8_t pdir[MAXN][MAXN];
        memset(dist, 0x3f, sizeof(dist));
        memset(pdir, -1, sizeof(pdir));

        uint8_t head = st.bodyFront();
        int hr = posR(head), hc = posC(head);
        uint8_t neck = 255;
        if (st.bodyLen >= 2) neck = st.bodyAt(1);

        using Node = tuple<int, int, int>;
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        dist[hr][hc] = 0;
        pq.push({0, hr, hc});

        pair<int, int> goal = {-1, -1};
        while (!pq.empty()) {
            auto [t, r, c] = pq.top(); pq.pop();
            if (t != dist[r][c]) continue;
            if (!(r == hr && c == hc) && st.grid[r][c] == targetColor) {
                goal = {r, c}; break;
            }
            for (int idx = 0; idx < 4; ++idx) {
                int d = dirOrder[idx];
                int nr = r + DR[d], nc = c + DC[d];
                if ((unsigned)nr >= (unsigned)n || (unsigned)nc >= (unsigned)n) continue;
                if (r == hr && c == hc && packPos(nr, nc) == neck) continue;
                int food = st.grid[nr][nc];
                if (food != 0 && food != targetColor) continue;
                int nt = t + 1;
                if (nt < release[nr][nc]) continue;
                if (nt < dist[nr][nc]) {
                    dist[nr][nc] = nt;
                    parentPacked[nr][nc] = packPos(r, c);
                    pdir[nr][nc] = (int8_t)d;
                    pq.push({nt, nr, nc});
                }
            }
        }

        if (goal.first == -1) {
            if (orderedPathCache.size() > PATH_CACHE_LIMIT) orderedPathCache.clear();
            orderedPathCache.emplace(cacheKey, vector<int>{});
            return {};
        }
        vector<int> path;
        int cr = goal.first, cc = goal.second;
        while (!(cr == hr && cc == hc)) {
            path.push_back(pdir[cr][cc]);
            uint8_t pp = parentPacked[cr][cc];
            cr = posR(pp); cc = posC(pp);
        }
        reverse(path.begin(), path.end());
        if (orderedPathCache.size() > PATH_CACHE_LIMIT) orderedPathCache.clear();
        orderedPathCache.emplace(cacheKey, path);
        return path;
    }

    vector<int> findDynamicStrictPathToTarget(const SnakeState& st, int targetColor) const {
        auto paths = findDynamicStrictPathsToTarget(st, targetColor, 1);
        if (paths.empty()) return {};
        return paths[0];
    }

    vector<int> findDynamicStrictPathToTail(const SnakeState& st, int targetColor) const {
        if (st.bodyLen == 0) return {};
        const int n = st.N;
        const int INF = 0x3f3f3f3f;

        int release[MAXN][MAXN] = {};
        for (int i = 1; i < st.bodyLen; ++i) {
            uint8_t bp = st.bodyAt(i);
            release[posR(bp)][posC(bp)] = max(release[posR(bp)][posC(bp)], (int)st.bodyLen - i);
        }

        uint8_t tail = st.bodyBack();
        int gr = posR(tail), gc = posC(tail);

        int dist[MAXN][MAXN];
        uint8_t parentPacked[MAXN][MAXN];
        int8_t pdir[MAXN][MAXN];
        memset(dist, 0x3f, sizeof(dist));
        memset(pdir, -1, sizeof(pdir));

        uint8_t head = st.bodyFront();
        int hr = posR(head), hc = posC(head);
        uint8_t neck = 255;
        if (st.bodyLen >= 2) neck = st.bodyAt(1);

        using Node = tuple<int, int, int>;
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        dist[hr][hc] = 0;
        pq.push({0, hr, hc});

        while (!pq.empty()) {
            auto [t, r, c] = pq.top(); pq.pop();
            if (t != dist[r][c]) continue;
            if (!(r == hr && c == hc) && r == gr && c == gc) break;
            for (int d = 0; d < 4; ++d) {
                int nr = r + DR[d], nc = c + DC[d];
                if ((unsigned)nr >= (unsigned)n || (unsigned)nc >= (unsigned)n) continue;
                if (r == hr && c == hc && packPos(nr, nc) == neck) continue;
                int food = st.grid[nr][nc];
                if (food != 0 && food != targetColor) continue;
                int nt = t + 1;
                if (nt < release[nr][nc]) continue;
                if (nt < dist[nr][nc]) {
                    dist[nr][nc] = nt;
                    parentPacked[nr][nc] = packPos(r, c);
                    pdir[nr][nc] = (int8_t)d;
                    pq.push({nt, nr, nc});
                }
            }
        }

        if (dist[gr][gc] >= INF) return {};
        vector<int> path;
        int cr = gr, cc = gc;
        while (!(cr == hr && cc == hc)) {
            path.push_back(pdir[cr][cc]);
            uint8_t pp = parentPacked[cr][cc];
            cr = posR(pp); cc = posC(pp);
        }
        reverse(path.begin(), path.end());
        return path;
    }

    vector<int> findPenalizedPathToTarget(const SnakeState& st, int targetColor, int foodPenalty) const {
        if (st.bodyLen == 0) return {};
        const int n = st.N;
        const int INF = 0x3f3f3f3f;

        int release[MAXN][MAXN] = {};
        for (int i = 1; i < st.bodyLen; ++i) {
            uint8_t bp = st.bodyAt(i);
            release[posR(bp)][posC(bp)] = max(release[posR(bp)][posC(bp)], (int)st.bodyLen - i);
        }

        int dist[MAXN][MAXN];
        uint8_t parentPacked[MAXN][MAXN];
        int8_t pdir[MAXN][MAXN];
        memset(dist, 0x3f, sizeof(dist));
        memset(pdir, -1, sizeof(pdir));

        uint8_t head = st.bodyFront();
        int hr = posR(head), hc = posC(head);
        uint8_t neck = 255;
        if (st.bodyLen >= 2) neck = st.bodyAt(1);

        using Node = tuple<int, int, int>;
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        dist[hr][hc] = 0;
        pq.push({0, hr, hc});

        pair<int, int> goal = {-1, -1};
        while (!pq.empty()) {
            auto [t, r, c] = pq.top(); pq.pop();
            if (t != dist[r][c]) continue;
            if (!(r == hr && c == hc) && st.grid[r][c] == targetColor) {
                goal = {r, c}; break;
            }
            for (int d = 0; d < 4; ++d) {
                int nr = r + DR[d], nc = c + DC[d];
                if ((unsigned)nr >= (unsigned)n || (unsigned)nc >= (unsigned)n) continue;
                if (r == hr && c == hc && packPos(nr, nc) == neck) continue;
                int nt = t + 1;
                if (nt < release[nr][nc]) continue;
                int food = st.grid[nr][nc];
                int ncost = nt;
                if (food != 0 && food != targetColor) ncost += foodPenalty;
                if (ncost < dist[nr][nc]) {
                    dist[nr][nc] = ncost;
                    parentPacked[nr][nc] = packPos(r, c);
                    pdir[nr][nc] = (int8_t)d;
                    pq.push({ncost, nr, nc});
                }
            }
        }

        if (goal.first == -1) return {};
        vector<int> path;
        int cr = goal.first, cc = goal.second;
        while (!(cr == hr && cc == hc)) {
            path.push_back(pdir[cr][cc]);
            uint8_t pp = parentPacked[cr][cc];
            cr = posR(pp); cc = posC(pp);
        }
        reverse(path.begin(), path.end());
        return path;
    }

    vector<int> bfsToTargetColor(
        const SnakeState& st,
        int targetColor,
        bool avoidBody,
        bool avoidNonTargetFood
    ) const {
        if (st.bodyLen == 0) return {};
        const int n = st.N;

        int dist[MAXN][MAXN];
        uint8_t parentPacked[MAXN][MAXN];
        int8_t pdir[MAXN][MAXN];
        char blocked[MAXN][MAXN] = {};
        memset(dist, -1, sizeof(dist));
        memset(pdir, -1, sizeof(pdir));

        if (avoidBody) {
            for (int i = 1; i < st.bodyLen; ++i) {
                uint8_t bp = st.bodyAt(i);
                blocked[posR(bp)][posC(bp)] = 1;
            }
        }

        uint8_t head = st.bodyFront();
        int hr = posR(head), hc = posC(head);
        uint8_t neck = 255;
        if (st.bodyLen >= 2) neck = st.bodyAt(1);

        pair<int8_t,int8_t> q[MAXN * MAXN];
        int qh = 0, qt = 0;
        q[qt++] = {(int8_t)hr, (int8_t)hc};
        dist[hr][hc] = 0;

        pair<int, int> goal = {-1, -1};
        while (qh < qt) {
            auto [r, c] = q[qh++];
            if (!(r == hr && c == hc) && st.grid[r][c] == targetColor) {
                goal = {r, c}; break;
            }
            for (int d = 0; d < 4; ++d) {
                int nr = r + DR[d], nc = c + DC[d];
                if ((unsigned)nr >= (unsigned)n || (unsigned)nc >= (unsigned)n) continue;
                if (dist[nr][nc] != -1) continue;
                if (r == hr && c == hc && packPos(nr, nc) == neck) continue;
                if (avoidBody && blocked[nr][nc]) continue;
                int food = st.grid[nr][nc];
                if (avoidNonTargetFood && food != 0 && food != targetColor) continue;
                dist[nr][nc] = dist[r][c] + 1;
                parentPacked[nr][nc] = packPos(r, c);
                pdir[nr][nc] = (int8_t)d;
                q[qt++] = {(int8_t)nr, (int8_t)nc};
            }
        }

        if (goal.first == -1) return {};
        vector<int> path;
        int cr = goal.first, cc = goal.second;
        while (!(cr == hr && cc == hc)) {
            path.push_back(pdir[cr][cc]);
            uint8_t pp = parentPacked[cr][cc];
            cr = posR(pp); cc = posC(pp);
        }
        reverse(path.begin(), path.end());
        return path;
    }

    bool isTargetAdjacentToPrefixSegment(const SnakeState& st, int anchorLen, int targetColor) const {
        if (anchorLen <= 0 || anchorLen > st.bodyLen) return false;
        uint8_t bp = st.bodyAt(anchorLen - 1);
        int r = posR(bp), c = posC(bp);
        for (int d = 0; d < 4; ++d) {
            int nr = r + DR[d], nc = c + DC[d];
            if (st.inBounds(nr, nc) && st.grid[nr][nc] == targetColor) return true;
        }
        return false;
    }

    void enumerateCutCandidatesDFS(
        const SnakeState& cur,
        int depth, int maxDepth,
        int baseL, int targetColor,
        int8_t seq[3], int seqLen,
        vector<CutCandidate>& out
    ) const {
        if (depth >= maxDepth) return;
        DirList dirs = cur.legalDirs();
        for (int di = 0; di < dirs.n; ++di) {
            int d = dirs.d[di];
            SnakeState nxt = cur;
            MoveResult ret = nxt.apply(d);
            if (!ret.ok) continue;

            seq[seqLen] = (int8_t)d;
            int newLen = seqLen + 1;

            if (ret.bite) {
                int pref = nxt.prefixLen(desired.data(), M);
                int lenAfter = nxt.bodyLen;
                if (lenAfter >= 3 && (lenAfter % 2 == 1)) {
                    int anchorLen = min(baseL, lenAfter);
                    CutCandidate cand;
                    memcpy(cand.seq, seq, newLen);
                    cand.seqLen = (int8_t)newLen;
                    cand.after = nxt;
                    cand.biteTurn = newLen;
                    cand.prefixAfter = pref;
                    cand.anchorLen = anchorLen;
                    cand.adjacentToPrefix = isTargetAdjacentToPrefixSegment(nxt, anchorLen, targetColor);
                    auto dp = findDynamicStrictPathToTarget(nxt, targetColor);
                    auto lp = bfsToTargetColor(nxt, targetColor, false, true);
                    cand.directPathLen = dp.empty() ? INT_MAX : (int)dp.size();
                    cand.loosePathLen = lp.empty() ? INT_MAX : (int)lp.size();
                    out.push_back(move(cand));
                }
            } else {
                enumerateCutCandidatesDFS(nxt, depth + 1, maxDepth, baseL, targetColor, seq, newLen, out);
            }
        }
    }

    vector<CutCandidate> enumerateCutCandidates(
        const SnakeState& src, int baseL, int targetColor, int maxDepth = 3
    ) const {
        vector<CutCandidate> out;
        int8_t seq[3];
        enumerateCutCandidatesDFS(src, 0, maxDepth, baseL, targetColor, seq, 0, out);
        return out;
    }

    optional<CutCandidate> chooseBestCutCandidate(const SnakeState& src, int baseL, int targetColor) {
        auto cands = enumerateCutCandidates(src, baseL, targetColor, 3);
        if (cands.empty()) return nullopt;

        int curLen = src.bodyLen;
        int floorHalf = max(1, curLen / 2);
        int halfOdd = floorHalf;
        if (halfOdd % 2 == 0) --halfOdd;
        halfOdd = max(3, halfOdd);

        auto cutLenCost = [&](const CutCandidate& c) {
            int la = c.after.bodyLen;
            int cost = abs(la - halfOdd) * 100;
            if (la > floorHalf) cost += (la - floorHalf) * 300;
            return cost;
        };

        int bestLC = INT_MAX;
        for (auto& c : cands) bestLC = min(bestLC, cutLenCost(c));

        auto eval = [&](const CutCandidate& c) -> long long {
            if (!(c.adjacentToPrefix || c.directPathLen != INT_MAX || c.loosePathLen != INT_MAX)) return (long long)4e18;
            long long s = 60'000LL * c.biteTurn;
            if (c.adjacentToPrefix) s -= 120'000LL;
            s += (c.directPathLen == INT_MAX ? 20'000 : c.directPathLen * 220);
            s += (c.loosePathLen == INT_MAX ? 10'000 : c.loosePathLen * 30);
            s -= 300LL * c.prefixAfter;
            return s;
        };

        auto pick = [&](bool reqAdj) -> int {
            long long bs = (long long)4e18; int bi = -1;
            for (int i = 0; i < (int)cands.size(); ++i) {
                if (cutLenCost(cands[i]) != bestLC) continue;
                if (reqAdj && !cands[i].adjacentToPrefix) continue;
                long long s = eval(cands[i]);
                if (s < bs) { bs = s; bi = i; }
            }
            return bi;
        };

        int bi = pick(true);
        if (bi == -1) bi = pick(false);
        if (bi == -1) return nullopt;
        return cands[bi];
    }

    optional<CutCandidate> chooseRandomHalfCutCandidate(const SnakeState& src, int baseL, int targetColor) {
        auto cands = enumerateCutCandidates(src, baseL, targetColor, 3);
        if (cands.empty()) return nullopt;
        int curLen = src.bodyLen, floorHalf = max(1, curLen / 2);
        int halfOdd = floorHalf; if (halfOdd % 2 == 0) --halfOdd; halfOdd = max(3, halfOdd);
        auto clc = [&](const CutCandidate& c) {
            int la = c.after.bodyLen;
            int cost = abs(la - halfOdd) * 100;
            if (la > floorHalf) cost += (la - floorHalf) * 300;
            return cost;
        };
        int bestLC = INT_MAX;
        for (auto& c : cands) bestLC = min(bestLC, clc(c));
        vector<int> idxs;
        for (int i = 0; i < (int)cands.size(); ++i) if (clc(cands[i]) == bestLC) idxs.push_back(i);
        if (idxs.empty()) return nullopt;
        return cands[idxs[uniform_int_distribution<int>(0, (int)idxs.size() - 1)(rng)]];
    }

    vector<CutCandidate> chooseTopCutCandidatesForBeam(
        const SnakeState& src, int baseL, int targetColor, int topK
    ) const {
        topK = max(1, topK);
        auto cands = enumerateCutCandidates(src, baseL, targetColor, 3);
        if (cands.empty()) return {};
        int wrongSuffix = max(0, (int)src.bodyLen - baseL);
        struct R { long long s; int i; };
        vector<R> ranked; ranked.reserve(cands.size());
        for (int i = 0; i < (int)cands.size(); ++i) {
            auto& c = cands[i];
            int la = c.after.bodyLen, rw = max(0, la - baseL), lp = max(0, baseL - la);
            int rmw = max(0, wrongSuffix - rw);
            bool reach = c.adjacentToPrefix || c.directPathLen != INT_MAX || c.loosePathLen != INT_MAX;
            long long s = 2'000'000LL * rw + 120'000LL * lp;
            if (!rmw && wrongSuffix > 0) s += 2'500'000LL;
            s += 20'000LL * c.biteTurn;
            if (!c.adjacentToPrefix) s += 90'000LL;
            s += (c.directPathLen == INT_MAX ? 400'000 : 120LL * c.directPathLen);
            s += (c.loosePathLen == INT_MAX ? 200'000 : 25LL * c.loosePathLen);
            if (!reach) s += 4'000'000LL;
            ranked.push_back({s, i});
        }
        sort(ranked.begin(), ranked.end(), [](const R& a, const R& b) { return a.s != b.s ? a.s < b.s : a.i < b.i; });
        vector<CutCandidate> out;
        int take = min(topK, (int)ranked.size());
        for (int i = 0; i < take; ++i) out.push_back(cands[ranked[i].i]);
        return out;
    }

    long long evaluateBeamState(const SnakeState& st, int maxPrefix) const {
        int k = st.bodyLen, pref = min(maxPrefix, k), E = k - pref;
        return st.turn + 10000LL * (E + 2LL * (M - k));
    }

    uint64_t beamStateKey(const SnakeState& st, int maxPrefix) const {
        uint64_t h = 1469598103934665603ULL;
        auto mix = [&](uint64_t x) { h ^= x + 0x9e3779b97f4a7c15ULL + (h << 6) + (h >> 2); };
        mix(st.hGrid);
        mix(st.hBody);
        mix(st.hColor);
        mix((uint64_t)st.turn);
        mix((uint64_t)st.bodyLen);
        mix((uint64_t)st.colorLen);
        mix((uint64_t)min(maxPrefix, M));
        return h;
    }

    bool betterBeamNode(const BeamNode& a, const BeamNode& b) const {
        if (a.eval != b.eval) return a.eval < b.eval;
        if (a.maxPrefix != b.maxPrefix) return a.maxPrefix > b.maxPrefix;
        return a.st.turn < b.st.turn;
    }

    int pickWanderStepForState(const SnakeState& st, int targetColor, int baseL) {
        DirList dirs = st.legalDirs();
        if (dirs.n == 0) return -1;
        uniform_real_distribution<double> ur(0.0, 1.0);
        struct SM { double s; int d; };
        SM sc[4]; int sn = 0;
        for (int di = 0; di < dirs.n; ++di) {
            int d = dirs.d[di];
            SnakeState nxt = st;
            MoveResult ret = nxt.apply(d);
            if (!ret.ok) continue;
            uint8_t head = st.bodyFront();
            int nr = posR(head) + DR[d], nc = posC(head) + DC[d];
            int food = st.grid[nr][nc];
            double s = ur(rng) * 5.0 + ur(rng) * 5.0 + (food == 0 ? 1.0 : 2.0) + nxt.legalDirs().n * 0.5;
            if (food == targetColor) s += 3.0;
            if (ret.bite) s -= 5.0;
            if (nxt.prefixLen(desired.data(), M) < baseL) s -= 8.0;
            int nt = manhattanToNearestTarget(nxt, targetColor);
            if (nt != INT_MAX) s -= nt * 0.05;
            sc[sn++] = {s, d};
        }
        if (sn == 0) return dirs.d[0];
        sort(sc, sc + sn, [](const SM& a, const SM& b) { return a.s > b.s; });
        return sc[uniform_int_distribution<int>(0, min(3, sn) - 1)(rng)].d;
    }

    void transitionGoTargetCandidates(
        const BeamNode& cur,
        chrono::steady_clock::time_point dl,
        int topK,
        vector<BeamNode>& out
    ) {
        out.clear();
        if (chrono::steady_clock::now() >= dl) return;
        int p = cur.curPrefix;
        if (p >= M || p < cur.st.colorLen) return;
        int tc = desired[p];
        vector<vector<int>> paths;
        paths.reserve(topK);
        auto tryPush = [&](const vector<int>& path) {
            if (path.empty()) return;
            for (auto& ex : paths) if (ex == path) return;
            paths.push_back(path);
        };
        tryPush(findDynamicStrictPathToTargetWithDirOrder(cur.st, tc, {0,1,2,3}));
        tryPush(findDynamicStrictPathToTargetWithDirOrder(cur.st, tc, {3,2,1,0}));
        if ((int)paths.size() < topK) {
            auto fp = findDynamicStrictPathsToTarget(cur.st, tc, topK);
            for (auto& p2 : fp) { tryPush(p2); if ((int)paths.size() >= topK) break; }
        }
        if (paths.empty()) return;
        if ((int)paths.size() > topK) paths.resize(topK);

        if ((int)out.capacity() < (int)paths.size()) out.reserve(paths.size());
        for (auto& path : paths) {
            if (chrono::steady_clock::now() >= dl) break;
            BeamNode nxt; nxt.st = cur.st; nxt.path = cur.path;
            nxt.path.reserve(cur.path.size() + path.size());
            bool ok = true;
            for (int d : path) {
                if (chrono::steady_clock::now() >= dl) { ok = false; break; }
                if (nxt.st.turn >= activeTurnLimit) break;
                MoveResult ret = nxt.st.apply(d);
                if (!ret.ok) { ok = false; break; }
                nxt.path.push_back((char)d);
            }
            if (!ok) continue;
            int np = nxt.st.prefixLen(desired.data(), M);
            nxt.curPrefix = np;
            nxt.maxPrefix = max(cur.maxPrefix, np);
            nxt.eval = evaluateBeamState(nxt.st, nxt.maxPrefix);
            out.push_back(move(nxt));
        }
    }

    void transitionCutRecoverCandidates(
        const BeamNode& cur,
        chrono::steady_clock::time_point dl,
        int topK,
        vector<BeamNode>& out
    ) {
        out.clear();
        if (chrono::steady_clock::now() >= dl) return;
        int p = cur.curPrefix;
        if (p >= M) return;
        auto cuts = chooseTopCutCandidatesForBeam(cur.st, p, desired[p], topK);
        if (cuts.empty()) return;

        if ((int)out.capacity() < (int)cuts.size()) out.reserve(cuts.size());
        for (auto& cut : cuts) {
            if (chrono::steady_clock::now() >= dl) break;
            BeamNode nxt; nxt.st = cur.st; nxt.path = cur.path;
            bool bitten = false, ok = true;
            for (int si = 0; si < cut.seqLen; ++si) {
                if (chrono::steady_clock::now() >= dl) { ok = false; break; }
                if (nxt.st.turn >= activeTurnLimit) break;
                SnakeState bef = nxt.st;
                int pb = bef.prefixLen(desired.data(), M);
                MoveResult ret = nxt.st.apply(cut.seq[si]);
                if (!ret.ok) { ok = false; break; }
                nxt.path.push_back((char)cut.seq[si]);
                if (ret.bite) {
                    bitten = true;
                    for (int rd : buildRecoveryPathByOldBody(bef, nxt.st, pb)) {
                        if (chrono::steady_clock::now() >= dl) { ok = false; break; }
                        if (nxt.st.turn >= activeTurnLimit) break;
                        MoveResult rr = nxt.st.apply(rd);
                        if (!rr.ok) { ok = false; break; }
                        nxt.path.push_back((char)rd);
                    }
                    break;
                }
            }
            if (!ok || !bitten) continue;
            int np = nxt.st.prefixLen(desired.data(), M);
            nxt.curPrefix = np;
            nxt.maxPrefix = max(cur.maxPrefix, np);
            nxt.eval = evaluateBeamState(nxt.st, nxt.maxPrefix);
            out.push_back(move(nxt));
        }
    }

    optional<BeamNode> transitionWander(const BeamNode& cur, chrono::steady_clock::time_point dl) {
        if (chrono::steady_clock::now() >= dl) return nullopt;
        int p = cur.curPrefix;
        if (p >= M) return nullopt;
        int tc = desired[p];
        BeamNode nxt; nxt.st = cur.st; nxt.path = cur.path;
        int moved = 0;
        for (int t = 0; t < WANDER_LEN; ++t) {
            if (chrono::steady_clock::now() >= dl || nxt.st.turn >= activeTurnLimit) break;
            int d = pickWanderStepForState(nxt.st, tc, p);
            if (d == -1) break;
            MoveResult ret = nxt.st.apply(d);
            if (!ret.ok) break;
            nxt.path.push_back((char)d);
            ++moved;
            if (nxt.st.prefixLen(desired.data(), M) >= M) break;
        }
        if (moved == 0) return nullopt;
        int np = nxt.st.prefixLen(desired.data(), M);
        nxt.curPrefix = np;
        nxt.maxPrefix = max(cur.maxPrefix, np);
        nxt.eval = evaluateBeamState(nxt.st, nxt.maxPrefix);
        return nxt;
    }

    bool isDoneNode(const BeamNode& node) const { return node.curPrefix >= M; }
    bool betterFinalNode(const BeamNode& a, const BeamNode& b) const {
        bool ad = isDoneNode(a), bd = isDoneNode(b);
        if (ad != bd) return ad;
        return betterBeamNode(a, b);
    }

    vector<int> buildMaxPrefixCurveFromPath(const SnakeState& initial, const string& path) const {
        SnakeState st = initial;
        int best = st.prefixLen(desired.data(), M);
        vector<int> curve; curve.reserve(path.size() + 1); curve.push_back(best);
        for (unsigned char d : path) {
            MoveResult ret = st.apply(d);
            if (!ret.ok) break;
            best = max(best, st.prefixLen(desired.data(), M));
            curve.push_back(best);
            if (st.turn >= activeTurnLimit) break;
        }
        return curve;
    }

    int greedyPrefixLB(const vector<int>& curve, int turn) const {
        if (curve.empty()) return 0;
        if (turn <= 0) return curve[0];
        if (turn >= (int)curve.size()) return curve.back();
        return curve[turn];
    }

    BeamNode runLegacyFallbackPolicy(const SnakeState& initial, chrono::steady_clock::time_point deadline) {
        state = initial;
        moves.clear();
        recoveryMoves.clear();
        wanderBudget = 0;

        int bestPrefix = state.prefixLen(desired.data(), M);
        int stagnation = 0;
        auto execCut = [&](const int8_t* seq, int len) -> bool {
            for (int i = 0; i < len; ++i) {
                if (state.turn >= activeTurnLimit || chrono::steady_clock::now() >= deadline) break;
                if (!executeDir(seq[i])) return false;
            }
            return true;
        };

        while (state.turn < activeTurnLimit && chrono::steady_clock::now() < deadline) {
            int p = state.prefixLen(desired.data(), M);
            if (p >= M) break;
            bool prefBroken = p < state.colorLen;

            if (!recoveryMoves.empty()) {
                int d = recoveryMoves.front(); recoveryMoves.pop_front();
                if (!executeDir(d)) recoveryMoves.clear();
                continue;
            }

            if (p > bestPrefix) { bestPrefix = p; stagnation = 0; wanderBudget = 0; }
            else ++stagnation;

            int tc = desired[p];
            int rem = M - p;
            bool nearFin = rem <= 2;
            bool empty = state.foodCount == 0;

            if (empty) {
                auto co = chooseBestCutCandidate(state, p, tc);
                if (!co) co = chooseRandomHalfCutCandidate(state, p, tc);
                if (co) { if (!execCut(co->seq, co->seqLen)) break; stagnation = 0; wanderBudget = 0; continue; }
                DirList dirs = state.legalDirs();
                if (dirs.n == 0) break;
                if (!executeDir(dirs.d[0])) break;
                continue;
            }

            if (!prefBroken) {
                auto direct = findDynamicStrictPathToTarget(state, tc);
                if (!direct.empty()) { if (!executeDir(direct.front())) break; continue; }
                auto tail = findDynamicStrictPathToTail(state, tc);
                if (!tail.empty() && (nearFin || stagnation < 60)) { if (!executeDir(tail.front())) break; continue; }
            }

            if (wanderBudget == 0 && (stagnation >= 10 || prefBroken)) wanderBudget = 5;
            if (wanderBudget > 0) {
                int d = prefBroken ? pickExploreMove(tc, p, true, false) : pickWanderStepForState(state, tc, p);
                if (d == -1) { DirList dirs = state.legalDirs(); if (dirs.n == 0) break; d = dirs.d[0]; }
                if (!executeDir(d)) break;
                --wanderBudget;
                continue;
            }

            int ct = nearFin ? 120 : 30;
            if (prefBroken) ct = min(ct, 18);
            if (stagnation >= ct) {
                auto co = chooseBestCutCandidate(state, p, tc);
                if (co) { if (!execCut(co->seq, co->seqLen)) break; stagnation = max(0, stagnation - 15); continue; }
            }

            if (!prefBroken && stagnation >= 80) {
                auto pen = findPenalizedPathToTarget(state, tc, N * 3);
                if (!pen.empty()) { if (!executeDir(pen.front())) break; continue; }
            }

            int fb = pickExploreMove(tc, p, true, !prefBroken);
            if (fb == -1) { DirList dirs = state.legalDirs(); if (dirs.n == 0) break; fb = dirs.d[0]; }
            if (!executeDir(fb)) {
                DirList dirs = state.legalDirs();
                if (dirs.n == 0) break;
                if (!executeDir(dirs.d[0])) break;
            }
        }

        BeamNode out; out.st = state;
        out.curPrefix = state.prefixLen(desired.data(), M);
        out.maxPrefix = max(bestPrefix, out.curPrefix);
        out.eval = evaluateBeamState(out.st, out.maxPrefix);
        out.path.reserve(moves.size());
        for (char c : moves) {
            if (c == 'U') out.path.push_back((char)0);
            else if (c == 'D') out.path.push_back((char)1);
            else if (c == 'L') out.path.push_back((char)2);
            else out.path.push_back((char)3);
        }
        return out;
    }

    optional<BeamNode> runBeamSearch(
        const SnakeState& initial, chrono::steady_clock::time_point deadline,
        const vector<int>& gpc, int beamWidth, int beamTurnCap
    ) {
        BeamNode init; init.st = initial;
        init.curPrefix = init.st.prefixLen(desired.data(), M);
        init.maxPrefix = init.curPrefix;
        init.eval = evaluateBeamState(init.st, init.maxPrefix);
        if (init.st.turn > beamTurnCap) return nullopt;

        int startTurn = init.st.turn;
        if ((int)beamLayersPool.size() <= beamTurnCap) {
            int ns = beamTurnCap + 1;
            beamLayersPool.resize(ns);
            beamIndexPool.resize(ns);
            beamLayerGen.resize(ns, 0);
        }
        ++beamGen;
        if (beamGen == INT_MAX) {
            fill(beamLayerGen.begin(), beamLayerGen.end(), 0);
            beamGen = 1;
        }

        auto ensureTurn = [&](int t) {
            if (beamLayerGen[t] != beamGen) {
                beamLayerGen[t] = beamGen;
                beamLayersPool[t].clear();
                beamIndexPool[t].clear();
            }
        };

        auto ins = [&](BeamNode&& cand) {
            int t = cand.st.turn;
            if (t < startTurn || t > beamTurnCap) return;
            if (cand.maxPrefix < greedyPrefixLB(gpc, t)) return;
            uint64_t key = beamStateKey(cand.st, cand.maxPrefix);
            ensureTurn(t);
            auto& mp = beamIndexPool[t];
            auto& vec = beamLayersPool[t];
            if (mp.empty()) {
                mp.reserve((size_t)beamWidth * 4U + 8U);
                vec.reserve((size_t)beamWidth * 4U + 8U);
            }
            auto it = mp.find(key);
            if (it == mp.end()) { mp[key] = (int)vec.size(); vec.push_back(move(cand)); }
            else { if (betterBeamNode(cand, vec[it->second])) vec[it->second] = move(cand); }
        };

        ensureTurn(startTurn);
        beamLayersPool[startTurn].push_back(init);
        beamIndexPool[startTurn][beamStateKey(init.st, init.maxPrefix)] = 0;

        bool hasDone = false; BeamNode bestDone, bestSeen = init;
        vector<BeamNode> goBuf;
        vector<BeamNode> cutBuf;
        goBuf.reserve(max(2, BEAM_CANDIDATE_TOP_K));
        cutBuf.reserve(4);

        for (int turn = startTurn; turn <= beamTurnCap; ++turn) {
            if (chrono::steady_clock::now() >= deadline) break;
            if (beamLayerGen[turn] != beamGen) continue;
            auto& beam = beamLayersPool[turn];
            if (beam.empty()) continue;
            auto cmpNode = [&](const BeamNode& a, const BeamNode& b) { return betterBeamNode(a, b); };
            if ((int)beam.size() > beamWidth) {
                nth_element(beam.begin(), beam.begin() + beamWidth, beam.end(), cmpNode);
                beam.resize(beamWidth);
            }
            sort(beam.begin(), beam.end(), cmpNode);

            for (auto& node : beam) {
                if (chrono::steady_clock::now() >= deadline) break;
                if (betterBeamNode(node, bestSeen)) bestSeen = node;
                if (node.maxPrefix < greedyPrefixLB(gpc, node.st.turn)) continue;
                int p = node.curPrefix;
                if (p >= M) { if (!hasDone || betterBeamNode(node, bestDone)) { hasDone = true; bestDone = node; } continue; }
                if (node.st.turn >= beamTurnCap) continue;

                transitionGoTargetCandidates(node, deadline, BEAM_CANDIDATE_TOP_K, goBuf);
                for (auto& nxt : goBuf) ins(move(nxt));
                if (chrono::steady_clock::now() >= deadline) break;
                transitionCutRecoverCandidates(node, deadline, 1, cutBuf);
                for (auto& nxt : cutBuf) ins(move(nxt));
                if (chrono::steady_clock::now() >= deadline) break;
                auto w = transitionWander(node, deadline);
                if (w) ins(move(*w));
            }
            if (hasDone) break;
            beamIndexPool[turn].clear();
        }
        return hasDone ? optional(bestDone) : optional(bestSeen);
    }

    int pickExploreMove(int tc, int baseL, bool randomized, bool preferTC = true) {
        DirList dirs = state.legalDirs();
        if (dirs.n == 0) return -1;
        uniform_real_distribution<double> ur(0.0, 1.0);
        if (randomized && ur(rng) < 0.15) return dirs.d[uniform_int_distribution<int>(0, dirs.n - 1)(rng)];

        struct SM { double s; int d; };
        SM sc[4]; int sn = 0;
        for (int di = 0; di < dirs.n; ++di) {
            int d = dirs.d[di];
            uint8_t head = state.bodyFront();
            int nr = posR(head) + DR[d], nc = posC(head) + DC[d];
            int lf = state.grid[nr][nc];
            SnakeState nxt = state;
            MoveResult ret = nxt.apply(d);
            if (!ret.ok) continue;
            int pref = nxt.prefixLen(desired.data(), M);
            int nt = manhattanToNearestTarget(nxt, tc);
            int mob = nxt.legalDirs().n;
            double s = 0;
            if (preferTC) { if (lf == 0) s += 2.5; else if (lf == tc) s += 8.0; else s -= 8.0; }
            else { s += lf == 0 ? 2.0 : 1.5; }
            if (ret.bite) s += 0.5;
            if (pref < baseL) s -= 2000.0;
            s += mob * 0.6;
            if (preferTC && nt != INT_MAX) s -= nt * 0.4;
            if (randomized) s += ur(rng);
            sc[sn++] = {s, d};
        }
        if (sn == 0) return dirs.d[0];
        sort(sc, sc + sn, [](const SM& a, const SM& b) { return a.s > b.s; });
        if (!randomized) return sc[0].d;
        int topK = min(3, sn);
        if (ur(rng) < 0.75) return sc[uniform_int_distribution<int>(0, topK - 1)(rng)].d;
        return sc[uniform_int_distribution<int>(0, sn - 1)(rng)].d;
    }

    int greedyTurnStep(int cap) const { return cap < 1000 ? 100 : cap < 10000 ? 1000 : 10000; }

    void solve() {
        auto start = chrono::steady_clock::now();
        auto totalDL = start + chrono::milliseconds(SEARCH_TIME_LIMIT_MS);
        SnakeState initial = state;
        BeamNode greedy; bool hasGreedy = false; int selTL = INITIAL_GREEDY_TURN_LIMIT;

        for (int cap = INITIAL_GREEDY_TURN_LIMIT; cap <= MAX_TURN_LIMIT;) {
            if (chrono::steady_clock::now() >= totalDL) break;
            activeTurnLimit = cap;
            BeamNode cand = runLegacyFallbackPolicy(initial, totalDL);
            selTL = cap;
            if (!hasGreedy || betterFinalNode(cand, greedy)) { greedy = cand; hasGreedy = true; }
            if (isDoneNode(cand)) { greedy = move(cand); break; }
            int step = greedyTurnStep(cap);
            if (cap > MAX_TURN_LIMIT - step) break;
            cap += step;
        }

        if (!hasGreedy) {
            activeTurnLimit = INITIAL_GREEDY_TURN_LIMIT;
            greedy.st = initial; greedy.path.clear();
            greedy.curPrefix = initial.prefixLen(desired.data(), M);
            greedy.maxPrefix = greedy.curPrefix;
            greedy.eval = evaluateBeamState(greedy.st, greedy.maxPrefix);
            selTL = activeTurnLimit;
        } else { activeTurnLimit = selTL; greedy.eval = evaluateBeamState(greedy.st, greedy.maxPrefix); }

        auto gpc = buildMaxPrefixCurveFromPath(initial, greedy.path);
        int btcBase = min({activeTurnLimit, (int)greedy.path.size(), 5000});
        BeamNode best = greedy;
        int bestDoneTurnCap = isDoneNode(best) ? (int)best.path.size() : INT_MAX;
        int bw = BEAM_WIDTH;
        while (chrono::steady_clock::now() < totalDL) {
            int btc = btcBase;
            if (bestDoneTurnCap != INT_MAX) btc = min(btc, bestDoneTurnCap);

            auto bb = runBeamSearch(initial, totalDL, gpc, bw, btc);
            if (bb && betterFinalNode(*bb, best)) {
                best = move(*bb);
                if (isDoneNode(best)) bestDoneTurnCap = min(bestDoneTurnCap, (int)best.path.size());
            } else if (bb && isDoneNode(*bb)) {
                bestDoneTurnCap = min(bestDoneTurnCap, (int)bb->path.size());
            }
            if (chrono::steady_clock::now() >= totalDL || bw >= 1'000'000) break;
            bw = min(1'000'000, bw * 2);
        }

        moves.clear();
        for (unsigned char d : best.path) moves.push_back(DCHAR[d]);
    }

    void printAnswer() const { for (char c : moves) cout << c << '\n'; }
};

}  // namespace

int main() {
    Solver solver;
    solver.readInput();
    solver.solve();
    solver.printAnswer();
    return 0;
}
