/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28233379
 * Submitted at: 2021-12-30 15:59:09
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bi
 * Result: AC
 * Execution Time: 356 ms
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
    ll q; cin >> q;
    vector<int> ans(0);
    rep(i,q){
        ll a,b; cin >> a >> b;
        if(a == 1)ans.insert(ans.begin(),b);
        else if(a == 2)ans.insert(ans.end(),b);
        else if(a == 3)cout << ans[b-1] << endl;
    }
    return 0;
}