/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/31008215
 * Submitted at: 2022-04-16 21:04:09
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_b
 * Result: AC
 * Execution Time: 5 ms
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
    ll a,b,k,cnt = 0; cin >> a >> b >> k;
    while(a < b){
        a *= k;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}