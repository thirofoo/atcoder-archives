/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/atc001/submissions/29560259
 * Submitted at: 2022-02-21 13:43:00
 * Problem URL: https://atcoder.jp/contests/atc001/tasks/unionfind_a
 * Result: AC
 * Execution Time: 409 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,q; cin >> n >> q;
    dsu d(n);
    rep(i,q){
        int p,a,b; cin >> p >> a >> b;
        if(p == 0){
            d.merge(a,b);
        }
        else{
            if(d.same(a,b))cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}