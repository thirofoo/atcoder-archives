/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc358/submissions/54566507
 * Submitted at: 2024-06-15 21:08:24
 * Problem URL: https://atcoder.jp/contests/abc358/tasks/abc358_c
 * Result: AC
 * Execution Time: 1 ms
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
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, m; cin >> n >> m;
    vector<string> s(n);
    vector<ll> sbit;
    rep(i, n) {
        cin >> s[i];
        ll bit = 0;
        rep(j, m) {
            if(s[i][j] == 'o') {
                bit |= (1LL << j);
            }
        }
        sbit.emplace_back(bit);
    }
    ll ans = INF;
    reps(i, 1, (1LL << n)) {
        ll pop_cnt = 0;
        ll ok = 0;
        rep(j, n) {
            if(!(i & (1LL << j))) continue;
            pop_cnt++;
            ok |= sbit[j];
        }
        if(ok == (1LL << m)-1) {
            ans = min(ans, pop_cnt);
        }
    }
    cout << ans << endl;
    
    return 0;
}