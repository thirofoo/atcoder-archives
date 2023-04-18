/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc298/submissions/40745134
 * Submitted at: 2023-04-18 19:14:40
 * Problem URL: https://atcoder.jp/contests/abc298/tasks/abc298_a
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
    
    ll n; string s; input(n,s);
    ll ok = 0, ng = 0;
    rep(i,s.size()){
        if(s[i] == 'o')ok++;
        else if(s[i] == 'x')ng++;
    }
    if(ng)print("No");
    else if(ok)print("Yes");
    else print("No");
    
    return 0;
}