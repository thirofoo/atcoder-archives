/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc137/submissions/36751542
 * Submitted at: 2022-11-24 15:46:37
 * Problem URL: https://atcoder.jp/contests/abc137/tasks/abc137_c
 * Result: AC
 * Execution Time: 73 ms
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
    map<string,ll> mp;
    rep(i,n){
        string s; input(s);
        sort(s.begin(),s.end());
        mp[s]++;
    }
    ll ans = 0;
    for(auto [k,num]:mp)ans += num*(num-1)/2;
    print(ans);
    
    return 0;
}