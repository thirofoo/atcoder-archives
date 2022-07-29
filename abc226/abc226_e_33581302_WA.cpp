/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc226/submissions/33581302
 * Submitted at: 2022-07-29 10:09:47
 * Problem URL: https://atcoder.jp/contests/abc226/tasks/abc226_e
 * Result: WA
 * Execution Time: 128 ms
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
    vector<P> edge;
    rep(i,m){
        int a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        edge.push_back(P(a,b));
    }

    //連結成分ごとに分けるpart
    vector<int>  visited(n,0),v_num(n,0);
    int cnt = 1;
    queue<int> todo;
    rep(i,n){
        if(visited[i])continue;
        todo.push(i);
        while(!todo.empty()){
            int now = todo.front(); todo.pop();
            if(visited[now])continue;
            visited[now] = cnt;
            v_num[cnt]++;
            for(auto k:Graph[now])todo.push(k);
        }
        cnt++;
    }

    //各連結成分において何個の辺が存在するかcountするpart
    vector<int> num(n,0);
    int ans = 0;
    for(auto [from,to]:edge){
        num[visited[from]]++;
        if(num[visited[from]] == v_num[visited[from]])ans += 2;
    }
    cout << ans << endl;
    
    return 0;
}