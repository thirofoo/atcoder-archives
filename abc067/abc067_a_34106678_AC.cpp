/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc067/submissions/34106678
 * Submitted at: 2022-08-17 18:11:23
 * Problem URL: https://atcoder.jp/contests/abc067/tasks/abc067_a
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll a,b; cin >> a >> b;
    if(a%3 == 0 || b%3 == 0 || (a+b)%3 == 0)cout << "Possible" << endl;
    else cout << "Impossible" << endl;
    
    return 0;
}