/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc179/submissions/34505631
 * Submitted at: 2022-09-02 14:43:14
 * Problem URL: https://atcoder.jp/contests/abc179/tasks/abc179_c
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll factorize(ll n){
    vector<ll> fact;
    for(ll i=1;i*i<=n;i++){
        if(n%i)continue;
        fact.push_back(i);
        if(i != n/i)fact.push_back(n/i);
    }
    return fact.size();
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,ans = 0; input(n);
    for(ll c=1;c<=n;c++){
        ans += factorize(n-c);
    }
    print(ans);
    
    return 0;
}