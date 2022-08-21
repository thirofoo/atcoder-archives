/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc265/submissions/34201945
 * Submitted at: 2022-08-21 21:03:23
 * Problem URL: https://atcoder.jp/contests/abc265/tasks/abc265_a
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
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll x,y,n; cin >> x >> y >> n;
    if(3*x <= y)cout << x*n << endl;
    else cout << (n/3)*y + (n%3)*x << endl;

    return 0;
}