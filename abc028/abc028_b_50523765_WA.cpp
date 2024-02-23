/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc028/submissions/50523765
 * Submitted at: 2024-02-23 09:02:00
 * Problem URL: https://atcoder.jp/contests/abc028/tasks/abc028_b
 * Result: WA
 * Execution Time: 6 ms
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
    vector<ll> cnt(6,0);
    rep(i,s.size()) cnt[s[i]-'A']++;
    rep(i,6) cout << cnt[i] << " ";
    cout << endl;
    
    return 0;
}