/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc218/submissions/29858322
 * Submitted at: 2022-03-05 17:22:32
 * Problem URL: https://atcoder.jp/contests/abc218/tasks/abc218_e
 * Result: AC
 * Execution Time: 163 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m; cin >> n >> m;
    ll ans = 0;
    priority_queue<T,vector<T>,greater<T>> todo;
    dsu d(n);
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        todo.push(T(c,a-1,b-1));
    }
    while(!todo.empty()){
        auto [w,u,v] = todo.top(); todo.pop();
        if(!d.same(u,v) || w <= 0)d.merge(u,v);
        else ans += w;
    }
    cout << ans << '\n';
    return 0;
}