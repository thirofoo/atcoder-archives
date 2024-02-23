/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc008/submissions/50523803
 * Submitted at: 2024-02-23 09:08:08
 * Problem URL: https://atcoder.jp/contests/abc008/tasks/abc008_2
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
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    map<string, ll> mp;
    string ans = "";
    ll max_cnt = 0;
    rep(i, n) {
        string s; cin >> s;
        mp[s]++;
        if (mp[s] > max_cnt) {
            max_cnt = mp[s];
            ans = s;
        }
    }
    cout << ans << endl;
    
    return 0;
}