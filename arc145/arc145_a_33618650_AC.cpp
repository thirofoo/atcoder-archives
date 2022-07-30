/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc145/submissions/33618650
 * Submitted at: 2022-07-30 21:27:31
 * Problem URL: https://atcoder.jp/contests/arc145/tasks/arc145_a
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
    
    ll n; string s; cin >> n >> s;
    if(s[0] == 'A' && s[n-1] == 'B')cout << "No" << endl;
    else if(n == 2 && s[0] == 'B' && s[1] == 'A')cout << "No" << endl;
    else cout << "Yes" << endl;
    
    return 0;
}