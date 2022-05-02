/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc154/submissions/31396473
 * Submitted at: 2022-05-02 17:10:44
 * Problem URL: https://atcoder.jp/contests/abc154/tasks/abc154_a
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
    string s,t,u; int a,b; cin >> s >> t >> a >> b >> u;
    if(s == u)cout << a-1 << " " << b << endl;
    else cout << a << " " << b-1 << endl;
    return 0;
}