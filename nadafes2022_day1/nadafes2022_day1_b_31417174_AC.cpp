/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/nadafes2022_day1/submissions/31417174
 * Submitted at: 2022-05-03 19:48:10
 * Problem URL: https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_b
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
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,k; cin >> n >> k;
    //階上のmintを記録しておく。
    vector<mint> fact(n+1);
    fact[0] = 1;
    rep(i,n)fact[i+1] = fact[i]*(i+1);
    if((n+1)/2 > k)cout << 0 << endl;
    else cout << (fact[n-(n+1)/2] / fact[k-(n+1)/2] / fact[n-k]).val() << endl;
    return 0;
}