/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc172/submissions/37273942
 * Submitted at: 2022-12-15 00:49:41
 * Problem URL: https://atcoder.jp/contests/abc172/tasks/abc172_d
 * Result: AC
 * Execution Time: 96 ms
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
    
    // point : 約数でfor文を回す
    ll n; input(n);
    ll ans = 0;
    // iを約数として持つものの合計
    // => 初項i 項差i 合計n/i項の総和 
    rep(i,n){
        ll num = n/(i+1),d = i+1;
        ans += (i+1 + i+1+(num-1)*d)*num/2;
    }
    print(ans);
    
    return 0;
}