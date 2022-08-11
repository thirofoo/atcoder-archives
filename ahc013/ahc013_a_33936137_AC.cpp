/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc013/submissions/33936137
 * Submitted at: 2022-08-11 15:36:54
 * Problem URL: https://atcoder.jp/contests/ahc013/tasks/ahc013_a
 * Result: AC
 * Execution Time: 2959 ms
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
#define rep(i, n) for(int i = 0; i < n; i++)

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

inline unsigned int rand_int() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}

inline double rand_double() {
    return (double)(rand_int()%(int)1e9)/1e9;
}

//温度関数
#define TIME_LIMIT 2950
inline double temp(int start) {
    //時間が過ぎる程温度は低くなる → 採用率down
    //スコアの差分とtempが等しいと1/eの確率で採用されることになる
    double start_temp = 30,end_temp = 0.01;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int now,int next,int start) {
    //next > now なら必ず1以上になる。
    //逆ならnow-nextが小さい程、指数部が0に近い負の数になる → 採用率up
    //また、tempが大きい程、指数部が0に近い負の数になる → 採用率up
    return exp((double)(next - now) / temp(start));
}

//-----------------以下から実装部分-----------------//

int n,k,noSize = 0,bestScore = -INT_MAX;
//Graphは高々上下左右の4辺しか存在しないことを利用。
vector<vector<int>> Graph;

//答えの候補
vector<T> cand,connect,moveE;

//visited : 接続に影響を受けているマスならtrue
vector<vector<bool>> visited;

//visited2 : 属しているクラスタの親を格納
vector<vector<int>> visited2;

//field状況の配列
vector<string> field;

//空白の座標を格納
vector<P> nothing;

//bfs用
queue<P> todo;

//左上右下の順のdxdy
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

//各グループの要素数を保管する配列(一番左上の要素を親とする)
vector<int> num;



void init(){
    cin >> n >> k;
    k *= 100;
    field.assign(n,"");
    num.assign(n*n,0);
    rep(i,n)cin >> field[i];

    //空白の座標を管理
    rep(i,n)rep(j,n){
        if(field[i][j] == '0'){
            nothing.push_back(P(i,j));
            noSize++;
        }
    }
}

bool outField(int x,int y){
    if(x < 0 || x >= n || y < 0 || y >= n)return true;
    else return false;
}



//繋がっているグループの要素数を返す関数。
void serchGroup(int i,int j,int dr){

    char now = field[i][j];
    todo.push(P(i+dx[dr],j+dy[dr]));

    while(!todo.empty()){
        auto [x,y] = todo.front(); todo.pop();
        // cerr << x << " " << y << endl;
        if(outField(x,y) || visited[x][y])continue;
        visited[x][y] = true;

        if(field[x][y] == '0'){
            int nx = x+dx[dr],ny = y+dy[dr];
            if(!outField(nx,ny)){
                todo.push(P(nx,ny));
            }
            else{
                //目当てのマスが無い場合は今までvisitedしてきたところをリセット。
                while(x != i || y != j){
                    visited[x][y] = false;
                    x += dx[(dr+2)%4];
                    y += dy[(dr+2)%4];
                }
            }
        }
        else if(field[x][y] == now){
            // cout << "Yeah!" << now  << endl;
            Graph[i*n+j][dr] = x*n+y;
            Graph[x*n+y][(dr+2)%4] = i*n+j;
            // cerr << i << " " << j << " : " << x << " " << y << endl;
            visited[x][y] = false;
        }
        else{
            while(x != i || y != j){
                visited[x][y] = false;
                x += dx[(dr+2)%4];
                y += dy[(dr+2)%4];
            }
        }
    }
}



int calcScore(){
    int score = 0;
    //有向辺を張ってbfs → 1グル当たりのスコアがnC2よりスコアを求める。

    //有向辺を張るpart
    visited.assign(n,vector<bool>(n,false));
    Graph.assign(n*n,vector<int>(4,-1));
    rep(i,n){
        rep(j,n){
            if(visited[i][j] || field[i][j] == '0')continue;
            visited[i][j] = true;
            // cerr << i << " " << j << endl;

            //各ブロックにおいて右を確かめる
            serchGroup(i,j,2);

            //各ブロックにおいて下を確かめる
            serchGroup(i,j,3);
        }
    }

    // cerr << "第一ステップ完了！" << endl;

    //bfsをしてスコアを求めるpart
    queue<T> todo2;
    visited2.assign(n,vector<int>(n,-1));
    cand.erase(cand.begin(),cand.end());
    rep(i,n){
        rep(j,n){
            if(visited2[i][j] >= 0 || field[i][j] == '0')continue;
            visited2[i][j] = i*n+j;
            int cnt = 1;
            rep(l,4){
                int nx = Graph[i*n+j][l]/n;
                int ny = Graph[i*n+j][l]%n;
                if(nx < 0 || ny < 0)continue;
                todo2.push(T(i,j,nx,ny));
            }
            
            while(!todo2.empty()){
                auto [x,y,x2,y2] = todo2.front(); todo2.pop();
                if(visited2[x2][y2] >= 0)continue;
                // cerr << x2 << " " << y2 << " : " << field[x2][y2] << endl;

                visited2[x2][y2] = i*n+j;
                //答え出力
                cand.push_back(T(x,y,x2,y2));
                cnt++;

                rep(l,4){
                    int nx = Graph[x2*n+y2][l]/n;
                    int ny = Graph[x2*n+y2][l]%n;
                    if(nx < 0 || ny < 0)continue;
                    todo2.push(T(x2,y2,nx,ny));
                }
            }
            if(cnt <= 3){
                while(cnt != 1){
                    cand.pop_back();
                    cnt--;
                }
            }
            else{
                score += cnt*(cnt-1)/2;
                num[i*n+j] = cnt;
            }
        }
    }
    return score;
}



//近傍を求めるための関数
// int calcDiff(int x,int y,int dr){
//     //nx,ny : swap前に空白でない場所
//     int nx = x+dx[dr],ny = y+dy[dr],diff = 0;

//     //辺切断 & それによるスコア下げ & 残ったグループの要素数--part
//     rep(l,4){
//         //辺切断
//         int tmp = Graph[nx*n+ny][l];
//         if(tmp < 0)continue;
//         Graph[tmp][(l+2)%4] = -1;
//         Graph[nx*n+ny][l] = -1;

//         //要素数-- & diff反映
//         int xx = tmp/n,yy = tmp%n;
//         num[visited2[xx][yy]]--;
//         diff -= num[visited2[tmp/n][tmp%n]];

//         //通り道削除
//         visited[nx][ny] = false;
//         while(xx != nx || yy != ny){
//             visited[xx][yy] = false;
//             xx += dx[(dr+2)%4];
//             yy += dy[(dr+2)%4];
//         }
//     }

//     //辺再生
//     char now = field[x][y];
//     rep(i,4){
//         todo.push(P(x+dx[i],y+dy[i]));
//         while(!todo.empty()){
//             auto [tox,toy] = todo.front(); todo.pop();
//             // cout << x << " " << y << endl;
//             if(field[tox][toy] == '0'){
//                 int ntox = x+dx[i],ntoy = y+dy[i];
//                 if(!outField(ntox,ntoy)){
//                     todo.push(P(ntox,ntoy));
//                 }
//                 else{
//                     while(tox != x || toy != y){
//                         visited[tox][toy] = false;
//                         tox += dx[(i+2)%4];
//                         toy += dy[(i+2)%4];
//                     }
//                 }
//             }
//             else if(field[tox][toy] == now){
//                 //自分が属するグループを変更
//                 visited2[x][y] = visited2[tox][toy];

//                 //
//             }
//             else{
//                 tox += dx[(i+2)%4];
//                 toy += dy[(i+2)%4];
//                 while(tox != x || toy != y){
//                     visited[tox][toy] = false;
//                     tox += dx[(i+2)%4];
//                     toy += dy[(i+2)%4];
//                 }
//             }
//         }
//     }
//     return diff;
// }



//近傍の移動の関数
void moveNum(int x,int y,int nx,int ny){
    swap(field[x][y],field[nx][ny]);
}



int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    //入力受付
    init();
    utility::mytm.CodeStart();

    bestScore = calcScore();
    connect = cand;
    cerr << "Score = " << bestScore << endl;
    cerr << "Passed time : " << utility::mytm.elapsed() << "ms" << endl;


    //実行時間制限までギリギリ近傍シミュレーション
    int sTime = utility::mytm.elapsed();
    while(utility::mytm.elapsed() <= TIME_LIMIT){
        int nm = rand_int()%noSize;
        int dr = rand_int()%4;

        auto [x,y] = nothing[nm];
        int nx = x+dx[dr],ny = y+dy[dr];
        if(!outField(nx,ny) && field[nx][ny] != '0'){
            moveNum(x,y,nx,ny);
            int nowScore = calcScore();
        
            if(moveE.size()+cand.size()+1 > k){
                moveNum(x,y,nx,ny);
                continue;
            }

            //適当に焼きなまし
            if(nowScore > bestScore){
                cerr << nowScore << " " << bestScore << endl;
                bestScore = nowScore;
                connect = cand;
                nothing[nm] = P(nx,ny);

                moveE.push_back(T(nx,ny,x,y));

                //答え出力
                // cout << moveE.size() << endl;
                // for(auto [x1,y1,x2,y2]:moveE){
                //     cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                // }
                // cout << connect.size() << endl;
                // for(auto [x1,y1,x2,y2]:connect){
                //     cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
                // }
            }
            else if(nowScore != bestScore){
                double tmp = rand_double();
                double p = prob(bestScore*10,nowScore*10,sTime);
                if(tmp < p){
                    cerr << tmp << " " << p << " " << bestScore << " " << nowScore << endl;
                    bestScore = nowScore;
                    connect = cand;
                    nothing[nm] = P(nx,ny);
    
                    moveE.push_back(T(nx,ny,x,y));
                }
                else moveNum(x,y,nx,ny);
            }
            else moveNum(x,y,nx,ny);
        }
    }

    //答え出力
    cout << moveE.size() << endl;
    for(auto [x1,y1,x2,y2]:moveE){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    cout << connect.size() << endl;
    for(auto [x1,y1,x2,y2]:connect){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }

    
}