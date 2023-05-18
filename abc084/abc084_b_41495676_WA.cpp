/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc084/submissions/41495676
 * Submitted at: 2023-05-18 18:47:37
 * Problem URL: https://atcoder.jp/contests/abc084/tasks/abc084_b
 * Result: WA
 * Execution Time: 16 ms
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
    string s; input(s);
    ll cnt = 0;
    rep(i,s.size()){
        if(s[i] == '-')cnt++;
    }
    if(cnt != 1)print("No");
    else if(s[0] != '-' && s.back() != '-')print("Yes");
    else print("No");
    
    return 0;
}