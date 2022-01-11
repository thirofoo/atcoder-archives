/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28460256
 * Submitted at: 2022-01-11 13:31:04
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bz
 * Result: TLE
 * Execution Time: 2205 ms
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
    int n,m,ans = 0; cin >> n >> m;
    multiset<int> edge;
    rep(i,m){
        int a,b; cin >> a >> b;
        edge.insert(max(a,b));
    }
    for(auto k:edge){
        if(edge.count(k) == 1)ans++;
    }
    cout << ans << endl;
    return 0;
}