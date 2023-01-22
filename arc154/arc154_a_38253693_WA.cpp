/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc154/submissions/38253693
 * Submitted at: 2023-01-22 21:12:41
 * Problem URL: https://atcoder.jp/contests/arc154/tasks/arc154_a
 * Result: WA
 * Execution Time: 15 ms
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
#define rep(i, n) for(ll i = 0; i < n; i++)

ll mod = 998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; string a,b; input(n,a,b);
    rep(i,n)if(a[i] < b[i])swap(a[i],b[i]);
    ll a1 = 0,a2 = 0;
    rep(i,n){
        a1 %= mod;
        a1 *= 10;
        a1 += a[i]-'0';
    }
    rep(i,n){
        a2 %= mod;
        a2 *= 10;
        a2 += b[i]-'0';
    }
    print((a1*a2)%mod);
    
    return 0;
}