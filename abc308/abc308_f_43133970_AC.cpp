/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc308/submissions/43133970
 * Submitted at: 2023-07-01 22:02:14
 * Problem URL: https://atcoder.jp/contests/abc308/tasks/abc308_f
 * Result: AC
 * Execution Time: 101 ms
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
    vector<ll> p(n), l(m), d(m);
    rep(i,n)input(p[i]);
    rep(i,m)input(l[i]);
    rep(i,m)input(d[i]);
    vector<P> c;
    rep(i,m)c.push_back(P(l[i],d[i]));
    sort(c.begin(),c.end());

    sort(p.begin(),p.end());
    priority_queue<ll> off;
    ll idx = 0, ans = 0;
    rep(i,n){
        while(idx != m){
            auto [nl,nd] = c[idx];
            if( p[i] < nl )break;
            off.push(nd);
            idx++;
        }
        ll v_off;
        if( off.empty() )v_off = 0;
        else {
            v_off = off.top();
            off.pop();
        }
        ans += p[i] - v_off;
    }
    print(ans);
    
    return 0;
}