/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc208/submissions/29600555
 * Submitted at: 2022-02-23 15:26:20
 * Problem URL: https://atcoder.jp/contests/abc208/tasks/abc208_d
 * Result: TLE
 * Execution Time: 3308 ms
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
    int n,m,total = 0; cin >> n >> m;
    vector<vector<P>> Graph(n);
    priority_queue<T> todo;
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        Graph[a-1].push_back(P(b-1,c));
    }

    rep(s,n)rep(t,n)rep(k,n){
        if(s == t)continue;
        vector<int> visited(n,-1);
        visited[s] = 0;
        for(auto l:Graph[s])todo.push(T(l.second,s,l.first));
        while(!todo.empty()){
            auto[c,a,b] = todo.top(); todo.pop();
            if((visited[b] != -1 && visited[b] <= visited[a]+c) || (b > k && b != t))continue;
            visited[b] = visited[a]+c;
            for(auto l:Graph[b])todo.push(T(l.second,b,l.first));
        }
        if(visited[t] != -1)total += visited[t];
    }
    cout << total << endl;
    return 0;
}