/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc191/submissions/31959138
 * Submitted at: 2022-05-26 14:53:40
 * Problem URL: https://atcoder.jp/contests/abc191/tasks/abc191_e
 * Result: AC
 * Execution Time: 152 ms
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
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,m; cin >> n >> m;
    vector<vector<P>> Graph(n);
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        Graph[a].push_back(P(c,b));
    }

    priority_queue<T,vector<T>,greater<T>> todo;
    vector<int> ans(n,INT_MAX),score;

    rep(i,n){
        score.assign(n,INT_MAX);
        for(auto [c,to]:Graph[i])todo.push(T(c,i,to));
        while(!todo.empty()){
            auto [c,from,to] = todo.top();todo.pop();
            if(score[to] <= c)continue;
            score[to] = c;
            for(auto [nc,nto]:Graph[to]){
                todo.push(T(c+nc,to,nto));
            }
        }
        if(score[i] == INT_MAX)continue;
        ans[i] = score[i];
    }

    rep(i,n)cout << (ans[i] == INT_MAX ? -1 : ans[i]) << endl;
    
    return 0;
}