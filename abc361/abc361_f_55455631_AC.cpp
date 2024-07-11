/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc361/submissions/55455631
 * Submitted at: 2024-07-11 18:50:45
 * Problem URL: https://atcoder.jp/contests/abc361/tasks/abc361_f
 * Result: AC
 * Execution Time: 88 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	ll n; cin >> n;
	vector<ll> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
	ll size = primes.size();

	auto check = [&](ll num, ll r) -> ll {
		ll res = 1;
		rep(i, r) {
			if(res > n / num) return INF;
			res *= num;
		}
		return res;
	};
	
	ll ans = 1;
	rep(i, (1LL << size)) {
		if(i == 0) continue;
		ll now = 1;
		rep(j, size) {
			if(!((1LL << j) & i)) continue;
			if(now > n / primes[j]) {
				now = INF;
				break;
			}
			now *= primes[j];
		}
		if(now == INF) continue;

		ll left = 1, right = INF;
		while(right - left > 1) {
			ll mid = (left + right) / 2;
			if(check(mid, now) <= n) left = mid;
			else right = mid;
		}
		if(left == 1) continue;
		if(__builtin_popcount(i) % 2 == 0) ans -= left-1;
		else ans += left-1;
	}
	cout << ans << '\n';
	
	return 0;
}