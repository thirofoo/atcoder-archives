/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc302/submissions/41550598
 * Submitted at: 2023-05-20 21:20:57
 * Problem URL: https://atcoder.jp/contests/abc302/tasks/abc302_d
 * Result: AC
 * Execution Time: 115 ms
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
    
    ll n,m,d; input(n,m,d);
    vector<ll> a(n),b(m);
    rep(i,n)input(a[i]);
    rep(i,m)input(b[i]);
    sort(b.begin(),b.end());

    ll ans = -1;
    rep(i,n){
        auto itr1 = lower_bound(b.begin(),b.end(),a[i]-d);
        auto itr2 = upper_bound(b.begin(),b.end(),a[i]+d);
        itr2--;
        if(abs(a[i]-*itr1) <= d)ans = max(a[i]+*itr1,ans);
        if(abs(a[i]-*itr2) <= d)ans = max(a[i]+*itr2,ans);
    }
    print(ans);
    
    return 0;
}