/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/54400973
 * Submitted at: 2024-06-09 16:37:57
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_e
 * Result: AC
 * Execution Time: 21 ms
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
	
	ll n, m, k; cin >> n >> m >> k;
	if(k == 0) {
		cout << mint(m).pow(n).val() << endl;
		return 0;
	}
	vector<vector<mint>> dp(n+1, vector<mint>(m+1, 0));
	rep(i, m+1) dp[0][i] = 1;
	reps(i, 1, n+1) {
		reps(j, 1, m+1) {
			dp[i][j] = dp[i-1].back() - (dp[i-1][min(j+k-1, m)] - dp[i-1][max(j-k, 0LL)]);
			dp[i][j] += dp[i][j-1];
		}
	}
	cout << dp[n][m].val() << endl;
	
	return 0;
}