/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc145/submissions/42242045
 * Submitted at: 2023-06-13 23:31:19
 * Problem URL: https://atcoder.jp/contests/abc145/tasks/abc145_e
 * Result: AC
 * Execution Time: 152 ms
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
    
    // 解法2 (天才解法)
    // 今回は最後の食事が特殊
    // → 最後の食事を全探索して、それ以外の食事でt-1までの最大値を求める
    // → 1個除外と言えば 左右からdpで積める
    // dp1[i][j] : 1~iまでの美味しさ総和最大
    // dp2[i][j] : n~iまでの美味しさ総和最大
    // とすれば、iを除いてt-1分までの美味しさ最大は、
    // max(dp1[i-1][j] + dp2[n-i+1][t-1-j])

    ll n,t; input(n,t);
    vector<P> cook;
    rep(i,n){
        ll a,b; input(a,b);
        cook.push_back(P(a,b));
    }
    vector<vector<ll>> dp1(n+1,vector<ll>(t,-1)), dp2(n+1,vector<ll>(t,-1));
    dp1[0][0] = 0;
    dp2[0][0] = 0;
    rep(i,n){
        auto [a,b] = cook[i];
        rep(j,t){
            if(dp1[i][j] == -1)continue;
            dp1[i+1][j] = max(dp1[i+1][j],dp1[i][j]);
            if(j+a <= t-1)dp1[i+1][j+a] = max(dp1[i+1][j+a],dp1[i][j]+b);
        }
    }
    reverse(cook.begin(),cook.end());
    rep(i,n){
        auto [a,b] = cook[i];
        rep(j,t){
            if(dp2[i][j] == -1)continue;
            dp2[i+1][j] = max(dp2[i+1][j],dp2[i][j]);
            if(j+a <= t-1)dp2[i+1][j+a] = max(dp2[i+1][j+a],dp2[i][j]+b);
        }
    }
    rep(i,n){
        rep(j,t-1){
            dp1[i][j+1] = max(dp1[i][j+1],dp1[i][j]);
            dp2[i][j+1] = max(dp2[i][j+1],dp2[i][j]);
        }
    }
    reverse(cook.begin(),cook.end());
    ll ans = 0;
    rep(i,n){
        auto [a,b] = cook[i];
        rep(j,t){
            ans = max(ans,dp1[i][j]+dp2[n-i-1][t-1-j]+b);
        }
    }
    print(ans);
    
    return 0;
}