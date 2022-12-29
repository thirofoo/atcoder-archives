/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc046/submissions/37608846
 * Submitted at: 2022-12-29 12:01:42
 * Problem URL: https://atcoder.jp/contests/abc046/tasks/arc062_b
 * Result: AC
 * Execution Time: 8 ms
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
    ll ans = s.size()/2;
    rep(i,s.size())if(s[i] == 'p')ans--;
    print(ans);
    
    return 0;
}