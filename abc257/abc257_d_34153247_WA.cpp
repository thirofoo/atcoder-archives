/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc257/submissions/34153247
 * Submitted at: 2022-08-20 12:04:34
 * Problem URL: https://atcoder.jp/contests/abc257/tasks/abc257_d
 * Result: WA
 * Execution Time: 21 ms
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
typedef tuple<ld, ld, ld> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(6) << fixed;
    
    int n; cin >> n;
    vector<T> ju;
    vector d(n,vector<ll>(n,0));
    rep(i,n){
        ld x,y,p; cin >> x >> y >> p;
        ju.push_back(T(x,y,p));
    }
    rep(i,n){
        auto [x1,y1,p1] = ju[i];
        for(int j=i+1;j<n;j++){
            auto [x2,y2,p2] = ju[j];
            d[i][j] = abs(x1-x2)+abs(y1-y2);
        }
    }
    ll left = 0,right = 1e10;
    while(right-left > 1){
        ll mid = (right+left)/2;
        bool flag = false;
        dsu uf(n);
        rep(i,n){
            auto [x1,y1,p1] = ju[i];
            rep(j,n){
                auto [x2,y2,p2] = ju[j];
                if(p1*mid >= abs(x1-x2)+abs(y1-y2))uf.merge(i,j);
            }
        }

        if(uf.size(0) == n)right = mid;
        else left = mid;
    }
    cout << right << endl;

    return 0;
}