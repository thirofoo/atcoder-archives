/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc297/submissions/40452109
 * Submitted at: 2023-04-09 21:01:39
 * Problem URL: https://atcoder.jp/contests/abc297/tasks/abc297_a
 * Result: AC
 * Execution Time: 14 ms
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
    
    ll n,d; input(n,d);
    vector<ll> t(n);
    rep(i,n)input(t[i]);
    rep(i,n-1){
        if(t[i+1]-t[i] <= d){
            print(t[i+1]);
            return 0;
        }
    }
    print(-1);
    
    return 0;
}