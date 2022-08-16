/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc013/submissions/34078246
 * Submitted at: 2022-08-16 09:55:22
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
vector<double> startTemp =  {0, 0, 10,   10,    10,   INFINITY};
vector<double> endTemp =    {0, 0, 0.05, 0.05,  0.05, INFINITY};
inline double temp(int start,int k) {
    //時間が過ぎる程温度は低くなる → 採用率down
    //スコアの差分とtempが等しいと1/eの確率で採用されることになる
    return startTemp[k] + (endTemp[k]-startTemp[k])*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int now,int next,int start,int k) {
    //next > now なら必ず1以上になる。
    //逆ならnow-nextが小さい程、指数部が0に近い負の数になる → 採用率up
    //また、tempが大きい程、指数部が0に近い負の数になる → 採用率up
    if(next-now >= validScore[k])return 1;
    return exp((double)(next - now - validScore[k]) / temp(start,k));
}

//-----------------以下から実装部分-----------------//
 
int n,k,K,sTime,nowTime,nm,dr;
int moveSize = 0,bestScore = 0,turn = 0,mSize = 0,eleBase = 15;
bool moveFlag,reFlag = false,firstFlag = true;
//Graph：隣接行列で表現
vector<vector<int>> Graph;
 
//答え格納配列
vector<T> cand,connect,movement;
priority_queue<T2> total;
priority_queue<int> ele;
 
//visited : 接続に影響を受けているマスならtrue
vector<vector<bool>> visited;
 
//field状況の配列
vector<string> field,reField;
 
//空白or数字のうち少ない方の座標を格納
vector<P> movedTile,baseTile;
 
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
    visited.assign(n,vector<bool>(n,false));
    moveFlag = (n*n <= 2*k);
    rep(i,n)cin >> field[i];
    reField = field;

    validScore[2] -= ((n-13)/3) * 10;
    validScore[3] -= ((n-13)/10) * 10;
    
    //動かす座標を管理
    rep(i,n)rep(j,n){
        if(field[i][j] == '0' && moveFlag){
            movedTile.push_back(P(i,j));
            moveSize++;
        }
        else if(field[i][j] != '0' && !moveFlag){
            movedTile.push_back(P(i,j));
            moveSize++;
        }
    }
    baseTile = movedTile;
    utility::mytm.CodeStart();
}
 
 
bool outField(int x,int y){
    if(x >= n || y >= n || x < 0 || y < 0)return true;
    else return false;
}
 
 
void visitUpdate(int c,int i,int j,int dr){
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
            visitUpdate(c+1,i,j,dr);
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
            if(!visited[i][j])continue;
            visited[i][j] = false;
            if(field[i][j] == '0')continue;
            
            int count = 1,p = i*n+j;
            rep(l,4){
                int nx = Graph[p][l]/n;
                int ny = Graph[p][l]%n;
                if(nx < 0 || ny < 0 || !visited[nx][ny])continue;
                todo.push(T(i,j,nx,ny));
            }
            
            while(!todo.empty()){
                auto [x,y,x2,y2] = todo.front(); todo.pop();
                if(!visited[x2][y2])continue;
                visited[x2][y2] = false;
                
                cand.push_back(T(x,y,x2,y2));
                count++;

                p = x2*n+y2;
                rep(l,4){
                    int nx = Graph[p][l]/n;
                    int ny = Graph[p][l]%n;
                    if(nx < 0 || ny < 0 || !visited[nx][ny])continue;
                    todo.push(T(x2,y2,nx,ny));
                }
            }
            
            if(firstFlag)ele.push(count);
            //eleBase以下のグルはスコアが低いから考慮しない
            if(count < eleBase)while((count--) != 1)cand.pop_back();
            else score += count*(count-1)/2;
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
// vector<int> validSwap1 = {0,0,1000,900,800,700};
int swapNum(int t,int r){
    if(t <= 1000+r)return 0;
    else return (t-1000-r)/300;
}
 

//遷移をリセットする関数
void queryReset(int c){
    while(c >= 0){
        auto [x1,y1,x2,y2] = query[c];
        moveNum(x1,y1,x2,y2);
        c--;
    }
}


void solve(){

    bestScore = calcScore();
    firstFlag = false;
    rep(i,min(K-1,(int)ele.size()-1))ele.pop();
    eleBase = ele.top();
    cerr << eleBase << endl;
 
    cerr << "Score = " << bestScore << endl;
    cerr << "Passed time : " << utility::mytm.elapsed() << "ms" << endl;

    
    int rn1 = rand_int()%moveSize,rn2;

    //実行時間制限までギリギリ近傍シミュレーション
    while((nowTime = utility::mytm.elapsed()) <= TIME_LIMIT){
        
        if(reFlag){
            total.push(T2(bestScore,movement,connect));
            field = reField;
            movement.assign(0,{});
            bestScore = calcScore();
            connect = move(cand);
            movedTile = baseTile;
            sTime = nowTime;
            reFlag = false;
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
 

        if(!outField(nx,ny) && ( (field[nx][ny] != '0' && moveFlag) || (field[nx][ny] == '0' && !moveFlag) )){

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
                if(moveFlag){
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
            if(mSize+dis+1+cand.size() > k){
                reFlag = true;
                continue;
            }
 
 
            //k <= 3の時だけ焼きなまし
            if(k <= 300){
                double tmp = rand_double();
                double p = prob(bestScore,nowScore,sTime,K);
                if(tmp < p){
                    // cerr << nowScore << " " << bestScore << endl;
                    bestScore = nowScore;
                    connect = cand;
                    movedTile[nm] = P(x+vx,y+vy);
                    mSize += dis+1;
                    rep(l,dis+1){
                        auto [x1,y1,x2,y2] = query[l];
                        if(moveFlag)movement.push_back(T(x2,y2,x1,y1));
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
                    mSize += dis+1;
                    rep(l,dis+1){
                        auto [x1,y1,x2,y2] = query[l];
                        if(moveFlag)movement.push_back(T(x2,y2,x1,y1));
                        else movement.push_back(T(x1,y1,x2,y2));
                    }
                }
                else queryReset(c-1);   
            }
        }
        turn++;
    }

    total.push(T2(bestScore,movement,connect));
    cerr << turn << endl;
}
 
 
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    //入力受付
    init();
 
    //問題解決部分
    solve();
 
    //答え出力
    printAnswer();
 
    return 0;
}