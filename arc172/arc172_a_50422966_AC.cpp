/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc172/submissions/50422966
 * Submitted at: 2024-02-18 21:44:37
 * Problem URL: https://atcoder.jp/contests/arc172/tasks/arc172_a
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w, n; cin >> h >> w >> n;
    vector<ll> a(n), cnt(30,0), rui(30,1);
    rep(i,n) cin >> a[i];
    rep(i,29) rui[i+1] = rui[i] * 2;
    // チョコを 2^? の正方形に分割して個数を求める
    auto dfs = [&](auto self, ll nh, ll nw, ll r) -> void {
        if( nh == 0 || nw == 0 || r < 0 ) return;
        if( max(h,w) < rui[r] ) {
            self(self,nh,nw,r-1);
            return;
        }
        ll th = nh / rui[r], tw = nw / rui[r];
        cnt[r] += th * tw;
        self(self,rui[r]*th,nw-rui[r]*tw,r-1);
        self(self,nh-rui[r]*th,rui[r]*tw,r-1);
        self(self,nh-rui[r]*th,nw-rui[r]*tw,r-1);
        return;
    };
    dfs(dfs,h,w,29);
    sort(a.begin(), a.end(), greater<ll>());
    // rep(i,29) cerr << cnt[i] << " ";
    // cerr << endl;
    rep(i,n) {
        ll ok = -1;
        for(ll j=a[i]; j<30; j++) {
            if( cnt[j] > 0 ) {
                ok = j;
                cnt[j]--;
                break;
            }
        }
        if( ok == -1 ) {
            cout << "No" << endl;
            return 0;
        }
        // 余った部分を cnt に加える
        dfs(dfs,rui[ok]-rui[a[i]],rui[a[i]],29);
        dfs(dfs,rui[a[i]],rui[ok]-rui[a[i]],29);
        dfs(dfs,rui[ok]-rui[a[i]],rui[ok]-rui[a[i]],29);
        // rep(i,29) cerr << cnt[i] << " ";
        // cerr << endl << endl;
    }
    cout << "Yes" << endl;
    
    return 0;
}