/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc308/submissions/43168473
 * Submitted at: 2023-07-02 09:57:19
 * Problem URL: https://atcoder.jp/contests/abc308/tasks/abc308_e
 * Result: AC
 * Execution Time: 26 ms
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
    
    ll n; input(n);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    string s; input(s);

    // dp[i][j] : "MEX"のi文字目までok & 実際の状態j (0,1,2 が既出か) の場合の数
    vector<vector<ll>> dp(3,vector<ll>(8,0));
    rep(i,n){
        if(s[i] == 'M')dp[0][(1LL << a[i])]++;
        else if(s[i] == 'E'){
            rep(j,8){
                dp[1][j | (1LL << a[i])] += dp[0][j];
            }
        }
        else{
            rep(j,8){
                dp[2][j | (1LL << a[i])] += dp[1][j];
            }
        }
    }
    ll ans = 0;
    rep(i,8){
        ll mex = 0;
        rep(j,3){
            if(i & (1LL << j))mex++;
            else break;
        }
        ans += dp[2][i] * mex;
    }
    print(ans);
    
    return 0;
}