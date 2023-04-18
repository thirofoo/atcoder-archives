/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc298/submissions/40737569
 * Submitted at: 2023-04-18 12:22:30
 * Problem URL: https://atcoder.jp/contests/abc298/tasks/abc298_f
 * Result: AC
 * Execution Time: 627 ms
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
    map<ll,ll> row,col;
    map<ll,map<ll,ll>> v;
    rep(i,n){
        ll r,c,x; input(r,c,x);
        v[r][c] += x;
        row[r] += x;
        col[c] += x;
    }
    vector<P> yoko;
    priority_queue<P> tate;
    for(auto [c,value]:col)tate.push(P(value,c));
    for(auto [r,value]:row)yoko.push_back(P(value,r));
    sort(yoko.begin(),yoko.end(),[](P a,P b){
        return a > b;
    });

    ll ans = 0;
    while(!tate.empty()){
        auto [v1,c] = tate.top(); tate.pop();
        for(auto &&[v2,r]:yoko){
            ll cand = v1+v2-(!v[r].count(c) ? 0 : v[r][c]);
            if(!v[r].count(c) && ans >= cand)break;
            ans = max(ans,cand);
        }
    }
    print(ans);
    
    return 0;
}