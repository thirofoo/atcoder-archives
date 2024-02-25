/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc342/submissions/50637291
 * Submitted at: 2024-02-25 19:03:23
 * Problem URL: https://atcoder.jp/contests/abc342/tasks/abc342_f
 * Result: AC
 * Execution Time: 14 ms
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
    
	ll n, l, d; cin >> n >> l >> d;
	vector<ld> dealer(n+d+1, 0.0);
	dealer[0] = 1.0;
	rep(i,n+d) {
		if( i < l ) {
			ld np = dealer[i] / d;
			dealer[i+1] += np;
			dealer[i+d+1] -= np;
		}
		if( i != 0 ) dealer[i+1] += dealer[i];
	}
	rep(i,n+d+1) {
		if( i != 0 ) dealer[i] += dealer[i-1];
		if( i < l ) dealer[i] = 0.0;
	}
	ld pre_d_sum = 0.0;
	vector<ld> dp(n+d+1, 0.0);
	for(ll i=n; i>=0; i--) {
		dp[i] = max(dp[i], ( i == 0 ? 0.0 : dealer[i-1] ) + dealer[n+d]-dealer[n]);
		dp[i] = max(dp[i], pre_d_sum / d);
		pre_d_sum += dp[i] - dp[i+d];
	}
	cout << setprecision(10) <<  dp[0] << endl;
    
    return 0;
}