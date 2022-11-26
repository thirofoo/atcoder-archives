/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc181/submissions/36783293
 * Submitted at: 2022-11-26 13:40:45
 * Problem URL: https://atcoder.jp/contests/abc181/tasks/abc181_e
 * Result: AC
 * Execution Time: 77 ms
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
    vector<ll> h(n),w(m);
    rep(i,n)input(h[i]);
    rep(i,m)input(w[i]);
    w.push_back(1e15);
    w.push_back(-1e15);
    sort(h.begin(),h.end());
    sort(w.begin(),w.end());

    ll total = 0,ans = LLONG_MAX;
    for(int i=2;i<n;i+=2)total += h[i]-h[i-1];
    rep(i,n){
        auto itr = lower_bound(w.begin(),w.end(),h[i]);
        ans = min(ans,total+min(abs(h[i]-*itr),abs(h[i]-*(itr-1))));
        if(i != n-1)total += (i%2 == 0 ? 1 : -1)*(-h[i]+h[i+1]);
    }
    print(ans);

    return 0;
}