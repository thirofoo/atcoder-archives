/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc220/submissions/29000649
 * Submitted at: 2022-02-02 11:39:45
 * Problem URL: https://atcoder.jp/contests/abc220/tasks/abc220_a
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
    int a,b,c,ans = 0; cin >> a >> b >> c;
    while(ans <= 1000){
        ans += c;
        if(a <= ans && ans <= b)return cout << ans << endl,0;
    }
    cout << -1 << endl;
    return 0;
}