/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/42062413
 * Submitted at: 2023-06-07 22:57:58
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_o
 * Result: AC
 * Execution Time: 43 ms
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
    vector<mint> fact(2*n+1,1);
    vector<mint> r_fact(2*n+1,1);
    for(int i=1;i<=2*n;i++){
        fact[i] = fact[i-1]*i;
        r_fact[i] = (mint)1/fact[i];
    }
    // ans[i] : i個ちょうど空きの数
    vector<mint> ans(n+1,0);
    for(ll ball=1;ball<=n;ball++){
        for(ll space=1;space<=n;space++){
            ll min_num = ball + (ball-1)*(space-1);
            if(min_num > n)break;
            ans[space] += fact[n-min_num+ball] * r_fact[n-min_num] * r_fact[ball];
        }
    }
    rep(i,n)print(ans[i+1].val());
    
    return 0;
}