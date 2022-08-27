/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc266/submissions/34412042
 * Submitted at: 2022-08-28 02:51:25
 * Problem URL: https://atcoder.jp/contests/abc266/tasks/abc266_f
 * Result: TLE
 * Execution Time: 3309 ms
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
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<ll>> Graph(n);
    vector<ll> dig(n,0);
    rep(i,n){
        ll u,v; cin >> u >> v; u--; v--;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        dig[u]++;
        dig[v]++;
    }

    //サイクル検出(次数が1のやつから探索していく)
    vector<bool> visited(n,false),visited2(n,false);
    queue<int> todo;
    rep(i,n)if(dig[i] == 1)todo.push(i);
    while(!todo.empty()){
        ll tmp = todo.front(); todo.pop();
        visited[tmp] = true;
        dig[tmp]--;
        for(auto to:Graph[tmp]){
            dig[to]--;
            if(!visited[to] && dig[to] == 1)todo.push(to);
        }
    }

    //サイクルで分断されている二つのグループを作成
    vector<set<ll>> group;
    rep(i,n){
        if(visited2[i])continue;
        set<ll> t;
        if(!visited[i])todo.push(i);
        while(!todo.empty()){
            ll tmp = todo.front(); todo.pop();
            visited2[tmp] = true;
            t.insert(tmp);
            for(auto to:Graph[tmp]){
                if(!visited2[to] && visited[to])todo.push(to);
            }
        }
        if(t.size() >= 1)group.push_back(t);
    }

    //各クエリに答える
    ll q,size = group.size(); cin >> q;
    while(q--){
        ll x,y; cin >> x >> y; x--; y--;
        bool f = false;
        rep(k,size)f |= (group[k].count(x) && group[k].count(y));
        if(f)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
    return 0;
}