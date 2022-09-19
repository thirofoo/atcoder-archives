/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc014/submissions/34998429
 * Submitted at: 2022-09-19 21:56:47
 * Problem URL: https://atcoder.jp/contests/ahc014/tasks/ahc014_a
 * Result: AC
 * Execution Time: 4907 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int, int, int, int, int, int> T;
typedef pair<double, vector<T>> T2;
typedef tuple<double, int, T> T3;
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
    //時間が過ぎる程温度は低くなる → 採用率down
    //スコアの差分とtempが等しいと1/eの確率で採用されることになる
    double start_temp = 10,end_temp = 1;
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

int n,m,turn = 0,x2,y2,x3,y3,x4,y4,lx,ly,nd,rd,nrd,start,now,total;
bool f = true;
double r;
// Graph：n*nマスに対して8方向のbool値を持つ配列
vector<vector<vector<bool>>> Graph;
// vertex : 格子点の有無の配列
vector<vector<bool>> vertex,base;
// cand : スコアと答えの配列のtupleを管理するpq
vector<T2> cand;
// 上・右・下・左・右上・右下・左下・左上
vector<int> dx = {0,1,0,-1,1,1,-1,-1};
vector<int> dy = {1,0,-1,0,1,-1,-1,1};

priority_queue<T3,vector<T3>,greater<T3>> todo;


void input(){
    cin >> n >> m;
    Graph.assign(n,vector<vector<bool>>(n,vector<bool>(8,false)));
    vertex.assign(n,vector<bool>(n,false));
    cand.push_back(T2(0,{}));

    // 今回は左下を原点として実装する事に注意
    rep(i,m){
        int x,y; cin >> x >> y;
        vertex[x][y] = true;
    }
    base = vertex;
    utility::mytm.CodeStart();
}


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
inline void updateGraph(int x,int y,int nx,int ny,int d){
    while(x != nx || y != ny){
        Graph[x][y][d] = true;
        x += dx[d]; y += dy[d];
    }
}


inline int score(int x1,int y1){
    return (x1-(n-1)/2)*(x1-(n-1)/2)+(y1-(n-1)/2)*(y1-(n-1)/2)+1;
}


// inline int edgeL(int x1,int x2,int x3,int x4,int y1,int y2,int y3,int y4){
//     return abs(x1-x4)+abs(y1-y4)+abs(x2-x3)+abs(y2-y3);
// }


// 長方形を追加する関数
bool createRect(int x1,int y1){
    rep(i,8){
        // x2,y2,x3,y3を見つけるpart
        lx = 0,ly = 0,nd = nextDir(i);
        while(!outField(x1+lx,y1+ly) && !vertex[x1+lx][y1+ly]){
            if(Graph[x1][y1][i])break;
            lx += dx[i]; ly += dy[i];
        }
        if(outField(x1+lx,y1+ly) || !vertex[x1+lx][y1+ly])continue;
        x2 = x1+lx, y2 = y1+ly;

        lx = 0,ly = 0;
        while(!outField(x1+lx,y1+ly) && !vertex[x1+lx][y1+ly]){
            if(Graph[x1][y1][nd])break;
            lx += dx[nd]; ly += dy[nd];
        }
        if(outField(x1+lx,y1+ly) || !vertex[x1+lx][y1+ly])continue;
        x3 = x1+lx, y3 = y1+ly;

        // x4,y4が印無し & 頂点2/4間、頂点3/4間に他の頂点が無い場合に長方形を作成するpart
        int tx2 = x2,ty2 = y2,tx3 = x3,ty3 = y3;
        while(!outField(tx2,ty2) && !sameLine(tx2,ty2,tx3,ty3,i)){
            if(Graph[tx2][ty2][nd])break;
            tx2 += dx[nd];
            ty2 += dy[nd];
            if(outField(tx2,ty2) || vertex[tx2][ty2])break;
        }
        if(outField(tx2,ty2) || !sameLine(tx2,ty2,tx3,ty3,i) || !vertex[tx2][ty2])continue;

        while(tx2 != tx3 || ty2 != ty3){
            if(Graph[tx3][ty3][i])break;
            tx3 += dx[i];
            ty3 += dy[i];
            if(outField(tx3,ty3) || vertex[tx3][ty3])break;
        }
        if(tx2 != tx3 || ty2 != ty3 || outField(tx3,ty3) || !vertex[tx3][ty3])continue;
        x4 = tx2, y4 = ty2;

        // ここまで到達したら4点が揃ったということ => スコアを計算して候補に入れる
        todo.push(T3(score(x1,y1)+score(x2,y2)+score(x3,y3)+score(x4,y4),i,T(x1,y1,x2,y2,x4,y4,x3,y3)));
    }

    if(todo.empty())return false;
    
    // cand　& vertexを更新
    auto [s,dir,p] = todo.top(); todo.pop();

    r = prob(n*n/32+1,s,start);
    if(r < 1 && r < randDouble()){
        while(!todo.empty())todo.pop();
        return false;
    }
    cand[turn].first += s;
    cand[turn].second.push_back(p);
    vertex[x1][y1] = true;
    auto [nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3] = p;

    // Graphの更新
    nd = nextDir(dir);
    rd = reverseDir(dir);
    nrd = reverseDir(nd);
    updateGraph(nx1,ny1,nx2,ny2,dir);
    updateGraph(nx1,ny1,nx3,ny3,nd);
    updateGraph(nx2,ny2,nx1,ny1,rd);
    updateGraph(nx2,ny2,nx4,ny4,nd);
    updateGraph(nx3,ny3,nx1,ny1,nrd);
    updateGraph(nx3,ny3,nx4,ny4,dir);
    updateGraph(nx4,ny4,nx2,ny2,nrd);
    updateGraph(nx4,ny4,nx3,ny3,rd);

    while(!todo.empty())todo.pop();

    int ddx = 0,ddy = 0;
    f = false;
    rep(i,8){
        ddx = 0; ddy = 0;
        if(abs(nx1-(n-1)/2)+abs(ny1-(n-1)/2) > abs(nx1+dx[i]-(n-1)/2)+abs(ny1+dy[i]-(n-1)/2))continue;
        ddx += dx[i]; ddy += dy[i];
        while(!outField(nx1+ddx,ny1+ddy) && !vertex[nx1+ddx][ny1+ddy]){
            if(createRect(nx1+ddx,ny1+ddy)){
                f = true;
                break;
            }
            ddx += dx[i]; ddy += dy[i];
        }
        if(f)break;
    }

    return true;
}


void solve(){
    // ランダムに点・方向を選んで山登り
    int cnt = 0; total = 0;
    start = utility::mytm.elapsed();
    while(utility::mytm.elapsed() <= TIME_LIMIT){
        total++;
        if(cnt >= n*n*3){
            cnt = 0;
            Graph.assign(n,vector<vector<bool>>(n,vector<bool>(8,false)));
            vertex = base;
            turn++;
            cand.push_back(T2(0,{}));
            start = utility::mytm.elapsed();
        }

        int x = randInt()%n, y = randInt()%n;
        if(vertex[x][y])continue;

        if(!createRect(x,y))cnt++;
        else cnt = 0;
    }
    sort(cand.begin(),cand.end());
    reverse(cand.begin(),cand.end());
    cerr << total << endl;
}


void output(){
    cout << cand[0].second.size() << '\n';
    for(auto [x1,y1,x2,y2,x3,y3,x4,y4]:cand[0].second){
        cout << x1 << " " <<  y1 << " " <<  x2 << " " <<  y2 << " " <<  x3 << " " <<  y3 << " " <<  x4 << " " <<  y4 << '\n';
    }
}


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    // 入力受付part
    input();

    // 解答part
    solve();

    // 出力part
    output();

    return 0;
}