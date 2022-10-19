/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc183/submissions/35782231
 * Submitted at: 2022-10-19 13:21:47
 * Problem URL: https://atcoder.jp/contests/abc183/tasks/abc183_e
 * Result: AC
 * Execution Time: 84 ms
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
    
    ll h,w; input(h,w);
    vector<string> field(h+1);
    string tmp = "";
    rep(i,w+1)tmp += "#";
    field[0] = tmp;
    rep(i,h){
        tmp; input(tmp);
        field[i+1] = "#" + tmp;
    }

    // r1:横 r2:縦 r3:斜
    vector<vector<mint>> dp(h+1,vector<mint>(w+1,0)),r1(h+1,vector<mint>(w+1,0)),r2(h+1,vector<mint>(w+1,0)),r3(h+1,vector<mint>(w+1,0));
    dp[1][1] = 1; r1[1][1] = 1; r2[1][1] = 1; r3[1][1] = 1;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            if(field[i][j] == '#')continue;
            dp[i][j] += r1[i][j-1] + r2[i-1][j] + r3[i-1][j-1];
            r1[i][j] = r1[i][j-1] + dp[i][j];
            r2[i][j] = r2[i-1][j] + dp[i][j];
            r3[i][j] = r3[i-1][j-1] + dp[i][j];
        }
    }
    print(dp[h][w].val());
    
    return 0;
}