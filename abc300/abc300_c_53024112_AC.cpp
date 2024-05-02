/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc300/submissions/53024112
 * Submitted at: 2024-05-02 19:29:00
 * Problem URL: https://atcoder.jp/contests/abc300/tasks/abc300_c
 * Result: AC
 * Execution Time: 2 ms
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
#define DIR_NUM 4
vector<int> dx = { 1,-1, 1,-1};
vector<int> dy = { 1,-1,-1, 1};

inline bool outField(int x,int y,int h,int w) {
	if(0 <= x && x < h && 0 <= y && y < w)return false;
	return true;
}

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	ll h, w; cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	vector<ll> ans(min(h,w)+1, 0);
	rep(i,h) rep(j,w) {
		if( s[i][j] != '#' ) continue;
		bool f = true;
		rep(d,DIR_NUM) {
			ll nx = i + dx[d];
			ll ny = j + dy[d];
			if( outField(nx,ny,h,w) ) {
				f = false;
				break;
			}
			f &= ( s[nx][ny] == '#' ); 
		}
		if( !f ) continue;
		ll now_x = i + dx[0], now_y = j + dy[0], cnt = 0;
		while( !outField(now_x,now_y,h,w) && s[now_x][now_y] == '#' ) {
			now_x += dx[0], now_y += dy[0];
			cnt++;
		}
		ans[cnt]++;
	}
	reps(i,1,min(h,w)+1) cout << ans[i] << " ";
	cout << endl;
	
	return 0;
}