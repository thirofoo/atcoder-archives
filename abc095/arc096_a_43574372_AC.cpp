/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc095/submissions/43574372
 * Submitted at: 2023-07-15 15:55:12
 * Problem URL: https://atcoder.jp/contests/abc095/tasks/arc096_a
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
    
    ll a,b,c,x,y; input(a,b,c,x,y);
    ll ans = 1e16, cand = 0;
    if( a+b >= c*2 ){
        ll mini = min(x,y);
        cand += c * 2 * mini;
        cand += a * (x - mini);
        cand += b * (y - mini);
        ans = min(ans,cand);

        cand = c * 2 * max(x,y);
        ans = min(ans,cand);
    }
    cand = 0;
    cand += a*x;
    cand += b*y;
    ans = min(ans,cand);

    print(ans);
    
    return 0;
}