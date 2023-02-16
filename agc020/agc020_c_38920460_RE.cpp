/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc020/submissions/38920460
 * Submitted at: 2023-02-16 15:55:03
 * Problem URL: https://atcoder.jp/contests/agc020/tasks/agc020_c
 * Result: RE
 * Execution Time: 192 ms
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
    
    // bitset64倍高速化
    ll n,sum = 0; input(n);
    vector<ll> a(n);
    rep(i,n){
        input(a[i]);
        sum += a[i];
    }
    vector<ll> dp(sum/64+3,0);
    dp[0] = 1;
    rep(i,n){
        ll shift = a[i]%64;
        rep(j,sum/64+1){
            ll nj = j + a[i]/64;
            dp[nj] |= (dp[j] << shift);
            dp[nj+1] |= (dp[j] >> (63-shift));
        }
    }

    ll ans;
    for(ll i=sum/2;i<2000*2000/64+1;i++){
        ll shift = i%64;
        ll next = i/64;
        if(dp[next] & (1LL << shift)){
            ans = i;
            break;
        }
    }
    print(ans);
    
    return 0;
}