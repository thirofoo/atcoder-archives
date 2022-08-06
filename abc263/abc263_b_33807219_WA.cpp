/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc263/submissions/33807219
 * Submitted at: 2022-08-06 21:06:23
 * Problem URL: https://atcoder.jp/contests/abc263/tasks/abc263_b
 * Result: WA
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> p(n,0);
    rep(i,n-1)cin >> p[i+1];
    int now = n-1,ans = 0;
    while(now != 0){
        ans++;
        now = p[now-1];
    }
    cout << ans << endl;
    
    return 0;
}