/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc219/submissions/50217003
 * Submitted at: 2024-02-12 09:16:27
 * Problem URL: https://atcoder.jp/contests/abc219/tasks/abc219_c
 * Result: AC
 * Execution Time: 71 ms
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
    
    string x; cin >> x;
    vector<int> p(26);
    rep(i,x.size()) p[x[i]-'a'] = i;

    ll n; cin >> n;
    vector<string> s(n);
    rep(i, n) cin >> s[i];
    sort(s.begin(), s.end(), [&](string a, string b) {
        // X の辞書順でソート
        rep(i,min(a.size(),b.size())) {
            if( a[i] == b[i] ) continue;
            return p[a[i]-'a'] < p[b[i]-'a'];
        }
        return a.size() < b.size();
    });
    rep(i,n) cout << s[i] << endl;
    
    return 0;
}