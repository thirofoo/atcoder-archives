/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc013/submissions/34060361
 * Submitted at: 2022-08-15 13:29:08
 * Problem URL: https://atcoder.jp/contests/ahc013/tasks/ahc013_a
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
typedef pair<int, int> P;
typedef tuple<int, int, int, int> T;
typedef tuple<int, vector<T>, vector<T>> T2;
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
//k == 5の時の温度は良くわからん。
vector<double> validScore = {0, 0, 130,  100,   25,   INFINITY};
vector<double> startTemp =  {0, 0, 10,   10,   10,   INFINITY};
vector<double> endTemp =    {0, 0, 0.05, 0.05, 0.05, INFINITY};
inline double temp(int start,int k) {
    //時間が過ぎる程温度は低くなる → 採用率down
    //スコアの差分とtempが等しいと1/eの確率で採用されることになる
    return startTemp[k] + (endTemp[k]-startTemp[k])*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//AHC013-温度設定
//seed0 : 15 : 0.05 で 6496点
//seed1 : 35 : 0.05 で 3894点
//seed1 : 5 : 0.05 score30↑で100% で 3894点
//seed3 : 25 : 0.05 で 2889点

//k = 2, 10 : 0.05 で score60↑で100% ave5600点位
//k = 3, 10 : 0.05 で score35↑で100% ave4200点位(密集してるほど点数取れない)
//k = 4, 10 : 0.05 で score35↑で100% ave4200点位(密集してるほど点数取れない)
//k = 5, 10 : 0.05 で score35↑で100% ave4200点位(密集してるほど点数取れない)

//焼きなましの採用確率
inline double prob(int now,int next,int start,int k) {
    //next > now なら必ず1以上になる。
    //逆ならnow-nextが小さい程、指数部が0に近い負の数になる → 採用率up
    //また、tempが大きい程、指数部が0に近い負の数になる → 採用率up
    if(next-now >= validScore[k])return 1;
    return exp((double)(next - now - validScore[k]) / temp(start,k));
}

//-----------------以下から実装部分-----------------//
 
int n,k,K,moveSize = 0,bestScore = -INT_MAX,cnt = 0,sTime,nowTime,nm,dr,eleBase = 10;
bool moveF;
//Graph：隣接行列で表現
vector<vector<int>> Graph;
 
//答え格納配列
vector<T> cand,connect,movement;
priority_queue<T2> total;
 
//visited : 接続に影響を受けているマスならtrue
vector<vector<bool>> visited;
 
//field状況の配列
vector<string> field,reField;
 
//空白or数字のうち少ない方の座標を格納
vector<P> movedTile;
 
//bfs用
queue<T> todo;
vector<T> query;
 
//左上右下の順のdxdy
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};
 
 
void init(){
    cin >> n >> k;
    K = k;
    k *= 100;
    field.assign(n,"");
    query.assign(2*n,{});
    moveF = (n*n <= 2*k);
    rep(i,n)cin >> field[i];
    reField = field;

    validScore[2] -= ((n-13)/3) * 10;
    validScore[3] -= ((n-13)/10) * 10;
 
    //空白の座標を管理
    rep(i,n)rep(j,n){
        if(field[i][j] == '0' && moveF){
            movedTile.push_back(P(i,j));
            moveSize++;
        }
        else if(field[i][j] != '0' && !moveF){
            movedTile.push_back(P(i,j));
            moveSize++;
        }
    }
}
 
 
bool outField(int x,int y){
    if(x >= n || y >= n || x < 0 || y < 0)return true;
    else return false;
}
 
 
void visitCount(int c,int i,int j,int x,int y,int dr){
    //目当てのマスが有る場合はvisitedを更新。
    while(c--){
        visited[i][j] = true;
        i += dx[dr];
        j += dy[dr];
    }
}
 
 
//有向辺を張ってグループ作成する関数
void serchGroup(int i,int j,int dr){
    char now = field[i][j];
    int x = i+dx[dr],y = j+dy[dr],c = 0;
    
    while(true){
        if(outField(x,y) || visited[x][y])break;
 
        if(field[x][y] == now){
            Graph[i*n+j][dr] = x*n+y;
            Graph[x*n+y][(dr+2)%4] = i*n+j;
            visitCount(c+1,i,j,x,y,dr);
            break;
        }
        else if(field[x][y] != '0')break;
 
        x += dx[dr]; y += dy[dr];
        c++;
    }
}
 
 
//評価関数
int calcScore(){
    int score = 0;
    //有向辺を張ってbfs → 1グル当たりのスコアがkC2よりスコアを求める。
 
    //有向辺を張るpart
    visited.assign(n,vector<bool>(n,false));
    Graph.assign(n*n,vector<int>(4,-1));
    rep(i,n){
        rep(j,n){
            if(visited[i][j])continue;
            visited[i][j] = true;
            if(field[i][j] == '0')continue;
 
            //各ブロックにおいて右を確かめる
            serchGroup(i,j,2);
 
            //各ブロックにおいて下を確かめる
            serchGroup(i,j,3);
        }
    }
 
    //bfsをしてスコアを求めるpart
    cand.assign(0,{});
    rep(i,n){
        rep(j,n){
            if(!visited[i][j] || field[i][j] == '0')continue;
            visited[i][j] = false;
            int cnt = 1;
            rep(l,4){
                int nx = Graph[i*n+j][l]/n;
                int ny = Graph[i*n+j][l]%n;
                if(nx < 0 || ny < 0 || !visited[nx][ny])continue;
                todo.push(T(i,j,nx,ny));
            }
            
            while(!todo.empty()){
                auto [x,y,x2,y2] = todo.front(); todo.pop();
                if(!visited[x2][y2])continue;
                visited[x2][y2] = false;
                
                cand.push_back(T(x,y,x2,y2));
                cnt++;
 
                rep(l,4){
                    int nx = Graph[x2*n+y2][l]/n;
                    int ny = Graph[x2*n+y2][l]%n;
                    if(nx < 0 || ny < 0 || !visited[nx][ny])continue;
                    todo.push(T(x2,y2,nx,ny));
                }
            }
            
            //大きさ10以下のグルはスコアが低いから考慮しない
            if(cnt <= eleBase)while((cnt--) != 1)cand.pop_back();
            else score += cnt*(cnt-1)/2;
        }
    }
    return score;
}

 
//近傍の移動の関数
void moveNum(int x,int y,int nx,int ny){
    swap(field[x][y],field[nx][ny]);
}
 
 
void printAnswer(){
    auto [a,b,c] = total.top();
    cout << b.size() << endl;
    for(auto [x1,y1,x2,y2]:b){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    cout << c.size() << endl;
    for(auto [x1,y1,x2,y2]:c){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    cerr << "Final Score : " << a << endl;
}
 
 
//swap回数を決める関数
vector<int> validSwap1 = {0,0,700,700,800,800};
int swapNum(int t,int r){
    if(t <= validSwap1[K]+r)return 0;
    else return (t-validSwap1[K]-r)/300;
}
 

//遷移をリセットする関数
void queryReset(int c){
    while(c >= 0){
        auto [x1,y1,x2,y2] = query[c];
        moveNum(x1,y1,x2,y2);
        c--;
    }
}
 

//最終仕上げをする関数
void beforeFinish(){
    rep(i,n)rep(j,n){
        if((field[i][j] == '0' && moveF) || (field[i][j] != '0' && !moveF)){
            rep(nr,4){
                int nx = i+dx[nr],ny = j+dy[nr];
                if(!outField(nx,ny) && ( (field[nx][ny] != '0' && moveF) || (field[nx][ny] == '0' && !moveF) )){
                    moveNum(i,j,nx,ny);

                    int nowScore = calcScore();

                    //score↑で更新
                    if(nowScore > bestScore && movement.size()+cand.size()+1 <= k){
                        bestScore = nowScore;
                        connect = cand;
                        if(moveF)movement.push_back(T(nx,ny,i,j));
                        else movement.push_back(T(i,j,nx,ny));
                    }
                    else moveNum(i,j,nx,ny);
                }
            }
        }
    }
    total.push(T2(bestScore,movement,connect));
}


void solve(){
    int rn1 = rand_int()%moveSize,rn2;

    //実行時間制限までギリギリ近傍シミュレーション
    while((nowTime = utility::mytm.elapsed()) <= TIME_LIMIT){
        
        //数手分余らせて次へ行く
        if(movement.size()+cand.size()+swapNum(nowTime,sTime)+1 + n/4 > k){
            //最終仕上げをして送る
            beforeFinish();
            field = reField;
            movement.assign(0,{});
            bestScore = calcScore();
            connect = move(cand);
            sTime = utility::mytm.elapsed();
            movedTile.assign(0,{});
            rep(i,n)rep(j,n){
                if(field[i][j] == '0' && moveF){
                    movedTile.push_back(P(i,j));
                }
                else if(field[i][j] != '0' && !moveF){
                    movedTile.push_back(P(i,j));
                }
            }
            continue;
        }

        rn2 = rand_int()%moveSize;
        nm = rn1;
        dr = (rn1+rn2)%4;
        rn1 = rn2;  
 
        //dis+1回移動
        int dis = swapNum(nowTime,sTime);
        auto [x,y] = movedTile[nm];
        int nx = x+dx[dr],ny = y+dy[dr],c = 0;
 

        if(!outField(nx,ny) && ( (field[nx][ny] != '0' && moveF) || (field[nx][ny] == '0' && !moveF) )){

            query[c] = T(x,y,nx,ny);
            moveNum(x,y,nx,ny);
            x += dx[dr],y += dy[dr];
            c++;
 
            //vx,vy : 変化量分
            int vx = 0,vy = 0;
            rep(i,dis){
                int ddr = rand_int()%4;
                vx += dx[ddr],vy += dy[ddr];
                int tox = x+vx,toy = y+vy;
                if(moveF){
                    if(!outField(tox,toy) && field[tox][toy] != '0'){
                        query[c] = T(tox-dx[ddr],toy-dy[ddr],tox,toy);
                        moveNum(tox-dx[ddr],toy-dy[ddr],tox,toy);
                        c++;
                    }
                    else{
                        vx -= dx[ddr],vy -= dy[ddr];
                        i--;
                    }
                }
                else{
                    if(!outField(tox,toy) && field[tox][toy] == '0'){
                        query[c] = T(tox-dx[ddr],toy-dy[ddr],tox,toy);
                        moveNum(tox-dx[ddr],toy-dy[ddr],tox,toy);
                        c++;
                    }
                    else{
                        vx -= dx[ddr],vy -= dy[ddr];
                        i--;
                    }
                }
            }


            int nowScore = calcScore();
 
 
            //k <= 3の時だけ焼きなまし
            if(k <= 300){
                double tmp = rand_double();
                double p = prob(bestScore,nowScore,sTime,K);
                if(tmp < p){
                    // cerr << nowScore << " " << bestScore << endl;
                    bestScore = nowScore;
                    connect = cand;
                    movedTile[nm] = P(x+vx,y+vy);
                    rep(l,c){
                        auto [x1,y1,x2,y2] = query[l];
                        if(moveF)movement.push_back(T(x2,y2,x1,y1));
                        else movement.push_back(T(x1,y1,x2,y2));
                    }
                }
                else queryReset(c-1);
            }
            else{
                //k >= 4は山登り
                if(nowScore > bestScore){
                    // cerr << nowScore << " " << bestScore << endl;
                    bestScore = nowScore;
                    connect = cand;
                    movedTile[nm] = P(x+vx,y+vy);
                    rep(l,c){
                        auto [x1,y1,x2,y2] = query[l];
                        if(moveF)movement.push_back(T(x2,y2,x1,y1));
                        else movement.push_back(T(x1,y1,x2,y2));
                    }
                }
                else queryReset(c-1);   
            }
        }
        cnt++;
    }

    total.push(T2(bestScore,movement,connect));
    cerr << cnt << endl;
}
 
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    //入力受付
    init();
    utility::mytm.CodeStart();
 
    bestScore = calcScore();
    while(bestScore == 0){
        bestScore = calcScore();
        eleBase--;
    }
    connect = cand;
 
    cerr << "Score = " << bestScore << endl;
    cerr << "Passed time : " << utility::mytm.elapsed() << "ms" << endl;
 
    //問題解決部分
    solve();
 
    //答え出力
    printAnswer();
 
    return 0;
}