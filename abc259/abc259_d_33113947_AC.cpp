/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc259/submissions/33113947
 * Submitted at: 2022-07-09 22:22:04
 * Problem URL: https://atcoder.jp/contests/abc259/tasks/abc259_d
 * Result: AC
 * Execution Time: 47 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,sx,sy,tx,ty; cin >> n >> sx >> sy >> tx >> ty;
    dsu uf(n);
    ll si = -1,ti = -1;
    vector<T> info;
    rep(i,n){
        ll x,y,r; cin >> x >> y >> r;
        info.push_back(T(x,y,r));
        if( (x-sx)*((x-sx))+(y-sy)*(y-sy) == r*r )si = i;
        if( (x-tx)*((x-tx))+(y-ty)*(y-ty) == r*r )ti = i;
    }
    if(si == -1 || ti == -1)return cout << "No" << endl,0;
    rep(i,n){
        for(ll j=i+1;j<n;j++){
            auto [x1,y1,r1] = info[i];
            auto [x2,y2,r2] = info[j];
            //内側にいる時は除外
            if( (ll)(x1-x2)*(x1-x2)+(ll)(y1-y2)*(y1-y2) <  (ll)(r1-r2)*(r1-r2))continue;
            if( (ll)(x1-x2)*(x1-x2)+(ll)(y1-y2)*(y1-y2) <= (ll)(r1+r2)*(r1+r2) ){
                uf.merge(i,j);
            }
        }
    }
    if(uf.same(si,ti))cout << "Yes" << endl;
    else cout << "No" << endl;

    
    return 0;
}