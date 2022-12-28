/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc241/submissions/37600828
 * Submitted at: 2022-12-28 21:51:35
 * Problem URL: https://atcoder.jp/contests/abc241/tasks/abc241_e
 * Result: AC
 * Execution Time: 244 ms
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
    
    ll n,k; input(n,k);
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    // d[i][j] : 皿jから2^i回操作したら増える飴の個数
    vector d(60,vector<ll>(n));
    rep(i,n)d[0][i] = a[i];
    for(ll i=1;i<60;i++){
        rep(j,n){
            d[i][j] = d[i-1][j] + d[i-1][(j+d[i-1][j])%n];
        }
    }

    ll ans = 0,cnt = 0;
    while(k){
        if(k & 1)ans += d[cnt][ans%n];
        k >>= 1;
        cnt++;
    }
    print(ans);
    
    return 0;
}