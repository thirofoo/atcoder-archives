/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc194/submissions/31763419
 * Submitted at: 2022-05-17 19:01:35
 * Problem URL: https://atcoder.jp/contests/abc194/tasks/abc194_a
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
    
    int a,b; cin >> a >> b;
    if(a+b >= 15 && b >= 8)cout << 1 << endl;
    else if(a+b >= 10 && b >= 3)cout << 2 << endl;
    else if(a+b >= 3)cout << 3 << endl;
    else cout << 4 << endl;
    return 0;
}