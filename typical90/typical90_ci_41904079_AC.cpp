/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41904079
 * Submitted at: 2023-06-02 14:52:48
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ci
 * Result: AC
 * Execution Time: 22 ms
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
    
    ll n,p,k; input(n,p,k);
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,n)rep(j,n)input(a[i][j]);

    ll l1 = 0, r1 = 1e16;
    while(r1-l1 > 1){
        ll mid = (r1+l1)/2;
        vector now(n,vector<ll>(n,LLONG_MAX));
        rep(i,n)rep(j,n)now[i][j] = (a[i][j] == -1 ? mid : a[i][j]);
        rep(i,n){
            rep(j,n){
                rep(l,n){
                    now[j][l] = min(now[j][l],now[j][i]+now[i][l]);
                }
            }
        }

        ll cnt = 0;
        rep(i,n){
            for(ll j=i+1;j<n;j++){
                if(now[i][j] <= p)cnt++;
            }
        }
        if(cnt <= k)r1 = mid;
        else l1 = mid;
    }

    ll l2 = 0, r2 = 1e16;
    while(r2-l2 > 1){
        ll mid = (r2+l2)/2;
        vector now(n,vector<ll>(n,LLONG_MAX));
        rep(i,n)rep(j,n)now[i][j] = (a[i][j] == -1 ? mid : a[i][j]);
        rep(i,n){
            rep(j,n){
                rep(l,n){
                    now[j][l] = min(now[j][l],now[j][i]+now[i][l]);
                }
            }
        }
        ll cnt = 0;
        rep(i,n){
            for(ll j=i+1;j<n;j++){
                if(now[i][j] <= p)cnt++;
            }
        }
        if(cnt <= k-1)r2 = mid;
        else l2 = mid;
    }

    print( (r2 == 1e16 && r1 != 1e16 ? "Infinity" : to_string(r2-r1)) );
    
    return 0;
}