/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc219/submissions/50216945
 * Submitted at: 2024-02-12 09:06:58
 * Problem URL: https://atcoder.jp/contests/abc219/tasks/abc219_c
 * Result: WA
 * Execution Time: 74 ms
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
    ll n; cin >> n;
    vector<string> s(n);
    vector<pair<string, int>> t;
    rep(i, n) {
        cin >> s[i];
        string ts = "";
        rep(j,s[i].size()) ts += x[s[i][j]-'a'];
        t.emplace_back(pair{ts, i});
    }
    sort(t.begin(), t.end(), [&](auto a, auto b) {
        if( a.first.size() == b.first.size() ) return a.first < b.first;
        return a.first.size() < b.first.size();
    });
    rep(i,n) cout << s[t[i].second] << endl;
    
    return 0;
}