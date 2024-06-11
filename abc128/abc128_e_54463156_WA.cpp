/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc128/submissions/54463156
 * Submitted at: 2024-06-12 00:58:07
 * Problem URL: https://atcoder.jp/contests/abc128/tasks/abc128_e
 * Result: WA
 * Execution Time: 442 ms
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
	
	ll n, q; cin >> n >> q;
	vector<ll> s(n), t(n), x(n), comp;
	rep(i, n) {
		cin >> s[i] >> t[i] >> x[i];
		comp.emplace_back(s[i] - x[i]);
		comp.emplace_back(t[i] - x[i]);
	}
	sort(comp.begin(), comp.end());
	comp.erase(unique(comp.begin(), comp.end()), comp.end());
	vector<vector<ll>> start(comp.size()), end(comp.size());
	rep(i, n) {
		s[i] = lower_bound(comp.begin(), comp.end(), s[i] - x[i]) - comp.begin();
		t[i] = lower_bound(comp.begin(), comp.end(), t[i] - x[i]) - comp.begin();
		start[s[i]].emplace_back(i);
		end[t[i]].emplace_back(i);
	}
	multiset<ll> st;
	vector<ll> ans(comp.size(), -1);
	rep(i, comp.size()) {
		for(auto &&j : start[i]) st.insert(x[j]);
		for(auto &&j : end[i]) st.erase(st.find(x[j]));
		if(st.empty()) continue;
		ans[i] = *st.begin();
	}
	rep(i, q) {
		ll d; cin >> d;
		d = lower_bound(comp.begin(), comp.end(), d) - comp.begin();
		if(d == comp.size()) cout << -1 << endl;
		else cout << ans[d] << endl;
	}
	
	return 0;
}