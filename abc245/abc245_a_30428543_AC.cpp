/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc245/submissions/30428543
 * Submitted at: 2022-03-26 21:02:53
 * Problem URL: https://atcoder.jp/contests/abc245/tasks/abc245_a
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
    int a,b,c,d; cin >> a >> b >> c >> d;
    if(a*3600+b*60 > c*3600+d*60+1)cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;
    return 0;
}