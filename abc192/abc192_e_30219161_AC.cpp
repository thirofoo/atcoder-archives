/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc192/submissions/30219161
 * Submitted at: 2022-03-19 14:23:44
 * Problem URL: https://atcoder.jp/contests/abc192/tasks/abc192_e
 * Result: AC
 * Execution Time: 147 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,m,x,y; cin >> n >> m >> x >> y;
    x--; y--;
    vector<vector<T>> Graph(n);
    rep(i,m){
        ll a,b,t,k; cin >> a >> b >> t >> k;
        a--; b--;
        Graph[a].push_back(T(b,t,k));
        Graph[b].push_back(T(a,t,k));
    }

    vector<ll> time(n,LLONG_MAX);
    time[x] = 0;
    priority_queue<T,vector<T>,greater<T>> todo;
    for(auto [to,t,k]:Graph[x]){
        //最初は待ち時間無しで出発→コストはtのみ。
        todo.push(T(t,x,to));
    }

    //djkstra
    while(!todo.empty()){
        auto [c,a,b] = todo.top(); todo.pop();
        if(time[b] > c){
            time[b] = c;
            for(auto [to,t,k]:Graph[b]){
                //(k-(time[b]%k))%k は次の出発時間までの時間。
                todo.push(T( time[b]+t+(k-(time[b]%k))%k ,b ,to ));
            }
        }
    }

    cout << (time[y] == LLONG_MAX ? -1 : time[y]) << endl;
    return 0;
}