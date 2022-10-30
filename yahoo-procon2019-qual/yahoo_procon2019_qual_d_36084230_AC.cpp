/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/yahoo-procon2019-qual/submissions/36084230
 * Submitted at: 2022-10-30 11:51:04
 * Problem URL: https://atcoder.jp/contests/yahoo-procon2019-qual/tasks/yahoo_procon2019_qual_d
 * Result: AC
 * Execution Time: 44 ms
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
    
    ll l; input(l);
    vector<ll> a(l,0);
    rep(i,l)input(a[i]);
    // 耳dp : 現在の状態をパラメータに持つdp。えぐい。
    // 今回は解説の通り地点d,s,t,uを定め、その5等分されたそれぞれの状態でdpする。
    // Point : d~s,t~uは行き来すれば任意の偶数回操作可能。
    // 　　　　またs~tは任意の奇数回操作可能。
    //         その他は操作不可能。
    vector<vector<ll>> dp(l+1,vector<ll>(5,LLONG_MAX));
    rep(i,5)dp[0][i] = 0;
    for(int i=1;i<=l;i++){
        // 各区間において
        // ①同じ区間での遷移
        // ①違う区間から移動してくる遷移
        // またa[i] == 0の時の遷移は無駄に石を入れてしまうから例外遷移

        dp[i][0] = dp[i-1][0] + a[i-1];
        dp[i][1] = min({dp[i][1],dp[i-1][1] + (a[i-1] == 0 ? 2 : a[i-1]%2    ),dp[i][0]});
        dp[i][2] = min({dp[i][2],dp[i-1][2] + (a[i-1] == 0 ? 1 : (a[i-1]+1)%2),dp[i][1]});
        dp[i][3] = min({dp[i][3],dp[i-1][3] + (a[i-1] == 0 ? 2 : a[i-1]%2    ),dp[i][2]});
        dp[i][4] = min({dp[i][4],dp[i-1][4] + a[i-1]                          ,dp[i][3]});
    }
    print(dp[l][4]);
    
    return 0;
}