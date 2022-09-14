/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc018/submissions/34852515
 * Submitted at: 2022-09-14 18:16:53
 * Problem URL: https://atcoder.jp/contests/abc018/tasks/abc018_2
 * Result: AC
 * Execution Time: 12 ms
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
    
    string s;ll n; input(s,n);
    rep(i,n){
        ll l,r; input(l,r); l--; r--;
        for(ll j=l;j<r;j++){
            swap(s[j],s[r]);
            r--;
        }
    }
    print(s);
    
    return 0;
}