/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc178/submissions/30020914
 * Submitted at: 2022-03-12 17:01:41
 * Problem URL: https://atcoder.jp/contests/abc178/tasks/abc178_c
 * Result: WA
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int mod = 1000000007;

int main() {
    int n; cin >> n;
    cout << pow_mod(10,n,mod)-pow_mod(9,n,mod)*2+pow_mod(8,n,mod) << endl;
    return 0;
}