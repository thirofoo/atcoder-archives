/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc011/submissions/32102512
 * Submitted at: 2022-05-30 12:35:28
 * Problem URL: https://atcoder.jp/contests/ahc011/tasks/ahc011_a
 * Result: RE
 * Execution Time: 3048 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(int i = 0; i < n; i++)

int n,t,sx,sy;
constexpr int sample_num = 6;
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
            if(cand > score){
                score = cand;
            }
        }
    }
    return score;
}


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> t;

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


    //初期解作成(?)part
    vector<string> ans(sample_num,"");
    vector<P> best_p(sample_num);
    vector<vector<vector<vector<bool>>>> oks(sample_num);
    vector<int> scores(sample_num,0);
    scores[0] = calc_score(ok);
    best_p[0] = P(sx,sy);

    vector<vector<vector<bool>>> tmp_ok;
    int count = 0;

    while(utility::mytm.elapsed() <= 550){
        count++;
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
        int score = calc_score(tmp_ok);

        //scoreの順位に応じてsampleを更新。
        rep(i,sample_num){
            if(score > scores[i]){
                for(int j=sample_num-1;j>=1+i;j--){
                    swap(oks[j-1],oks[j]);
                    swap(scores[j-1],scores[j]);
                    swap(ans[j-1],ans[j]);
                    swap(best_p[j-1],best_p[j]);
                }
                oks[i] = tmp_ok;
                scores[i] = score;
                ans[i] = tmp;
                best_p[i] = P(now_x,now_y);

                // cout << count << " : " << utility::mytm.elapsed() << "ms" << endl;
            }
        }
    }

    //初期解から特定の手数だけ伸ばしてスコア更新part1
    string ans1 = "";
    int first = calc_score(ok);
    int bx1,by1;
    vector<vector<vector<bool>>> first_ok;

    int cnt = 0,size = t-ans[cnt].size();
    tmp_ok = oks[cnt];
    stack<P> handle;

    while(utility::mytm.elapsed() <= 2950){
        if(size < 10)continue;

        if(utility::mytm.elapsed() > 550+2400/sample_num * (cnt+1)){
            cnt++;
            size = t-ans[cnt].size();
            tmp_ok = oks[cnt];
        }

        count++;
        int now_x = best_p[cnt].first,now_y = best_p[cnt].second;
        string tmp = "";
        int pre = -1;

        rep(i,15){
            int r = rand_int()%4;
            int nx = now_x+dx[r],ny = now_y+dy[r]; 
            if(0 <= nx && nx < n && 0 <= ny && ny < n && pre != (r+2)%4){
                //移動できるなら移動。
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
        int score = calc_score(tmp_ok);
        if(score > scores[cnt]){
            size -= 10;
            scores[cnt] = score;
            ans[cnt] += tmp;
            best_p[cnt] = P(now_x,now_y);

            // cout << count << " : " << utility::mytm.elapsed() << "ms" << endl;
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

    // cout << count << endl;
    // rep(i,sample_num)cout << ans[i] << endl;

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