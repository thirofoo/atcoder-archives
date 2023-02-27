/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc200/submissions/39290042
 * Submitted at: 2023-02-27 18:18:39
 * Problem URL: https://atcoder.jp/contests/abc200/tasks/abc200_e
 * Result: AC
 * Execution Time: 107 ms
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
    
    ll n,k; input(n,k);

    // 1. パラメータの総和が小さい方が順番が速い
    // 2. パラメータの総和が同じ時はn進数の大小と同じ

    // まずk番目が、パラメータの和がいくつかを求める
    // あとは 綺麗さをループすれば、残り二つは必然的に (0,n),(1,n-1),...と言う順番になる
    
    // パラメータの総和がxである総数は、一見重複組合せっぽく求まりそうだが、
    // 各パラメータがn以下である制約より、一筋縄では求まらない。
    // dpで求める
    vector dp(4,vector<ll>(3*n+3,0));
    dp[0][0] = 1;
    rep(i,3){
        rep(j,2*n+1){
            dp[i+1][j+1] += dp[i][j];
            dp[i+1][j+n+1] -= dp[i][j];
        }
        rep(j,3*n+2)dp[i+1][j+1] += dp[i+1][j];
    }
    ll cnt = 0;
    rep(i,3*n+1){
        if(k <= dp[3][i])break;
        k -= dp[3][i];
        cnt++;
    }
    for(ll i=1;i<=cnt-2;i++){
        ll tmp = (cnt-i > 2*n ? 0 : min(n,cnt-i-1)-max(1LL,cnt-i-n)+1);
        if(k <= tmp){
            for(ll j=max(1LL,cnt-i-n);j<=min(n,cnt-i-1);j++){
                if(k == 1){
                    print(i,j,cnt-i-j);
                    return 0;
                }
                k--;
            }
        }
        k -= tmp;
    }
    
    return 0;
}