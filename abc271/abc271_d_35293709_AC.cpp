/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc271/submissions/35293709
 * Submitted at: 2022-10-01 21:36:12
 * Problem URL: https://atcoder.jp/contests/abc271/tasks/abc271_d
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,s; input(n,s);
    vector<vector<bool>> dp(n+1,vector<bool>(s+1,false));
    dp[0][0] = true;
    stack<P> tmp;
    rep(i,n){
        ll a,b; input(a,b);
        tmp.push(P(a,b));
        rep(j,s){
            if(!dp[i][j])continue;
            if(j+a <= s)dp[i+1][j+a] = true;
            if(j+b <= s)dp[i+1][j+b] = true;
        }
    }
    if(!dp[n][s])return print("No"),0;
    else print("Yes");
    ll now = s;
    stack<char> ans;
    for(int i=n;i>0;i--){
        auto [a,b] = tmp.top(); tmp.pop();
        if(now-a >= 0 && dp[i-1][now-a]){
            now -= a;
            ans.push('H');
        }
        else{
            now -= b;
            ans.push('T');
        }
    }
    while(!ans.empty()){
        cout << ans.top();
        ans.pop();
    }
    print();
    
    return 0;
}