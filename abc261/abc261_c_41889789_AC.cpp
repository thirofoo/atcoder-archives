/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc261/submissions/41889789
 * Submitted at: 2023-06-01 19:06:34
 * Problem URL: https://atcoder.jp/contests/abc261/tasks/abc261_c
 * Result: AC
 * Execution Time: 125 ms
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
    vector<string> s(n);
    rep(i,n)input(s[i]);
    map<string,ll> mp;
    rep(i,n){
        if(mp.count(s[i]))print(s[i] + "(" + to_string(mp[s[i]]) + ")");
        else print(s[i]);
        mp[s[i]]++;
    }
    
    return 0;
}