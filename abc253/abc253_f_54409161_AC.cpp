/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/54409161
 * Submitted at: 2024-06-09 21:53:44
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_f
 * Result: AC
 * Execution Time: 189 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, n) for(ll i = 0; i < n; i++)

struct query {
	ll t, l, r, x, i, j;
};

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// 解説AC O(QlogM)
	// 1. Query1 を lazy_segment_tree や fenwick_tree で管理
	// 2. Query2 で保持すべきグリッドの情報の j をクエリ先読みで精査すると均し O(Q)
	// 3. Query3 で 2 で蓄えた情報との差分で求める

	ll n, m, q; cin >> n >> m >> q;
	vector<query> queries(q);
	vector<ll> i_latest_q2id(n, -1);
	vector<vector<ll>> q2_update_j(q, vector<ll>{});
	rep(id, q) {
		ll t; cin >> t;
		if(t == 1) {
			ll l, r, x; cin >> l >> r >> x; l--;
			queries[id] = {t, l, r, x, -1, -1};
		}
		else if(t == 2) {
			ll i, x; cin >> i >> x; i--;
			queries[id] = {t, -1, -1, x, i, -1};
			i_latest_q2id[i] = id;
		}
		else {
			ll i, j; cin >> i >> j; i--; j--;
			queries[id] = {t, -1, -1, -1, i, j};
			if(i_latest_q2id[i] == -1) continue;
			q2_update_j[i_latest_q2id[i]].emplace_back(j);
		}
	}

	fenwick_tree<ll> fw(m+1);
	map<P, ll> pre2;
	rep(now, q) {
		auto query = queries[now];
		if(query.t == 1) {
			fw.add(query.l,  query.x);
			fw.add(query.r, -query.x);
		}
		else if(query.t == 2) {
			for(auto j : q2_update_j[now]) {
				pre2[P(query.i, j)] = query.x - fw.sum(0, j+1);
			}
		}
		else {
			ll ans = fw.sum(0, query.j+1) + pre2[P(query.i, query.j)];
			cout << ans << endl;
		}
	}
	
	return 0;
}