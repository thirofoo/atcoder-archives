/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc242/submissions/39347674
 * Submitted at: 2023-03-02 12:28:57
 * Problem URL: https://atcoder.jp/contests/abc242/tasks/abc242_e
 * Result: WA
 * Execution Time: 75 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; input(t);
    while(t--){
        ll n; string s1,s2 = ""; input(n,s1);
        string t1 = "",t2 = "";
        rep(i,n/2)t1 += s1[i];
        rep(i,n/2)t2 += s1[(n+1)/2+i];
        reverse(t2.begin(),t2.end());
        if(t1 >= t2){
            s2 += t2;
            if(n%2)s2 += s1[n/2];
            reverse(t2.begin(),t2.end());
            s2 += t2;
        }
        else{
            s2 += t1;
            if(n%2)s2 += s1[n/2];
            reverse(t1.begin(),t1.end());
            s2 += t1;
        }
        // s2が答えに含まれるか否か
        bool f = false;
        if(s2 > s1)f = true;

        vector<vector<mint>> dp(2,vector<mint>(n,0));
        dp[0][0] = 1;
        rep(j,n/2){
            dp[0][j+1] += dp[0][j];
            dp[1][j+1] += dp[0][j]*(s2[j]-'A');
            dp[1][j+1] += dp[1][j]*26;
        }
        if(n%2){
            dp[0][n/2] *= (s2[n/2]-'A'+1);
            dp[1][n/2] *= 26;
        }
        print( (dp[0][n/2]+dp[1][n/2]-f).val() );
    }

    
    return 0;
}