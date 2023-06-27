/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/43008441
 * Submitted at: 2023-06-28 00:37:24
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_s
 * Result: AC
 * Execution Time: 206 ms
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
    
    string k; ll d; input(k,d);
    vector<vector<vector<mint>>> dp(k.size()+1,vector<vector<mint>>(2,vector<mint>(d,0)));
    // dp[i][j][k] : i桁目まで見て、d以上になる可能性がjで、桁和がkの場合の数
    dp[0][1][0] = 1;
    rep(i,k.size()){
        rep(j,2){
            rep(l,d){
                for(ll m=0;m<=(j ? k[i]-'0' : 9);m++){
                    dp[i+1][j && (m == k[i]-'0')][(l+m)%d] += dp[i][j][l];
                }
            }
        }
    }
    print( (dp[k.size()][0][0] + dp[k.size()][1][0] - 1).val() );
    
    return 0;
}