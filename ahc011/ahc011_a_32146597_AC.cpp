/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc011/submissions/32146597
 * Submitted at: 2022-06-01 21:50:46
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
typedef pair<int, int> P;
#define rep(i, n) for(int i = 0; i < n; i++)

int n,t,sx,sy,sample_num;
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

//評価関数。
int calc_score(vector<vector<vector<bool>>>& tmp_ok,bool flag){

    int score = 0;
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
            }
        }
    }
    if(flag){
        rep(i,n){
            if(tmp_ok[i][0][0])score--;
            if(tmp_ok[0][i][1])score--;
            if(tmp_ok[i][n-1][2])score--;
            if(tmp_ok[n-1][i][3])score--;
        }
    }
    return score;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> t;
    sample_num = 14-n;

    //field作成 & 左上右下行けるか確認part
    field.assign(n,vector<int>(n,0));
    ok.assign(n,vector<vector<bool>>(n,vector<bool>(4,false)));
    rep(i,n){
        string s; cin >> s;
        rep(j,n){
            if(s[j] == '0'){
                sx = i; sy = j;
            }
            else if('a' <= s[j] && s[j] <= 'f'){
                field[i][j] = s[j]-'a'+10;
            }
            else field[i][j] = s[j]-'0';
            rep(k,4){
                if((field[i][j]-'0') & (1 << k)){
                    ok[i][j][k] = true;
                }
            }
        }
    }
    utility::mytm.CodeStart();

    //初期処理part
    

    //初期解作成(?)part
    vector<vector<vector<vector<bool>>>> oks(sample_num,vector<vector<vector<bool>>>(n,vector<vector<bool>>(n,vector<bool>(4,false))));
    vector<vector<vector<bool>>> tmp_ok;
    vector<string> ans(sample_num,"");
    vector<int> scores(sample_num,0);
    vector<P> best_p(sample_num,P(-1,-1));
    scores[sample_num-1] = calc_score(ok,true);
    best_p[sample_num-1] = P(sx,sy);
    stack<P> handle;

    while(utility::mytm.elapsed() <= 550){
        int now_x = sx,now_y = sy;
        int pre = -1;
        string tmp = "";
        tmp_ok = ok;
 
        rep(j,n*n){
            rep(i,t/n/n){
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
            int score = calc_score(tmp_ok,true);
 
            //scoreの順位に応じてsampleを更新。
            rep(i,sample_num){
                int idx = sample_num-1-i;
                if(score > scores[idx]){
                    for(int j=0;j<idx;j++){
                        swap(oks[j],oks[j+1]);
                        swap(scores[j],scores[j+1]);
                        swap(ans[j],ans[j+1]);
                        swap(best_p[j],best_p[j+1]);
                    }
                    oks[idx] = tmp_ok;
                    scores[idx] = score;
                    ans[idx] = tmp;
                    best_p[idx] = P(now_x,now_y);
                    break;
                }
            }
        }
    }

    //初期解から特定の手数だけ伸ばしてスコア更新part
    int cnt = 0,size = t-ans[cnt].size();
    tmp_ok = oks[cnt];
    bool flag = true;

    while(utility::mytm.elapsed() <= 2900){
        if(size < 10)continue;

        if(utility::mytm.elapsed() > 500+2400/sample_num * (cnt+1) && flag){
            //sampleが十分に集めきれてなかった場合は次に進まないようにする。
            if(cnt == sample_num-1 || best_p[cnt].first == -1)flag = false;
            else{
                cnt++;
                size = t-ans[cnt].size();
                tmp_ok = oks[cnt];
            }
        }

        int now_x = best_p[cnt].first,now_y = best_p[cnt].second;
        string tmp = "";
        int pre = -1;

        rep(i,20+(n >= 8 ? 5 : 0)+(n >= 9 ? 5 : 0)+(n >= 10 ? 5 : 0)){
            int r = rand_int()%4;
            int nx = now_x+dx[r],ny = now_y+dy[r]; 
            if(0 <= nx && nx < n && 0 <= ny && ny < n && pre != (r+2)%4){
                if(r == 0)tmp += "L";
                else if(r == 1)tmp += "U";
                else if(r == 2)tmp += "R";
                else tmp += "D";

                swap(tmp_ok[now_x][now_y],tmp_ok[nx][ny]);
                handle.push(P(now_x,now_y));
                handle.push(P(nx,ny));
                now_x += dx[r]; now_y += dy[r];
                pre = r;
            }
        }
        int score = calc_score(tmp_ok,false);
        if(score > scores[cnt]){
            size -= 10;
            scores[cnt] = score;
            ans[cnt] += tmp;
            best_p[cnt] = P(now_x,now_y);

            while(!handle.empty())handle.pop();
        }
        else{
            while(!handle.empty()){
                auto [x1,y1] = handle.top(); handle.pop();
                auto [x2,y2] = handle.top(); handle.pop();
                swap(tmp_ok[x1][y1],tmp_ok[x2][y2]);
            }
        }
    }

    //答え出力part
    int score = 0,idx = -1;
    rep(i,sample_num){
        if(scores[i] > score){
            score = scores[i];
            idx = i;
        }
    }
    cout << ans[idx] << endl;

    return 0;
}