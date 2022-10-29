/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc275/submissions/36047695
 * Submitted at: 2022-10-29 21:16:53
 * Problem URL: https://atcoder.jp/contests/abc275/tasks/abc275_d
 * Result: TLE
 * Execution Time: 2205 ms
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
        return memo[k/2] + f(k/3);
    }
    else if(memo[k/3]){
        return f(k/2) + memo[k/3];
    }
    else return f(k/2)+f(k/3);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    print(f(n));
    
    return 0;
}