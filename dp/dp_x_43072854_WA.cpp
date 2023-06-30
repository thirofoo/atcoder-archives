/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/43072854
 * Submitted at: 2023-07-01 02:36:12
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_x
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
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC
    // 少し惜しい。頑張って条件式を計算すると
    // s+w が大きい順から用いるべきと分かる。
    // ※ どうせ順番を上手く決めるのだとは思った

    ll n; input(n);
    vector<T> block;
    rep(i,n){
        ll w,s,v; input(w,s,v);
        block.push_back(T(w,s,v));
    }

    sort(block.begin(), block.end(), [](T &b1, T &b2){
        auto &[w1,s1,v1] = b1;
        auto &[w2,s2,v2] = b2;
        return w1+s1 > w2+s2;
    });

    // dp[i][j] : i個目まで考慮して、残りjだけ重さに耐えられる時
    vector<vector<ll>> dp(n+1,vector<ll>(10005,-1));
    dp[0][10004] = 0;
    rep(i,n){
        auto [w,s,v] = block[i];
        rep(j,10005){
            if(dp[i][j] == -1)continue;
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            if( min(j-w,s) >= 0 ){
                dp[i+1][min(j-w,s)] = max(dp[i+1][min(j-w,s)],dp[i][j]+v);
            }
        }
    }

    ll ans = 0;
    rep(i,10005)ans = max(ans,dp[n][i]);
    print(ans);
    
    return 0;
}