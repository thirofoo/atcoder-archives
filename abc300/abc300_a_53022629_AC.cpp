/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc300/submissions/53022629
 * Submitted at: 2024-05-02 18:27:45
 * Problem URL: https://atcoder.jp/contests/abc300/tasks/abc300_a
 * Result: AC
 * Execution Time: 1 ms
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
	
	ll n, a, b; cin >> n >> a >> b;
	vector<ll> c(n);
	rep(i,n) cin >> c[i];
	rep(i,n) {
		if( a+b == c[i] ) return cout << i+1 << endl, 0;
	}
	
	return 0;
}