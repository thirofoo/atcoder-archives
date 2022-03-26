/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc073/submissions/30411334
 * Submitted at: 2022-03-26 13:10:25
 * Problem URL: https://atcoder.jp/contests/abc073/tasks/abc073_d
 * Result: AC
 * Execution Time: 326 ms
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

int a,b,c;
vector<int> place;
vector<vector<P>> Graph;

int main() {
    int n,m,r; cin >> n >> m >> r;
    place.assign(r,0);
    Graph.assign(n,vector<P>(0));
    rep(i,r){
        int tmp; cin >> tmp;
        tmp--; place[i] = tmp;
    }
    rep(i,m){
        cin >> a >> b >> c;
        a--; b--;
        Graph[a].push_back(P(b,c));
        Graph[b].push_back(P(a,c));
    }

    vector<vector<int>> dp(1 << r,vector<int>(n,INT_MAX));
    priority_queue<T,vector<T>,greater<T>> todo;
    rep(i,r){
        todo.push(T(0,1 << i,place[i]));
        dp[1 << i][place[i]] = 0;
    }

    while(!todo.empty()){
        auto [c,bit,now] = todo.top(); todo.pop();
        for(auto [to,cost]:Graph[now]){
            int tmp = find(place.begin(),place.end(),to)-place.begin();

            int n_bit = bit | (tmp == r ? 0 : 1 << tmp);

            if(dp[n_bit][to] <= c + cost)continue;

            dp[n_bit][to] = c + cost;

            //目的の都市をまだ全て訪れてない時はpush。
            if(n_bit != (1 << r)-1)todo.push(T(c+cost, n_bit, to));
        }
    }

    int ans = INT_MAX;
    rep(i,n)ans = min(ans,dp[(1 << r)-1][i]);
    cout << ans << endl;

    return 0;
}