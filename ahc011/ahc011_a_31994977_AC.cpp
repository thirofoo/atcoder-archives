/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc011/submissions/31994977
 * Submitted at: 2022-05-28 19:18:23
 * Problem URL: https://atcoder.jp/contests/ahc011/tasks/ahc011_a
 * Result: AC
 * Execution Time: 2960 ms
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

//完全ランダムでスコア計算して更新出来たら更新。

//best_x,best_yは一番でかい要素の内部の点の一つ。
int n,t,sx,sy,best_x,best_y;
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

//scoreと最大要素の内の1点の座標を送る関数。
T calc_score(vector<vector<vector<bool>>>& tmp_ok){
    int score = 0,bx = -1,by = -1;
    visited.assign(n,vector<bool>(n,false));
    finished.assign(n,vector<bool>(n,false));
    rep(i,n){
        rep(j,n){
            if(visited[i][j])continue;
            visited[i][j] = true;
            int cand = 0; cycle_flag = false;
            dfs(&cand,-10,i,j,tmp_ok);
            if(cand > score){
                score = cand;
                bx = i; by = j;
            }
        }
    }
    return T(score,bx,by);
}


//dfsで最大要素のfixedを塗る。
void fix(vector<vector<bool>>& fixed,vector<vector<vector<bool>>>& ok,int pd){
    fixed[best_x][best_y] = true;
    rep(i,4){
        if(move_check(i,pd,best_x,best_y,ok)){
            best_x += dx[i];
            best_y += dy[i];
            fixed[best_x][best_y] = true;
            fix(fixed,ok,i);
        }
    }
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

    auto [s,cx,cy] = calc_score(ok);
    string ans = ""; int best = s,bx,by;
    vector<vector<vector<bool>>> tmp_ok,best_ok;

    //初期解作成(?)
    while(utility::mytm.elapsed() <= 1000){
        tmp_ok = ok;
        int now_x = sx,now_y = sy;
        string tmp = "";
        int pre = -1;

        rep(i,t){
            int r = rand_int()%4;
            int nx = now_x+dx[r],ny = now_y+dy[r]; 
            if(0 <= nx && nx < n && 0 <= ny && ny < n && pre != (r+2)%4){
                //移動できるなら移動。
                if(r == 0)tmp += "L";
                else if(r == 1)tmp += "U";
                else if(r == 2)tmp += "R";
                else tmp += "D";

                swap(tmp_ok[now_x][now_y],tmp_ok[nx][ny]);
                now_x += dx[r]; now_y += dy[r];
                pre = r;
            }
        }
        auto [score,i,j] = calc_score(tmp_ok);
        if(score > best){
            best_ok = tmp_ok;
            best = score;
            ans = tmp;
            bx = now_x,by = now_y;
            best_x = i,best_y = j;
        }
    }

    //第二段階。初期会から特定の手数だけ伸ばした時。
    ok = best_ok;
    int cnt = t-ans.size();
    while(utility::mytm.elapsed() <= 2950 && cnt >= 10){
        tmp_ok = ok;
        int now_x = bx,now_y = by;
        string tmp = "";
        int pre = -1;

        //周りが囲われてきたら30が出て対応できるように。
        rep(i,(rand_int()%3)*10){
            int r = rand_int()%4;
            int nx = now_x+dx[r],ny = now_y+dy[r]; 
            if(0 <= nx && nx < n && 0 <= ny && ny < n && pre != (r+2)%4){
                //移動できるなら移動。
                if(r == 0)tmp += "L";
                else if(r == 1)tmp += "U";
                else if(r == 2)tmp += "R";
                else tmp += "D";

                swap(tmp_ok[now_x][now_y],tmp_ok[nx][ny]);
                now_x += dx[r]; now_y += dy[r];
                pre = r;
            }
        }
        auto [score,i,j] = calc_score(tmp_ok);
        if(score > best){
            best = score;
            ans += tmp;
            ok = tmp_ok;
            bx = now_x,by = now_y;
        }
    }

    //答え出力。
    cout << ans << endl;

    return 0;
}