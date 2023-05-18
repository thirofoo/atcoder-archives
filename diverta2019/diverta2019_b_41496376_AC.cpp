/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/diverta2019/submissions/41496376
 * Submitted at: 2023-05-18 19:20:14
 * Problem URL: https://atcoder.jp/contests/diverta2019/tasks/diverta2019_b
 * Result: AC
 * Execution Time: 46 ms
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
    
    ll r,g,b,n; input(r,g,b,n);
    ll ans = 0;
    for(ll rn=0;rn<=n;rn++){
        for(ll gn=0;rn*r+gn*g<=n;gn++){
            if( (n-rn*r-gn*g)%b == 0 ){
                ans++;
            }
        }
    }
    print(ans);
    
    return 0;
}