/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc166/submissions/36945401
 * Submitted at: 2022-12-03 19:19:21
 * Problem URL: https://atcoder.jp/contests/abc166/tasks/abc166_e
 * Result: AC
 * Execution Time: 27 ms
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
    vector<ll> a(n),b(n,0);
    ll ans = 0;
    rep(i,n){
        input(a[i]);
        if(i-a[i] >= 0)ans += b[i-a[i]];
        if(i+a[i] < n)b[i+a[i]]++;
    }
    print(ans);
    
    return 0;
}