/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/adt_all_20231026_2/submissions/46943797
 * Submitted at: 2023-10-26 18:40:38
 * Problem URL: https://atcoder.jp/contests/adt_all_20231026_2/tasks/abc285_b
 * Result: AC
 * Execution Time: 13 ms
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
    
    ll n; string s; cin >> n >> s;
    for(int i=1; i<=n-1; i++) {
        ll idx = 0, ans = 0;
        while(idx+i < n) {
            if( s[idx] == s[idx+i] ) break;
            ans++;
            idx++;
        }
        cout << ans << endl;
    }
    
    return 0;
}