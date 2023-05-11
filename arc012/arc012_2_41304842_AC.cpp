/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc012/submissions/41304842
 * Submitted at: 2023-05-11 18:53:50
 * Problem URL: https://atcoder.jp/contests/arc012/tasks/arc012_2
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
    cout << setprecision(10) << fixed;
    
    ld n,va,vb,l;
    input(n,va,vb,l);

    ld u = 0,k = l;
    rep(i,n){
        ld tmp = k-u;
        u = k;
        k += vb*(tmp/va);
    }
    print(k-u);
    
    return 0;
}