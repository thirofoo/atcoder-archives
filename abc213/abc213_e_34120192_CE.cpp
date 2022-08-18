/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc213/submissions/34120192
 * Submitted at: 2022-08-18 13:30:04
 * Problem URL: https://atcoder.jp/contests/abc213/tasks/abc213_e
 * Result: CE
 * Execution Time: None ms
 */

#pragma GCC optimize ("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target ("avx2")
//#include<bits/stdc++.h>
//#include<atcoder/all>
//using namespace atcoder;
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

char S[1 << 18];
const int dh = 1 << 9;
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W;
	scanf("%d %d", &H, &W);
	getchar();
	rep(i, H) fread(S + dh * (2 + i) + 2, 1, W + 1, stdin);

	if (H == 2 && W == 2) {
		if (S[dh * 2 + 3] == '#' && S[dh * 3 + 2] == '#') co(1);
		else co(0);
		return 0;
	}

	deque<int> q;

	auto upd1 = [&](int hw) {
		if (S[hw] & 4) {
			S[hw] = 0;
			q.push_front(hw);
		}
	};
	auto upd2 = [&](int hw) {
		if (S[hw] & 32) {
			S[hw] ^= 32;
			q.pb(hw);
		}
	};

	upd1(dh * 2 + 2);
	q.pb(-1);
	int owa = dh * (1 + H) + 1 + W;
	int d = 0,int hw;
	while (1) {
		hw = q.front();
		q.pop_front();
		if (hw < 0) {
			q.pb(-1);
			d++;
			continue;
		}
		if (hw == owa) break;
		S[hw] = 0;
		upd1(hw - dh);
		upd1(hw + dh);
		upd1(hw - 1);
		upd1(hw + 1);
		upd2(hw - dh - dh - 1);
		upd2(hw - dh - dh);
		upd2(hw - dh - dh + 1);
		upd2(hw + dh + dh - 1);
		upd2(hw + dh + dh);
		upd2(hw + dh + dh + 1);
		upd2(hw + dh + 2);
		upd2(hw + 2);
		upd2(hw - dh + 2);
		upd2(hw + dh - 2);
		upd2(hw - 2);
		upd2(hw - dh - 2);
	}
	co(d);

	return 0;
}