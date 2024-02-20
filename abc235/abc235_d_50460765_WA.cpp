/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc235/submissions/50460765
 * Submitted at: 2024-02-20 09:49:53
 * Problem URL: https://atcoder.jp/contests/abc235/tasks/abc235_d
 * Result: WA
 * Execution Time: 34 ms
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
    
    ll a, n; cin >> a >> n;
    vector<bool> vis(10000005, false);
    vector<ll> num(10000005, 1e9);
    num[1] = 0;
    
    auto dfs = [&](auto dfs, ll x) -> void {
        if( vis[x] ) return;
        vis[x] = true;
        ll nx = x/a;
        if( x%a == 0 ) {
            dfs(dfs, nx);
            num[x] = min(num[x], num[nx]+1);
        }
        if( x < 10 ) return;

        ll digit = 0, tx = x;
        while( tx ) digit++, tx /= 10;
        nx = x%(ll)pow(10, digit-1)*10 + x/pow(10, digit-1);
        dfs(dfs, nx);
        num[x] = min(num[x], num[nx]+1);

        return;
    };
    dfs(dfs, n);
    cout << (num[n] != 1e9 ? num[n] : -1) << endl;
    
    return 0;
}