/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/31056012
 * Submitted at: 2022-04-17 11:17:11
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_e
 * Result: AC
 * Execution Time: 70 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

int main() {
    ll n,k; cin >> n >> k;
    vector<P> vertex;
    map<T,set<int>> a;
    set<T> c;
    rep(i,n){
        ll x,y; cin >> x >> y;
        vertex.push_back(P(x,y));
    }
    if(k == 1)return cout << "Infinity" << endl,0;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            auto [x1,y1] = vertex[i];
            auto [x2,y2] = vertex[j];
            ll dx = x1-x2, dy = y1-y2, gcd = euclid(abs(dx),abs(dy));
            dx /= gcd; dy /= gcd;
            if(dx < 0 && dy < 0)dx *= -1,dy *= -1;
            else if(dx < 0 && dy > 0)dx *= -1,dy *= -1;

            ll b = dx*y1 - dy*x1;
            if(dx != 0 && dy == 0)dx = 1,b = y1;
            if(dx == 0 && dy != 0)dy = 1,b = x1;

            a[T(dx,dy,b)].insert(i);
            a[T(dx,dy,b)].insert(j);
            c.insert(T(dx,dy,b));
        }
    }
    ll ans = 0;
    for(auto l:c){
        if(a[l].size() >= k)ans++;
    }
    cout << ans << endl;
    return 0;
}