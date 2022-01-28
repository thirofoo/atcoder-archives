/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc224/submissions/28836028
 * Submitted at: 2022-01-28 15:14:17
 * Problem URL: https://atcoder.jp/contests/abc224/tasks/abc224_d
 * Result: AC
 * Execution Time: 1196 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int m,v; cin >> m;
    string s = "999999999";
    vector<vector<int>> edge(9);
    queue<string> todo;
    map<string,int> dist;
    rep(i,m){
        int a,b; cin >> a >> b;
        edge[a-1].push_back(b-1);
        edge[b-1].push_back(a-1);
    }
    rep(i,8){
        int a; cin >> a;
        s[a-1] = i+1 + '0';
    }
    dist[s] = 0; todo.push(s);
    while(!todo.empty()){
        string tmp = todo.front(); todo.pop();
        if(tmp == "123456789")return cout << dist[tmp] << endl,0;
        rep(i,9)if(tmp[i] == '9') v = i;
        for(auto k:edge[v]){
            string cand = tmp;
            swap(cand[v],cand[k]);
            if(dist.count(cand))continue;
            dist[cand] = dist[tmp] + 1;
            todo.push(cand);
        }
    }
    cout << -1 << endl;
    return 0;
}