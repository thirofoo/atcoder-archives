/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc267/submissions/34535495
 * Submitted at: 2022-09-03 21:03:52
 * Problem URL: https://atcoder.jp/contests/abc267/tasks/abc267_a
 * Result: AC
 * Execution Time: 16 ms
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
    
    string s; input(s);
    vector<string> d = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    rep(i,5){
        if(d[i] == s)return print(5-i),0;
    }
    
    return 0;
}