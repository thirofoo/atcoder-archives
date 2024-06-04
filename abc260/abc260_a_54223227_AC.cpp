/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc260/submissions/54223227
 * Submitted at: 2024-06-04 16:55:16
 * Problem URL: https://atcoder.jp/contests/abc260/tasks/abc260_a
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
    rep(i,s.size()) {
        ll cnt = 0;
        rep(j,s.size()) {
            if(s[j] == s[i]) cnt++;
        }
        if(cnt == 1) {
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    
    return 0;
}