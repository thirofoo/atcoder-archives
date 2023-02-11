/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc289/submissions/38795702
 * Submitted at: 2023-02-11 21:26:10
 * Problem URL: https://atcoder.jp/contests/abc289/tasks/abc289_d
 * Result: AC
 * Execution Time: 44 ms
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
    
    ll n; input(n);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    ll m; input(m);
    set<ll> b;
    rep(i,m){
        ll c; input(c);
        b.insert(c);
    }
    ll x; input(x);
    vector<bool> dp(1e5+5,false);
    dp[0] = true;
    for(ll i=1;i<1e5+5;i++){
        if(b.count(i))continue;
        rep(j,n){
            ll pre_x = i-a[j];
            if(pre_x < 0)continue;
            if(dp[pre_x])dp[i] = true;
        }
    }
    print(dp[x] ? "Yes" : "No");
    
    return 0;
}