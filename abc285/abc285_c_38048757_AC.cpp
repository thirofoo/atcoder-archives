/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc285/submissions/38048757
 * Submitted at: 2023-01-15 21:10:12
 * Problem URL: https://atcoder.jp/contests/abc285/tasks/abc285_c
 * Result: AC
 * Execution Time: 19 ms
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
    
    string s; input(s);
    ll ans = 0;
    rep(i,s.size()){
        ans *= 26;
        ans += s[i]-'A'+1;
    }
    print(ans);
    
    return 0;
}