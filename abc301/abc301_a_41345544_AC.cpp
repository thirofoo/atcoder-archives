/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc301/submissions/41345544
 * Submitted at: 2023-05-13 21:02:49
 * Problem URL: https://atcoder.jp/contests/abc301/tasks/abc301_a
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
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    string s; input(s);
    ll cnt = 0;
    rep(i,n)if(s[i] == 'T')cnt++;
    if(cnt == (n-cnt))print( (s.back() == 'T' ? 'A' : 'T') );
    else print( (cnt >= (n-cnt) ? "T" : "A") );
    
    return 0;
}