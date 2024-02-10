/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc340/submissions/50151309
 * Submitted at: 2024-02-10 21:09:05
 * Problem URL: https://atcoder.jp/contests/abc340/tasks/abc340_c
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    map<ll,ll> mp;
    mp[0] = 0, mp[1] = 0;
    ll ans = 0;
    auto f = [&](auto self, ll now) -> ll {
        if( mp.count(now) ) return mp[now];
        ll res = 0;
        if( now%2 == 0 ) {
            res += self(self,now/2);
            res += self(self,now/2);
        }
        else {
            res += self(self,now/2);
            res += self(self,now/2+1);
        }
        res += now;
        mp[now] = res;
        return res;
    };
    cout << f(f,n) << endl;
    
    return 0;
}