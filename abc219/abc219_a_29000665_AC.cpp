/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc219/submissions/29000665
 * Submitted at: 2022-02-02 11:41:33
 * Problem URL: https://atcoder.jp/contests/abc219/tasks/abc219_a
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

int main() {
    int x; cin >> x;
    if(x < 40)cout << 40-x << endl;
    else if(x < 70)cout << 70-x << endl;
    else if(x < 90)cout << 90-x << endl;
    else cout << "expert" << endl;
    return 0;
}