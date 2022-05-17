/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc205/submissions/31763676
 * Submitted at: 2022-05-17 19:16:57
 * Problem URL: https://atcoder.jp/contests/abc205/tasks/abc205_c
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
    
    int a,b,c; cin >> a >> b >> c;
     
    if(a == b || (abs(a) == abs(b) && c%2 == 0))cout << "=" << endl;
    else if(a > b)cout << ">" << endl;
    else cout << "<" << endl; 
    return 0;
}