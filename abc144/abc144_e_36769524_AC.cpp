/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc144/submissions/36769524
 * Submitted at: 2022-11-25 16:44:20
 * Problem URL: https://atcoder.jp/contests/abc144/tasks/abc144_e
 * Result: AC
 * Execution Time: 597 ms
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
    vector<ll> a(n),f(n);
    rep(i,n)input(a[i]);
    rep(i,n)input(f[i]);
    sort(a.begin(),a.end());
    sort(f.begin(),f.end());
    reverse(f.begin(),f.end());

    ll left = -1,right = 1e15;
    while(right-left > 1){
        ll mid = (right + left)/2;
        ll tmp = 0;
        rep(i,n){
            // (a[i]-?)*f[i] <= mid となる?の総和で決め打ち二分探索
            ll l2 = -1,r2 = a[i];
            while(r2-l2 > 1){
                ll m2 = (l2 + r2)/2;
                if( (a[i]-m2)*f[i] <= mid )r2 = m2;
                else l2 = m2;
            }
            tmp += r2;
        }
        if(tmp <= k)right = mid;
        else left = mid;
    }
    print(right);
    
    return 0;
}