/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc064/submissions/44561458
 * Submitted at: 2023-08-13 21:23:14
 * Problem URL: https://atcoder.jp/contests/agc064/tasks/agc064_a
 * Result: AC
 * Execution Time: 25 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> ans = {n,n-1,n,n-2,n,n-1};
    for(ll i=4;i<=n;i++) {
        int cnt = (i+1)/2, now = n;
        while(cnt--) {
            ans.push_back(now);
            now -= 2;
        }
        cnt = i/2, now = n-i+1 + (i%2);
        while(cnt--) {
            ans.push_back(now);
            now += 2;
        }
    }
    rep(i,ans.size()) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}