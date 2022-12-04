/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc174/submissions/37014732
 * Submitted at: 2022-12-04 17:06:18
 * Problem URL: https://atcoder.jp/contests/abc174/tasks/abc174_d
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
    
    ll n; string c; input(n,c);
    ll red = 0;
    rep(i,c.size())if(c[i] == 'R')red++;
    ll tmp = red,idx = 0;
    while(tmp--){
        if(c[idx] == 'R')red--;
        idx++;
    }
    print(red);
    
    return 0;
}