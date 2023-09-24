/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc024/submissions/45918868
 * Submitted at: 2023-09-24 19:52:08
 * Problem URL: https://atcoder.jp/contests/ahc024/tasks/ahc024_a
 * Result: WA
 * Execution Time: 1859 ms
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
        // 経過時間 (ms) を返す
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
#define TIME_LIMIT 1850
inline double temp(double start) {
    double start_temp = 100,end_temp = 1;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int best,int now,int start) {
    return exp((double)(now - best) / temp(start));
}

//-----------------以下から実装部分-----------------//

int n, m;

#define DIR_NUM 4
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

#define INSIDE_DIR_NUM 2
vector<vector<int>> idx = {
    {0, 1}, // 第一象限
    {0, 1}, // 第二象限
    {0,-1}, // 第三象限
    {0,-1}, // 第四象限
};
vector<vector<int>> idy = {
    {-1, 0}, // 第一象限
    { 1, 0}, // 第二象限
    { 1, 0}, // 第三象限
    {-1, 0}, // 第四象限
};

struct Region{
    vector<int> neighbor, color_cnt;
    vector<pair<int,int>> place;

    Region(){
        color_cnt.assign(m+1,0);
    }
};

struct Solver{
    int rnd, nx, ny, nnx, nny, erase_cnt;
    vector<vector<int>> c;
    vector<vector<bool>> visited;
    vector<Region> region;
    vector<int> color_cnt;
    queue<pair<int,int>> todo;

    Solver(){
        input();
    }

    void input(){
        cin >> n >> m;
        c.assign(n+2,vector<int>(n+2,0));
        region.assign(m+1,Region());
        color_cnt.assign(m+1,0);

        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) {
            cin >> c[i][j];
            color_cnt[c[i][j]]++;
            region[c[i][j]].place.emplace_back(pair(i,j));
        }
        for(int i=0;i<=n+1;i++)for(int j=0;j<=n+1;j++) {
            rep(d,DIR_NUM) {
                nx = i + dx[d], ny = j + dy[d];
                if( outField(nx,ny) ) continue;
                region[c[i][j]].neighbor.emplace_back(c[nx][ny]);
                region[c[i][j]].color_cnt[c[nx][ny]]++;
            }
        }
        rep(i,m+1) {
            sort(region[i].neighbor.begin(), region[i].neighbor.end());
            region[i].neighbor.erase(unique(region[i].neighbor.begin(), region[i].neighbor.end()), region[i].neighbor.end());
        }
    }

    void solve(){
        utility::mytm.CodeStart();

        // 山登り近傍候補 : 
        // 1. 1 or 2 個破壊 ⇒ 再構築
        // 2. 依存関係を保ちつつ領土交換

        // 山登り (?)
        int turn = 0;
        while( utility::mytm.elapsed() <= TIME_LIMIT ) {
            // 1. 内側に侵食させる
            erosion();
            // if(turn == 0) output();

            // 2. 外側から消していく
            clean_color();
            // if(turn == 0) output();

            // 3. 同じパターンがある時は短縮させる
            erase_patern();
            // if(turn == 0) output();
            turn++;
        }
        return;
    }

    inline void erosion() {
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) {
            if( c[i][j] == 0 ) continue;

            // 隣接マスを侵食
            rep(d,INSIDE_DIR_NUM) {
                int syogen;
                // 第何象限にいるか (0-idx)
                if( i <= n/2 && j <= n/2 ) syogen = 1;
                else if( i <= n/2 ) syogen = 0;
                else if( j <= n/2 ) syogen = 2;
                else syogen = 3;

                nx = i + idx[syogen][d], ny = j + idy[syogen][d];
                if( !(1 <= nx && nx <= n && 1 <= ny && ny <= n) || c[i][j] == c[nx][ny] ) continue;

                // 塗り替え可能か調査
                bool f = true;
                rep(nd,DIR_NUM) {
                    nnx = nx + dx[nd], nny = ny + dy[nd];
                    region[c[nnx][nny]].color_cnt[c[nx][ny]]--;
                    region[c[nx][ny]].color_cnt[c[nnx][nny]]--;
                    f &= (region[c[nnx][nny]].color_cnt[c[nx][ny]] != 0);
                    f &= (region[c[nx][ny]].color_cnt[c[nnx][nny]] != 0);

                    // 新規の色ではないことを確認
                    f &= (region[c[nnx][nny]].color_cnt[c[i][j]] != 0);
                    f &= (region[c[i][j]].color_cnt[c[nnx][nny]] != 0);
                    region[c[nnx][nny]].color_cnt[c[i][j]]++;
                    region[c[i][j]].color_cnt[c[nnx][nny]]++;
                }
                if( !f ) {
                    rep(nd,DIR_NUM) {
                        nnx = nx + dx[nd], nny = ny + dy[nd];
                        if( outField(nnx, nny) ) continue;
                        region[c[nnx][nny]].color_cnt[c[nx][ny]]++;
                        region[c[nx][ny]].color_cnt[c[nnx][nny]]++;
                        region[c[nnx][nny]].color_cnt[c[i][j]]--;
                        region[c[i][j]].color_cnt[c[nnx][nny]]--;
                    }
                    continue;
                }
                // bfs で連結確認 part (塗り替えてしまったところが連結のままか)
                visited.assign(n+2,vector<bool>(n+2,false));
                int cnt = 0;
                rep(nd,DIR_NUM) {
                    nnx = nx + dx[nd], nny = ny + dy[nd];
                    if( outField(nnx,nny) || c[nnx][nny] != c[nx][ny] ) continue;
                    todo.push(pair(nnx,nny));
                    while( !todo.empty() ) {
                        auto [x,y] = todo.front(); todo.pop();
                        if( visited[x][y] ) continue;
                        visited[x][y] = true;
                        cnt++;
                        rep(d,DIR_NUM) {
                            nnx = x + dx[d], nny = y + dy[d];
                            if( !(1 <= nnx && nnx <= n && 1 <= nny && nny <= n) ) continue;
                            if( visited[nnx][nny] || c[nnx][nny] != c[nx][ny] || (nnx == nx && nny == ny) ) continue;
                            todo.push(pair(nnx,nny));
                        }
                    }
                    break;
                }
                if( cnt == color_cnt[c[nx][ny]]-1 ) {
                    color_cnt[c[nx][ny]]--;
                    c[nx][ny] = c[i][j];
                    color_cnt[c[nx][ny]]++;
                }
                rep(d,DIR_NUM) {
                    nnx = nx + dx[d], nny = ny + dy[d];
                    if( outField(nnx, nny) ) continue;
                    region[c[nnx][nny]].color_cnt[c[nx][ny]]++;
                    region[c[nx][ny]].color_cnt[c[nnx][nny]]++;
                    region[c[nnx][nny]].color_cnt[c[i][j]]--;
                    region[c[i][j]].color_cnt[c[nnx][nny]]--;
                }
            }
        }
    }

    inline void clean_color() {
        for(int i=1;i<=n;i++)for(int j=1;j<=n;j++) {
            if( c[i][j] == 0 ) continue;

            bool f = true, surround = false;
            rep(d,DIR_NUM) {
                nx = i + dx[d], ny = j + dy[d];
                region[c[nx][ny]].color_cnt[c[i][j]]--;
                region[c[i][j]].color_cnt[c[nx][ny]]--;
                f &= (region[c[nx][ny]].color_cnt[c[i][j]] != 0);
                f &= (region[c[i][j]].color_cnt[c[nx][ny]] != 0);
                f &= (region[c[nx][ny]].color_cnt[0] != 0);
                surround |= (c[nx][ny] == 0);
            }
            if( !f || !surround ) {
                rep(d,DIR_NUM) {
                    nx = i + dx[d], ny = j + dy[d];
                    region[c[nx][ny]].color_cnt[c[i][j]]++;
                    region[c[i][j]].color_cnt[c[nx][ny]]++;
                }
                continue;
            }

            // bfs で連結確認 part
            visited.assign(n+2,vector<bool>(n+2,false));
            int cnt = 0;
            rep(nd,DIR_NUM) {
                nx = i + dx[nd], ny = j + dy[nd];
                if( c[nx][ny] != c[i][j] ) continue;

                todo.push(pair(nx,ny));
                while( !todo.empty() ) {
                    auto [x,y] = todo.front(); todo.pop();
                    if( visited[x][y] ) continue;
                    visited[x][y] = true;
                    cnt++;
                    rep(d,DIR_NUM) {
                        nx = x + dx[d], ny = y + dy[d];
                        if( !(1 <= nx && nx <= n && 1 <= ny && ny <= n) ) continue;
                        if( visited[nx][ny] || c[nx][ny] != c[i][j] || (nx == i && ny == j) ) continue;
                        todo.push(pair(nx,ny));
                    }
                }
                break;
            }

            if( cnt == color_cnt[c[i][j]]-1 ) {
                color_cnt[c[i][j]]--;
                c[i][j] = 0;
                color_cnt[c[i][j]]++;
            }
            rep(d,DIR_NUM) {
                nx = i + dx[d], ny = j + dy[d];
                region[c[nx][ny]].color_cnt[c[i][j]]++;
                region[c[i][j]].color_cnt[c[nx][ny]]++;
            }
        }
    }

    inline void erase_patern() {
        // 縦方向に裁断した時
        for(int i=1;i<=n;i++) {
            int b1 = -1, b2 = -1;
            for(int j=1;j<=n;j++) {
                if( c[j][i] != 0 ) {
                    if( b1 == -1 ) b1 = j-1;
                }
                else {
                    if( b1 == -1 ) continue;
                    else {
                        b2 = j;
                        // 自身の左に同じパターンがあるか
                        bool f = true;
                        for(int nj=b1;nj<=b2;nj++) {
                            f &= ( c[nj][i-1] == c[nj][i] );
                        }
                        if( f ) {
                            // パターン消去
                            todo.push(pair(b1+1,i));
                            visited.assign(n+2,vector<bool>(n+2,false));
                            while( !todo.empty() ) {
                                auto [x,y] = todo.front(); todo.pop();
                                if( visited[x][y] ) continue;
                                visited[x][y] = true;

                                rep(d,DIR_NUM) {
                                    nx = x + dx[d], ny = y + dy[d];
                                    if( ny > i || c[nx][ny] == 0 ) continue;
                                    if( !(1 <= nx && nx <= n && 1 <= ny && ny <= n) ) continue;
                                    if( visited[nx][ny] ) continue;
                                    todo.push(pair(nx,ny));
                                }
                            }

                            for(int ni=n;ni>0;ni--) {
                                for(int nj=n;nj>0;nj--) {
                                    if( !visited[nj][ni] && !visited[nj][ni-1] ) continue;
                                    c[nj][ni] = c[nj][ni-1];
                                }
                            }
                        }
                        b1 = -1, b2 = -1;
                    }
                }
            }
        }

        // 横方向に裁断した時
        for(int i=1;i<=n;i++) {
            int b1 = -1, b2 = -1;
            for(int j=1;j<=n;j++) {
                if( c[i][j] != 0 ) {
                    if( b1 == -1 ) b1 = j-1;
                }
                else {
                    if( b1 == -1 ) continue;
                    else {
                        b2 = j;
                        // 自身の左に同じパターンがあるか
                        bool f = true;
                        for(int nj=b1;nj<=b2;nj++) {
                            f &= ( c[i-1][nj] == c[i][nj] );
                        }
                        if( f ) {
                            // パターン消去
                            todo.push(pair(i,b1+1));
                            visited.assign(n+2,vector<bool>(n+2,false));
                            while( !todo.empty() ) {
                                auto [x,y] = todo.front(); todo.pop();
                                if( visited[x][y] ) continue;
                                visited[x][y] = true;
                                rep(d,DIR_NUM) {
                                    nx = x + dx[d], ny = y + dy[d];
                                    if( nx > i || c[nx][ny] == 0 ) continue;
                                    if( !(1 <= nx && nx <= n && 1 <= ny && ny <= n) ) continue;
                                    if( visited[nx][ny] ) continue;
                                    todo.push(pair(nx,ny));
                                }
                            }

                            for(int ni=n;ni>0;ni--) {
                                for(int nj=n;nj>0;nj--) {
                                    if( !visited[ni][nj] && !visited[ni-1][nj] ) continue;
                                    c[ni][nj] = c[ni-1][nj];
                                }
                            }
                        }
                        b1 = -1, b2 = -1;
                    }
                }
            }
        }
    }

    inline bool outField(int x,int y){
        if(0 <= x && x < n+2 && 0 <= y && y < n+2) return false;
        return true;
    }

    void output(){
        rep(i,n) {
            rep(j,n) cout << c[i+1][j+1] << " ";
            cout << '\n';
        }
        cout << '\n' << flush;
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Solver solver;
    solver.solve();
    solver.output();
    
    return 0;
}

// 明日の予約状況によるけど、前回と同じ時間として認識しといて欲しい感じ
// ( 時間変更があったら明日朝にアナウンスする )