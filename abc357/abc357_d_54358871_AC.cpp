/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc357/submissions/54358871
 * Submitted at: 2024-06-08 21:44:22
 * Problem URL: https://atcoder.jp/contests/abc357/tasks/abc357_d
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
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string n; cin >> n;
    // 等比数列の総和
    ll dig = n.size();
    vector<mint> doubling(62, 1);
    rep(i, dig) doubling[0] *= 10;
    reps(i,1,62) doubling[i] = doubling[i-1] * doubling[i-1];
    cerr << "doubling[0]: " << doubling[0].val() << endl;
    mint r = 1;
    ll n_num = stoll(n);
    rep(i,62) if(n_num & (1LL << i)) r *= doubling[i];

    mint ans = 0;
    rep(i,n.size()) {
        mint a = n[n.size()-(i+1)] - '0';
        rep(j,i) a *= 10;
        ans += a * (r - 1) / (doubling[0] - 1);
    }
    cout << ans.val() << endl;
    
    return 0;
}