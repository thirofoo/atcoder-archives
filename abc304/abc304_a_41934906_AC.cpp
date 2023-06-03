/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc304/submissions/41934906
 * Submitted at: 2023-06-03 21:04:09
 * Problem URL: https://atcoder.jp/contests/abc304/tasks/abc304_a
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
    ll min = LLONG_MAX, idx = 0;
    vector<string> str;
    rep(i,n){
        string s; ll a; input(s,a);
        str.push_back(s);
        if(a < min){
            min = a;
            idx = i;
        }
    }
    rep(i,n)print(str[(i+idx)%n]);
    
    return 0;
}