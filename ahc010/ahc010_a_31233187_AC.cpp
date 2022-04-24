/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc010/submissions/31233187
 * Submitted at: 2022-04-24 18:44:10
 * Problem URL: https://atcoder.jp/contests/ahc010/tasks/ahc010_a
 * Result: AC
 * Execution Time: 1987 ms
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
 
//左上右下の順での移動表現
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};
 
//tileの状況
vector<string> tiles(30);
//tileを何回回転するかのメモ
vector<vector<int>> r_time(30,vector<int>(30,0));
//to[i][j][k]:tiles[i][j]に方向dから入った時の出る方向。
vector<vector<vector<int>>> to(30,vector<vector<int>>(30,vector<int>(4)));
 
namespace utility {
    struct timer {
        chrono::system_clock::time_point start;
 
        // 開始時間を記録
        void CodeStart() {
            start = chrono::system_clock::now();
        }
 
        // 経過時間 (s) を返す
        double elapsed() const {
            using namespace std::chrono;
            return (double)duration_cast<milliseconds>(system_clock::now() - start).count();
        }
    } mytm;
}
 
//Xor-shift (超高速乱数生成)
unsigned int randInt() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}
 
vector<char> ch1 = {'0','1','2','3'};
vector<char> ch2 = {'4','5'};
vector<char> ch3 = {'6','7'};
char to_ch(int i,int j){
    char now = tiles[i][j],tmp;
    if('0' <= now && now <= '3')tmp = ch1[(now-'0'+r_time[i][j])%4];
    else if(now == '4' || now == '5')tmp = ch2[(now-'0'+r_time[i][j])%2];
    else tmp = ch3[(now-'0'+r_time[i][j])%2];
    return tmp;
}
 
void to_memo(){
    rep(i,30)rep(j,30){
        switch(to_ch(i,j)){
            case '0':
                to[i][j][0] = 1;
                to[i][j][1] = 0;
                to[i][j][2] = -1;
                to[i][j][3] = -1;
                break;
            case '1':
                to[i][j][0] = 3;
                to[i][j][1] = -1;
                to[i][j][2] = -1;
                to[i][j][3] = 0;
                break;
            case '2':
                to[i][j][0] = -1;
                to[i][j][1] = -1;
                to[i][j][2] = 3;
                to[i][j][3] = 2;
                break;
            case '3':
                to[i][j][0] = -1;
                to[i][j][1] = 2;
                to[i][j][2] = 1;
                to[i][j][3] = -1;
                break;
            case '4':
                to[i][j][0] = 1;
                to[i][j][1] = 0;
                to[i][j][2] = 3;
                to[i][j][3] = 2;
                break;
            case '5':
                to[i][j][0] = 3;
                to[i][j][1] = 2;
                to[i][j][2] = 1;
                to[i][j][3] = 0;
                break;
            case '6':
                to[i][j][0] = 2;
                to[i][j][1] = -1;
                to[i][j][2] = 0;
                to[i][j][3] = -1;
                break;
            case '7':
                to[i][j][0] = -1;
                to[i][j][1] = 3;
                to[i][j][2] = -1;
                to[i][j][3] = 1;
                break;
        }
    }
}
 
ll CalcScore(){
    ll length1 = 0,length2 = 0;
    vector<vector<vector<bool>>> visited(30,vector<vector<bool>>(30,vector<bool>(4,false)));
    rep(i,30){
        rep(j,30){
            rep(k,4){
                if(visited[i][j][k])continue;
                int sx = i,sy = j,sd = k,tmp_l = 0,x = i,y = j,d = k;
                while(true){
                    visited[x][y][d] = true;
                    int nd = to[x][y][d];
                    if(nd == -1){
                        tmp_l = 0;
                        break;
                    }
                    visited[x][y][nd] = true;
                    x += dx[nd];
                    y += dy[nd];
                    if(x < 0 || 30 <= x || y < 0 || 30 <= y){
                        tmp_l = 0;
                        break;
                    }
                    //方向反転
                    d = (nd+2)%4;
                    tmp_l++;
                    if(x == sx && y == sy && d == sd)break;
                }
                if(tmp_l > length1){
                    length2 = length1;
                    length1 = tmp_l;
                }
                else if(tmp_l > length2)length2 = tmp_l;
                // if(tmp_l)cout << i << " " << j << " " << k << " : " << tmp_l << endl;
            }
        }
    }
    return length1*length2;
}
 
int main() {
    utility::mytm.CodeStart();
    
    rep(i,30)cin >> tiles[i];
 
    //処理part
    ll best_score = 0;
    string best_str = "";
    while(utility::mytm.elapsed() <= 1980){
        // cout << best_score << " ";
        string now_str = "";
        rep(i,30)rep(j,30){
            r_time[i][j] = randInt()%4;
            now_str += to_string(r_time[i][j]);
        }
        to_memo();
        ll now_score = CalcScore();
        if(now_score > best_score){
            best_score = now_score;
            best_str = now_str;
        }
    }
    cout << best_str << endl;
 
    // cout << best_score << endl;
    // cout << utility::mytm.elapsed() << endl;
 
    return 0;
}