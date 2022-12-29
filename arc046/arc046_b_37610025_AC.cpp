/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc046/submissions/37610025
 * Submitted at: 2022-12-29 13:35:39
 * Problem URL: https://atcoder.jp/contests/arc046/tasks/arc046_b
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
    
    ll n,a,b; input(n,a,b);
    if(a == b)print(n%(a+1) == 0 ? "Aoki" : "Takahashi");
    else{
        if(a > b)print("Takahashi");
        else if(n <= a)print("Takahashi");
        else print("Aoki");
    }
    
    return 0;
}