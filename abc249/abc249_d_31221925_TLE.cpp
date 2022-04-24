/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc249/submissions/31221925
 * Submitted at: 2022-04-24 11:21:39
 * Problem URL: https://atcoder.jp/contests/abc249/tasks/abc249_d
 * Result: TLE
 * Execution Time: 2203 ms
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

vector<ll> factorize(ll n){
    vector<ll> solve;
    solve.push_back(1);
    if(n != 1)solve.push_back(n);
    for(ll i=2;i*i<=n;i++){
        if(n%i)continue;
        solve.push_back(i);
        if(i != n/i)solve.push_back(n/i);
    }
    sort(solve.begin(),solve.end());
    return solve;
}

int main() {
    ll n; cin >> n;
    vector<ll> a(n);
    map<ll,ll> a_num;
    vector<vector<ll>> fact(n);
    rep(i,n){
        cin >> a[i];
        a_num[a[i]]++;
        fact[i] = factorize(a[i]);
    }

    ll ans = 0;
    rep(i,n){
        ll size = fact[i].size();
        rep(j,size){
            ll tmp1 = a_num[fact[i][j]]; 
            ll tmp2 = a_num[a[i]/fact[i][j]]; 
            ans += tmp1*tmp2;
        }
    }
    cout << ans << endl;

    return 0;
}