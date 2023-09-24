/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc024/submissions/45910450
 * Submitted at: 2023-09-24 16:33:34
 * Problem URL: https://atcoder.jp/contests/ahc024/tasks/ahc024_a
 * Result: WA
 * Execution Time: 1143 ms
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

// 左上右下の順番
#define DIR_NUM 4
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

struct Region{
    vector<int> neighbor, color_cnt;
    vector<pair<int,int>> place;

    Region(){
        color_cnt.assign(m+1,0);
    }
};

struct Solver{
    int rnd, nx, ny;
    vector<vector<int>> c;
    vector<Region> region;
    vector<int> color_cnt;
    queue<pair<int,int>> todo;

    Solver(){
        input();
    }

    void input(){
        cin >> n >> m;
        c.assign(n,vector<int>(n));
        region.assign(m+1,Region());
        color_cnt.assign(m+1,0);

        rep(i,n)rep(j,n) {
            cin >> c[i][j];
            color_cnt[c[i][j]]++;
            region[c[i][j]].place.emplace_back(pair(i,j));
            if( i != 0 ) {
                region[c[i][j]].neighbor.emplace_back(c[i-1][j]);
                region[c[i-1][j]].neighbor.emplace_back(c[i][j]);
                region[c[i][j]].color_cnt[c[i-1][j]]++;
                region[c[i-1][j]].color_cnt[c[i][j]]++;
            }
            if( j != 0 ) {
                region[c[i][j]].neighbor.emplace_back(c[i][j-1]);
                region[c[i][j-1]].neighbor.emplace_back(c[i][j]);
                region[c[i][j]].color_cnt[c[i][j-1]]++;
                region[c[i][j-1]].color_cnt[c[i][j]]++;
            }
        }
        rep(i,m+1) {
            sort(region[i].neighbor.begin(), region[i].neighbor.end());
            region[i].neighbor.erase(unique(region[i].neighbor.begin(), region[i].neighbor.end()), region[i].neighbor.end());
        }
    }

    void solve(){
        utility::mytm.CodeStart();
        // まずは貪欲解
        rep(_,n) {
            if( utility::mytm.elapsed() > TIME_LIMIT ) break;
            rep(i,n) {
                rep(j,n) {
                    bool f = true, surround = false;
                    rep(d,DIR_NUM) {
                        nx = i + dx[d], ny = j + dy[d];
                        if( outField(nx, ny) || c[nx][ny] == 0 ) {
                            surround = true;
                            continue;
                        }
                        region[c[nx][ny]].color_cnt[c[i][j]]--;
                        region[c[i][j]].color_cnt[c[nx][ny]]--;
                        f &= (region[c[nx][ny]].color_cnt[c[i][j]] != 0);
                        f &= (region[c[i][j]].color_cnt[c[nx][ny]] != 0);
                        surround |= (c[nx][ny] == 0);
                    }
                    if( !f || !surround ) {
                        rep(d,DIR_NUM) {
                            nx = i + dx[d], ny = j + dy[d];
                            if( outField(nx, ny) || c[nx][ny] == 0 ) continue;
                            region[c[nx][ny]].color_cnt[c[i][j]]++;
                            region[c[i][j]].color_cnt[c[nx][ny]]++;
                        }
                        continue;
                    }

                    // bfs で連結確認 part
                    vector<vector<bool>> visited(n,vector<bool>(n,false));
                    int cnt = 0;
                    rep(nd,DIR_NUM) {
                        nx = i + dx[nd], ny = j + dy[nd];
                        if( outField(nx,ny) || c[nx][ny] != c[i][j] ) continue;

                        todo.push(pair(nx,ny));
                        while( !todo.empty() ) {
                            auto [x,y] = todo.front(); todo.pop();
                            if( visited[x][y] ) continue;
                            visited[x][y] = true;
                            cnt++;
                            rep(d,DIR_NUM) {
                                nx = x + dx[d], ny = y + dy[d];
                                if( outField(nx, ny) || visited[nx][ny] || c[nx][ny] != c[i][j] || (nx == i && ny == j) ) continue;
                                todo.push(pair(nx,ny));
                            }
                        }
                        break;
                    }
                    if( cnt == color_cnt[c[i][j]]-1 ) {
                        color_cnt[c[i][j]]--;
                        c[i][j] = 0;
                    }
                    else {
                        rep(d,DIR_NUM) {
                            nx = i + dx[d], ny = j + dy[d];
                            if( outField(nx, ny) || c[nx][ny] == 0 ) continue;
                            region[c[nx][ny]].color_cnt[c[i][j]]++;
                            region[c[i][j]].color_cnt[c[nx][ny]]++;
                        }
                    }
                }
            }
        }
        return;

        while( utility::mytm.elapsed() <= TIME_LIMIT ) {
            // 候補 : 
            // 1. 1 or 2 個破壊 ⇒ 再構築
            // 2. 依存関係を保ちつつ領土交換
            rnd = rand_int()%m;

        }
    }

    inline bool outField(int x,int y){
        if(0 <= x && x < n && 0 <= y && y < n) return false;
        return true;
    }

    void output(){
        rep(i,n) {
            rep(j,n) cout << c[i][j] << " ";
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