/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc014/submissions/34916389
 * Submitted at: 2022-09-17 19:54:52
 * Problem URL: https://atcoder.jp/contests/ahc014/tasks/ahc014_a
 * Result: AC
 * Execution Time: 4908 ms
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

// pointまとめ：
// 1.辺はどれも一度のみしか用いれないが、格子点は最大8回まで用いられる(上下左右斜め)。
// 2.長方形の外周には他の点が存在してはいけない。
// 3.斜めの線が交わることはok。

ll n,m,turn = 0,x2,y2,x3,y3,x4,y4,lx,ly,nd,rd,nrd;
// Graph：n*nマスに対して8方向のbool値を持つ配列
vector<vector<vector<bool>>> Graph;
// vertex : 格子点の有無の配列
vector<vector<bool>> vertex,base;
// cand : スコアと答えの配列のtupleを管理するpq
vector<T2> cand;
// 上・右・下・左・右上・右下・左下・左上
vector<int> dx = {0,1,0,-1,1,1,-1,-1};
vector<int> dy = {1,0,-1,0,1,-1,-1,1};

priority_queue<T3> todo;


void input(){
    cin >> n >> m;
    Graph.assign(n,vector<vector<bool>>(n,vector<bool>(8,false)));
    vertex.assign(n,vector<bool>(n,false));
    cand.push_back(T2(0,{}));

    // 今回は左下を原点として実装する事に注意
    rep(i,m){
        ll x,y; cin >> x >> y;
        vertex[x][y] = true;
    }
    base = vertex;
    utility::mytm.CodeStart();
}


inline bool outField(ll x,ll y){
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


// 長方形を追加する関数
bool createRect(ll x1,ll y1){
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
        ll tx2 = x2,ty2 = y2,tx3 = x3,ty3 = y3;
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
        todo.push(T3((double)max(abs(x1-n/2),abs(y1-n/2)),i,T(x1,y1,x2,y2,x4,y4,x3,y3)));
    }

    if(todo.empty())return false;

    // cand　& vertexを更新
    auto [s,dir,p] = todo.top(); todo.pop();
    cand[turn].first += s;
    cand[turn].second.push_back(p);
    vertex[x1][y1] = true;
    auto [nx1,ny1,nx2,ny2,nx4,ny4,nx3,ny3] = p;

    // Graphの更新
    nd = nextDir(dir);
    rd = reverseDir(dir);
    nrd = reverseDir(nd);

    ll tx = nx1,ty = ny1;
    while(tx != nx2 || ty != ny2){
        Graph[tx][ty][dir] = true;
        tx += dx[dir]; ty += dy[dir];
    }
    tx = nx1,ty = ny1;
    while(tx != nx3 || ty != ny3){
        Graph[tx][ty][nd] = true;
        tx += dx[nd]; ty += dy[nd];
    }

    tx = nx2,ty = ny2;
    while(tx != nx1 || ty != ny1){
        Graph[tx][ty][rd] = true;
        tx += dx[rd]; ty += dy[rd];
    }
    tx = nx2,ty = ny2;
    while(tx != nx4 || ty != ny4){
        Graph[tx][ty][nd] = true;
        tx += dx[nd]; ty += dy[nd];
    }

    tx = nx3,ty = ny3;
    while(tx != nx1 || ty != ny1){
        Graph[tx][ty][nrd] = true;
        tx += dx[nrd]; ty += dy[nrd];
    }
    tx = nx3,ty = ny3;
    while(tx != nx4 || ty != ny4){
        Graph[tx][ty][dir] = true;
        tx += dx[dir]; ty += dy[dir];
    }

    tx = nx4,ty = ny4;
    while(tx != nx2 || ty != ny2){
        Graph[tx][ty][nrd] = true;
        tx += dx[nrd]; ty += dy[nrd];
    }
    tx = nx4,ty = ny4;
    while(tx != nx3 || ty != ny3){
        Graph[tx][ty][rd] = true;
        tx += dx[rd]; ty += dy[rd];
    }

    while(!todo.empty())todo.pop();
    return true;
}


void solve(){
    // ランダムに点・方向を選んで山登り
    ll cnt = 0;
    while(utility::mytm.elapsed() <= 4900){

        if(cnt >= 10000){
            cnt = 0;
            turn++;
            Graph.assign(n,vector<vector<bool>>(n,vector<bool>(8,false)));
            vertex = base;
            cand.push_back(T2(0,{}));
        }

        ll x = randInt()%n, y = randInt()%n;
        if(vertex[x][y])continue;

        if(!createRect(x,y)){
            cnt++;
        }
        
    }
    sort(cand.begin(),cand.end());
    reverse(cand.begin(),cand.end());
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