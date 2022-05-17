/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc167/submissions/31763561
 * Submitted at: 2022-05-17 19:10:11
 * Problem URL: https://atcoder.jp/contests/abc167/tasks/abc167_b
 * Result: WA
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int a,b,c,k; cin >> a >> b >> c >> k;
    if(k <= a+b)cout << a << endl;
    else cout << a+(k-a-b)*(-1) << endl;
    return 0;
}