/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc338/submissions/49692289
 * Submitted at: 2024-01-27 21:01:59
 * Problem URL: https://atcoder.jp/contests/abc338/tasks/abc338_b
 * Result: AC
 * Execution Time: 1 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    vector<ll> cnt(26,0);
    rep(i,s.size()) cnt[s[i]-'a']++;
    ll ans = 0, max_cnt = 0;
    rep(i,26) {
        if(cnt[i] > max_cnt) {
            max_cnt = cnt[i];
            ans = i;
        }
    }
    cout << char(ans+'a') << endl;
    
    return 0;
}