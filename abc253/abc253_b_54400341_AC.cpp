/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/54400341
 * Submitted at: 2024-06-09 16:18:11
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_b
 * Result: AC
 * Execution Time: 1 ms
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
	
	ll h, w; cin >> h >> w;
	vector<string> s(h);
	rep(i,h) cin >> s[i];
	ll x1 = -1, y1 = -1, x2 = -1, y2 = -1;
	rep(i,h) rep(j,w) {
		if(s[i][j] == 'o') {
			if(x1 == -1) x1 = i, y1 = j;
			else x2 = i, y2 = j;
		}
	}
	cout << abs(x1-x2) + abs(y1-y2) << endl;
	
	return 0;
}