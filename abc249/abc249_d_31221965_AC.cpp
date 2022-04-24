/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc249/submissions/31221965
 * Submitted at: 2022-04-24 11:23:51
 * Problem URL: https://atcoder.jp/contests/abc249/tasks/abc249_d
 * Result: AC
 * Execution Time: 1794 ms
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
 
vector<int> factorize(int n){
    vector<int> solve;
    solve.push_back(1);
    if(n != 1)solve.push_back(n);
    for(int i=2;i*i<=n;i++){
        if(n%i)continue;
        solve.push_back(i);
        if(i != n/i)solve.push_back(n/i);
    }
    sort(solve.begin(),solve.end());
    return solve;
}
 
int main() {
    int n; cin >> n;
    vector<int> a(n);
    map<int,ll> a_num;
    vector<vector<int>> fact(n);
    rep(i,n){
        cin >> a[i];
        a_num[a[i]]++;
        fact[i] = factorize(a[i]);
    }
 
    ll ans = 0;
    rep(i,n){
        int size = fact[i].size();
        rep(j,size){
            ll tmp1 = a_num[fact[i][j]]; 
            ll tmp2 = a_num[a[i]/fact[i][j]]; 
            ans += tmp1*tmp2;
        }
    }
    cout << ans << endl;
 
    return 0;
}