/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc339/submissions/50524882
 * Submitted at: 2024-02-23 10:44:59
 * Problem URL: https://atcoder.jp/contests/abc339/tasks/abc339_f
 * Result: AC
 * Execution Time: 136 ms
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

vector<ll> mod = {1000000007, 998244353, 1000000009};
vector<ll> str_hash(const string &s) {
    ll n = s.size();
    vector<ll> res(3,0);
    rep(i,3) rep(j,n) {
        res[i] *= 10;
        res[i] += (s[j] - '0');
        res[i] %= mod[i];
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<string> s(n);
    vector<vector<ll>> hash;
    map<vector<ll>, ll> hs;
    rep(i, n) {
        cin >> s[i];
        hash.emplace_back(str_hash(s[i]));
        hs[hash[i]]++;
    }
    ll ans = 0;
    vector<ll> h1(3), h2(3), h3(3);
    rep(i, n) rep(j,n) {
        rep(k, 3) h3[k] = (hash[i][k] * hash[j][k]) % mod[k];
        if( hs.count(h3) ) ans += hs[h3];
    }
    cout << ans << endl;
    
    return 0;
}