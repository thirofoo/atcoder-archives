/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/aising2020/submissions/37694281
 * Submitted at: 2023-01-02 19:33:54
 * Problem URL: https://atcoder.jp/contests/aising2020/tasks/aising2020_d
 * Result: RE
 * Execution Time: 121 ms
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
    
    ll n; string s; input(n,s);

    // いかなるsでも1回操作後は n 未満
    // => n未満を前計算
    vector<ll> ans(n+1,0);
    for(ll i=1;i<=n;i++){
        ll now = i,pop_count = 0;
        while(now){
            if(now & 1)pop_count++;
            now /= 2;
        }
        ans[i] = ans[i%pop_count] + 1;
    }

    // S が1回目の操作後何になるか計算
    ll cnt = 0;
    rep(i,n)if(s[i] == '1')cnt++;
    vector<vector<ll>> b(3,vector<ll>(n,0));
    rep(i,3){
        if(cnt-(1-i) <= 0)continue;
        ll mod = cnt-(1-i);
        b[i][0] = 1%mod;
        for(ll j=1;j<n;j++)b[i][j] = (b[i][j-1]*2)%mod;
    }

    vector<ll> tmp(3,0); // S % (pop_count + [-1,0,1])
    rep(i,3){
        rep(j,n){
            if(s[j] == '1'){
                tmp[i] += b[i][n-1-j];
                tmp[i] %= (cnt-(1-i));
            }
        }
    }

    ll mod;
    rep(i,n){
        if(s[i] == '1'){
            mod = cnt-1;
            if(cnt == 1)print(1);
            else print( ans[((tmp[0] - b[0][n-1-i])%mod + mod)%mod] + 1 );
        }
        else{
            mod = cnt+1;
            if(cnt == 0)print(1);
            else print( ans[(tmp[2] + b[2][n-1-i])%mod] + 1 );
        }
    }
    
    return 0;
}