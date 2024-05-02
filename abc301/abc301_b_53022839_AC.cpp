/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc301/submissions/53022839
 * Submitted at: 2024-05-02 18:35:46
 * Problem URL: https://atcoder.jp/contests/abc301/tasks/abc301_b
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
	
	ll n; cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	rep(i,n-1) {
		cout << a[i] << " ";
		vector<ll> ans;
		reps(j,min(a[i],a[i+1])+1, max(a[i],a[i+1])) ans.emplace_back(j);
		if(a[i] > a[i+1]) reverse(ans.begin(), ans.end());
		for(auto x: ans) cout << x << " ";	
	}
	cout << a[n-1] << endl;
	
	return 0;
}