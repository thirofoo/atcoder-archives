/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc273/submissions/35667834
 * Submitted at: 2022-10-15 21:08:42
 * Problem URL: https://atcoder.jp/contests/abc273/tasks/abc273_b
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
    
    ll x,k,tmp = 1; input(x,k);
    rep(i,k){
        if((x/tmp)%10 >= 5){
            x += tmp*10;
        }
        tmp *= 10;
        x /= tmp;
        x *= tmp;
    }
    print(x);
    
    return 0;
}