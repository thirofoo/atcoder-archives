/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc155/submissions/42249021
 * Submitted at: 2023-06-14 12:38:01
 * Problem URL: https://atcoder.jp/contests/abc155/tasks/abc155_e
 * Result: AC
 * Execution Time: 85 ms
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
    ll ans = 0;
    // 10^i 硬貨は s[i]-'0'+1 or s[i]-'0' 枚のどちらかのみ
    // 既に支払額を超えてる場合：お釣りを貰って桁skip可能
    // 　支払額を超えてない場合：その桁以上は払わないと駄目

    // dp[i][j] : 上からi桁目の硬貨を用いて、状態j (1:支払額超過, 0:支払額未満) の時の枚数最小値
    n = "0" + n;
    vector<vector<ll>> dp(n.size()+1,vector<ll>(2,1e9));
    dp[0][0] = 0;
    rep(i,n.size()){
        ll k = n[i]-'0';
        // 端数分払う遷移
        dp[i+1][0] = min(dp[i+1][0],dp[i][0] + k);
        // 支払って超過にする繊維
        if(k != 9)dp[i+1][1] = min(dp[i+1][1],dp[i][0] + k+1);

        // 超過の状況を残しつつお釣りを貰う遷移
        dp[i+1][1] = min(dp[i+1][1],dp[i][1] + 10-k-1);
        // 未満になるようにお釣りを貰う遷移
        dp[i+1][0] = min(dp[i+1][0],dp[i][1] + 10-k);
    }
    print( min(dp[n.size()][0],dp[n.size()][1]+1) );
    
    return 0;
}