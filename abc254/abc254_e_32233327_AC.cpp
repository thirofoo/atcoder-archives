/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc254/submissions/32233327
 * Submitted at: 2022-06-04 22:03:36
 * Problem URL: https://atcoder.jp/contests/abc254/tasks/abc254_e
 * Result: AC
 * Execution Time: 446 ms
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
    vector<vector<int>> Graph(n);
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }

    //頂点nから4まで離れた場所の総和を記録
    vector<vector<int>> num(n,vector<int>(4,0));
    vector<bool> visited(n,false);
    queue<P> todo;
    rep(i,n){
        vector<int> tmp;
        todo.push(P(i,0));
        while(!todo.empty()){
            auto [v,d] = todo.front(); todo.pop();
            if(visited[v])continue;
            visited[v] = true;
            tmp.push_back(v);
            num[i][d] += v+1;
            for(auto k:Graph[v]){
                if(d != 3)todo.push(P(k,d+1));
            }
        }
        for(auto k:tmp)visited[k] = false;
    }
    rep(i,n){
        rep(j,3){
            num[i][j+1] += num[i][j];
        }
    }

    int q; cin >> q;
    while(q--){
        int x,k; cin >> x >> k;
        x--;
        cout << num[x][k] << endl;
    }

    return 0;
}