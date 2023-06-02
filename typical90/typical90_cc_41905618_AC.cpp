/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41905618
 * Submitted at: 2023-06-02 16:17:39
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_cc
 * Result: AC
 * Execution Time: 248 ms
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
    // 2次元Gridにplot → 各人の±kの矩形内の人の数を調べる → 2次元imos
    vector<vector<ll>> imos(5005,vector<ll>(5005,0));
    rep(i,n){
        ll a,b; input(a,b);
        imos[a][b]++;
    }
    rep(i,5004)rep(j,5005)imos[i+1][j] += imos[i][j];
    rep(i,5005)rep(j,5004)imos[i][j+1] += imos[i][j];

    // 矩形の左下全探索
    ll ans = 1;
    for(ll i=1;i<=5000;i++){
        for(ll j=1;j<=5000;j++){
            ll cand = 0;
            cand += imos[min(i+k,5000LL)][min(j+k,5000LL)];
            cand -= imos[max(i-1,0LL)][min(j+k,5000LL)];
            cand -= imos[min(i+k,5000LL)][max(j-1,0LL)];
            cand += imos[max(i-1,0LL)][max(j-1,0LL)];
            ans = max(ans,cand);
        }
    }
    print(ans);
    
    return 0;
}