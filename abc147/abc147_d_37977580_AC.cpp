/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc147/submissions/37977580
 * Submitted at: 2023-01-13 18:24:10
 * Problem URL: https://atcoder.jp/contests/abc147/tasks/abc147_d
 * Result: AC
 * Execution Time: 114 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    mint ans = 0,t = 1;
    rep(i,60){
        ll c0 = 0,c1 = 0;
        rep(j,n){
            if((a[j] & (1LL << i)))c1++;
            else c0++;
        }
        ans += t*c0*c1;
        t *= 2;
    }
    print(ans.val());
    
    return 0;
}