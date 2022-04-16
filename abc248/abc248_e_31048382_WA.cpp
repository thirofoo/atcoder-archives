/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/31048382
 * Submitted at: 2022-04-17 00:10:28
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_e
 * Result: WA
 * Execution Time: 123 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<long double,long double> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cout << fixed << setprecision(10);
    ll n,k; cin >> n >> k;
    vector<P> vertex;
    map<P,set<int>> a;
    set<P> c;
    rep(i,n){
        ll x,y; cin >> x >> y;
        vertex.push_back(P(x,y));
    }
    if(k == 1)return cout << "Infinity" << endl,0;
    rep(i,n){
        rep(j,n){
            if(i == j)continue;
            auto [x1,y1] = vertex[i];
            auto [x2,y2] = vertex[j];
            long double z = (x1 == x2 ? LLONG_MAX : (y1-y2)/(x1-x2));
            long double b = (x1 == x2 ? x1 : y1+z*(-x1));
            a[P(z,b)].insert(i);
            a[P(z,b)].insert(j);
            c.insert(P(z,b));
        }
    }
    ll ans = 0;
    for(auto l:c){
        if(a[l].size() >= k)ans++;
    }
    cout << ans << endl;
    return 0;
}