/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc292/submissions/39450137
 * Submitted at: 2023-03-05 00:37:37
 * Problem URL: https://atcoder.jp/contests/abc292/tasks/abc292_f
 * Result: AC
 * Execution Time: 11 ms
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
    cout << setprecision(12) << fixed;
    
    ld a,b; input(a,b);
    ld left = 0,right = 10000;
    while(right-left > 0.0000000001){
        ld mid = (right+left)/2;
        ld s = (mid <= a ? 0 : acos(a/mid));
        if(s <= M_PI/6 && mid*cos(M_PI/6-s) <= b)left = mid;
        else right = mid;
    }
    print(left);
    
    return 0;
}