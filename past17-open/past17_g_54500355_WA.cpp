/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54500355
 * Submitted at: 2024-06-13 18:05:51
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_g
 * Result: WA
 * Execution Time: 82 ms
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
vector<ll> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector<ll> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

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
        rep(d1, DIR_NUM) rep(d2, DIR_NUM) rep(d3, DIR_NUM) rep(d4, DIR_NUM) {
            set<char> st;
            vector<P> surround, dxs;
            dxs.emplace_back(P(0, 0));
            dxs.emplace_back(P(dx[d1], dy[d1]));
            dxs.emplace_back(P(dx[d2], dy[d2]));
            dxs.emplace_back(P(dx[d3], dy[d3]));
            dxs.emplace_back(P(dx[d4], dy[d4]));
            ll tdx = 0, tdy = 0;
            rep(k, n) {
                auto &&[ndx, ndy] = dxs[k];
                tdx += ndx, tdy += ndy;
                if(outField(i+tdx, j+tdy, h, w)) continue;
                surround.emplace_back(P(i+tdx, j+tdy));
                st.insert(g[i+tdx][j+tdy]);
            }
            if(st.size() < n) continue;

            bool f = true;
            rep(k, n) {
                auto &&[x, y] = surround[k];
                f &= (s[k] == g[x][y]);
            }
            if(f) {
                cout << "Yes" << endl;
                return 0;
            }
        }

    }
    cout << "No" << endl;
    
    return 0;
}