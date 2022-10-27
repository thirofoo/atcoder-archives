/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/hhkb2020/submissions/35996081
 * Submitted at: 2022-10-27 18:21:46
 * Problem URL: https://atcoder.jp/contests/hhkb2020/tasks/hhkb2020_c
 * Result: AC
 * Execution Time: 39 ms
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
    vector<bool> p(200005);
    ll ans = 0;
    rep(i,n){
        ll tmp; input(tmp);
        p[tmp] = true;
        while(p[ans])ans++;
        print(ans);
    }
    
    return 0;
}