/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc339/submissions/49960063
 * Submitted at: 2024-02-03 22:13:48
 * Problem URL: https://atcoder.jp/contests/abc339/tasks/abc339_f
 * Result: WA
 * Execution Time: 385 ms
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

constexpr int B = 5;
int mod[B] = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};

// hash で管理する
vector<ll> makeHash(string &s) {
    vector<ll> res(B);
    rep(i,B) {
        ll v = 0;
        for(char &c : s) {
            v *= 10;
            v += c - '0';
            v %= mod[i];
        }
        res[i] = v;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<string> a(n);
    vector<vector<ll>> hash_a(n);
    vector<map<ll, ll>> mp(B);
    rep(i,n) {
        cin >> a[i];
        hash_a[i] = makeHash(a[i]);
        rep(j,B) mp[j][hash_a[i][j]]++;
    }
    ll ans = 0;
    rep(i,n) rep(j,n) {
        vector<ll> cnt(B,0);
        bool f = true;
        rep(k,B) {
            ll cand_hash = (hash_a[i][k] * hash_a[j][k]) % mod[k];
            if( !mp[k].count(cand_hash) ) {
                f = false;
                break;
            }
            cnt[k] = mp[k][cand_hash];
        }
        rep(k,B-1) f &= (cnt[k] == cnt[k+1]);
        if( f ) ans += cnt[0];
    }
    cout << ans << endl;
    
    return 0;
}