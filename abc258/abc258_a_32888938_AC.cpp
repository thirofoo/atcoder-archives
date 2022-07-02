/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/32888938
 * Submitted at: 2022-07-02 21:03:11
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_a
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
    
    ll n; cin >> n;
    if(n < 10)cout << "21:0" << n%60 << endl;
    else if(n < 60)cout << "21:" << n << endl;
    else if(n < 70)cout << "22:0" << n%60 << endl;
    else cout << "22:" << n%60 << endl;
    
    return 0;
}