/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc298/submissions/40737476
 * Submitted at: 2023-04-18 12:13:47
 * Problem URL: https://atcoder.jp/contests/abc298/tasks/abc298_f
 * Result: AC
 * Execution Time: 848 ms
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
    // 基本的に一番大きい列行のペア
    // ただ交点がある場合は他も候補になる
    map<ll,ll> row,col;
    map<ll,map<ll,ll>> v;
    rep(i,n){
        ll r,c,x; input(r,c,x);
        v[r][c] += x;
        row[r] += x;
        col[c] += x;
    }
    vector<P> yoko,tate;
    for(auto [r,value]:row)yoko.emplace_back(P(value,r));
    for(auto [c,value]:col)tate.emplace_back(P(value,c));
    sort(tate.begin(),tate.end(),[](auto a, auto b){
        return a > b;
    });
    priority_queue<T> todo;
    auto [v2,c] = tate[0];
    rep(i,yoko.size()){
        auto [v1,r] = yoko[i];
        todo.push(T(v1+v2-(!v[r].count(c) ? 0 : v[r][c]),i,0));
    }

    ll ans = 0;
    while(!todo.empty()){
        auto [value,ri,ci] = todo.top(); todo.pop();
        if(!v[yoko[ri].second].count(tate[ci].second) && ans >= value)continue;
        ans = max(ans,value);
        if(ci == tate.size()-1)continue;
        auto [pv1,pr] = yoko[ri];
        auto [pv2,pc] = tate[ci];
        auto [nv,nc] = tate[ci+1];
        value += (!v[pr].count(pc) ? 0 : v[pr][pc]);
        value -= (!v[pr].count(nc) ? 0 : v[pr][nc]);
        value -= pv2;
        value += nv;
        todo.push(T(value,ri,ci+1));
    }
    print(ans);
    
    return 0;
}