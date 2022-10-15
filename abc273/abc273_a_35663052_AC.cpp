/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc273/submissions/35663052
 * Submitted at: 2022-10-15 21:02:00
 * Problem URL: https://atcoder.jp/contests/abc273/tasks/abc273_a
 * Result: AC
 * Execution Time: 17 ms
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

ll f(ll k){
    if(k == 0)return 1;
    return k*f(k-1);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    print(f(n));
    
    return 0;
}