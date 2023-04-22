/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc299/submissions/40840995
 * Submitted at: 2023-04-22 21:15:24
 * Problem URL: https://atcoder.jp/contests/abc299/tasks/abc299_d
 * Result: AC
 * Execution Time: 18 ms
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
    ll left = 1,right = n+1;
    while(right-left > 1){
        ll mid = (right+left)/2;
        print("?",mid);
        cout << flush;
        ll s; input(s);
        if(s == 0)left = mid;
        else right = mid;
    }
    print("!",left);
    
    return 0;
}