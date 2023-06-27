/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc156/submissions/43007474
 * Submitted at: 2023-06-27 23:53:57
 * Problem URL: https://atcoder.jp/contests/abc156/tasks/abc156_d
 * Result: AC
 * Execution Time: 50 ms
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
    
    ll n,a,b; input(n,a,b);
    mint ans = 1;
    vector<mint> r(70,0);
    r[0] = 2;
    for(ll i=1;i<70;i++)r[i] = r[i-1]*r[i-1];
    rep(i,40)if(n & (1LL << i))ans *= r[i];
    
    ans--;
    mint tmp1 = 1, tmp2 = 1;
    rep(i,a){
        tmp1 *= (n-i);
        tmp1 /= (i+1);
    }
    rep(i,b){
        tmp2 *= (n-i);
        tmp2 /= (i+1);
    }
    ans -= tmp1;
    ans -= tmp2;
    print(ans.val());
    
    return 0;
}