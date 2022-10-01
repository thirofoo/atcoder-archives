/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc271/submissions/35275621
 * Submitted at: 2022-10-01 21:05:55
 * Problem URL: https://atcoder.jp/contests/abc271/tasks/abc271_b
 * Result: AC
 * Execution Time: 86 ms
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
    
    ll n,q; input(n,q);
    vector<vector<ll>> ans;
    rep(i,n){
        ll l; input(l);
        vector<ll> tmp;
        rep(j,l){
            ll a; input(a);
            tmp.push_back(a);
        }
        ans.push_back(tmp);
    }
    while(q--){
        ll s,t; input(s,t); s--; t--;
        print(ans[s][t]);
    }
    
    return 0;
}