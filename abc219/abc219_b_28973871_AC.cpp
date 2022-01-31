/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc219/submissions/28973871
 * Submitted at: 2022-01-31 18:52:21
 * Problem URL: https://atcoder.jp/contests/abc219/tasks/abc219_b
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
    string a,b,c,t,ans = ""; cin >> a >> b >> c >> t;
    rep(i,t.size()){
        if(t[i] == '1')ans += a;
        else if(t[i] == '2')ans += b;
        else ans += c;
    }
    cout << ans << endl;
    return 0;
}