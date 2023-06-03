/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc304/submissions/41947695
 * Submitted at: 2023-06-03 21:19:28
 * Problem URL: https://atcoder.jp/contests/abc304/tasks/abc304_d
 * Result: AC
 * Execution Time: 278 ms
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

    ll w,h,n; input(w,h,n);
    vector<P> place;
    rep(i,n){
        ll p,q; input(p,q);
        place.push_back(P(p,q));
    }
    ll a,b; input(a);
    vector<ll> l1(a);
    rep(i,a)input(l1[i]);
    input(b);
    vector<ll> l2(b);
    rep(i,b)input(l2[i]);
    sort(l1.begin(),l1.end());
    sort(l2.begin(),l2.end());

    map<ll,ll> mp;
    rep(i,n){
        auto [x,y] = place[i];
        auto itr1 = lower_bound(l1.begin(),l1.end(),x);
        auto itr2 = lower_bound(l2.begin(),l2.end(),y);
        ll piece = (itr1-l1.begin()) + (itr2-l2.begin())*h;
        mp[piece]++;
    }

    ll cnt = 0, mi = LLONG_MAX, ma = 0;
    for(auto [key,v]:mp){
        mi = min(mi,v);
        ma = max(ma,v);
        cnt++;
    }
    if(cnt == (a+1)*(b+1))print(mi,ma);
    else print(0, ma);
    
    return 0;
}