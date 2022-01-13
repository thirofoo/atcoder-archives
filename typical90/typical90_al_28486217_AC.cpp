/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28486217
 * Submitted at: 2022-01-13 10:25:12
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_al
 * Result: AC
 * Execution Time: 8 ms
 */

#include <iostream>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	long long A, B, THRESHOLD = 1000000000000000000LL;
	cin >> A >> B;

	long long C = A / gcd(A, B);
	if (B <= THRESHOLD / C) cout << C * B << endl;
	else cout << "Large" << endl;
	return 0;
}