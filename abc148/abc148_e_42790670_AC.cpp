/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc148/submissions/42790670
 * Submitted at: 2023-06-21 23:58:27
 * Problem URL: https://atcoder.jp/contests/abc148/tasks/abc148_e
 * Result: AC
 * Execution Time: 10 ms
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
    if(n%2 == 1){
        print(0);
        return 0;
    }
    ll ans = 0;
    while(n >= 10){
        ans += (n/10ll);
        n /= 5ll;
    }
    print(ans);
    
    return 0;
}