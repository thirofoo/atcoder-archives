/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc305/submissions/53022885
 * Submitted at: 2024-05-02 18:37:27
 * Problem URL: https://atcoder.jp/contests/abc305/tasks/abc305_b
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

vector<ll> v = {0,3,4,8,9,14,23};

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	char p, q; cin >> p >> q;
	cout << abs(v[p-'A']-v[q-'A']) << endl;
	
	return 0;
}