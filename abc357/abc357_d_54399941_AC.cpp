/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc357/submissions/54399941
 * Submitted at: 2024-06-09 16:04:44
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

    // 便利な関数はどんどん使うべし
    ll n; cin >> n;
    ll dig = 0, tn = n;
    while(tn) {
        dig++;
        tn /= 10;
    }
    mint rd = mint(10).pow(dig);
    mint rn = rd.pow(n);
    cout << (n * (rn-1) / (rd-1)).val() << endl;
    
    return 0;
}