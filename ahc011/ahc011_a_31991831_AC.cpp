/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc011/submissions/31991831
 * Submitted at: 2022-05-28 16:35:20
 * Problem URL: https://atcoder.jp/contests/ahc011/tasks/ahc011_a
 * Result: AC
 * Execution Time: 2908 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int n,t,sx,sy;
vector<string> str;
vector<vector<int>> field;

//各マスにおいて左上右下が行けるか行けないかを格納。
vector<vector<vector<bool>>> ok;

//左上右下の順の移動。
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

//score計算の為のdfs用。
vector<vector<bool>> visited,finished;


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


unsigned int rand_int() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}


int move_check(int d,int pd,int x,int y,vector<vector<vector<bool>>>& tmp_ok){
    int nx = x+dx[d],ny = y+dy[d];

    //前回行ったマスへの移動 or 場外 or (x,y)から方向dに行く道がない or 移動先に道が無い or 既に行ったことある場合。
    if(d == (pd+2)%4 || nx < 0 || nx >= n || ny < 0 || ny >= n || !tmp_ok[x][y][d] || !tmp_ok[nx][ny][(d+2)%4] || (visited[nx][ny] && finished[nx][ny]))return 0;
    
    //閉路が見つかった場合。
    if(visited[nx][ny] && !finished[nx][ny])return -1;

    return 1;
}


bool cycle_flag = false;
void dfs(int* cand,int pd,int x,int y,vector<vector<vector<bool>>>& tmp_ok){
    (*cand)++;

    rep(i,4){
        if(cycle_flag)break;
        int nx = x+dx[i],ny = y+dy[i];
        int now = move_check(i,pd,x,y,tmp_ok);

        if(now == -1)cycle_flag = true;
        else if(now == 1){
            visited[nx][ny] = true;
            dfs(cand,i,nx,ny,tmp_ok);
            finished[nx][ny] = true;
        }
    }
    //閉路が出来た瞬間に強制的にscore0。
    if(cycle_flag){
        *cand = 0;
        return;
    }
}


int calc_score(vector<vector<vector<bool>>>& tmp_ok){
    int score = 0;
    visited.assign(n,vector<bool>(n,false));
    finished.assign(n,vector<bool>(n,false));
    rep(i,n){
        rep(j,n){
            if(visited[i][j])continue;
            visited[i][j] = true;
            int cand = 0; cycle_flag = false;
            dfs(&cand,-10,i,j,tmp_ok);
            score = max(score,cand);
        }
    }
    return score;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> t;
    str.assign(n,"");
    rep(i,n)cin >> str[i];
    utility::mytm.CodeStart();

    //fieldを0~16に対応させつつ、左上右下に移動できるか確認。
    field.assign(n,vector<int>(n,0));
    ok.assign(n,vector<vector<bool>>(n,vector<bool>(4,false)));
    rep(i,n){
        rep(j,n){
            if(str[i][j] == '0'){
                sx = i; sy = j;
            }
            else if('a' <= str[i][j] && field[i][j] <= 'f'){
                field[i][j] = str[i][j]-'a'+10;
            }
            else field[i][j] = str[i][j]-'0';

            rep(k,4){
                if((field[i][j]-'0') & (1 << k)){
                    ok[i][j][k] = true;
                }
            }
        }
    }

    string ans = ""; int best = calc_score(ok);
    vector<vector<vector<bool>>> tmp_ok;

    while(utility::mytm.elapsed() <= 2900){
        tmp_ok = ok;
        int now_x = sx,now_y = sy;
        string tmp = "";

        rep(i,t){
            int r = rand_int()%4;
            if(0 <= now_x+dx[r] && now_x+dx[r] < n && 0 <= now_y+dy[r] && now_y+dy[r] < n){
                //移動できるなら移動。
                if(r == 0)tmp += "L";
                else if(r == 1)tmp += "U";
                else if(r == 2)tmp += "R";
                else tmp += "D";

                swap(tmp_ok[now_x][now_y],tmp_ok[now_x+dx[r]][now_y+dy[r]]);
                now_x += dx[r]; now_y += dy[r];
            }
        }
        int score = calc_score(tmp_ok);
        if(score > best){
            best = score;
            ans = tmp;
        }
    }

    //答え出力。
    cout << ans << endl;

    return 0;
}