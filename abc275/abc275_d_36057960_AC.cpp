/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc275/submissions/36057960
 * Submitted at: 2022-10-29 21:42:47
 * Problem URL: https://atcoder.jp/contests/abc275/tasks/abc275_d
 * Result: AC
 * Execution Time: 11 ms
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

map<ll,ll> memo;
ll f(ll k){
    if(k == 0)return 1;
    if(memo[k/2] && memo[k/3]){
        return memo[k/2] + memo[k/3];
    }
    else if(memo[k/2]){
        ll t = f(k/3);
        memo[k/3] = t;
        return memo[k/2] + t;
    }
    else if(memo[k/3]){
        ll t = f(k/2);
        memo[k/2] = t;
        return t + memo[k/3];
    }
    else{
        ll t = f(k/2),s = f(k/3);
        memo[k/2] = t;
        memo[k/3] = s;
        return t+s;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    print(f(n));
    
    return 0;
}