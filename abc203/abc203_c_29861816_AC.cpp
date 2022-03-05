/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc203/submissions/29861816
 * Submitted at: 2022-03-05 20:11:51
 * Problem URL: https://atcoder.jp/contests/abc203/tasks/abc203_c
 * Result: AC
 * Execution Time: 221 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,k; cin >> n >> k;
    map<ll,ll> friends;
    rep(i,n){
        ll a,b; cin >> a >> b;
        friends[a] += b;
    }
    ll ans = 0;
    for(auto u:friends){
        if(u.first > k+ans)return cout << ans+k << '\n',0;
        k -= u.first;
        k += u.second;
        ans += u.first;
    }
    cout << ans+k << '\n';
    return 0;
}