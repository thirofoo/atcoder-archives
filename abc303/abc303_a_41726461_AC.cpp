/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc303/submissions/41726461
 * Submitted at: 2023-05-27 21:01:45
 * Problem URL: https://atcoder.jp/contests/abc303/tasks/abc303_a
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
    string s,t; input(s,t);
    ll cnt = 0;
    rep(i,n){
        if(s[i] == '1' && t[i] == 'l')cnt++;
        if(s[i] == 'l' && t[i] == '1')cnt++;
        if(s[i] == 'o' && t[i] == '0')cnt++;
        if(s[i] == '0' && t[i] == 'o')cnt++;
        if(s[i] == t[i])cnt++;
    }
    print( (cnt == n ? "Yes" : "No") );
    
    return 0;
}