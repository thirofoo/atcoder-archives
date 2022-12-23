/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc152/submissions/37459252
 * Submitted at: 2022-12-23 19:56:09
 * Problem URL: https://atcoder.jp/contests/abc152/tasks/abc152_e
 * Result: WA
 * Execution Time: 10 ms
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

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    // LCM part
    ll lcm = a[0];
    rep(i,n)lcm = lcm * a[i] / euclid(lcm,a[i]);

    mint ans = 0;
    rep(i,n)ans += lcm / (mint)a[i];
    print(ans.val());
    
    return 0;
}