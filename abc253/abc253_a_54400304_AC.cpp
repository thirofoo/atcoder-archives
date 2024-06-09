/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/54400304
 * Submitted at: 2024-06-09 16:16:54
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_a
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
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	ll a, b, c; cin >> a >> b >> c;
	cout << ((a <= b && b <= c) || (c <= b && b <= a) ? "Yes" : "No") << endl;
	
	return 0;
}