/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc014/submissions/35049265
 * Submitted at: 2022-09-22 22:02:02
 * Problem URL: https://atcoder.jp/contests/ahc014/tasks/ahc014_a
 * Result: AC
 * Execution Time: 4917 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
typedef tuple<int, int, int, int, int, int, int, int, int> T;
typedef pair<double, vector<T>> T2;
typedef tuple<double, T> T3;
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

unsigned int randInt() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}

inline double randDouble() {
    return (double)(randInt()%(int)1e9)/1e9;
}

//温度関数
#define TIME_LIMIT 4900
inline double temp(int start) {
    double start_temp = 10,end_temp = 1;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int now,int next,int start) {
    return exp((double)(next - now) / temp(start));
}

//-----------------以下から実装部分-----------------//

int n,m,turn = 0,x2,y2,x3,y3,x4,y4,lx,ly,nd,rd,nrd,start,total,tmp,tx,ty,tx2,ty2,tx3,ty3,rnd1,rnd2;
double r,preScore,nowScore,bestScore,now;
bool f = true;
T2 info;
queue<P> que;
vector<T2> cand;
set<P> erasable,first;
vector<vector<int>> vertex;
vector<vector<vector<bool>>> Graph;
vector<int> dx = {0,1,0,-1,1,1,-1,-1};
vector<int> dy = {1,0,-1,0,1,-1,-1,1};
priority_queue<T3,vector<T3>,greater<T3>> todo;
priority_queue<T3> todo2;

inline bool outField(int x,int y){
    if(0 <= x && x <= n-1 && 0 <= y && y <= n-1)return false;
    else return true;
}


// 1方向からもう1方向を返す関数
inline int nextDir(int i){
    if(i <= 3)return (i+1)%4;
    else return (i+1)%4+4;
}


// 逆方向を返す関数
inline int reverseDir(int i){
    if(i <= 3)return (i+2)%4;
    else return (i+2)%4+4;
}


// 同じ直線上にあるかどうかを返す関数
inline bool sameLine(int x2,int y2,int x3,int y3,int i){
    if(i <= 3)return ( x2 == x3 || y2 == y3 );
    else if(i == 4 || i == 6)return ( -x2+y2 == -x3+y3 );
    else return ( x2+y2 == x3+y3 );
}


// Graphの状況を更新する関数
inline void updateGraph(int x,int y,int nx,int ny,int d,int nd){
    tmp = 0;
    while(x != nx || y != ny){
        Graph[x][y][d] = true;
        if(tmp != 0)Graph[x][y][nd] = true;
        x += dx[d]; y += dy[d];
        tmp++;
    }
    Graph[nx][ny][nd] = true;
}


// Graphの状況を更新する関数
inline void eraseGraph(int x,int y,int nx,int ny,int d,int nd){
    tmp = 0;
    while(x != nx || y != ny){
        Graph[x][y][d] = false;
        if(tmp != 0)Graph[x][y][nd] = false;
        x += dx[d]; y += dy[d];
        tmp++;
    }
    Graph[nx][ny][nd] = false;
}


inline double score(int x1,int y1){
    return (double)(x1-(n-1)/2)*(double)(x1-(n-1)/2)+(double)(y1-(n-1)/2)*(double)(y1-(n-1)/2)+1.0;
}


// 長方形の頂点を決める関数
bool decideVertex(int x1,int y1,int i){
    // x2,y2 part
    lx = 0,ly = 0,nd = nextDir(i);
    while(!outField(x1+lx,y1+ly) && !vertex[x1+lx][y1+ly]){
        if(Graph[x1][y1][i])break;
        lx += dx[i]; ly += dy[i];
    }
    if(outField(x1+lx,y1+ly) || !vertex[x1+lx][y1+ly])return false;
    x2 = x1+lx, y2 = y1+ly;

    // x3,y3 part
    lx = 0,ly = 0;
    while(!outField(x1+lx,y1+ly) && !vertex[x1+lx][y1+ly]){
        if(Graph[x1][y1][nd])break;
        lx += dx[nd]; ly += dy[nd];
    }
    if(outField(x1+lx,y1+ly) || !vertex[x1+lx][y1+ly])return false;
    x3 = x1+lx, y3 = y1+ly;

    // x4,y4 part
    tx2 = x2,ty2 = y2,tx3 = x3,ty3 = y3;
    while(!outField(tx2,ty2) && !sameLine(tx2,ty2,tx3,ty3,i)){
        if(Graph[tx2][ty2][nd])break;
        tx2 += dx[nd];
        ty2 += dy[nd];
        if(outField(tx2,ty2) || vertex[tx2][ty2])break;
    }
    if(outField(tx2,ty2) || !sameLine(tx2,ty2,tx3,ty3,i) || !vertex[tx2][ty2])return false;

    while(tx2 != tx3 || ty2 != ty3){
        if(Graph[tx3][ty3][i])break;
        tx3 += dx[i];
        ty3 += dy[i];
        if(outField(tx3,ty3) || vertex[tx3][ty3])break;
    }
    if(tx2 != tx3 || ty2 != ty3 || outField(tx3,ty3) || !vertex[tx3][ty3])return false;
    x4 = tx2, y4 = ty2;
    return true;
}


// 情報を更新する関数
void updateInfo(T p){
    auto [nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3,dir] = p;
    vertex[nx1][ny1] = info.second.size()+1;
    erasable.insert(P(nx1,ny1));
    if(erasable.count(P(nx2,ny2)))erasable.erase(P(nx2,ny2));
    if(erasable.count(P(nx3,ny3)))erasable.erase(P(nx3,ny3));
    if(erasable.count(P(nx4,ny4)))erasable.erase(P(nx4,ny4));

    // Graphの更新part
    nd = nextDir(dir);
    rd = reverseDir(dir);
    nrd = reverseDir(nd);
    updateGraph(nx1,ny1,nx2,ny2,dir,rd);
    updateGraph(nx1,ny1,nx3,ny3,nd,nrd);
    updateGraph(nx2,ny2,nx4,ny4,nd,nrd);
    updateGraph(nx3,ny3,nx4,ny4,dir,rd);
}


// 長方形を追加する関数
bool createRect(int x1,int y1){
    rep(i,8){
        // 候補を格納するpart
        if(!decideVertex(x1,y1,i))continue;
        todo.push(T3(score(x4,y4),T(x1,y1,x2,y2,x4,y4,x3,y3,i)));
    }

    if(todo.empty())return false;

    // info & vertexを更新part
    auto [s,p] = todo.top();
    auto [nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3,dir] = p;
    info.first += score(nx1,ny1);
    info.second.push_back(p);
    updateInfo(p);

    while(!todo.empty())todo.pop();
    return true;
}


void eraseRect(){
    int t = randInt()%erasable.size(),idx = 0;
    auto itr = erasable.begin();
    while(t--)itr++;
    auto [nx,ny] = *itr;
    while(true){
        auto [nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3,d] = info.second[idx];
        if(nx1 == nx && ny1 == ny)break;
        idx++;
    }
    auto [nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3,d] = info.second[idx];
    info.second.erase(info.second.begin()+idx);
    que.push(P(nx1,ny1));
    vertex[nx1][ny1] = 0;
    info.first -= score(nx1,ny1);
    nd = nextDir(d);
    rd = reverseDir(d);
    nrd = reverseDir(nd);
    eraseGraph(nx1,ny1,nx2,ny2,d,rd);
    eraseGraph(nx1,ny1,nx3,ny3,nd,nrd);
    eraseGraph(nx2,ny2,nx4,ny4,nd,nrd);
    eraseGraph(nx3,ny3,nx4,ny4,d,rd);
    erasable.erase(P(nx1,ny1));
    tmp = 0;
    rep(i,8)if(Graph[nx2][ny2][i])tmp++;
    if(tmp == 2 && !first.count(P(nx2,ny2)))erasable.insert(P(nx2,ny2));
    tmp = 0;
    rep(i,8)if(Graph[nx3][ny3][i])tmp++;
    if(tmp == 2 && !first.count(P(nx3,ny3)))erasable.insert(P(nx3,ny3));
    tmp = 0;
    rep(i,8)if(Graph[nx4][ny4][i])tmp++;
    if(tmp == 2 && !first.count(P(nx4,ny4)))erasable.insert(P(nx4,ny4));
}


void popBackRect(){
    auto [nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3,d] = info.second.back();
    info.second.pop_back();
    que.push(P(nx1,ny1));
    vertex[nx1][ny1] = 0;
    info.first -= score(nx1,ny1);
    nd = nextDir(d);
    rd = reverseDir(d);
    nrd = reverseDir(nd);
    eraseGraph(nx1,ny1,nx2,ny2,d,rd);
    eraseGraph(nx1,ny1,nx3,ny3,nd,nrd);
    eraseGraph(nx2,ny2,nx4,ny4,nd,nrd);
    eraseGraph(nx3,ny3,nx4,ny4,d,rd);
    erasable.erase(P(nx1,ny1));
    tmp = 0;
    rep(i,8)if(Graph[nx2][ny2][i])tmp++;
    if(tmp == 2 && !first.count(P(nx2,ny2)))erasable.insert(P(nx2,ny2));
    tmp = 0;
    rep(i,8)if(Graph[nx3][ny3][i])tmp++;
    if(tmp == 2 && !first.count(P(nx3,ny3)))erasable.insert(P(nx3,ny3));
    tmp = 0;
    rep(i,8)if(Graph[nx4][ny4][i])tmp++;
    if(tmp == 2 && !first.count(P(nx4,ny4)))erasable.insert(P(nx4,ny4));
}


inline double calcScore(){
    double s = 0;
    rep(x1,n)rep(y1,n)if(vertex[x1][y1])s += score(x1,y1);
    return s;
}


// 1~3個長方形を作成する関数
void query1(){
    rnd1 = randInt()%10;
    rnd2 = 0;
    preScore = calcScore();
    while(rnd1--){
        tx = randInt()%n, ty = randInt()%n;
        if(!vertex[tx][ty])rnd2 += createRect(tx,ty);
    }
    if(!rnd2)return;
    nowScore = calcScore();

    if(nowScore >= preScore + rnd2*(n*n/16)*(TIME_LIMIT-now)/TIME_LIMIT){
        if(nowScore > bestScore){
            bestScore = nowScore;
            cand.push_back(info);
        }
        return;
    }
    r = prob(preScore + rnd2*(n*n/16)*(TIME_LIMIT-now)/TIME_LIMIT,nowScore,start);
    if(r <= randDouble())while(rnd2--)popBackRect();
    else cerr << "1 : " << preScore << " " << nowScore << endl;
}


// 1~3個長方形を削除する関数
void query2(){
    rnd1 = randInt()%5;
    preScore = calcScore();
    while(!erasable.empty() && rnd1--)eraseRect();
    if(que.empty())return;
    nowScore = calcScore();

    if(nowScore >= preScore - que.size()*(n*n/16)*(TIME_LIMIT-now)/TIME_LIMIT){
        if(nowScore > bestScore){
            bestScore = nowScore;
            cand.push_back(info);
        }
        return;
    }
    r = prob(preScore - que.size()*(n*n/16)*(TIME_LIMIT-now)/TIME_LIMIT,nowScore,start);
    if(r <= randDouble()){
        while(!que.empty()){
            auto [x,y] = que.front(); que.pop();
            if(!vertex[x][y])createRect(x,y);
        }
    }
    else cerr << "2 : " << preScore << " " << nowScore << endl;
}


// 加えられた頂点を全て確認して辺を短くできないか精査する関数
void query3(){
    rep(j,info.second.size()){
        auto [nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3,d] = info.second[j];

        nd = nextDir(d);
        rd = reverseDir(d);
        nrd = reverseDir(nd);
        eraseGraph(nx1,ny1,nx2,ny2,d,rd);
        eraseGraph(nx1,ny1,nx3,ny3,nd,nrd);
        eraseGraph(nx2,ny2,nx4,ny4,nd,nrd);
        eraseGraph(nx3,ny3,nx4,ny4,d,rd);
        vertex[nx1][ny1] = 0;

        erasable.erase(P(nx1,ny1));
        tmp = 0;
        rep(i,8)if(Graph[nx2][ny2][i])tmp++;
        if(tmp == 2 && !first.count(P(nx2,ny2)))erasable.insert(P(nx2,ny2));
        tmp = 0;
        rep(i,8)if(Graph[nx3][ny3][i])tmp++;
        if(tmp == 2 && !first.count(P(nx3,ny3)))erasable.insert(P(nx3,ny3));
        tmp = 0;
        rep(i,8)if(Graph[nx4][ny4][i])tmp++;
        if(tmp == 2 && !first.count(P(nx4,ny4)))erasable.insert(P(nx4,ny4));

        todo2.push(T3(abs(nx1-nx4)+abs(ny1-ny4)+abs(nx2-nx3)+abs(ny2-ny3),T(nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3,d)));

        rep(i,8){
            if(i == d || !decideVertex(nx1,ny1,i) || vertex[x2][y2] > vertex[nx1][ny1] || vertex[x3][y3] > vertex[nx1][ny1] || vertex[x4][y4] > vertex[nx1][ny1])continue;
            todo2.push(T3(abs(nx1-x4)+abs(ny1-y4)+abs(x2-x3)+abs(y2-y3),T(nx1,ny1,x2,y2,x4,y4,x3,y3,i)));
        }
        auto [s,p] = todo2.top();
        info.second[j] = p;
        updateInfo(p);
        while(!todo2.empty())todo2.pop();
    }
}


void solve(){
    // ランダムに点・方向を選んで山登り
    int cnt = 0; total = 0;
    start = utility::mytm.elapsed();
    while((now = utility::mytm.elapsed()) <= TIME_LIMIT){
        total++;

        // query実行part
        rnd1 = randInt()%1000;
        preScore = info.first;
        if(rnd1 > 10)query1();
        else if(rnd1 > 0) query2();
        else query3();
    }
    cand.push_back(info);
    
    sort(cand.begin(),cand.end());
    reverse(cand.begin(),cand.end());
    cerr << total << endl;
    cerr << cand.size() << endl;
}


inline void input(){
    cin >> n >> m;
    Graph.assign(n,vector<vector<bool>>(n,vector<bool>(8,false)));
    vertex.assign(n,vector<int>(n,0));

    rep(i,m){
        int x,y; cin >> x >> y;
        vertex[x][y] = 1;
        first.insert(P(x,y));
    }
    info = T2(calcScore(),{});
    bestScore = info.first;
    utility::mytm.CodeStart();
}


void output(){
    cout << cand[0].second.size() << '\n';
    for(auto [x1,y1,x2,y2,x3,y3,x4,y4,d]:cand[0].second){
        cout << x1 << " " <<  y1 << " " <<  x2 << " " <<  y2 << " " <<  x3 << " " <<  y3 << " " <<  x4 << " " <<  y4 << '\n';
    }
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(6) << fixed;
    
    // 入力受付part
    input();

    // 解答part
    solve();

    // 出力part
    output();

    return 0;
}