/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30317582
 * Submitted at: 2022-03-21 11:02:52
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_br
 * Result: AC
 * Execution Time: 84 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    vector<ll> px,py;
    long double ave_x = 0,ave_y = 0;
    rep(i,n){
        ll x,y; cin >> x >> y;
        px.push_back(x);
        py.push_back(y);
    }
    sort(px.begin(),px.end());
    sort(py.begin(),py.end());

    if(n%2 == 0){
        ave_x = (px[n/2-1]+px[n/2])/2;
        ave_y = (py[n/2-1]+py[n/2])/2;
    }
    else{
        ave_x = px[n/2];
        ave_y = py[n/2];
    }

    long double ans = 0;
    rep(i,n){
        ll x = px[i],y = py[i];
        ans += abs(x-ave_x);
        ans += abs(y-ave_y);
    }
    cout << (ll)ans << endl;

    
    return 0;
}