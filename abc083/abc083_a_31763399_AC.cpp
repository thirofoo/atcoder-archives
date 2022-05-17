/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc083/submissions/31763399
 * Submitted at: 2022-05-17 18:59:31
 * Problem URL: https://atcoder.jp/contests/abc083/tasks/abc083_a
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int a,b,c,d; cin >> a >> b >> c >> d;
    if(a+b == c+d)cout << "Balanced" << endl;
    else if(a+b < c+d)cout << "Right" << endl;
    else cout << "Left" << endl;
    return 0;
}