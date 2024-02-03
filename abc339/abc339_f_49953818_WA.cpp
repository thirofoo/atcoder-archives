/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc339/submissions/49953818
 * Submitted at: 2024-02-03 21:57:30
 * Problem URL: https://atcoder.jp/contests/abc339/tasks/abc339_f
 * Result: WA
 * Execution Time: 711 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll mod = 1000000007;

// hash で管理する
ll makeHash(string s) {
    ll res = 0;
    for(char c : s) {
        res *= 10;
        res += c - '0';
        res %= mod;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<string> a(n);
    vector<ll> hash_a(n);
    map<ll, ll> mp;
    rep(i,n) {
        cin >> a[i];
        hash_a[i] = makeHash(a[i]);
        mp[hash_a[i]]++;
    }
    ll ans = 0;
    rep(i,n) rep(j,n) {
        ll cand_hash = (hash_a[i] * hash_a[j]) % mod;
        ans += mp[cand_hash];
    }
    cout << ans << endl;
    
    return 0;
}