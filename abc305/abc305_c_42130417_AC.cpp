/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc305/submissions/42130417
 * Submitted at: 2023-06-10 21:10:02
 * Problem URL: https://atcoder.jp/contests/abc305/tasks/abc305_c
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll h,w; input(h,w);
    vector<string> f(h);
    rep(i,h)input(f[i]);

    ll x1 = LLONG_MAX,y1 = LLONG_MAX,x2 = 0,y2 = 0;
    rep(i,h){
        rep(j,w){
            if(f[i][j] == '#'){
                x1 = min(x1,i);
                x2 = max(x2,i);
                y1 = min(y1,j);
                y2 = max(y2,j);
            }
        }
    }
    for(ll i=x1;i<=x2;i++){
        for(ll j=y1;j<=y2;j++){
            if(f[i][j] == '.'){
                print(i+1,j+1);
                return 0;
            }
        }
    }
    
    return 0;
}