/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc192/submissions/31389986
 * Submitted at: 2022-05-02 09:22:39
 * Problem URL: https://atcoder.jp/contests/abc192/tasks/abc192_e
 * Result: AC
 * Execution Time: 150 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,m,x,y; cin >> n >> m >> x >> y;
    x--; y--;
    vector<vector<T>> Graph(n);
    rep(i,m){
        ll a,b,t,k; cin >> a >> b >> t >> k;
        a--; b--;
        Graph[a].push_back(T(t,k,b));
        Graph[b].push_back(T(t,k,a));
    }

    vector<ll> ans(n,LLONG_MAX);
    priority_queue<P,vector<P>,greater<P>> todo;
    ans[x] = 0;
    for(auto [t,k,b]:Graph[x])todo.push(P(t,b));
    while(!todo.empty()){
        auto [t,from] = todo.top(); todo.pop();
        if(ans[from] > t){
            ans[from] = t;
            for(auto [nt,k,to]:Graph[from]){
                todo.push(P(t + (k-t%k)%k + nt,to));
            }
        }
    }
    cout << (ans[y] == LLONG_MAX ? -1 : ans[y]) << endl;
    return 0;
}