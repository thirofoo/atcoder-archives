/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/zone2021/submissions/54410757
 * Submitted at: 2024-06-09 22:46:44
 * Problem URL: https://atcoder.jp/contests/zone2021/tasks/zone2021_c
 * Result: TLE
 * Execution Time: 2210 ms
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
	
	ll n; cin >> n;
	vector<vector<ll>> p(n, vector<ll>(5));
	rep(i, n) rep(j,5) cin >> p[i][j];
	// power_min[i][j] := 各人の i の bit が立ってる能力の最小値と idx
	vector<vector<P>> power_min(1LL << 5, vector<P>{});
	rep(i, 1LL << 5) rep(j, n) {
		ll min_p = INF;
		rep(k, 5) if(i & (1LL << k)) min_p = min(min_p, p[j][k]);
		power_min[i].emplace_back(P(min_p, j));
	}
	rep(i, 1LL << 5) sort(power_min[i].begin(), power_min[i].end());
	ll ans = 0;
	rep(i, n) reps(j, i+1, n) {
		vector<ll> now_p(5, 0);
		rep(k, 5) now_p[k] = max({p[i][k], p[j][k]});
		ll l = 0, r = INF;
		while(r - l > 1) {
			ll mid = (r + l) / 2;
			ll bit = 0;
			rep(k, 5) if(now_p[k] < mid) bit |= (1LL << k);
			auto itr = lower_bound(power_min[bit].begin(), power_min[bit].end(), P(mid, -1));
			while(itr != power_min[bit].end() && ((*itr).first == i || (*itr).first == j)) itr++;
			if(itr != power_min[bit].end()) l = mid;
			else r = mid;
		}
		ans = max(ans, l);
	}
	cout << ans << endl;
	
	return 0;
}