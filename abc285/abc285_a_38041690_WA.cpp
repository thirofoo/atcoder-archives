/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc285/submissions/38041690
 * Submitted at: 2023-01-15 21:01:28
 * Problem URL: https://atcoder.jp/contests/abc285/tasks/abc285_a
 * Result: WA
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
    
    ll a,b; input(a,b);
    if(a > b)swap(a,b);
    if(2*a == b || 2*a == b+1)print("Yes");
    else print("No");
    
    return 0;
}