/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc080/submissions/38345123
 * Submitted at: 2023-01-27 09:43:58
 * Problem URL: https://atcoder.jp/contests/abc080/tasks/abc080_d
 * Result: AC
 * Execution Time: 58 ms
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
    
    ll n,c; input(n, c); 
    vector<vector<ll>> v(c, vector<ll>(1e5+5,0));
    rep(i, n) {
        ll s,t,c; input(s,t,c); c--;
        v[c][s-1]++;
        v[c][t]--;
    }
    rep(i,c)rep(j,1e5+4)v[i][j+1] += v[i][j];
    ll ans = -1;
    rep(i,1e5+5){
        ll tmp = 0;
        rep(j,c)tmp += (v[j][i] >= 1);
        ans = max(ans,tmp);
    }
    print(ans);
    
    return 0;
}