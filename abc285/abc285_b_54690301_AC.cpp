/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc285/submissions/54690301
 * Submitted at: 2024-06-18 18:19:41
 * Problem URL: https://atcoder.jp/contests/abc285/tasks/abc285_b
 * Result: AC
 * Execution Time: 11 ms
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
    reps(l, 1, n) {
        ll cnt = 0;
        rep(j, n) {
            if(j + l >= n) break;
            if(s[j] != s[j+l]) cnt++;
            else break;
        }
        cout << cnt << endl;
    }
    
    return 0;
}