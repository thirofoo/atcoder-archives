/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc305/submissions/42125637
 * Submitted at: 2023-06-10 21:05:41
 * Problem URL: https://atcoder.jp/contests/abc305/tasks/abc305_b
 * Result: AC
 * Execution Time: 5 ms
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

vector<ll> d = {0,3,4,8,9,14,23};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    char p,q; input(p,q);
    print( abs(d[p-'A'] - d[q-'A']) );
    
    return 0;
}