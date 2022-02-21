/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/29559091
 * Submitted at: 2022-02-21 12:18:22
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bt
 * Result: AC
 * Execution Time: 5 ms
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
map<int,int> ans;
int h,w;

void dfs(int x,int y,vector<vector<int>>& seen,vector<string>& field){
    rep(i,4){
        int nx = x+mx[i],ny = y+my[i];
        if(nx < 0 || nx >= h || ny < 0 || ny >= w || field[nx][ny] == '#')continue;
        if(!seen[nx][ny]){
            seen[nx][ny] = seen[x][y] + 1;
            dfs(nx,ny,seen,field);
        }
        else if(seen[nx][ny] == 1 && seen[x][y] > 2){
            ans[nx*w+ny] = max(seen[x][y],ans[nx*w+ny]);
        }
    }
    seen[x][y] = 0;
}

int main() {
    cin >> h >> w;
    vector<string> field(h);
    vector<vector<int>> seen(h,vector<int>(w,0));
    rep(i,h)cin >> field[i];
    rep(i,h)rep(j,w){
        if(field[i][j] == '#')continue;
        seen[i][j] = 1;
        dfs(i,j,seen,field);
    }
    int a = 0;
    rep(i,h*w)a = max(a,ans[i]);
    cout << (a == 0 ? -1 : a) << endl;
    return 0;
}