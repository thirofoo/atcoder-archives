/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc249/submissions/31223700
 * Submitted at: 2022-04-24 13:17:45
 * Problem URL: https://atcoder.jp/contests/abc249/tasks/abc249_d
 * Result: WA
 * Execution Time: 689 ms
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
    for(int i=1;i*i<=n;i++){
        if(n%i)continue;
        solve.push_back(i);
        if(i != n/i)solve.push_back(n/i);
    }
    return solve;
}
 
int main() {
    int n; cin >> n;
    vector<int> a(n);
    map<int,int> a_num,memo;
    vector<vector<int>> fact(n);
    rep(i,n){
        cin >> a[i];
        a_num[a[i]]++;
        fact[i] = factorize(a[i]);
    }
 
    ll ans = 0;
    rep(i,n){
        if(memo[a[i]])ans += memo[a[i]];
        else{
            ll tmp = 0;
            for(auto l:fact[i]){
                ll tmp1 = a_num[l]; 
                ll tmp2 = a_num[a[i]/l]; 
                ans += tmp1*tmp2;
                tmp += tmp1*tmp2;
            }
            memo[a[i]] = tmp;
        }
    }
    cout << ans << endl;
 
    return 0;
}