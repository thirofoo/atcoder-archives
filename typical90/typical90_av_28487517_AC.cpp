/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28487517
 * Submitted at: 2022-01-13 12:52:55
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_av
 * Result: AC
 * Execution Time: 148 ms
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

//公式解説のソースコード
//配列に部分点と部分点から満点になるときの追加点を入れてsortすると
//必ず後者の方が小さくなる為(部分点>=満点/2より)、後者を追加するときには必然的に前者を選んでいることになり、
//満点の時に2分要するという条件を考えなくても済む！

long long N, K, A[1 << 18], B[1 << 18];
vector<long long> vec;

int main() {
	// Step #1. 入力など
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> A[i] >> B[i];
		vec.push_back(B[i]);
		vec.push_back(A[i] - B[i]);
	}

	// Step #2. 答えを求める
	long long Answer = 0;
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());
	for (int i = 0; i < K; i++) Answer += vec[i];

	// Step #3. 出力
	cout << Answer << endl;
	return 0;
}