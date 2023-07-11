/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc247/submissions/43470918
 * Submitted at: 2023-07-11 09:39:09
 * Problem URL: https://atcoder.jp/contests/abc247/tasks/abc247_f
 * Result: AC
 * Execution Time: 74 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC
    // p,q 両方から選ばない数字が無いように辺を消す
    // → graphに帰着して、自身に来る2辺を共に消さない場合の数
    // → 円環dp

    ll n; input(n);
    vector<ll> p(n), q(n);
    dsu uf(n);
    rep(i,n) input(p[i]);
    rep(i,n) input(q[i]);
    rep(i,n) uf.merge(p[i]-1,q[i]-1);
    vector<vector<mint>> dp(n+1,vector<mint>(4,0));
    // dp[i][j] : i頂点サイクルにおいて、jの時の場合の数
    // ※ j は 2進数で最初・最後の辺を利用するか否かを持つ感じ
    dp[1][3] = 1; dp[1][0] = 1;
    for(int i = 1; i < n; i++){
        dp[i+1][0] += dp[i][2];
        dp[i+1][1] += dp[i][3];
        dp[i+1][2] += dp[i][0];
        dp[i+1][2] += dp[i][2];
        dp[i+1][3] += dp[i][1];
        dp[i+1][3] += dp[i][3];
    }
    vector g = uf.groups();
    mint ans = 1;
    for(auto &&v:g) ans *= (dp[v.size()][1] + dp[v.size()][2] + dp[v.size()][3]);
    print( ans.val() );
    
    return 0;
}