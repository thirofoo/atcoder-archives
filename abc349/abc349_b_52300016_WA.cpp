/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc349/submissions/52300016
 * Submitted at: 2024-04-13 21:04:40
 * Problem URL: https://atcoder.jp/contests/abc349/tasks/abc349_b
 * Result: WA
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
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
    vector<ll> cnt(26,0);
    for(auto c : s) cnt[c-'a']++;
    vector<ll> ans(s.size()+1, 0);
    rep(i,26) ans[cnt[i]]++;
    reps(i,1,s.size()) {
        if( ans[i] != 0 && ans[i] != 2 ){
            // cerr << i << " " << ans[i] << endl;
            return cout << "No" << endl, 0;
        }
    }
    cout << "Yes" << endl;
    
    return 0;
}