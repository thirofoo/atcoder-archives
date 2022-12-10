/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc281/submissions/37140521
 * Submitted at: 2022-12-10 21:03:23
 * Problem URL: https://atcoder.jp/contests/abc281/tasks/abc281_b
 * Result: AC
 * Execution Time: 5 ms
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
    if(s[0] < 'A' || 'Z' < s[0])return print("No"),0;
    if(s.back() < 'A' || 'Z' < s.back())return print("No"),0;
    if(s.size() != 8)return print("No"),0;
    if(s[1] == '0')return print("No"),0;
    rep(i,6)if(s[i+1] < '0' || '9' < s[i+1])return print("No"),0;
    print("Yes");
    
    return 0;
}