/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc271/submissions/35273711
 * Submitted at: 2022-10-01 21:04:14
 * Problem URL: https://atcoder.jp/contests/abc271/tasks/abc271_a
 * Result: AC
 * Execution Time: 6 ms
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
    stack<char> ans;
    ans.push(n%16);
    n /= 16;
    ans.push(n%16);
    if(ans.top()%16 <= 9)cout << ans.top()%16;
    else cout << (char)('A'+(ans.top()-10)%16);
    ans.pop();
    if(ans.top()%16 <= 9)cout << ans.top()%16;
    else cout << (char)('A'+(ans.top()-10)%16);
    print();
    return 0;
}