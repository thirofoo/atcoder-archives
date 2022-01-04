/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc230/submissions/28320989
 * Submitted at: 2022-01-04 16:39:53
 * Problem URL: https://atcoder.jp/contests/abc230/tasks/abc230_d
 * Result: WA
 * Execution Time: 130 ms
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

ll inf = 9999999999999;
int main() {
    int n,d,ans = 0; cin >> n >> d;
    vector<P> wall(0);
    rep(i,n){
        ll a,b; cin >> a >> b;
        wall.push_back(P(a,b));
    }
    sort(wall.begin(),wall.end(),[](pair<ll,ll> a,pair<ll,ll> b){
        return a.second < b.second;
    });
    ll r = wall[0].second;
    rep(i,inf){
        ans++;
        if(r+d-1 < wall[i+1].first){
            r = wall[i+1].second;
            continue;
        }
        while(i+1 != n && r+d-1 >= wall[i+1].first)i++;
        if(i+1 == n)break;
        r = wall[i].second;
    }
    cout << ans << endl;
    return 0;
}