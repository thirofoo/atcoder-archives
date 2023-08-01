/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc249/submissions/44162560
 * Submitted at: 2023-08-01 21:05:54
 * Problem URL: https://atcoder.jp/contests/abc249/tasks/abc249_f
 * Result: AC
 * Execution Time: 96 ms
 */

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> t(n), y(n);
	rep(i,n) cin >> t[i] >> y[i];
	ll ans = -1e18;
	ll sum = 0;
	priority_queue<int> q;
	for (int i = n-1; i >= 0; --i) {
		if (k < 0) break;
		if (t[i] == 1) {
		  	ans = max(ans, y[i]+sum);
		  	k--;
		  	if (q.size() > k) {
		  		sum += q.top(); q.pop();
		  	}
		} else {
			if (y[i] >= 0) {
				sum += y[i];
			} else {
				q.push(y[i]);
				if (q.size() > k) {
					sum += q.top(); q.pop();
				}
			}
		}
	}
	if (k >= 0) ans = max(ans, sum);
	cout << ans << endl;
	return 0;
}