/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/54408783
 * Submitted at: 2024-06-09 21:40:57
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_f
 * Result: AC
 * Execution Time: 255 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

// S:実 F:遅延
using S = struct {
  ll size;
  ll val;
};
using F = ll;
// operator (作用素)
S op(S l,S r) {
  return {l.size+r.size, l.val+r.val};
}
// 遅延データ反映
S mapping(F f,S x) {
  return {x.size, x.val+f*x.size};
}
// 遅延データ作用 ※ f(g(x))
F composition(F f,F g) {
  return f+g;
}
S e() { return {0, 0}; } // 単位元 (op(e, a) = op(a, e) = a)
F id() { return 0; } // 恒等写像 (mapping(id, a) = a)

struct query {
	ll t, l, r, x, i, j;
};

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	// 解説AC : Query3 て必要になる過去の Query2 の答えを適切に保持する
	// 雑に過去の 2 の時の状態を保持すると O(QM) だが、Query3 が最大で Q 個しかない
	// ⇒ うまく管理すれば過去との差分は O(Q) で済むはず
	// ⇒ クエリ先読みで更新すべき場所を先に精査

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

	lazy_segtree<S, op, e, F, mapping, composition, id> seg(m);
	rep(i, m) seg.set(i, {1, 0});
	map<P, ll> pre2;
	rep(now, q) {
		auto query = queries[now];
		// cerr << "query: " << query.t << " " << query.l << " " << query.r << " " << query.x << " " << query.i << " " << query.j << endl;
		if(query.t == 1) {
			seg.apply(query.l, query.r, query.x);
		}
		else if(query.t == 2) {
			// cerr << "update: " << query.i << " " << query.x << endl;
			for(auto j : q2_update_j[now]) {
				// cerr << "update: " << j << " " << seg.get(j).val << " " << query.x << endl;
				pre2[P(query.i, j)] = query.x - seg.get(j).val;
			}
		}
		else {
			// cerr << "output: " << seg.get(query.j).val << " " << pre2[P(query.i, query.j)] << endl;
			cout << seg.get(query.j).val + pre2[P(query.i, query.j)] << endl;
		}
	}
	
	return 0;
}