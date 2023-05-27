/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc303/submissions/41731378
 * Submitted at: 2023-05-27 21:06:09
 * Problem URL: https://atcoder.jp/contests/abc303/tasks/abc303_b
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
    
    ll n,m; input(n,m);
    vector<vector<ll>> a(m,vector<ll>(n));
    vector<vector<ll>> ok(n,vector<ll>(n,0));
    rep(i,m)rep(j,n)input(a[i][j]);
    rep(i,m){
        rep(j,n-1){
            ok[a[i][j]-1][a[i][j+1]-1]++;
            ok[a[i][j+1]-1][a[i][j]-1]++;
        }
    }
    ll ans = 0;
    rep(i,n)rep(j,n){
        if(i == j)continue;
        if(!ok[i][j])ans++;
    }
    print(ans/2);
    
    return 0;
}