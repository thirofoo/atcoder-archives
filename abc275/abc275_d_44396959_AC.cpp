/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc275/submissions/44396959
 * Submitted at: 2023-08-09 02:43:22
 * Problem URL: https://atcoder.jp/contests/abc275/tasks/abc275_d
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for (int i = 0; i < (n); i++)

map<ll,ll> memo;
ll f(ll x){
    if( memo.count(x) ) return memo[x];
    if( x == 0 ) return 1;
    memo[x/2] = f(x/2);
    memo[x/3] = f(x/3);
    return f(x/2) + f(x/3);
}

int main(){
    ll n; cin >> n;
    cout << f(n) << endl;
    return 0;
}