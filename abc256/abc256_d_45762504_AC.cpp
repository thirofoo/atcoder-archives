/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/45762504
 * Submitted at: 2023-09-21 09:53:46
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_d
 * Result: AC
 * Execution Time: 63 ms
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
    
    ll n; cin >> n;
    vector<ll> cnt(200010, 0);
    rep(i,n) {
        ll l, r; cin >> l >> r;
        cnt[l]++;
        cnt[r]--;
    }
    rep(i,200010) cnt[i+1] += cnt[i];
    rep(i,200010) {
        bool f = false;
        ll left = i;
        while(cnt[i]) {
            f = true;
            i++;
        }
        if( f ) cout << left << " " << i << endl;
    }
    
    return 0;
}