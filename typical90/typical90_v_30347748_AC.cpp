/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30347748
 * Submitted at: 2022-03-22 19:08:17
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_v
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
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll gcd(ll a,ll b){
    if(a < b)return gcd(b,a);
    if(a%b == 0)return b;
    else return gcd(b,a%b);
}

int main() {
    ll a,b,c; cin >> a >> b >> c;
    ll tmp = gcd(a,gcd(b,c));
    a /= tmp; b /= tmp; c /= tmp;
    cout << a + b + c - 3 << endl;

    return 0;
}