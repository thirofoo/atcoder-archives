/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc246/submissions/43542896
 * Submitted at: 2023-07-14 09:48:55
 * Problem URL: https://atcoder.jp/contests/abc246/tasks/abc246_f
 * Result: AC
 * Execution Time: 182 ms
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

ll power(ll a, ll b){
    // a^b % mod を計算
    ll mod = 998244353, x = 1, y = a;
    while(b>0){
        if( b & 1ll ) x = ( x * y ) % mod;
        y = ( y * y )%mod;
        b >>= 1;
    }
    return x % mod;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 文字列包除っぽい
    ll n,l; input(n,l);
    vector<string> s(n);
    rep(i,n) input(s[i]);
    vector ch_cnt(n,vector<ll>(26,0));
    rep(i,n)rep(j,s[i].size())ch_cnt[i][s[i][j]-'a']++;

    mint ans = 0;
    for(ll i=1;i<(1LL << n);i++){
        ll cnt = 0, popcnt = __builtin_popcount(i);
        rep(j,26){
            bool f = true;
            rep(k,n){
                if( (i & (1LL << k)) ) f &= (ch_cnt[k][j] > 0);
            }
            cnt += f;
        }
        ans += power(cnt,l) * (popcnt%2 ? 1 : -1);
    }
    print( ans.val() );
    
    return 0;
}