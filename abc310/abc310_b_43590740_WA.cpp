/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc310/submissions/43590740
 * Submitted at: 2023-07-15 21:09:33
 * Problem URL: https://atcoder.jp/contests/abc310/tasks/abc310_b
 * Result: WA
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
    
    ll n,m; input(n,m);
    vector<vector<ll>> f(n,vector<ll>(m,0));
    vector<ll> p(n);
    rep(i,n){
        ll c; input(p[i],c);
        rep(j,c){
            ll tf; input(tf);
            tf--;
            f[i][tf]++;
        }
    }
    rep(i,n){
        rep(j,n){
            if(i == j || p[i] >= p[j])continue;
            bool flag = true;
            ll c1 = 0, c2 = 0;
            rep(k,m){
                if( !f[i][k] && f[j][k] ){
                    flag = false;
                    break;
                }
                c1 += f[i][k];
                c2 += f[j][k];
            }
            if( flag && (c1 != c2 || p[i] < p[j]) ){
                print("Yes");
                return 0;
            }
        }
    }
    print("No");
    
    return 0;
}