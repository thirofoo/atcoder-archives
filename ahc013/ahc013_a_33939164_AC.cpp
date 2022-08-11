/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc013/submissions/33939164
 * Submitted at: 2022-08-11 18:00:24
 * Problem URL: https://atcoder.jp/contests/ahc013/tasks/ahc013_a
 * Result: AC
 * Execution Time: 2968 ms
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
    double start_temp = 100,end_temp = 1;
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
//Graph：隣接行列で表現
vector<vector<int>> Graph;

//答え格納配列
vector<T> cand,connect,movement;

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


void visitReset(vector<vector<bool>>& visited,int x,int y,int i,int j,int dr){
    //目当てのマスが無い場合はvisitedを移動前にリセット。
    while(x != i || y != j){
        visited[x][y] = false;
        x += dx[(dr+2)%4];
        y += dy[(dr+2)%4];
    }
}


//有向辺を張ってグループ作成する関数
void serchGroup(int i,int j,int dr){
    char now = field[i][j];
    todo.push(P(i+dx[dr],j+dy[dr]));

    while(!todo.empty()){
        auto [x,y] = todo.front(); todo.pop();
        if(outField(x,y) || visited[x][y])continue;
        visited[x][y] = true;

        if(field[x][y] == '0'){
            int nx = x+dx[dr],ny = y+dy[dr];
            if(!outField(nx,ny)){
                todo.push(P(nx,ny));
            }
            else visitReset(visited,x,y,i,j,dr);
        }
        else if(field[x][y] == now){
            Graph[i*n+j][dr] = x*n+y;
            Graph[x*n+y][(dr+2)%4] = i*n+j;
            visited[x][y] = false;
        }
        else visitReset(visited,x,y,i,j,dr);
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
            if(visited[i][j] || field[i][j] == '0')continue;
            visited[i][j] = true;

            //各ブロックにおいて右を確かめる
            serchGroup(i,j,2);

            //各ブロックにおいて下を確かめる
            serchGroup(i,j,3);
        }
    }

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
                visited2[x2][y2] = i*n+j;
                
                cand.push_back(T(x,y,x2,y2));
                cnt++;

                rep(l,4){
                    int nx = Graph[x2*n+y2][l]/n;
                    int ny = Graph[x2*n+y2][l]%n;
                    if(nx < 0 || ny < 0)continue;
                    todo2.push(T(x2,y2,nx,ny));
                }
            }
            
            //大きさ3以下のグルはスコアが低いから考慮しない
            if(cnt <= 3)while((cnt--) != 1)cand.pop_back();
            else{
                score += cnt*(cnt-1)/2;
                num[i*n+j] = cnt;
            }
        }
    }
    return score;
}


//近傍の移動の関数
void moveNum(int x,int y,int nx,int ny){
    swap(field[x][y],field[nx][ny]);
}


void printAnswer(){
    cout << movement.size() << endl;
    for(auto [x1,y1,x2,y2]:movement){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    cout << connect.size() << endl;
    for(auto [x1,y1,x2,y2]:connect){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
}


//swap回数を決める関数
int swapNum(int t){
    if(t <= 1000)return 0;
    else return (t-1000)/200;
}


void solve(){
    int cnt = 0,nowTime;
    deque<T> query;

    //実行時間制限までギリギリ近傍シミュレーション
    while((nowTime = utility::mytm.elapsed()) <= TIME_LIMIT){
        int nm = rand_int()%noSize;
        int dr = rand_int()%4;

        //次にやること：今は遷移が1移動だが、それをdis+1回移動にする。
        int dis = swapNum(nowTime);

        auto [x,y] = nothing[nm];

        if(!outField(x+dx[dr],y+dy[dr]) && field[x+dx[dr]][y+dy[dr]] != '0'){

            query.push_back(T(x,y,x+dx[dr],y+dy[dr]));
            moveNum(x,y,x+dx[dr],y+dy[dr]);
            x += dx[dr],y += dy[dr];

            //vx,vy : 変化量分
            int vx = 0,vy = 0;
            rep(i,dis){
                int ddr = rand_int()%4;
                vx += dx[ddr],vy += dy[ddr];
                int tox = x+vx,toy = y+vy;
                if(!outField(tox,toy) && field[tox][toy] != '0'){
                    query.push_back(T(tox-dx[ddr],toy-dy[ddr],tox,toy));
                    moveNum(tox-dx[ddr],toy-dy[ddr],tox,toy);
                    // cerr << tox-dx[ddr] << " " << toy-dy[ddr] << " " << tox << " " << toy << endl;
                }
                else{
                    vx -= dx[ddr],vy -= dy[ddr];
                    i--;
                }
            }
            
            int nowScore = calcScore();
            //操作回数上限を突破する時
            if(movement.size()+cand.size()+1+dis > k){
                //リセット用
                while(!query.empty()){
                    auto [x1,y1,x2,y2] = query.back(); query.pop_back();
                    moveNum(x1,y1,x2,y2);
                }
                continue;
            }

            //山登り
            if(nowScore > bestScore){
                cerr << nowScore << " " << bestScore << endl;
                bestScore = nowScore;
                connect = cand;
                nothing[nm] = P(x+vx,y+vy);
                while(!query.empty()){
                    auto [x1,y1,x2,y2] = query.front(); query.pop_front();
                    movement.push_back(T(x2,y2,x1,y1));
                }
            }
            else{
                //リセット用
                while(!query.empty()){
                    auto [x1,y1,x2,y2] = query.back(); query.pop_back();
                    moveNum(x1,y1,x2,y2);
                }
            }
        }
        cnt++;
    }
    cerr << cnt << endl;
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

    //問題解決部分
    solve();

    //答え出力
    printAnswer();

    return 0;
}