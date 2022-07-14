/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc028/submissions/33219018
 * Submitted at: 2022-07-14 18:29:31
 * Problem URL: https://atcoder.jp/contests/abc028/tasks/abc028_a
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    if(n <= 59)cout << "Bad" << endl;
    else if(n <= 89)cout << "Good" << endl;
    else if(n <= 99)cout << "Great" << endl;
    else cout << "Perfect" << endl;
    
    return 0;
}