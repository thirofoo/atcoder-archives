/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/54400560
 * Submitted at: 2024-06-09 16:25:10
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_d
 * Result: AC
 * Execution Time: 4 ms
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
	
	ll n, a, b; cin >> n >> a >> b;
	ll gcd = __gcd(a, b);
	ll ac = n/a, bc = n/b, abc = n/(a*b/gcd);
	ll a_sum = (a + (a + (ac-1)*a)) * ac / 2;
	ll b_sum = (b + (b + (bc-1)*b)) * bc / 2;
	ll ab_sum = (a*b/gcd + (a*b/gcd + (abc-1)*a*b/gcd)) * abc / 2;
	ll total_sum = (1 + n) * n / 2;
	cout << total_sum - a_sum - b_sum + ab_sum << endl;
	
	return 0;
}