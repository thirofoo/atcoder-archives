/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc342/submissions/50558388
 * Submitted at: 2024-02-24 21:01:16
 * Problem URL: https://atcoder.jp/contests/abc342/tasks/abc342_a
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
    
    string s; cin >> s;
    map<char, ll> mp;
    rep(i,s.size()) mp[s[i]]++;
    char ans;
    for(auto [key, value] : mp) if(value == 1) ans = key;
    rep(i,s.size()) if(s[i] == ans) cout << i+1 << endl;
    
    return 0;
}