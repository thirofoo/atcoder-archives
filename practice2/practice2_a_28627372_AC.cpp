/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/practice2/submissions/28627372
 * Submitted at: 2022-01-19 11:36:02
 * Problem URL: https://atcoder.jp/contests/practice2/tasks/practice2_a
 * Result: AC
 * Execution Time: 249 ms
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
    int n,q; cin >> n >> q;
    dsu d(n);
    rep(i,q){
        int t,u,v; cin >> t >> u >> v;
        if(t == 0){
            d.merge(u,v);
        }
        else{
            if(d.same(u,v))cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}