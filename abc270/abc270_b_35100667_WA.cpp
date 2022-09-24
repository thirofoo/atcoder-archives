/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc270/submissions/35100667
 * Submitted at: 2022-09-24 21:13:03
 * Problem URL: https://atcoder.jp/contests/abc270/tasks/abc270_b
 * Result: WA
 * Execution Time: 10 ms
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
    
    ll x,y,z; input(x,y,z);
    if((x >= 0 && y >= 0 && y >= x) || (x <= 0 && y <= 0 && y <= x))print(abs(x));
    else if((y >= 0 && z >= 0 && z >= y) || ((y <= 0 && z <= 0 && z <= y)))print(-1);
    else print(abs(z)+abs(x-z));
    
    return 0;
}