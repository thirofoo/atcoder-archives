/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc275/submissions/36037492
 * Submitted at: 2022-10-29 21:03:49
 * Problem URL: https://atcoder.jp/contests/abc275/tasks/abc275_b
 * Result: AC
 * Execution Time: 6 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll a,b,c,d,e,f; input(a,b,c,d,e,f);
    mint g = 1,h = 1;
    g *= a;
    g *= b;
    g *= c;
    h *= d;
    h *= e;
    h *= f;
    print((g-h).val());
    
    return 0;
}