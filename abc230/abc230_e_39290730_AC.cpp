/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc230/submissions/39290730
 * Submitted at: 2023-02-27 18:51:55
 * Problem URL: https://atcoder.jp/contests/abc230/tasks/abc230_e
 * Result: AC
 * Execution Time: 19 ms
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
    ll ans = 0;
    for(ll i=1;i<=sqrt(n);i++){
        ans += n/i;
    }
    print(ans*2-(ll)sqrt(n)*(ll)sqrt(n));
    
    return 0;
}