/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc302/submissions/53023658
 * Submitted at: 2024-05-02 19:08:16
 * Problem URL: https://atcoder.jp/contests/abc302/tasks/abc302_d
 * Result: WA
 * Execution Time: 98 ms
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
	
	ll n, m, d; cin >> n >> m >> d;
	vector<ll> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll ans = -1;
	rep(i,n) {
		auto it1 = lower_bound(b.begin(), b.end(), a[i]);
		if( it1 != b.end() && abs((*it1)-a[i]) <= d ) ans = max(ans, (*it1) + a[i]);
		auto it2 = upper_bound(b.begin(), b.end(), a[i]);
		if( it2 != b.end() && abs((*it2)-a[i]) <= d ) ans = max(ans, (*it2) + a[i]);
	}
	rep(i,m) {
		auto it1 = lower_bound(a.begin(), a.end(), b[i]);
		if( it1 != a.end() && abs((*it1)-b[i]) <= d ) ans = max(ans, (*it1) + b[i]);
		auto it2 = upper_bound(a.begin(), a.end(), b[i]);
		if( it2 != a.end() && abs((*it2)-b[i]) <= d ) ans = max(ans, (*it2) + b[i]);
	}
	cout << ans << endl;
	
	return 0;
}