/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc339/submissions/49995484
 * Submitted at: 2024-02-04 17:05:34
 * Problem URL: https://atcoder.jp/contests/abc339/tasks/abc339_f
 * Result: AC
 * Execution Time: 985 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

constexpr int B = 3;
ll mod[B] = {998244353, 1000000007, 1000000009};
vector<ll> makeHash(const string &s) {
    vector<ll> res(B, 0);
    rep(i,B) for(const char &c : s) res[i] = (res[i] * 10 + c - '0') % mod[i];
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // hash の衝突の可能性あり
    // → 複数の hash を管理してその vector を hash として考えれば全ての hash が衝突する確率は≈0
    ll n; cin >> n;
    vector<string> a(n);
    map<vector<ll>, ll> mp;
    vector<vector<ll>> hash_a(n);
    rep(i,n) {
        cin >> a[i];
        hash_a[i] = makeHash(a[i]);
        mp[hash_a[i]]++;
    }
    ll ans = 0;
    vector<ll> cand_hash;
    rep(i,n) rep(j,n) {
        cand_hash.assign(B, 0);
        rep(k,B) cand_hash[k] = (hash_a[i][k] * hash_a[j][k]) % mod[k];
        ans += mp[cand_hash];
    }
    cout << ans << endl;
    
    return 0;
}
