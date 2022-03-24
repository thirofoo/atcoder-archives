/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30378032
 * Submitted at: 2022-03-24 13:00:06
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_m
 * Result: AC
 * Execution Time: 1644 ms
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
    vector<vector<P>> Graph(n);
    while(m--){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        Graph[a].push_back(P(b,c));
        Graph[b].push_back(P(a,c));
    }

    vector<int> time_1(n,INT_MAX),time_n(n,INT_MAX);
    priority_queue<T,vector<T>,greater<T>> todo;
    for(auto [to,c]:Graph[0])todo.push(T(c,0,to));
    time_1[0] = 0;
    
    //1~kまでpart
    while(!todo.empty()){
        auto [c,a,b] = todo.top(); todo.pop();
        if(time_1[b] > time_1[a]+c){
            time_1[b] = time_1[a]+c;
            for(auto [to,c]:Graph[b]){
                todo.push(T(c,b,to));
            }
        }
    }

    for(auto [to,c]:Graph[n-1])todo.push(T(c,n-1,to));
    time_n[n-1] = 0;
    
    //n~kまでpart
    while(!todo.empty()){
        auto [c,a,b] = todo.top(); todo.pop();
        if(time_n[b] > time_n[a]+c){
            time_n[b] = time_n[a]+c;
            for(auto [to,c]:Graph[b]){
                todo.push(T(c,b,to));
            }
        }
    }

    rep(i,n)cout << time_1[i] + time_n[i] << endl;

    return 0;
}