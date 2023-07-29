/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc059/submissions/44019075
 * Submitted at: 2023-07-29 09:37:39
 * Problem URL: https://atcoder.jp/contests/abc059/tasks/arc072_a
 * Result: AC
 * Execution Time: 21 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 累積和を作成 → +-+-... と -+-+.. のケース確認
    ll n; cin >> n;
    vector<ll> a(n+1,0);
    rep(i,n) {
        cin >> a[i+1];
        a[i+1] += a[i];
    }
    ll cand, ans = 1e16, dis;
    rep(j,2) {
        // j = 0 :+-+-... , j = 1 : -+-+...
        dis = 0, cand = 0;
        for(ll i=1;i<=n;i++) {
            if( (i+j)%2 == 1 ) {
                cand += max(0ll, 1-(a[i]+dis));
                dis += max(0ll, 1-(a[i]+dis));
            }
            else {
                cand += max(0ll, (a[i]+dis)+1);
                dis -= max(0ll, (a[i]+dis)+1);
            }
        }
        ans = min(ans, cand);
    }
    cout << ans << endl;
    
    return 0;
}