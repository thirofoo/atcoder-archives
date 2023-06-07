/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/42060487
 * Submitted at: 2023-06-07 21:32:00
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_k
 * Result: RE
 * Execution Time: 762 ms
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
    
    ll n; input(n);
    // 小課題2 → bitDP
    vector<ll> d(n),c(n),s(n);
    rep(i,n)input(d[i],c[i],s[i]);

    // dp[i][j] : 状態iで最後にjに訪れた際の最小時間
    vector<vector<ll>> dp((1LL << n),vector<ll>(n,1e16));
    rep(i,n)if(c[i] <= d[i])dp[(1LL << i)][i] = c[i];
    ll ans = 0;
    rep(i,(1LL << n)){
        rep(j,n){
            if(dp[i][j] >= 1e16)continue;
            ll cand = 0;
            rep(k,n){
                if(i & (1LL << k)){
                    cand += s[k];
                    continue;
                }
                if(dp[i][j]+c[k] > d[k])continue;
                dp[i | (1LL << k)][k] = min(dp[i | (1LL << k)][k],dp[i][j]+c[k]);
            }
            ans = max(ans,cand);
        }
    }
    print(ans);
    
    return 0;
}