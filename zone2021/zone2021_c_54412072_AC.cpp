/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/zone2021/submissions/54412072
 * Submitted at: 2024-06-09 23:38:53
 * Problem URL: https://atcoder.jp/contests/zone2021/tasks/zone2021_c
 * Result: AC
 * Execution Time: 3 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	
	// 模範解答 ver
	// point: 決め打ち二分探索する時、各能力が特定の値以上かは、2^{能力数} 通りしか存在しない
	// ⇒ 全てを列挙した後に、3 個全探索すれば行ける（天才過ぎ）
	int n; cin >> n;
	constexpr int ABILITY = 5;
	vector p(n, vector<int>(ABILITY));
	for(int i=0; i<n; i++) {
		for(int j=0; j<ABILITY; j++) {
			cin >> p[i][j];
		}
	}
	
	auto check = [&](int x) -> bool {
		set<int> s;
		for(int i=0; i<n; i++) {
			int bit = 0;
			for(int j=0; j<ABILITY; j++) {
				if(p[i][j] >= x) bit |= (1 << j);
			}
			s.insert(bit);
		}
		// 3 個以下の能力で全能力閾値以上になるか否か
		int size = s.size();
		for(auto &v1 : s) {
			for(auto &v2 : s) {
				for(auto &v3 : s) {
					if((v1 | v2 | v3) == (1 << ABILITY)-1) return true;
				}
			}
		}
		return false;
	};

	int left = 0, right = 1e9+5;
	while(right-left > 1) {
		int mid = (right+left) / 2;
		if(check(mid)) left = mid;
		else right = mid;
	}
	cout << left << '\n';
	
	return 0;
}