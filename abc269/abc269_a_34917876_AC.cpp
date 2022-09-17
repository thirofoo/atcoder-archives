/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc269/submissions/34917876
 * Submitted at: 2022-09-17 21:00:42
 * Problem URL: https://atcoder.jp/contests/abc269/tasks/abc269_a
 * Result: AC
 * Execution Time: 21 ms
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
    
    ll a,b,c,d; input(a,b,c,d);
    print((a+b)*(c-d));
    print("Takahashi");
    
    return 0;
}