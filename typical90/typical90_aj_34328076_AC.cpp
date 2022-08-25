/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/34328076
 * Submitted at: 2022-08-25 18:57:06
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_aj
 * Result: AC
 * Execution Time: 202 ms
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
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q; cin >> n >> q;
    //解説AC。天才。
    vector<ll> x,y,x2,y2;
    rep(i,n){
        ll tx,ty; cin >> tx >> ty;
        //45度回転はx'=x-y,y'=x+y。(極座標でもなんでも求めればわかる)
        x.push_back(tx-ty);
        y.push_back(tx+ty);
    }
    x2 = x, y2 = y;
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    while(q--){
        ll tq; cin >> tq; tq--;
        ll cx = x2[tq],cy = y2[tq];
        cout << max(max(abs(cx-x.back()),abs(cy-y.back())),max(abs(cx-x[0]),abs(cy-y[0]))) << endl;
    }
    
    return 0;
}