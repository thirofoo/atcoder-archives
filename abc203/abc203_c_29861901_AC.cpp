/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc203/submissions/29861901
 * Submitted at: 2022-03-05 20:15:55
 * Problem URL: https://atcoder.jp/contests/abc203/tasks/abc203_c
 * Result: AC
 * Execution Time: 217 ms
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
    for(auto u:friends){
        if(u.first > k)return cout << k << '\n',0;
        k += u.second;
    }
    cout << k << '\n';
    return 0;
}