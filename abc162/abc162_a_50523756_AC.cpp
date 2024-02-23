/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc162/submissions/50523756
 * Submitted at: 2024-02-23 09:00:46
 * Problem URL: https://atcoder.jp/contests/abc162/tasks/abc162_a
 * Result: AC
 * Execution Time: 2 ms
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
    bool f = false;
    rep(i,s.size()) f |= (s[i] == '7');
    cout << (f ? "Yes" : "No") << endl;
    
    return 0;
}