/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc309/submissions/43342315
 * Submitted at: 2023-07-08 21:04:37
 * Problem URL: https://atcoder.jp/contests/abc309/tasks/abc309_a
 * Result: WA
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
    
    ll a,b; input(a,b);
    bool f = false;
    if(a >= 4)f |= (b == a-3);
    if(a%3 != 1)f |= (b == a-1);
    if(a%3 != 0)f |= (b == a+1);
    if(a <= 6)f |= (b == a+3);
    print( (f ? "Yes" : "No") );
    
    return 0;
}