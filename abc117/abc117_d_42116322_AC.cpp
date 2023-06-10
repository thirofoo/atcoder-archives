/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc117/submissions/42116322
 * Submitted at: 2023-06-10 18:27:35
 * Problem URL: https://atcoder.jp/contests/abc117/tasks/abc117_d
 * Result: AC
 * Execution Time: 26 ms
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
    
    ll n,k; input(n,k);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    ll x = 0;
    for(ll i=60;i>=0;i--){
        ll cnt = 0;
        rep(j,n)cnt += ((a[j] & (1LL << i)) > 0);
        if(cnt < n-cnt){
            ll next = x | (1LL << i);
            if(next <= k)x = next;
        }
    }
    ll ans = 0;
    rep(i,n)ans += (x ^ a[i]);
    print(ans);
    
    return 0;
}