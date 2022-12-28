/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc023/submissions/37594225
 * Submitted at: 2022-12-28 15:38:10
 * Problem URL: https://atcoder.jp/contests/agc023/tasks/agc023_a
 * Result: AC
 * Execution Time: 81 ms
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
    vector<ll> a(n+1);
    rep(i,n){
        input(a[i+1]);
        a[i+1] += a[i];
    }
    map<ll,ll> mp;
    ll ans = 0;
    mp[0]++;
    rep(i,n){
        ans += mp[a[i+1]];
        mp[a[i+1]]++;
    }
    print(ans);
    
    return 0;
}