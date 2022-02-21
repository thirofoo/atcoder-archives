/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/atc001/submissions/29559500
 * Submitted at: 2022-02-21 12:51:33
 * Problem URL: https://atcoder.jp/contests/atc001/tasks/dfs_a
 * Result: TLE
 * Execution Time: 2206 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

vector<int> mx = {1,0,-1,0};
vector<int> my = {0,1,0,-1};
bool frag = false;
int h,w;

void dfs(P start,vector<string>& field, vector<vector<bool>>& visited){
    auto [x,y] = start;
    visited[x][y] = true;
    rep(i,4){
        if(frag)break;
        int nx = x+mx[i],ny = y+my[i];
        if(nx < 0 || nx >=  h || ny < 0 || ny >= w|| visited[nx][ny] || field[nx][ny] == '#')continue;
        if(field[nx][ny] == 'g')frag = true;
        dfs(P(nx,ny),field,visited);
    }
    visited[x][y] = false;
}

int main() {
    cin >> h >> w;
    vector<string> field(h);
    rep(i,h)cin >> field[i];
    P start;
    rep(i,h)rep(j,w){
        if(field[i][j] == 's'){
            start = P(i,j); break;
        }
    }
    vector<vector<bool>> visited(h,vector<bool>(w,false));
    dfs(start,field,visited);
    cout << (frag ? "Yes" : "No") << endl;
    return 0;
}