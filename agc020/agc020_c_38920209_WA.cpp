/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc020/submissions/38920209
 * Submitted at: 2023-02-16 15:39:45
 * Problem URL: https://atcoder.jp/contests/agc020/tasks/agc020_c
 * Result: WA
 * Execution Time: 1047 ms
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
    vector<ll> a(n);
    ll sn = 0;
    rep(i,n){
        input(a[i]);
        sn += a[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(2000*2000/64+1,0));
    dp[0][0] = 1;
    rep(i,n){
        ll shift = a[i]%64;
        rep(j,2000*2000/64+1){
            dp[i+1][j] |= dp[i][j];
            ll nj = j + a[i]/64;
            if(nj >= n*n/64+1)continue;

            dp[i+1][nj] |= (dp[i][j] << shift);
            dp[i+1][nj+1] |= (dp[i][j] >> (63-shift));
        }
    }

    // rep(i,n+1){
    //     rep(j,1){
    //         rep(k,30){
    //             cout << (bool)(dp[i][j+(i == n ? 0 : a[i]/64)] & (1LL << k)) << " ";
    //         }
    //     }
    //     print();
    // }

    ll ans;
    for(ll i=sn/2;i<2000*2000/64+1;i++){
        ll shift = i%64;
        ll next = i/64;
        if(dp[n][next] & (1LL << shift)){
            ans = i;
            break;
        }
    }
    print(ans);
    
    return 0;
}