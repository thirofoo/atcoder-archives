/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc280/submissions/36950414
 * Submitted at: 2022-12-03 21:02:19
 * Problem URL: https://atcoder.jp/contests/abc280/tasks/abc280_b
 * Result: AC
 * Execution Time: 8 ms
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
    vector<ll> s(n);
    rep(i,n)input(s[i]);
    rep(i,n){
        if(i == 0)cout << s[i] << " ";
        else cout << s[i]-s[i-1] << " ";
    }
    print();
    
    return 0;
}