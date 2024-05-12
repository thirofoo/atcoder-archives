/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc177/submissions/53417115
 * Submitted at: 2024-05-12 21:11:58
 * Problem URL: https://atcoder.jp/contests/arc177/tasks/arc177_b
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string s; cin >> n >> s;
    ll pre = 0;
    string ans = "";
    for(ll i=n-1; i>=0; i--) {
        if( s[i]-'0' == pre ) continue;
        rep(j,i+1) ans += ( pre == 0 ? 'A' : 'B' );
        pre = s[i]-'0';
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    
    return 0;
}