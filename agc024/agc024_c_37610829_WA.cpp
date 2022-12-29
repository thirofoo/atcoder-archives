/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc024/submissions/37610829
 * Submitted at: 2022-12-29 14:32:35
 * Problem URL: https://atcoder.jp/contests/agc024/tasks/agc024_c
 * Result: WA
 * Execution Time: 29 ms
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
    vector<ll> p(n);
    rep(i,n)input(p[i]);
    if(p[0] != 0)return print(-1),0;

    ll ans = 0,now = 0;
    for(ll i=n-1;i>=0;i--){
        if(p[i] > i)return print(-1),0;
        if(now > p[i])return print(-1),0;
        ans += p[i]-now;
        now = p[i];
        now--;
    }
    print(ans);
    
    return 0;
}