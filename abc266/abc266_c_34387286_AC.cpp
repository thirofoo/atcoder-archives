/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc266/submissions/34387286
 * Submitted at: 2022-08-27 21:33:27
 * Problem URL: https://atcoder.jp/contests/abc266/tasks/abc266_c
 * Result: AC
 * Execution Time: 11 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    vector<ld> x,y;
    rep(i,4){
        ld tx,ty; cin >> tx >> ty;
        x.push_back(tx);
        y.push_back(ty);
    }
    rep(i,4){
        int i1 = i,i2 = (i+2+4)%4,i3 = (i+1+4)%4,i4 = (i-1+4)%4;
        int dx = x[i2]-x[i1],dy = y[i2]-y[i1];
        bool f1 = (dy*x[i3]-dx*y[i3]+x[i2]*y[i1]-x[i1]*y[i2] > 0) && (dy*x[i4]-dx*y[i4]+x[i2]*y[i1]-x[i1]*y[i2] > 0);
        bool f2 = (dy*x[i3]-dx*y[i3]+x[i2]*y[i1]-x[i1]*y[i2] < 0) && (dy*x[i4]-dx*y[i4]+x[i2]*y[i1]-x[i1]*y[i2] < 0);
        if(f1 || f2){
            return cout << "No" << endl,0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}