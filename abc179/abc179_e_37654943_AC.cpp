/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc179/submissions/37654943
 * Submitted at: 2022-12-31 17:06:22
 * Problem URL: https://atcoder.jp/contests/abc179/tasks/abc179_e
 * Result: AC
 * Execution Time: 103 ms
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
    
    ll n,x,m; input(n,x,m);
    // d1[i][j] : A_1%m = j の時の A_{2^i+1}
    // d2[i][j] : A_1%m = j の時の ∑[k=1...2^i]A_k
    vector<vector<ll>> d1(60,vector<ll>(m,0)),d2(60,vector<ll>(m,0));
    rep(i,m)d1[0][i] = (i*i)%m;
    for(ll i=1;i<60;i++){
        rep(j,m){
            d1[i][j] = d1[i-1][d1[i-1][j]];
        }
    }
    rep(i,m)d2[0][i] = i;
    for(ll i=1;i<60;i++){
        rep(j,m){
            d2[i][j] = d2[i-1][d1[i-1][j]] + d2[i-1][j];
        }
    }
    
    // t1 : 初項%m
    // cnt : t1から2^cnt個分足す
    ll t1 = x,cnt = 0,ans = 0;
    while(n){
        if(n & 1){
            ans += d2[cnt][t1];
            t1 = d1[cnt][t1];
        }
        n /= 2;
        cnt++;
    }
    print(ans);
    
    return 0;
}