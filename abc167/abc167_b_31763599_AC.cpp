/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc167/submissions/31763599
 * Submitted at: 2022-05-17 19:12:23
 * Problem URL: https://atcoder.jp/contests/abc167/tasks/abc167_b
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int a,b,c,k; cin >> a >> b >> c >> k;
    if(k <= a+b)cout << min(a,k) << endl;
    else cout << a+(k-a-b)*(-1) << endl;
    return 0;
}