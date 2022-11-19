/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc278/submissions/36648044
 * Submitted at: 2022-11-19 23:22:03
 * Problem URL: https://atcoder.jp/contests/abc278/tasks/abc278_f
 * Result: TLE
 * Execution Time: 2205 ms
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

ll n;
vector<string> s;
bool dfs(int j,int k,int p){
    // cout << j << " " << k << " " << p << endl;
    if(j == (1LL << n)-1)return false;
    bool f = false;
    rep(i,n){
        if( (!(j & (1LL << i))) && s[k].back() == s[i][0] ){
            f |= !dfs(j | (1LL << i),i,(p == 0 ? 1 : 0));
        }
    }
    return f;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(n);
    s.assign(n,"");
    rep(i,n)input(s[i]);
    // i,j,k: 初手先手がSi,状態j,ラストkの時の勝つ人を持ったbitDP 
    // 0 : 先手番 1 : 後者番

    bool f = false;
    rep(i,n)f |= !dfs((1LL << i),i,1);
    print((f ? "First" : "Second"));

    // vector<vector<vector<ll>>> dp(n,vector<vector<ll>>((1LL << n),vector<ll>(n,-1)));
    // rep(i,n)dp[i][(1LL << i)][i] = 0;
    // bool f = false;
    // rep(i,n){
    //     rep(j,(1LL << n)){
    //         rep(k,n){
    //             if(dp[i][j][k] == -1)continue;
    //             bool ff = true;
    //             // 語尾判定
    //             rep(l,n){
    //                 if(s[k].back() == s[l][0] && !(j & 1LL << l)){
    //                     dp[i][j | l][l] = (dp[i][j][k] == 0 ? 1 : 0);
    //                     ff = false;
    //                 }
    //             }
    //             if(ff && dp[i][j][k] == 1){
    //                 f = true;
    //                 break;
    //             }
    //         }
    //         if(f)break;
    //     }
    //     if(f)break;
    // }
    // print((f ? "First" : "Second"));
    
    return 0;
}