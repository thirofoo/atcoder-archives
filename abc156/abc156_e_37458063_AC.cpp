/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc156/submissions/37458063
 * Submitted at: 2022-12-23 18:21:32
 * Problem URL: https://atcoder.jp/contests/abc156/tasks/abc156_e
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,k; input(n,k);
    vector<mint> kaizyo(2*n+1,0);
    kaizyo[0] = 1;
    for(int i=1;i<=2*n;i++)kaizyo[i] = kaizyo[i-1]*i;
    if(k >= n-1)return print((kaizyo[2*n-1] / kaizyo[n] / kaizyo[n-1]).val()),0;

    mint ans = 0;
    rep(i,k+1){
        // point : 初めに0人の部屋を決めれば順番を考慮せずに済む！(順番で悩んでた)
        // 0人の部屋の選び方 * その他の部屋の重複組合せ (残n人をn-i部屋に分け方の総数) (n-1_C_n-i-1)
        ans += (kaizyo[n] / kaizyo[i] / kaizyo[n-i]) * (kaizyo[n-1] / kaizyo[n-1 - (n-i-1)] / kaizyo[n-i-1]);
    }

    
    print(ans.val());
    
    return 0;
}