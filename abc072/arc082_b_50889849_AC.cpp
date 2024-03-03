/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc072/submissions/50889849
 * Submitted at: 2024-03-04 08:30:39
 * Problem URL: https://atcoder.jp/contests/abc072/tasks/arc082_b
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    
    ll n; cin >> n;
    vector<ll> p(n), idx;
    rep(i,n) {
        cin >> p[i];
        if( p[i] == i+1 ) idx.emplace_back(i);
    }
    ll ans = 0;
    rep(i,idx.size()) {
        if( i == idx.size()-1 || idx[i]+1 != idx[i+1] ) ans++;
        else ans++, i++;
    }
    cout << ans << endl;
    
    return 0;
}