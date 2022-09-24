/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc270/submissions/35130280
 * Submitted at: 2022-09-24 22:20:47
 * Problem URL: https://atcoder.jp/contests/abc270/tasks/abc270_e
 * Result: AC
 * Execution Time: 32 ms
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
    ll left = 0,right = 0;
    rep(i,n){
        input(a[i]);
        right = max(right,a[i]);
    }
    right++;
    while(right-left > 1){
        ll mid = (right+left)/2,tmp = 0;
        rep(i,n)tmp += min(a[i],mid);
        if(tmp <= k)left = mid;
        else right = mid;
    }
    rep(i,n){
        k -= min(a[i],left);
        a[i] = max(0LL,a[i]-left);
    }
    rep(i,n){
        if(k == 0)break;
        if(a[i] == 0)continue;
        a[i]--; k--;
    }
    rep(i,n)cout << a[i] << " ";
    print();
    
    return 0;
}