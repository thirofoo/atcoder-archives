/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc277/submissions/36737679
 * Submitted at: 2022-11-23 19:12:22
 * Problem URL: https://atcoder.jp/contests/abc277/tasks/abc277_d
 * Result: AC
 * Execution Time: 64 ms
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
    
    ll n,m,total = 0; input(n,m);
    vector<ll> a(n);
    rep(i,n){
        input(a[i]);
        total += a[i];
    }
    sort(a.begin(),a.end());
    dsu uf(n);
    rep(i,n)if((a[i]+1)%m == a[(i+1)%n] || a[i] == a[(i+1)%n])uf.merge(i,(i+1)%n);
    
    ll ans = LLONG_MAX;
    vector<vector<int>> g = uf.groups();
    for(auto team:g){
        ll tmp = 0;
        for(auto ele:team)tmp += a[ele];
        print();
        ans = min(ans,total-tmp);
    }
    print(ans);
    
    return 0;
}