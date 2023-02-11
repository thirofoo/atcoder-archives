/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc289/submissions/38780231
 * Submitted at: 2023-02-11 21:01:14
 * Problem URL: https://atcoder.jp/contests/abc289/tasks/abc289_a
 * Result: AC
 * Execution Time: 9 ms
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
    
    string s; input(s);
    rep(i,s.size()){
        if(s[i] == '0')s[i] = '1';
        else s[i] = '0';
    }
    print(s);
    
    return 0;
}