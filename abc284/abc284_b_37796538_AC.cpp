/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc284/submissions/37796538
 * Submitted at: 2023-01-07 21:02:49
 * Problem URL: https://atcoder.jp/contests/abc284/tasks/abc284_b
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
    
    ll t; input(t);
    while(t--){
        ll n; input(n);
        vector<ll> a(n);
        ll ans = 0;
        rep(i,n){
            input(a[i]);
            if(a[i]%2 == 1)ans++;
        }
        print(ans);
    }
    
    return 0;
}