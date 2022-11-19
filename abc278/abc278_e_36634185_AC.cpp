/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc278/submissions/36634185
 * Submitted at: 2022-11-19 22:10:19
 * Problem URL: https://atcoder.jp/contests/abc278/tasks/abc278_e
 * Result: AC
 * Execution Time: 327 ms
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
    
    ll H,W,n,h,w; input(H,W,n,h,w);
    vector<vector<ll>> a(H,vector<ll>(W));
    rep(i,H)rep(j,W)input(a[i][j]);
    vector<vector<vector<ll>>> s(H+1,vector<vector<ll>>(W+1,vector<ll>(n,0)));
    vector<int> cnt(n,0);

    rep(i,H){
        rep(j,W){
            cnt[ a[i][j]-1 ]++;
            s[i+1][j+1][ a[i][j]-1 ]++;

            rep(k,n)s[i+1][j+1][k] += s[i][j+1][k];
            rep(k,n)s[i+1][j+1][k] += s[i+1][j][k];
            rep(k,n)s[i+1][j+1][k] -= s[i][j][k];
        }
    }

    vector<int> tmp;
    rep(i,H+1){
        if(i-h < 0)continue;
        rep(j,W+1){
            if(j-w < 0)continue;
            tmp.assign(n,0);
            rep(k,n)tmp[k] += s[i][j][k];
            rep(k,n)tmp[k] -= s[i-h][j][k];
            rep(k,n)tmp[k] -= s[i][j-w][k];
            rep(k,n)tmp[k] += s[i-h][j-w][k];

            int ans = 0;
            rep(k,n)if(cnt[k] == tmp[k])ans++;
            cout << n-ans << " ";
        }
        cout << endl;
    }
    
    return 0;
}