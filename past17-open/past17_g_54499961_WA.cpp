/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54499961
 * Submitted at: 2024-06-13 17:51:43
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_g
 * Result: WA
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<char, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

#define DIR_NUM 8
vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

inline bool outField(int x,int y,int h,int w) {
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w; cin >> h >> w;
    vector<string> g(h);
    rep(i, h) cin >> g[i];
    ll n; string s; cin >> n >> s;

    rep(i, h) rep(j, w) {
        vector<P> surround;
        rep(k, DIR_NUM) {
            ll nx = i + dx[k], ny = j + dy[k];
            if(outField(nx, ny, h, w)) continue;
            surround.emplace_back(P(nx, ny));
        }
        if(surround.size() < n) continue;
        vector<ll> perm1(surround.size(), 0);
        rep(k, n) perm1[k] = 1;
        sort(perm1.begin(), perm1.end());
        do {
            set<char> st;
            vector<ll> idx;
            rep(k, surround.size()) {
                if(perm1[k] == 0) continue;
                auto &&[x, y] = surround[k];
                st.insert(g[x][y]);
                idx.emplace_back(k);
            }
            if(st.size() != n) continue;

            vector<ll> perm2(n, 0);
            iota(perm2.begin(), perm2.end(), 0);
            do {
                bool f = true;
                rep(k, n) {
                    auto &&[x, y] = surround[idx[k]];
                    f &= (g[x][y] == s[perm2[k]]);
                }
                if(f) {
                    cout << "Yes" << endl;
                    return 0;
                }
            } while(next_permutation(perm2.begin(), perm2.end()));

        } while(next_permutation(perm1.begin(), perm1.end()));
    }
    cout << "No" << endl;
    
    return 0;
}