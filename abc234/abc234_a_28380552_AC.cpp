/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/28380552
 * Submitted at: 2022-01-08 21:02:16
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_a
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int ans(int x){
	return x*x+2*x+3;
}

int main() {
	int t; cin >> t;
	cout << ans(ans(ans(t)+t)+ans(ans(t))) << endl;
    return 0;
}