/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc259/submissions/33108483
 * Submitted at: 2022-07-09 22:08:28
 * Problem URL: https://atcoder.jp/contests/abc259/tasks/abc259_d
 * Result: RE
 * Execution Time: 153 ms
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
        if( (ll)pow(abs(x-sx),2)+(ll)pow(abs(y-sy),2) == r*r )si = i;
        if( (ll)pow(abs(x-tx),2)+(ll)pow(abs(y-ty),2) == r*r )ti = i;
    }
    rep(i,n){
        for(int j=i+1;j<n;j++){
            auto [x1,y1,r1] = info[i];
            auto [x2,y2,r2] = info[j];

            //内側にいる時は除外
            if( (ll)pow(abs(x1-x2),2)+(ll)pow(abs(y1-y2),2) < (r1-r2)*(r1-r2))continue;
            if( (ll)pow(abs(x1-x2),2)+(ll)pow(abs(y1-y2),2) <= (r1+r2)*(r1+r2) ){
                uf.merge(i,j);
            }
        }
    }
    if(uf.same(si,ti))cout << "Yes" << endl;
    else cout << "No" << endl;

    
    return 0;
}