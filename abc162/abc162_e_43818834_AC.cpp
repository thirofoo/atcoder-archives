/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc162/submissions/43818834
 * Submitted at: 2023-07-22 15:33:12
 * Problem URL: https://atcoder.jp/contests/abc162/tasks/abc162_e
 * Result: AC
 * Execution Time: 16 ms
 */

#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
using mint = modint1000000007;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
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