/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc243/submissions/30028346
 * Submitted at: 2022-03-12 21:03:48
 * Problem URL: https://atcoder.jp/contests/abc243/tasks/abc243_a
 * Result: AC
 * Execution Time: 8 ms
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

int main() {
    int v,a,b,c; cin >> v >> a >> b >> c;
    if(v%(a+b+c) < a)cout << "F" << endl;
    else if(v%(a+b+c) < a+b)cout << "M" << endl;
    else cout << "T" << endl;
    return 0;
}