/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc162/submissions/43818205
 * Submitted at: 2023-07-22 15:05:28
 * Problem URL: https://atcoder.jp/contests/abc162/tasks/abc162_e
 * Result: AC
 * Execution Time: 16 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    ll n,k; cin >> n >> k;
    vector<mint> cnt(k+1,0);
    for(ll i=k;i>=1;i--){
        cnt[i] = mint(k/i).pow(n);
        for(ll j=2*i;j<=k;j+=i) cnt[i] -= cnt[j];
    }
    mint ans = 0;
    for(ll i=1;i<=k;i++) ans += cnt[i] * i;
    cout << ans.val() << endl;
    
    return 0;
}