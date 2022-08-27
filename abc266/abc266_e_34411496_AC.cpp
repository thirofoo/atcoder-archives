/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc266/submissions/34411496
 * Submitted at: 2022-08-28 01:57:49
 * Problem URL: https://atcoder.jp/contests/abc266/tasks/abc266_e
 * Result: AC
 * Execution Time: 10 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<ld> memo;
ld f(ll n){
    if(memo[n] != -1)return memo[n];
    return memo[n] = (max((ld)1,f(n-1))+max((ld)2,f(n-1))+max((ld)3,f(n-1))+max((ld)4,f(n-1))+max((ld)5,f(n-1))+max((ld)6,f(n-1)))/6; 
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n; cin >> n;
    memo.assign(n+1,-1);
    memo[1] = 3.5;
    cout << f(n) << endl;
    
    return 0;
}