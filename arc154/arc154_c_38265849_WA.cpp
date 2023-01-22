/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc154/submissions/38265849
 * Submitted at: 2023-01-22 22:50:40
 * Problem URL: https://atcoder.jp/contests/arc154/tasks/arc154_c
 * Result: WA
 * Execution Time: 272 ms
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
    
    ll t; input(t);
    while(t--){
        ll n; input(n);
        vector<ll> a1(n),b1(n),b2;
        rep(i,n)input(a1[i]);
        rep(i,n)input(b1[i]);
        a1.push_back(a1[0]);
        rep(i,n){
            if(b1[i] != b1[(i+1)%n]){
                b2.push_back(b1[(i+1)%n]);
            }
        }
        if(b2.size() == 0)b2.push_back(b1[0]);

        vector<vector<ll>> dp(b2.size()+5,vector<ll>(n+5,-1));
        rep(i,n+5)dp[0][i] = 0;
        rep(i,b2.size()+5)dp[i][0] = 0;

        rep(i,b2.size()){
            rep(j,n+1){
                if(b2[i] == a1[j])dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
                dp[i+1][j+1] = max(dp[i+1][j+1],dp[i+1][j]);
                dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j+1]);
            }
        }

        if(dp[b2.size()][n+1] == b2.size()){
            print("Yes");
            continue;
        }


        b2.push_back(*b2.begin());
        b2.erase(b2.begin());

        dp.assign(b2.size()+5,vector<ll>(n+1,-1));
        rep(i,n+5)dp[0][i] = 0;
        rep(i,b2.size()+5)dp[i][0] = 0;

        rep(i,b2.size()){
            rep(j,n+1){
                if(b2[i] == a1[j])dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
                dp[i+1][j+1] = max(dp[i+1][j+1],dp[i+1][j]);
                dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j+1]);
            }
        }

        if(dp[b2.size()][n+1] == b2.size()){
            print("Yes");
            continue;
        }
        print("No");
    }
    
    return 0;
}