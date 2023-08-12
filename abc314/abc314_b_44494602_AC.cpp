/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc314/submissions/44494602
 * Submitted at: 2023-08-12 21:07:32
 * Problem URL: https://atcoder.jp/contests/abc314/tasks/abc314_b
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
    
    ll n; cin >> n;
    vector<set<P>> p(37);
    rep(i,n) {
        ll c; cin >> c;
        rep(j,c) {
            ll a; cin >> a;
            p[a].insert(P(c,i+1));
        }
    }
    ll x; cin >> x;
    if( p[x].size() == 0 ) {
        cout << p[x].size() << endl;
        cout << endl;
        return 0;
    }

    ll now = (*p[x].begin()).first;
    queue<ll> ans;
    for(auto [num,ele]:p[x]) {
        if( num != now ) break;
        ans.push(ele);
    }
    cout << ans.size() << endl;
    while( !ans.empty() ) {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;
    
    return 0;
}