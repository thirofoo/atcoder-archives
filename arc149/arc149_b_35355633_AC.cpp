/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc149/submissions/35355633
 * Submitted at: 2022-10-02 22:21:41
 * Problem URL: https://atcoder.jp/contests/arc149/tasks/arc149_b
 * Result: AC
 * Execution Time: 105 ms
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

ll LIS(vector<ll> a){
    ll n = a.size();
    vector<ll> ans(n,LLONG_MAX);
    rep(i,n){
        auto itr = lower_bound(ans.begin(),ans.end(),a[i]);
        *itr = a[i];
    }
    return lower_bound(ans.begin(),ans.end(),LLONG_MAX)-ans.begin();
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> a,c;
    vector<P> p;
    rep(i,n){
        ll t; input(t);
        a.push_back(t);   
    }
    rep(i,n){
        ll t; input(t);
        p.push_back(P(a[i],t));   
    }
    sort(p.begin(),p.end());
    rep(i,n){
        auto [A,B] = p[i];
        c.push_back(B);
    }
    print(n+LIS(c));
    
    return 0;
}