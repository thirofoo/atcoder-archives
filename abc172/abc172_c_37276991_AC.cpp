/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc172/submissions/37276991
 * Submitted at: 2022-12-15 09:42:04
 * Problem URL: https://atcoder.jp/contests/abc172/tasks/abc172_c
 * Result: AC
 * Execution Time: 46 ms
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
    
    ll n,m,k; input(n,m,k);
    vector<ll> a(n+1,0),b(m+1,0);
    rep(i,n)input(a[i+1]);
    rep(i,m)input(b[i+1]);
    rep(i,n)a[i+1] += a[i];
    rep(i,m)b[i+1] += b[i];
    ll ans = 0;
    rep(i,n+1){
        ll tmp = a[i];
        if(tmp > k)continue;
        ll left = 0,right = m+1;
        while(right-left > 1){
            ll mid = (right+left)/2;
            if(tmp + b[mid] <= k)left = mid;
            else right = mid;
        }
        // print(i,left);
        ans = max(ans,i+left);
    }
    print(ans);
    
    return 0;
}