/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc287/submissions/38387283
 * Submitted at: 2023-01-28 21:10:17
 * Problem URL: https://atcoder.jp/contests/abc287/tasks/abc287_c
 * Result: AC
 * Execution Time: 108 ms
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
    vector<ll> cnt(n,0);
    vector<vector<ll>> Graph(n);
    dsu uf(n);
    rep(i,m){
        ll u,v; input(u,v); u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        cnt[u]++;
        cnt[v]++;
        uf.merge(u,v);
    }
    ll c1 = 0,c2 = 0;
    rep(i,n){
        if(cnt[i] == 1)c1++;
        else if(cnt[i] == 2)c2++;
        else return print("No"),0;
    }
    if(c1 != 2 || c2 != n-2)return print("No"),0;
    if(uf.size(0) == n)print("Yes");
    else print("No");
    
    return 0;
}