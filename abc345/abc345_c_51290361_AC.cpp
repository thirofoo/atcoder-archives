/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc345/submissions/51290361
 * Submitted at: 2024-03-16 21:10:01
 * Problem URL: https://atcoder.jp/contests/abc345/tasks/abc345_c
 * Result: AC
 * Execution Time: 4 ms
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
    rep(i,s.size()) cnt[s[i]-'a']++;
    ll ans = s.size()*(s.size()-1)/2;
    ll add = 0;
    rep(i,26) {
        ans -= cnt[i]*(cnt[i]-1)/2;
        if( cnt[i] >= 2 ) add = 1;
    }
    cout << ans + add << endl;
    
    return 0;
}