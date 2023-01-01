/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc176/submissions/37672908
 * Submitted at: 2023-01-01 15:51:27
 * Problem URL: https://atcoder.jp/contests/abc176/tasks/abc176_e
 * Result: RE
 * Execution Time: 2617 ms
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
    
    ll h,w,m; input(h,w,m);
    vector<vector<ll>> num1(h+1,vector<ll>(w+1,0)),num2(h+1,vector<ll>(w+1,0));
    rep(i,m){
        ll h1,w1; input(h1,w1);
        h1--; w1--;
        num1[h1][0]++; num1[h1+1][0]--;
        num1[h1][w]--; num1[h1+1][w]++;
        num1[0][w1]++; num1[0][w1+1]--;
        num1[h][w1]--; num1[h][w1+1]++;
        num2[h1][w1]--;
    }
    rep(i,h+1)rep(j,w)num1[i][j+1] += num1[i][j];
    rep(i,w+1)rep(j,h)num1[j+1][i] += num1[j][i];
    ll ans = 0;
    rep(i,h)rep(j,w)ans = max(ans,num1[i][j]+num2[i][j]);
    print(ans);
    
    return 0;
}