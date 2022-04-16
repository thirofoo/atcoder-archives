/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/31044477
 * Submitted at: 2022-04-16 22:51:06
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_e
 * Result: WA
 * Execution Time: 120 ms
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
    long double n,k; cin >> n >> k;
    vector<P> vertex;
    map<P,set<ll>> a;
    set<P> c;
    rep(i,n){
        ll x,y; cin >> x >> y;
        vertex.push_back(P(x,y));
    }
    if(n == 1 || k == 1)return cout << "Infinity" << endl,0;
    rep(i,n){
        rep(j,n){
            if(i == j)continue;
            auto [x1,y1] = vertex[i];
            auto [x2,y2] = vertex[j];
            long double k = (x1 == x2 ? LLONG_MAX : (y1-y2)/(x1-x2));
            long double b = (x1 == x2 ? x1 : y1+k*(-x1));
            a[P(k,b)].insert(i);
            a[P(k,b)].insert(j);
            c.insert(P(k,b));
        }
    }
    ll ans = 0;
    for(auto l:c){
        if(a[l].size() >= k)ans++;
    }
    cout << ans << endl;
    return 0;
}