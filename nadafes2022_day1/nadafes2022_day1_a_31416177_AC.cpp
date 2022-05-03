/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/nadafes2022_day1/submissions/31416177
 * Submitted at: 2022-05-03 18:40:24
 * Problem URL: https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_a
 * Result: AC
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

int main() {
    ll n; cin >> n;
    if(n%2 == 0)cout << n*(n-1)/2 << endl;
    else cout << n*(n-1)/2 - 1 << endl;
    return 0;
}