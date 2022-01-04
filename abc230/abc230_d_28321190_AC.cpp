/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc230/submissions/28321190
 * Submitted at: 2022-01-04 16:54:17
 * Problem URL: https://atcoder.jp/contests/abc230/tasks/abc230_d
 * Result: AC
 * Execution Time: 129 ms
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
    ll n,d,ans = 0; cin >> n >> d;
    vector<P> wall(0);
    rep(i,n){
        ll a,b; cin >> a >> b;
        wall.push_back(P(a,b));
    }
    sort(wall.begin(),wall.end(),[](pair<ll,ll> a,pair<ll,ll> b){
        return a.second < b.second;
    });
    ll left = 0,right = 0;
    while(right < n){
        while(right < n && wall[right].first-wall[left].second < d)right++;
        left = right;
        ans++;
    }
    cout << ans << endl;
    return 0;
}