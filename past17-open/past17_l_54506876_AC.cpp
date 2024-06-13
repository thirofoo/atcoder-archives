/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54506876
 * Submitted at: 2024-06-13 22:36:22
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_l
 * Result: AC
 * Execution Time: 174 ms
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
    
    ll n; cin >> n;
    // 頂点倍化したグラフで warshall_floyd 出来そう？
    vector warshall(n*2, vector<ll>(n*2, INF));
    rep(i, n) warshall[i][i+n] = 0;
    rep(i, 2*n) warshall[i][i] = 0;
    rep(i, n) reps(j, i+1, n) {
        cin >> warshall[i][j];
        warshall[j][i] = warshall[i][j];
        warshall[i+n][j+n] = warshall[i][j];
        warshall[j+n][i+n] = warshall[i][j];
    }
    rep(i, n) reps(j, i+1, n) {
        cin >> warshall[i][j+n];
        warshall[j][i+n] = warshall[i][j+n];
    }
    rep(k, 2*n) rep(i, 2*n) rep(j, 2*n) warshall[i][j] = min(warshall[i][j], warshall[i][k]+warshall[k][j]);
    rep(i, n-1) {
        reps(j, i+1, n) cout << min(warshall[i][j], warshall[i][j+n]) << " ";
        cout << endl;
    }
    
    return 0;
}