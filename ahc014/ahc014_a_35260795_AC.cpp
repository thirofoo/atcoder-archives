/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc014/submissions/35260795
 * Submitted at: 2022-10-01 11:49:05
 * Problem URL: https://atcoder.jp/contests/ahc014/tasks/ahc014_a
 * Result: AC
 * Execution Time: 4932 ms
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
    double start_temp = 1,end_temp = 0.01;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int now,int next,int start) {
    return exp((double)(next - now) / temp(start));
}

//-----------------以下から実装部分-----------------//

int n,m,x2,y2,x3,y3,x4,y4,nd,rd,nrd,start,tmp,tx,ty,tx1,ty1,tx2,ty2,tx3,ty3,rnd1,rnd2,vnum,lim;
int turn = 0,update = 0,sum = 0,cand = 0;
double r,pre_score,now_score,best_score,now,pena,mid;

vector<vector<int>> vertex,first,dig,best_vertex,best_dig;
vector<vector<vector<bool>>> Graph,best_graph;
set<P> erasable,best_erasable;
T2 info,best_info;

priority_queue<T3,vector<T3>,greater<T3>> todo;
queue<P> que;
vector<int> dx = {0,1,0,-1,1,1,-1,-1};
vector<int> dy = {1,0,-1,0,1,-1,-1,1};

inline bool outField(int x,int y){
    if(0 <= x && x <= n-1 && 0 <= y && y <= n-1)return false;
    return true;
}


// 次の方向を返す関数
inline int nextDir(int i){
    if(i <= 3)return (i+1)%4;
    return (i+1)%4+4;
}


// 逆方向を返す関数
inline int reverseDir(int i){
    if(i <= 3)return (i+2)%4;
    return (i+2)%4+4;
}


// 同直線上にあるか否かを返す関数
inline bool sameLine(int x2,int y2,int x3,int y3,int i){
    if(i <= 3)return ( x2 == x3 || y2 == y3 );
    else if(i == 4 || i == 6)return ( -x2+y2 == -x3+y3 );
    return ( x2+y2 == x3+y3 );
}


// Graphの状況を更新する関数
inline void updateGraph(int x,int y,int nx,int ny,int fd,int tod){
    tmp = 0;
    while(x != nx || y != ny){
        Graph[x][y][fd] = true;
        if(tmp != 0)Graph[x][y][tod] = true;
        x += dx[fd]; y += dy[fd];
        tmp++;
    }
    Graph[nx][ny][tod] = true;
}


// Graphの状況を更新する関数
inline void eraseGraph(int x,int y,int nx,int ny,int fd,int tod){
    tmp = 0;
    while(x != nx || y != ny){
        Graph[x][y][fd] = false;
        if(tmp != 0)Graph[x][y][tod] = false;
        x += dx[fd]; y += dy[fd];
        tmp++;
    }
    Graph[nx][ny][tod] = false;
}


inline double score(int x1,int y1){
    return (x1-mid)*(x1-mid)+(y1-mid)*(y1-mid)+1.0;
}


// 長方形の頂点を決める関数
inline bool decideVertex(int x1,int y1,int i){
    // x2,y2 part
    tx1 = x1;
    ty1 = y1;
    nd = nextDir(i);
    while(!outField(tx1,ty1) && !vertex[tx1][ty1] && !Graph[tx1][ty1][i]){
        tx1 += dx[i];
        ty1 += dy[i];
    }
    if(outField(tx1,ty1) || !vertex[tx1][ty1])return false;
    x2 = tx1;
    y2 = ty1;

    // x3,y3 part
    tx1 = x1;
    ty1 = y1;
    while(!outField(tx1,ty1) && !vertex[tx1][ty1] && !Graph[tx1][ty1][nd]){
        tx1 += dx[nd];
        ty1 += dy[nd];
    }
    if(outField(tx1,ty1) || !vertex[tx1][ty1])return false;
    x3 = tx1;
    y3 = ty1;

    // x4,y4 part
    tx2 = x2+dx[nd];
    ty2 = y2+dy[nd];
    tx3 = x3+dx[i];
    ty3 = y3+dy[i];
    if(Graph[x2][y2][nd] || Graph[x3][y3][i])return false;
    while(!outField(tx2,ty2) && !vertex[tx2][ty2] && !Graph[tx2][ty2][nd]){
        tx2 += dx[nd];;
        ty2 += dy[nd];
    }
    if(outField(tx2,ty2) || !vertex[tx2][ty2]|| !sameLine(tx2,ty2,tx3,ty3,i))return false;
 
    while(!outField(tx3,ty3) && !vertex[tx3][ty3] && !Graph[tx3][ty3][i]){
        tx3 += dx[i];
        ty3 += dy[i];
    }
    if(outField(tx3,ty3) || !vertex[tx3][ty3] || tx2 != tx3 || ty2 != ty3)return false;
    x4 = tx2;
    y4 = ty2;
    return true;
}


// 情報を更新する関数
inline void updateInfo(T p){
    auto [nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3,dir] = p;
    dig[nx1][ny1] += 2;
    dig[nx2][ny2] += 2;
    dig[nx3][ny3] += 2;
    dig[nx4][ny4] += 2;
    erasable.insert(P(nx1,ny1));
    erasable.erase(P(nx2,ny2));
    erasable.erase(P(nx3,ny3));
    erasable.erase(P(nx4,ny4));

    // Graphの更新part
    nd = nextDir(dir);
    rd = reverseDir(dir);
    nrd = reverseDir(nd);
    updateGraph(nx1,ny1,nx2,ny2,dir,rd);
    updateGraph(nx1,ny1,nx3,ny3,nd,nrd);
    updateGraph(nx2,ny2,nx4,ny4,nd,nrd);
    updateGraph(nx3,ny3,nx4,ny4,dir,rd);
}


// 情報を消去する関数
inline void eraseInfo(T p){
    auto [nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3,dir] = p;
    dig[nx1][ny1] -= 2;
    dig[nx2][ny2] -= 2;
    dig[nx3][ny3] -= 2;
    dig[nx4][ny4] -= 2;
    erasable.erase(P(nx1,ny1));
    if(dig[nx2][ny2] == 2 && !first[nx2][ny2])erasable.insert(P(nx2,ny2));
    if(dig[nx3][ny3] == 2 && !first[nx3][ny3])erasable.insert(P(nx3,ny3));
    if(dig[nx4][ny4] == 2 && !first[nx4][ny4])erasable.insert(P(nx4,ny4));

    // Graphの更新part
    nd = nextDir(dir);
    rd = reverseDir(dir);
    nrd = reverseDir(nd);
    eraseGraph(nx1,ny1,nx2,ny2,dir,rd);
    eraseGraph(nx1,ny1,nx3,ny3,nd,nrd);
    eraseGraph(nx2,ny2,nx4,ny4,nd,nrd);
    eraseGraph(nx3,ny3,nx4,ny4,dir,rd);
}


// 長方形を追加する関数
inline bool createRect(int x1,int y1){
    rep(i,8){
        // 候補を格納するpart
        if(!decideVertex(x1,y1,i))continue;
        todo.emplace(T3(score(x4,y4),T(x1,y1,x2,y2,x4,y4,x3,y3,i)));
    }

    if(todo.empty())return false;

    // info & vertexを更新part
    auto [s,p] = todo.top();
    info.second.emplace_back(p);
    info.first += score(x1,y1);
    updateInfo(p);
    vertex[x1][y1] = turn;
    turn++;

    while(!todo.empty())todo.pop();
    return true;
}


// 長方形を削除する関数
inline void eraseRect(){
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
    eraseInfo(info.second[idx]);
    que.emplace(P(nx1,ny1));
    vertex[nx1][ny1] = 0;
    info.first -= score(nx1,ny1);
    info.second.erase(info.second.begin()+idx);
}


// 最近の長方形を削除する関数
inline void popBackRect(){
    auto [nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3,d] = info.second.back();
    eraseInfo(info.second.back());
    que.emplace(P(nx1,ny1));
    vertex[nx1][ny1] = 0;
    info.first -= score(nx1,ny1);
    info.second.pop_back();
}


inline double calcScore(){
    double s = 0;
    rep(x1,n)rep(y1,n)if(vertex[x1][y1])s += score(x1,y1);
    return s;
}


// 1~10個長方形を作成する関数
inline void query1(){
    rnd1 = randInt()%10+1; rnd2 = 0;
    pre_score = info.first;
    while(rnd1--){
        tx = randInt()%n, ty = randInt()%n;
        if(!vertex[tx][ty])rnd2 += createRect(tx,ty);
    }
    if(!rnd2){
        update++;
        return;
    }

    now_score = info.first - rnd2*pena*(TIME_LIMIT-now)/TIME_LIMIT;

    if(now_score >= pre_score){
        if(now_score > best_score){
            best_erasable = erasable;
            best_score = now_score;
            best_vertex = vertex;
            best_graph = Graph;
            best_info = info;
            best_dig = dig;
            update = 0;
        }
        return;
    }
    else update++;
    r = prob(pre_score,now_score,start);
    if(r <= randDouble())while(rnd2--)popBackRect();
}


// 1~10個長方形を削除する関数
inline void query2(){
    update++;
    rnd1 = randInt()%10+1;
    pre_score = info.first;
    while(!erasable.empty() && rnd1--)eraseRect();
    if(que.empty())return;

    now_score = info.first + que.size()*pena*(TIME_LIMIT-now)/TIME_LIMIT;

    if(now_score >= pre_score)return;
    r = prob(pre_score,now_score,start);
    if(r <= randDouble()){
        while(!que.empty()){
            auto [x,y] = que.front(); que.pop();
            if(!vertex[x][y])createRect(x,y);
        }
    }
}


// 1~10個長方形を追加・削除する関数
inline void query3(){
    update++;
    rnd1 = randInt()%10+1; rnd2 = 0;
    pre_score = info.first;
    while(rnd1--){
        tx = randInt()%n, ty = randInt()%n;
        if(!vertex[tx][ty])rnd2 += createRect(tx,ty);
    }
    if(!rnd2)return;

    rnd1 = rnd2;
    while(!erasable.empty() && rnd1--)eraseRect();
    if(que.empty())return;

    now_score = info.first + (que.size()-rnd2)*pena*(TIME_LIMIT-now)/TIME_LIMIT;

    if(now_score >= pre_score)return;
    r = prob(pre_score,now_score,start);
    if(r <= randDouble()){
        while(rnd2--)popBackRect();
        while(!que.empty()){
            auto [x,y] = que.front(); que.pop();
            if(!vertex[x][y])createRect(x,y);
        }
    }
}


// 加えた長方形の辺を短くする関数
inline void query4(){
    rep(j,info.second.size()){
        auto [nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3,d] = info.second[j];
        eraseInfo(info.second[j]);
        vnum = vertex[nx1][ny1];
        vertex[nx1][ny1] = 0;

        todo.emplace(T3(abs(nx1-nx4)+abs(ny1-ny4)+abs(nx2-nx3)+abs(ny2-ny3),T(nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3,d)));
    
        rep(i,8){
            if(i == d || !decideVertex(nx1,ny1,i) || vertex[x2][y2] > vnum || vertex[x3][y3] > vnum || vertex[x4][y4] > vnum)continue;
            todo.emplace(T3(abs(nx1-x4)+abs(ny1-y4)+abs(x2-x3)+abs(y2-y3),T(nx1,ny1,x2,y2,x4,y4,x3,y3,i)));
        }
    
        auto [s,p] = todo.top();
        info.second[j] = p;
        vertex[nx1][ny1] = vnum;
        updateInfo(p);
        while(!todo.empty())todo.pop();
    }
}


void solve(){
    // 焼きなまし法
    start = utility::mytm.elapsed();
    while((now = utility::mytm.elapsed()) <= TIME_LIMIT){
        // 一定turn更新できなかったら元の状態に戻す。
        if(update >= lim){
            erasable = best_erasable;
            vertex = best_vertex;
            Graph = best_graph;
            info = best_info;
            dig = best_dig;
            update = 0;
        }

        // query実行part
        rnd1 = randInt()%1000;
        if(rnd1 > 105)query1();
        else if(rnd1 > 100)query2();
        else if(rnd1 > 0)query3();
        else query4();
    }
}


void input(){
    cin >> n >> m;
    Graph.assign(n,vector<vector<bool>>(n,vector<bool>(8,false)));
    vertex.assign(n,vector<int>(n,0));
    first.assign(n,vector<int>(n,0));
    dig.assign(n,vector<int>(n,0));
    pena = n*n/16;
    lim = n*n*n;
    mid = (n-1)/2;

    rep(i,m){
        int x,y; cin >> x >> y;
        vertex[x][y] = 1;
        first[x][y] = 1;
    }
    info = T2(calcScore(),{});
    best_score = info.first;
    rep(i,n)rep(j,n)sum += score(i,j);
    utility::mytm.CodeStart();
}


void output(){
    cout << best_info.second.size() << '\n';
    for(auto [x1,y1,x2,y2,x3,y3,x4,y4,d]:best_info.second){
        cout << x1 << " " <<  y1 << " " <<  x2 << " " <<  y2 << " " <<  x3 << " " <<  y3 << " " <<  x4 << " " <<  y4 << '\n';
    }
    cerr << best_info.first*n*n*1000000/(m*sum) << endl;
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