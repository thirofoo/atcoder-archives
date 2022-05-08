/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc112/submissions/31502952
 * Submitted at: 2022-05-08 10:49:17
 * Problem URL: https://atcoder.jp/contests/abc112/tasks/abc112_d
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<ll> divisor;
void enum_div(ll n){
    divisor.push_back(1);
    if(n != 1)divisor.push_back(n);
    for(ll i=2;i*i<=n;i++){
        if(n%i)continue;
        divisor.push_back(i);
        if(i != n/i)divisor.push_back(n/i);
    }
    sort(divisor.begin(),divisor.end());
    return;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,m; cin >> n >> m;
    enum_div(m);
    reverse(divisor.begin(),divisor.end());
    for(auto k:divisor){
        if(m >= k*n && (m-k*n)%k == 0){
            return cout << k << endl,0;
        }
    }
    return 0;
}