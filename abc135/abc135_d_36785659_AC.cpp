/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc135/submissions/36785659
 * Submitted at: 2022-11-26 15:58:16
 * Problem URL: https://atcoder.jp/contests/abc135/tasks/abc135_d
 * Result: AC
 * Execution Time: 37 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; input(s);
    int size = s.size();
    vector<vector<mint>> dp(size+1,vector<mint>(13,0));
    dp[0][0] = 1;
    rep(i,size){
        rep(j,13){
            if(s[i] == '?'){
                rep(d,10){
                    dp[i+1][(j*10+d)%13] += dp[i][j];
                }
            }
            else{
                dp[i+1][(j*10+s[i]-'0')%13] += dp[i][j];
            }
        }
    }
    print(dp[size][5].val());
    
    return 0;
}