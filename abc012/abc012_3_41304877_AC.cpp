/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc012/submissions/41304877
 * Submitted at: 2023-05-11 18:56:28
 * Problem URL: https://atcoder.jp/contests/abc012/tasks/abc012_3
 * Result: AC
 * Execution Time: 15 ms
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
    ll total = 0;
    rep(i,9)rep(j,9)total += (i+1)*(j+1);

    rep(i,9){
        rep(j,9){
            if((i+1)*(j+1) == total-n){
                print(i+1,"x",j+1);
            }
        }
    }
    
    return 0;
}