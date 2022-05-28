/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc011/submissions/31990089
 * Submitted at: 2022-05-28 15:10:42
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

int n,t,now_x,now_y;
vector<string> str;
vector<vector<int>> field;
//各マスにおいて左上右下が行けるか行けないかを格納。
vector<vector<vector<bool>>> ok;
//左上右下の順の移動。
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

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

int move_check(int d,int pd,int x,int y,vector<vector<bool>>& visited,vector<vector<bool>>& finished,vector<vector<vector<bool>>>& tmp_ok){
    int nx = x+dx[d],ny = y+dy[d];

    //場外 or (x,y)から方向dに行く道がない or 移動先に道が無い or 既に行ったことある場合。
    if(d == (pd+2)%4 || nx < 0 || nx >= n || ny < 0 || ny >= n || !tmp_ok[x][y][d] || !tmp_ok[nx][ny][(d+2)%4] || (visited[nx][ny] && finished[nx][ny]))return 0;
    
    //閉路が見つかった場合。
    if(visited[nx][ny] && !finished[nx][ny])return -1;

    return 1;
}

bool cycle_flag = false;
void dfs(ll* cand,int pd,int x,int y,vector<vector<bool>>& visited,vector<vector<bool>>& finished,vector<vector<vector<bool>>>& tmp_ok){
    if(cycle_flag)return;
    (*cand)++;

    rep(i,4){
        int now = move_check(i,pd,x,y,visited,finished,tmp_ok);
        if(now == -1){
            cycle_flag = true;
            break;
        }
        else if(now == 1){
            visited[x+dx[i]][y+dy[i]] = true;
            dfs(cand,i,x+dx[i],y+dy[i],visited,finished,tmp_ok);
            finished[x+dx[i]][y+dy[i]] = true;
        }
    }
    //閉路が出来た瞬間に強制的にscore0。
    if(cycle_flag){
        *cand = 0;
        return;
    }
}

ll calc_score(vector<vector<vector<bool>>>& tmp_ok){
    ll score = 0;
    vector<vector<bool>> visited(n,vector<bool>(n,false)),finished(n,vector<bool>(n,false));
    rep(i,n){
        rep(j,n){
            if(visited[i][j])continue;
            visited[i][j] = true;
            ll cand = 0; cycle_flag = false;
            dfs(&cand,-10,i,j,visited,finished,tmp_ok);
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
                now_x = i; now_y = j;
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

    // rep(i,n){
    //     rep(j,n){
    //         cout << field[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    string ans = ""; int best = calc_score(ok);
    while(utility::mytm.elapsed() <= 2900){
        vector<vector<vector<bool>>> tmp_ok = ok;
        int nx = now_x,ny = now_y;
        string tmp = "";
        rep(i,t){
            int r = rand_int()%4;
            if(0 <= nx+dx[r] && nx+dx[r] < n && 0 <= ny+dy[r] && ny+dy[r] < n){
                switch(r){
                    case 0:
                        tmp += "L";
                        break;
                    case 1:
                        tmp += "U";
                        break;
                    case 2:
                        tmp += "R";
                        break;
                    case 3:
                        tmp += "D";
                        break;
                }
                swap(tmp_ok[nx][ny],tmp_ok[nx+dx[r]][ny+dy[r]]);
                nx += dx[r];
                ny += dy[r];
            }
        }
        ll score = calc_score(tmp_ok);
        // cout << best << " ";
        if(score > best){
            best = score;
            ans = tmp;
        }
    }
    // cout << endl;

    // cout << best << endl;
    cout << ans << endl;

    return 0;
}