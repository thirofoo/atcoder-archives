/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc139/submissions/31282277
 * Submitted at: 2022-04-26 17:10:45
 * Problem URL: https://atcoder.jp/contests/arc139/tasks/arc139_b
 * Result: WA
 * Execution Time: 24 ms
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
    ll t,n,a,b,x,y,z;
    cin >> t;

    rep(i,t){
        ll ans = LLONG_MAX;
        cin >> n >> a >> b >> x >> y >> z;

        //+1あたりのコストが少ない方をyとする。
        if(y*b > z*a){
            swap(y,z); swap(a,b);
        }

        //c1 : +aするのにコストが少ない方
        //c2 : +bするのにコストが少ない方
        ll c1 = min(y,a*x),c2 = min(z,b*x);
        if(n/a < a-1){
            for(ll j=0;j<=n/a;j++){
                ll rest = n-a*j,cost = c1*j;
                cost += (rest/b)*c2;
                rest -= (rest/b)*b;
                cost += x*rest;
                ans = min(ans,cost);
            }
        }
        else{
            for(ll j=0;j<=a-1;j++){
                ll rest = n-b*j,cost = c2*j;
                cost += (rest/a)*c1;
                rest -= (rest/a)*a;
                cost += x*rest;
                ans = min(ans,cost);
            }
        }
        cout << ans << endl;
    }
    return 0;
}