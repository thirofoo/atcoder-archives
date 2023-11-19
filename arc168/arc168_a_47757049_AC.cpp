/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc168/submissions/47757049
 * Submitted at: 2023-11-19 21:05:00
 * Problem URL: https://atcoder.jp/contests/arc168/tasks/arc168_a
 * Result: AC
 * Execution Time: 2 ms
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
    ll ans = 0, cnt = 0;
    rep(i,n-1) {
        if( s[i] == '>' ) cnt++;
        else {
            ans += (cnt+1)*cnt/2;
            cnt = 0;
        }
    }
    ans += (cnt+1)*cnt/2;
    cout << ans << endl;
    
    return 0;
}