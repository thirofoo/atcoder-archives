/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc120/submissions/28245123
 * Submitted at: 2021-12-31 01:50:32
 * Problem URL: https://atcoder.jp/contests/abc120/tasks/abc120_c
 * Result: AC
 * Execution Time: 9 ms
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
    string s; cin >> s;
    int c1 = 0,c0 = 0;
    rep(i,s.size()){
        if(s[i] == '1')c1++;
        else c0++;
    }
    cout << 2*min(c1,c0) << endl;
    return 0;
}