/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc195/submissions/30784174
 * Submitted at: 2022-04-08 12:44:43
 * Problem URL: https://atcoder.jp/contests/abc195/tasks/abc195_c
 * Result: AC
 * Execution Time: 7 ms
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
    ll ans = 0,tmp = 1,cnt = 0;
    while(n >= tmp*1000)tmp *= 1000,cnt++;
    while(tmp){
        ans += (n-tmp+(n%1000 || tmp == n ? 1 : 0))*cnt;
        cnt--; n = tmp; tmp /= 1000;
    }

    cout << ans << endl;
    return 0;
}