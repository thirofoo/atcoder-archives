/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc137/submissions/36751506
 * Submitted at: 2022-11-24 15:44:39
 * Problem URL: https://atcoder.jp/contests/abc137/tasks/abc137_b
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll k,x; input(k,x);
    for(int i=max(-1000000LL,x-k+1);i<=min(1000000LL,x+k-1);i++)cout << i << " ";
    print();
    
    return 0;
}