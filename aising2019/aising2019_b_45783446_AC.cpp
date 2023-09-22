/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/aising2019/submissions/45783446
 * Submitted at: 2023-09-22 09:14:06
 * Problem URL: https://atcoder.jp/contests/aising2019/tasks/aising2019_b
 * Result: AC
 * Execution Time: 1 ms
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
    
    ll n, a, b; cin >> n >> a >> b;
    vector<ll> p(n);
    ll c1 = 0, c2 = 0, c3 = 0;
    rep(i,n) {
        cin >> p[i];
        if( p[i] <= a ) c1++;
        else if( p[i] <= b ) c2++;
        else c3++;
    }
    cout << min({c1,c2,c3}) << endl;
    
    return 0;
}