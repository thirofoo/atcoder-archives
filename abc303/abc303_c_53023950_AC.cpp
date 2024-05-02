/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc303/submissions/53023950
 * Submitted at: 2024-05-02 19:21:31
 * Problem URL: https://atcoder.jp/contests/abc303/tasks/abc303_c
 * Result: AC
 * Execution Time: 129 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

// right | down | left | up
map<char, P> dir = {{'R', { 1, 0}}, {'D', { 0, -1}}, {'L', {-1, 0}}, {'U', { 0, 1}}};

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	ll n, m, h, k; cin >> n >> m >> h >> k;
	string s; cin >> s;
	set<P> st;
	rep(i,m) {
		ll x, y; cin >> x >> y;
		st.insert({x, y});
	}

	ll now_x = 0, now_y = 0;
	rep(i,n) {
		auto [dx,dy] = dir[s[i]];
		if( h == 0 ) return cout << "No" << endl, 0;
		now_x += dx, now_y += dy;
		h--;
		if( st.count({now_x, now_y}) && h < k ) {
			st.erase({now_x, now_y});
			h = k;
		}
	}
	cout << "Yes" << endl;
	
	return 0;
}