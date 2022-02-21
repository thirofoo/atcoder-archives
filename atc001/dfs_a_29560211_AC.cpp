/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/atc001/submissions/29560211
 * Submitted at: 2022-02-21 13:39:32
 * Problem URL: https://atcoder.jp/contests/atc001/tasks/dfs_a
 * Result: AC
 * Execution Time: 23 ms
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
vector<vector<bool>> visited(505,vector<bool>(505,false));
vector<string> field(505);
bool frag = false;
int h,w;

void dfs(int x,int y){
    if(frag) return;
    visited[x][y] = true;
    rep(i,4){
        if(frag) return;
        int nx = x+mx[i],ny = y+my[i];
        if(nx < 0 || nx >=  h || ny < 0 || ny >= w || visited[nx][ny] || field[nx][ny] == '#')continue;
        if(field[nx][ny] == 'g'){frag = true; return;}
        dfs(nx,ny);
    }
}

int main() {
    cin >> h >> w;
    rep(i,h)cin >> field[i];
    int start_x,start_y;
    rep(i,h)rep(j,w){
        if(field[i][j] == 's'){
            start_x = i;
            start_y = j;
        }
    }
    dfs(start_x,start_y);
    cout << (frag ? "Yes" : "No") << endl;
    return 0;
}