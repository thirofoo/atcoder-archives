/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc127/submissions/41495160
 * Submitted at: 2023-05-18 18:23:27
 * Problem URL: https://atcoder.jp/contests/abc127/tasks/abc127_b
 * Result: AC
 * Execution Time: 9 ms
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
    
    ll r,d,x; input(r,d,x);
    rep(i,10){
        x = r*x-d;
        print(x);
    }
    
    return 0;
}