/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54507635
 * Submitted at: 2024-06-13 23:04:15
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_g
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

#define DIR_NUM 8
vector<int> dx = { -1, -1, -1, 0, 0, 1, 1, 1 };
vector<int> dy = { -1, 0, 1, -1, 1, -1, 0, 1 };

inline bool outField(int x,int y,int h,int w) {
    if(0 <= x && x < h && 0 <= y && y < w)return false;
    return true;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // dfs が一番手っ取り早く全探索可能
    // 解けるとしても、より簡単かつ高速に実装出来そうな方針を選ぶべし
    ll h, w; cin >> h >> w;
    vector<string> g(h);
    rep(i, h) cin >> g[i];
    ll n; string s; cin >> n >> s;

    bool ok = false;
    set<P> st;
    auto dfs = [&](auto self, ll x, ll y) -> void {
        if(st.size() == n) {
            ok = true;
            return;
        }
        rep(d, DIR_NUM) {
            ll nx = x + dx[d], ny = y + dy[d];
            if(outField(nx, ny, h, w) || st.count(P(nx, ny)) || g[nx][ny] != s[st.size()]) continue;
            st.insert(P(nx, ny));
            self(self, nx, ny);
            if(ok) return;
            st.erase(P(nx, ny));
        }
        return;
    };
    rep(i, h) rep(j, w) {
        dfs(dfs, i, j);
        if(ok) return cout << "Yes" << endl, 0;
    }
    cout << "No" << endl;
    
    return 0;
}