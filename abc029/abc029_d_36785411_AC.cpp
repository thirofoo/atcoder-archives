/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc029/submissions/36785411
 * Submitted at: 2022-11-26 15:46:08
 * Problem URL: https://atcoder.jp/contests/abc029/tasks/abc029_d
 * Result: AC
 * Execution Time: 7 ms
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
    
    string n; input(n);
    int size = n.size();
    vector<vector<vector<ll>>> dp(size+1,vector<vector<ll>>(2,vector<ll>(size+1,0)));
    dp[0][0][0] = 1;
    rep(i,size){
        rep(j,2){
            rep(k,size){
                for(ll d=0;d<=(j ? 9 : n[i]-'0');d++){
                    dp[i+1][j | (d != n[i]-'0')][k + (d == 1 ? 1 : 0)] += dp[i][j][k];
                }
            }
        }
    }

    ll ans = 0;
    rep(i,2){
        rep(j,n.size()+1){
            ans += dp[size][i][j]*j;
        }
    }
    print(ans);
    
    return 0;
}