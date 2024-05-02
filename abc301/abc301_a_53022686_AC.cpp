/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc301/submissions/53022686
 * Submitted at: 2024-05-02 18:29:54
 * Problem URL: https://atcoder.jp/contests/abc301/tasks/abc301_a
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

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	ll n; string s; cin >> n >> s;
	ll aoki = 0, takahashi = 0;
	rep(i,n) ( s[i] == 'A' ? aoki : takahashi )++;
	if( aoki != takahashi ) cout << ( aoki < takahashi ? "T" : "A" ) << endl;
	else cout << ( s.back() == 'A' ? "T" : "A" ) << endl;
	
	return 0;
}