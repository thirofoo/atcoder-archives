/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc020/submissions/38922348
 * Submitted at: 2023-02-16 17:33:23
 * Problem URL: https://atcoder.jp/contests/agc020/tasks/agc020_c
 * Result: AC
 * Execution Time: 300 ms
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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // print(100ULL >> 63); // 0
    // print(100ULL >> 64); // 0
    // print(100ULL >> 65); // 0
    // ull i = 100;
    // print(i >> 63); // 0
    // print(i >> 64); // 100
    // print(i >> 65); // 50

    bitset<4000001> dp("1");
    ll n,sum = 0; input(n);
    vector<ll> a(n);
    rep(i,n){
        input(a[i]);
        sum += a[i];
        dp |= (dp << a[i]);
    }
    for(ll i=(sum+1)/2;i<=sum;i++){
        if(dp[i])return print(i),0;
    }
    
    return 0;
}