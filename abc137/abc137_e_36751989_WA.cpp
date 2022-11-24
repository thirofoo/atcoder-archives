/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc137/submissions/36751989
 * Submitted at: 2022-11-24 16:15:52
 * Problem URL: https://atcoder.jp/contests/abc137/tasks/abc137_e
 * Result: WA
 * Execution Time: 130 ms
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
    
    ll n,m,p; input(n,m,p);
    vector<T> edge;
    rep(i,m){
        ll a,b,c; input(a,b,c);
        a--; b--;
        edge.push_back(T(a,b,c));
    }
    
    ll ans = -LLONG_MAX;
    vector<ll> cost(n,-LLONG_MAX);
    cost[0] = 0;
    rep(i,n-1){
        rep(j,m){
            auto [from,to,c] = edge[j];
            if(cost[from] == -LLONG_MAX)continue;
            if(cost[to] < cost[from]+c-(i+1)*p){
                cost[to] = cost[from]+c-(i+1)*p;
            }
            if(to == n-1)ans = max({ans,cost[from]+c-(i+1)*p});
        }
    }
 
    vector<bool> ng(n,false);
    rep(i,n-1){
        rep(j,m){
            auto [from,to,c] = edge[j];
            if(cost[from] == -LLONG_MAX)continue;
            if(cost[to] < cost[from]+c-(i+1)*p){
                cost[to] = cost[from]+c-(i+1)*p;
                ng[to] = true;
            }
        }
    }
    print((ng[n-1] ? -1 : max(ans,0LL)));
    
    return 0;
}