/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc192/submissions/30216052
 * Submitted at: 2022-03-19 10:56:10
 * Problem URL: https://atcoder.jp/contests/abc192/tasks/abc192_e
 * Result: TLE
 * Execution Time: 2207 ms
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
typedef tuple<int, int, int,int> T2;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,m,x,y; cin >> n >> m >> x >> y;
    x--; y--;
    vector<vector<T>> Graph(n);
    rep(i,m){
        int a,b,t,k; cin >> a >> b >> t >> k;
        a--; b--;
        Graph[a].push_back(T(b,t,k));
        Graph[b].push_back(T(a,t,k));
    }
    vector<ll> time(n,-1);
    time[x] = 0;
    priority_queue<T2,vector<T2>,greater<T2>> todo;
    for(auto l:Graph[x]){
        auto [to,t,k] = l;
        todo.push(T2(t,x,to,k));
    }
    while(!todo.empty()){
        auto [t,a,b,k] = todo.top(); todo.pop();
        if(time[b] == -1 || time[b] > time[a] + (k-time[a]%k)%k + t){
            time[b] = time[a] + (k-time[a]%k)%k + t;
            for(auto l:Graph[b]){
                auto [to,nt,nk] = l;
                if(to == a)continue;
                todo.push(T2(nt,b,to,nk));
            }
        }
    }
    cout << time[y] << endl;
    return 0;
}