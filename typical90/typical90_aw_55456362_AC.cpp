/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/55456362
 * Submitted at: 2024-07-11 19:25:13
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_aw
 * Result: AC
 * Execution Time: 25 ms
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
	
	ll n, m; cin >> n >> m;
	vector<tuple<ll, ll, ll>> items;
	rep(i, m) {
		ll c, l, r; cin >> c >> l >> r;
		items.emplace_back(tuple(c, l-1, r));
	}
	sort(items.begin(), items.end());

	dsu uf(n+1);
	ll ans = 0;
	rep(i, m) {
		auto [c, l, r] = items[i];
		if(uf.same(l, r)) continue;
		uf.merge(l, r);
		ans += c;
	}
	cout << (uf.size(0) == n+1 ? ans : -1) << '\n';
	
	return 0;
}