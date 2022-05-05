/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/nadafes2022_day1/submissions/31452287
 * Submitted at: 2022-05-05 18:57:17
 * Problem URL: https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_c
 * Result: AC
 * Execution Time: 230 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

//上右下左の順。
vector<int> dx = {-1,0,1,0};
vector<int> dy = {0,1,0,-1};

int main() {
    int h,w,k,turn = 0; cin >> h >> w >> k;
    vector<string> field(h);
    rep(i,h)cin >> field[i];

    bool frag = false;
    vector<vector<int>> visited(h,vector<int>(w,INT_MAX)),magma(h,vector<int>(w,INT_MAX));
    visited[0][0] = 0;
    queue<P> todo,mag;

    rep(i,h)rep(j,w)if(field[i][j] == '@')mag.push(P(i,j));
    todo.push(P(0,0));

    while(!todo.empty()){
        int size = todo.size();
        rep(i,size){
            auto [x,y] = todo.front(); todo.pop();
            // cout << x << " " << y << endl;
            if(field[x][y] != '.')continue;
            rep(j,4){
                int nx = x+dx[j],ny = y+dy[j];
                if(nx < 0 || h <= nx || ny < 0 || w <= ny || field[nx][ny] != '.' || visited[nx][ny] != INT_MAX)continue;
                visited[nx][ny] = visited[x][y]+1;
                //ゴール検知
                if(nx == h-1 && ny == w-1){
                    frag = true;
                    break;
                }
                todo.push(P(nx,ny));
            }
        }

        turn++;

        if(turn%k == 0){
            size = mag.size();
            rep(i,size){
                //1回流れたマグマに2回目は無い。(1回目で周りに浸食済みであるから)
                auto [x,y] = mag.front(); mag.pop();
                rep(j,4){
                    int nx = x+dx[j],ny = y+dy[j];
                    if(nx < 0 || h <= nx || ny < 0 || w <= ny || field[nx][ny] != '.')continue;
                    mag.push(P(nx,ny));
                    field[nx][ny] = '@';
                }
            }
        }

        // cout << "turn" << turn << endl;
        // rep(i,h){
        //     rep(j,w){
        //         cout << field[i][j] << " ";
        //     }
        //     cout << "   ";
        //     rep(j,w){
        //         cout << (visited[i][j] == INT_MAX ? -1 : visited[i][j]) << " ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        //ゴール地点が埋まってないか。
        if(field[h-1][w-1] != '.'){
            frag = false;
            break;
        }
        if(frag)break;
    }

    cout << (frag ? "Yes" : "No") << endl;
    return 0;
}