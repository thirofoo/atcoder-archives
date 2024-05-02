/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/panasonic2020/submissions/53023003
 * Submitted at: 2024-05-02 18:41:29
 * Problem URL: https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_b
 * Result: WA
 * Execution Time: 1 ms
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
	
	ll h, w; cin >> h >> w;
	ll v1 = (w+1)/2, v2 = w/2;
	if( (h+w)%2 == 0 ) cout << v1 * ((h+1)/2) + v2 * (h/2) << endl;
	else cout << v2 * ((h+1)/2) + v1 * (h/2) << endl;
	
	return 0;
}