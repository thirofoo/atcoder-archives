/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/54400421
 * Submitted at: 2024-06-09 16:20:52
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_c
 * Result: AC
 * Execution Time: 131 ms
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
	
	ll q; cin >> q;
	multiset<ll> st;
	while(q--) {
		ll t; cin >> t;
		if(t == 1) {
			ll x; cin >> x;
			st.insert(x);
		}
		else if(t == 2) {
			ll x, c; cin >> x >> c;
			while(c--) {
				auto itr = st.find(x);
				if(itr == st.end()) break;
				st.erase(itr);
			}
		}
		else {
			cout << *st.rbegin() - *st.begin() << endl;
		}
	}
	
	return 0;
}