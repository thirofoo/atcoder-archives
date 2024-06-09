/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/zone2021/submissions/54411763
 * Submitted at: 2024-06-09 23:27:26
 * Problem URL: https://atcoder.jp/contests/zone2021/tasks/zone2021_c
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	// 模範解答 ver
	// point: 決め打ち二分探索する時、各能力が特定の値以上かは、2^{能力数} 通りしか存在しない
	// ⇒ 全てを列挙した後に、3 個全探索すれば行ける（天才過ぎ）
	ll n; cin >> n;
	constexpr ll ABILITY = 5;
	vector p(n, vector<ll>(ABILITY));
	rep(i, n) rep(j, ABILITY) cin >> p[i][j];
	
	auto check = [&](ll x) -> bool {
		set<ll> s;
		rep(i, n) {
			ll bit = 0;
			rep(j, ABILITY) {
				if(p[i][j] >= x) bit |= (1LL << j);
			}
			s.insert(bit);
		}
		// 3 個以下の能力で全能力閾値以上になるか否か
		for(auto &&b1 : s) for(auto &&b2 : s) for(auto &&b3 : s) {
			if((b1 | b2 | b3) == (1LL << ABILITY)-1) return true;
		}
		return false;
	};

	ll left = 0, right = INF;
	while(right-left > 1) {
		ll mid = (right+left) / 2;
		if(check(mid)) left = mid;
		else right = mid;
	}
	cout << left << '\n';
	
	return 0;
}