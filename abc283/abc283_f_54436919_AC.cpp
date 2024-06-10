/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc283/submissions/54436919
 * Submitted at: 2024-06-10 23:57:55
 * Problem URL: https://atcoder.jp/contests/abc283/tasks/abc283_f
 * Result: AC
 * Execution Time: 108 ms
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

// SegTree に乗せる型
using S = ll;
// operator (作用素)
S op(S l, S r) {
	return min(l, r);
}
// 単位元 (op(e, a) = a)
S e() {
	return INF;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	// 解説AC : 絶対値 2 つくらいなら展開して 4 通り列挙する
	// ⇒ 同じ添え字でまとめると 2 変数の最小化問題になる
	// ⇒ Segment Tree で管理してシミュレーション
	ll n; cin >> n;
	vector<ll> p(n), ans(n, INF);
	rep(i, n) cin >> p[i];

	auto f = [&]() -> void {
		segtree<S, op, e> sg(n+1);
		rep(i,n) {
			ans[i] = min(ans[i], p[i] + i + sg.prod(0, p[i]));
			sg.set(p[i], -(p[i] + i));
		}
	};

	// 関数化して 4 通り列挙することも可能
	// i, j の大小の反転は reverse で対応 ⇒ 分かる
	// p_i, p_j の大小の反転は p = n + 1 - p で対応 ⇒ 分からん
	// ※ ⇑ のように置き換えても答えが変わらないことは証明出来るが天才すぎて参考にならない
	f();
	
	rep(i, n) p[i] = n + 1 - p[i];
	f();

	reverse(p.begin(), p.end());
	reverse(ans.begin(), ans.end());
	f();

	rep(i, n) p[i] = n + 1 - p[i];
	f();

	reverse(ans.begin(), ans.end());
	rep(i, n) cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}