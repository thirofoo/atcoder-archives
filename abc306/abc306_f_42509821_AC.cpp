/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc306/submissions/42509821
 * Submitted at: 2023-06-18 09:39:18
 * Problem URL: https://atcoder.jp/contests/abc306/tasks/abc306_f
 * Result: AC
 * Execution Time: 495 ms
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
    vector<vector<ll>> a(n,vector<ll>(m));
    vector<ll> comp;
    // 座標圧縮
    rep(i,n){
        rep(j,m){
            input(a[i][j]);
            comp.push_back(a[i][j]);
        }
    }
    sort(comp.begin(),comp.end());
    comp.erase( unique(comp.begin(),comp.end()), comp.end() );

    // fw : 今操作中のaの要素より後
    fenwick_tree<ll> fw(n*m);
    rep(i,n){
        rep(j,m){
            a[i][j] = lower_bound(comp.begin(),comp.end(),a[i][j])-comp.begin();
        }
    }
    ll ans = 0;
    rep(i,n){
        rep(j,m)ans += fw.sum(a[i][j]+1,n*m);
        rep(j,m)fw.add(a[i][j],1);
    }
    ll sum = (1+m)*m/2;
    print(ans + sum*n*(n-1)/2);
    
    return 0;
}