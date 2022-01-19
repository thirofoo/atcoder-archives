/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc065/submissions/28630117
 * Submitted at: 2022-01-19 15:35:44
 * Problem URL: https://atcoder.jp/contests/abc065/tasks/arc076_b
 * Result: AC
 * Execution Time: 105 ms
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
    int n,ans = 0; cin >> n;
    vector<P> x,y;
    rep(i,n){
        int a,b; cin >> a >> b;
        x.push_back(P(a,i));
        y.push_back(P(b,i));
    }
    dsu d(n);
    vector<tuple<int, int, int>> edges;
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    rep(i,n-1){
        edges.push_back(make_tuple( x[i + 1].first - x[i].first, x[i].second, x[i + 1].second));
        edges.push_back(make_tuple( y[i + 1].first - y[i].first, y[i].second, y[i + 1].second));
    }
    //ここでx,y混合の重みのsくなさじゅんにsortしている。
    sort(edges.begin(),edges.end());
    for(auto k:edges){
        auto [a,b,c] = k;
        if(!d.same(b,c)){
            d.merge(b,c);
            ans += a;
        }
    }
    cout << ans << endl;
    return 0;
}