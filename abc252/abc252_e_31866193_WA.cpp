/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/31866193
 * Submitted at: 2022-05-21 22:05:31
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_e
 * Result: WA
 * Execution Time: 106 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,m; cin >> n >> m;
    priority_queue<T,vector<T>,greater<T>> todo;
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        todo.push(T(c,i,a,b));
    }

    dsu d(n);
    while(!todo.empty()){
        auto [c,i,a,b] = todo.top(); todo.pop();
        if(d.same(a,b))continue;
        else{
            cout << i+1 << " ";
            d.merge(a,b);
        }
    }
    cout << endl;
    return 0;
}