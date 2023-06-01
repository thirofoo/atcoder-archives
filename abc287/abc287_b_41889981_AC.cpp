/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc287/submissions/41889981
 * Submitted at: 2023-06-01 19:16:03
 * Problem URL: https://atcoder.jp/contests/abc287/tasks/abc287_b
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
    
    ll n,m; input(n,m);
    vector<string> s(n), t(m);
    rep(i,n)input(s[i]);
    rep(i,m)input(t[i]);
    ll ans = 0;
    rep(i,n){
        bool f = false;
        rep(j,m){
            bool tf = true;
            rep(k,3)tf &= (s[i][k+3] == t[j][k]);
            f |= tf;
        }
        if(f)ans++;
    }
    print(ans);
    
    return 0;
}