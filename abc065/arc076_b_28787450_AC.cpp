/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc065/submissions/28787450
 * Submitted at: 2022-01-25 12:45:50
 * Problem URL: https://atcoder.jp/contests/abc065/tasks/arc076_b
 * Result: AC
 * Execution Time: 111 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    ll ans = 0;
    dsu d(n);
    vector<P> x,y;
    rep(i,n){
        int a,b; cin >> a >> b;
        x.push_back(P(a,i));
        y.push_back(P(b,i));
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    vector<tuple<int,int,int>> weight;
    rep(i,n-1) weight.push_back(tuple<int,int,int>(x[i+1].first-x[i].first, x[i].second, x[i+1].second));
    rep(i,n-1) weight.push_back(tuple<int,int,int>(y[i+1].first-y[i].first, y[i].second, y[i+1].second));
    sort(weight.begin(),weight.end());
    rep(i,weight.size()){
        auto [a,b,c] = weight[i];
        if(d.same(b,c))continue;
        d.merge(b,c);
        ans += a;
    }
    cout << ans << endl;
    return 0;
}