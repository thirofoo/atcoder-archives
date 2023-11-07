/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc300/submissions/47349768
 * Submitted at: 2023-11-07 14:24:24
 * Problem URL: https://atcoder.jp/contests/abc300/tasks/abc300_e
 * Result: AC
 * Execution Time: 9 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    map<ll, mint> mp;
    mp[1] = 1;
    mint inv = mint{1} / 5;
    for(auto [key,value]:mp) {
        for(ll i=2; i<=6; i++) {
            if( key*i > n ) continue;
            mp[key*i] += value / 5;
        }
    }
    cout << mp[n].val() << endl;
    
    return 0;
}