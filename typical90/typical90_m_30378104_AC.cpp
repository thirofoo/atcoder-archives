/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30378104
 * Submitted at: 2022-03-24 13:06:15
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_m
 * Result: AC
 * Execution Time: 290 ms
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
    priority_queue<P,vector<P>,greater<P>> todo;
    time_1[0] = 0;
    for(auto [to,c]:Graph[0])todo.push(P(c,to));
    
    //1~kまでpart
    while(!todo.empty()){
        auto [c,b] = todo.top(); todo.pop();
        if(time_1[b] > c){
            time_1[b] = c;
            for(auto [to,c]:Graph[b]){
                todo.push(P(time_1[b]+c,to));
            }
        }
    }

    time_n[n-1] = 0;
    for(auto [to,c]:Graph[n-1])todo.push(P(c,to));
    
    //n~kまでpart
    while(!todo.empty()){
        auto [c,b] = todo.top(); todo.pop();
        if(time_n[b] > c){
            time_n[b] = c;
            for(auto [to,c]:Graph[b]){
                todo.push(P(time_n[b]+c,to));
            }
        }
    }

    rep(i,n)cout << time_1[i] + time_n[i] << endl;

    return 0;
}