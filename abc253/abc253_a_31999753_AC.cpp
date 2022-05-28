/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc253/submissions/31999753
 * Submitted at: 2022-05-28 21:02:10
 * Problem URL: https://atcoder.jp/contests/abc253/tasks/abc253_a
 * Result: AC
 * Execution Time: 13 ms
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
    
    int a,b,c; cin >> a >> b >> c;
    if((a <= b && b <= c) || (c <= b && b <= a))cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}