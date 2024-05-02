/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc302/submissions/53024189
 * Submitted at: 2024-05-02 19:32:22
 * Problem URL: https://atcoder.jp/contests/abc302/tasks/abc302_c
 * Result: AC
 * Execution Time: 3 ms
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

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	ll n, m; cin >> n >> m;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<ll> p(n,0);
	iota(p.begin(), p.end(), 0);
	do {
		bool f = true;
		rep(i,n-1) {
			ll dis = 0;
			rep(j,m) if(s[p[i]][j] != s[p[i+1]][j]) dis++;
			if(dis > 1) {
				f = false;
				break;
			}
		}
		if( f ) return cout << "Yes" << endl, 0;
	} while(next_permutation(p.begin(), p.end()));
	cout << "No" << endl;
	
	return 0;
}