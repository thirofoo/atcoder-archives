/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/29387193
 * Submitted at: 2022-02-17 19:42:49
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_aq
 * Result: AC
 * Execution Time: 359 ms
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

vector<int> mx = {1,0,-1,0};
vector<int> my = {0,1,0,-1};

int main() {
    int h,w,rs,cs,rt,ct; cin >> h >> w >> rs >> cs >> rt >> ct;
    rs--; cs--; rt--; ct--;
    vector<vector<vector<int>>> cost(h,vector<vector<int>>(w,vector<int>(4,INT_MAX)));
    vector<string> field(h);
    rep(i,h)cin >> field[i];
    deque<T> todo;
    rep(i,4){
        cost[rs][cs][i] = 0;
        todo.push_back({rs,cs,i});
    }
    while(!todo.empty()){
        auto [x,y,dir] = todo.front(); todo.pop_front();
        rep(i,4){
            int tx = x+mx[i], ty = y+my[i], t_cost = cost[x][y][dir] + (dir == i ? 0 : 1);
            if(0 <= tx && tx < h && 0 <= ty && ty < w && field[tx][ty] != '#' && cost[tx][ty][i] > t_cost){
                cost[tx][ty][i] = t_cost;
                if(dir != i)todo.push_back({tx,ty,i});
                else todo.push_front({tx,ty,i});
            }
        }
    }
    int ans = INT_MAX;
    rep(i,4)ans = min(ans,cost[rt][ct][i]);
    cout << ans << endl;
    return 0;
}