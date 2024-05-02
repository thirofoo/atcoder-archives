/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc303/submissions/53023449
 * Submitted at: 2024-05-02 18:59:22
 * Problem URL: https://atcoder.jp/contests/abc303/tasks/abc303_d
 * Result: AC
 * Execution Time: 15 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	ll x, y, z; cin >> x >> y >> z;
	string s; cin >> s;
	vector<vector<ll>> dp(s.size()+1, vector<ll>(2,1e16));
	dp[0][0] = 0, dp[0][1] = z;
	reps(i,1,s.size()+1) {
		if( s[i-1] == 'A' ) {
			dp[i][0] = min(dp[i][0], dp[i-1][0] + y);
			dp[i][1] = min(dp[i][1], dp[i-1][0] + z + x);
			dp[i][1] = min(dp[i][1], dp[i-1][1] + x);
		}
		else {
			dp[i][1] = min(dp[i][1], dp[i-1][1] + y);
			dp[i][0] = min(dp[i][0], dp[i-1][1] + z + x);
			dp[i][0] = min(dp[i][0], dp[i-1][0] + x);
		}
		dp[i][0] = min(dp[i][0], dp[i][1] + z);
		dp[i][1] = min(dp[i][1], dp[i][0] + z);
	}
	cout << min(dp[s.size()][0], dp[s.size()][1]) << endl;
	
	return 0;
}