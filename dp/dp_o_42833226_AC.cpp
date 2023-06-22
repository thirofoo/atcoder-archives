/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/42833226
 * Submitted at: 2023-06-23 01:08:34
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_o
 * Result: AC
 * Execution Time: 305 ms
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
    
    // 解説AC bitDP
    // ※ 横軸に状態を持つから、本家(巡回セールスマン)とは本質的に違うっぽい？
    // 本家は最初の行は後の行の真部分集合であることを利用している。
    // ここでは単に状態として集合を用いてるだけ。
    
    ll n; input(n);
    vector<vector<mint>> dp(n+1,vector<mint>((1LL << n),0));
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n)rep(j,n)input(a[i][j]);
    dp[0][0] = 1;
    rep(i,n){
        rep(j,(1LL << n)){
            // 実は ↓ が肝。
            if(dp[i][j].val() <= 0)continue;
            // これが無いと O(2^N*N^2) になってしまう。
            // 今回はi行目は、i+1人の男女ペアを選んだ時
            // → bitがi+1個立ってるところしか、dpが保持されてない (他は-1)
            // → 枝狩りがあることで ∑ n_C_i = 2^n 通りの状態からしか、以下のループが始まらない
            // → O(2^N*N) に削減！！
            rep(k,n){
                if(j & (1LL << k) || !a[i][k])continue;
                dp[i+1][j | (1LL << k)] += dp[i][j];
            }
        }
    }
    print( dp[n][(1LL << n)-1].val() );
    
    return 0;
}