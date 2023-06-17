/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc306/submissions/42339923
 * Submitted at: 2023-06-17 21:20:08
 * Problem URL: https://atcoder.jp/contests/abc306/tasks/abc306_b
 * Result: AC
 * Execution Time: 7 ms
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
    
    vector<unsigned long long> a(64);
    rep(i,64)input(a[i]);
    unsigned long long rui = 1, ans = 0;
    rep(i,64){
        ans += rui*a[i];
        rui *= 2;
    }
    print(ans);
    
    return 0;
}