/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc270/submissions/35115485
 * Submitted at: 2022-09-24 21:39:01
 * Problem URL: https://atcoder.jp/contests/abc270/tasks/abc270_b
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
    
    ll x,y,z; input(x,y,z);
    if( (y >= 0 && y >= x) || (y <= 0 && y <= x) )print(abs(x));
    else{
        if( (y >= 0 && y >= z) || (y <= 0 && y <= z) )print(abs(z)+abs(x-z));
        else print(-1);
    }
    
    return 0;
}