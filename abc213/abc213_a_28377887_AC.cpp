/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc213/submissions/28377887
 * Submitted at: 2022-01-08 20:06:10
 * Problem URL: https://atcoder.jp/contests/abc213/tasks/abc213_a
 * Result: AC
 * Execution Time: 6 ms
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
    int a,b; cin >> a >> b;
    for(int i=0;i<256;i++){
        if((a^i) == b)return cout << i << endl,0;
    }
    return 0;
}