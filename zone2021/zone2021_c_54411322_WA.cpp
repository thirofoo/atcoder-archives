/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/zone2021/submissions/54411322
 * Submitted at: 2024-06-09 23:09:07
 * Problem URL: https://atcoder.jp/contests/zone2021/tasks/zone2021_c
 * Result: WA
 * Execution Time: 412 ms
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
	reps(i, 1, 1LL << 5) rep(j, n) {
		ll min_p = INF;
		rep(k, 5) if(i & (1LL << k)) min_p = min(min_p, p[j][k]);
		power_min[i].emplace_back(P(min_p, j));
	}
	reps(i, 1, 1LL << 5) sort(power_min[i].begin(), power_min[i].end());
	ll ans = 0;
	rep(i, n) reps(j, i+1, n) {
		vector<P> power;
		rep(k, 5) {
			power.emplace_back(P(max(p[i][k], p[j][k]), k));
		}
		sort(power.begin(), power.end());
		ll bit = 0;
		rep(k, 5) {
			auto &[pv, idx] = power[k];
			auto [nv, _] = (k == 4 ? P(INF, INF) : power[k+1]);
			bit |= (1LL << idx);
			auto itr = power_min[bit].end(); itr--, itr--;
			while(itr != power_min[bit].end() && ((*itr).second == i || (*itr).second == j)) itr++;
			if(itr != power_min[bit].end()) ans = max(ans, min(nv, (*itr).first));
		}
	}
	cout << ans << endl;
	
	return 0;
}