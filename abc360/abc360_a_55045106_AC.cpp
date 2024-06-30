/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc360/submissions/55045106
 * Submitted at: 2024-06-30 21:01:21
 * Problem URL: https://atcoder.jp/contests/abc360/tasks/abc360_a
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    rep(i, s.size()) {
        if(s[i] == 'R') {
            cout << "Yes" << endl;
            return 0;
        }
        if(s[i] == 'M') {
            cout << "No" << endl;
            return 0;
        }
    }
    
    return 0;
}