/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/31386359
 * Submitted at: 2022-05-02 00:01:07
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_m
 * Result: AC
 * Execution Time: 276 ms
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
    rep(i,m){
        int a,b,c; cin >> a >> b >> c;
        a--; b--;
        Graph[a].push_back(P(c,b));
        Graph[b].push_back(P(c,a));
    }

    vector<int> time_1(n,INT_MAX),time_n(n,INT_MAX);
    time_1[0] = 0; time_n[n-1] = 0;
    priority_queue<P,vector<P>,greater<P>> todo;
    todo.push(P(0,0));
    while(!todo.empty()){
        auto [c,from] = todo.top(); todo.pop();
        for(auto [nc,to]:Graph[from]){
            if(time_1[to] > c + nc){
                time_1[to] = c + nc;
                todo.push(P(c+nc,to));
            }
        }
    }
    todo.push(P(0,n-1));
    while(!todo.empty()){
        auto [c,from] = todo.top(); todo.pop();
        for(auto [nc,to]:Graph[from]){
            if(time_n[to] > c + nc){
                time_n[to] = c + nc;
                todo.push(P(c+nc,to));
            }
        }
    }
    rep(i,n)cout << time_1[i]+time_n[i] << endl;

    return 0;
}