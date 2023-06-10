/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc305/submissions/42123572
 * Submitted at: 2023-06-10 21:04:15
 * Problem URL: https://atcoder.jp/contests/abc305/tasks/abc305_a
 * Result: AC
 * Execution Time: 7 ms
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
    ll ans = 0, min = LLONG_MAX;
    rep(i,21){
        if(abs(n-i*5) < min){
            ans = i*5;
            min = abs(n-i*5);
        }
    }
    print(ans);
    
    return 0;
}