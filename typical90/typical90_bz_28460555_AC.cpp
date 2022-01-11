/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28460555
 * Submitted at: 2022-01-11 14:02:38
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bz
 * Result: AC
 * Execution Time: 64 ms
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
    vector<int> edge(n,0);
    rep(i,m){
        int a,b; cin >> a >> b;
        edge[max(a,b)-1]++;
    }
    rep(i,n)if(edge[i] == 1)ans++;
    cout << ans << endl;
    return 0;
}