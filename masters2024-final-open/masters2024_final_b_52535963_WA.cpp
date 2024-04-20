/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/masters2024-final-open/submissions/52535963
 * Submitted at: 2024-04-20 16:52:55
 * Problem URL: https://atcoder.jp/contests/masters2024-final-open/tasks/masters2024_final_b
 * Result: WA
 * Execution Time: 2208 ms
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

inline double gaussian(double mean, double stddev) {
    // 標準正規分布からの乱数生成（Box-Muller変換
    double z0 = sqrt(-2.0 * log(rand_double())) * cos(2.0 * M_PI * rand_double());
    // 平均と標準偏差の変換
    return mean + z0 * stddev;
}

//温度関数
#define TIME_LIMIT 2950
inline double temp(double start) {
    double start_temp = 100,end_temp = 1;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int best,int now,int start) {
    return exp((double)(now - best) / temp(start));
}

//-----------------以下から実装部分-----------------//

// right | down | left | up
#define DIR_NUM 4
vector<int> dx = { 1, 0,-1, 0, 0};
vector<int> dy = { 0,-1, 0, 1, 0};

struct Line {
    // type 1: y = ax + b ( 勾配 a, 切片 b )
    // type 2: ax + by + c = 0 ( 2頂点 p1, p2 を通る直線 )
    ll a, b, c, type;
    pair<ll, ll> p1, p2;
    Line(const ll a, const ll b) : a(a), b(b), c(0), type(1) {}
    Line(const P &p1, const P &p2) : type(2), p1(p1), p2(p2) {
        if( p1 == p2 ) cerr << "Warn: Same Vertex (p1,p2)\n";
        auto &&[x1, y1] = p1;
        auto &&[x2, y2] = p2;
        ll dx = x1 - x2, dy = y1 - y2;
        a = -dy, b = dx, c = dy*x1 - dx*y1;
    
        // gcd(a,b,c) = 1 & a > 0 で管理 ※ a == 0 の時は b > 0 で管理
        if( a < 0 || ( a == 0 && b < 0 ) ) a *= -1, b *= -1, c *= -1;
        ll g = gcd(abs(a), gcd(abs(b), abs(c)));
        a /= g, b /= g, c /= g;
    }
    inline bool isOnLine(const P &p) {
        auto &&[x,y] = p;
        bool res = false;
        res |= ( type == 1 && y == a*x + b );
        res |= ( type == 2 && a*x + b*y + c == 0 );
        return res;
    }
    inline bool isUpper(const P &p) {
        auto &&[x,y] = p;
        bool res = false;
        res |= ( type == 1 && y > a*x + b );
        res |= ( type == 2 && a*x + b*y + c > 0 );
        return res;
    }
    inline bool isLower(const P &p) {
        auto &&[x,y] = p;
        bool res = false;
        res |= ( type == 1 && y < a*x + b );
        res |= ( type == 2 && a*x + b*y + c < 0 );
        return res;
    }
    inline int distance(const P &p) {
        // 点と直線の距離公式
        auto &&[x,y] = p;
        if( type == 1 ) return abs(y - a*x - b) / sqrt(a*a + 1);
        if( type == 2 ) return abs(a*x + b*y + c) / sqrt(a*a + b*b);
        return -1;
    }
    // 演算子 overload (sort用)
    constexpr bool operator<(const Line& l) const { return tuple(a,b,c) < tuple(l.a,l.b,l.c); }
    constexpr bool operator>(const Line& l) const { return tuple(a,b,c) > tuple(l.a,l.b,l.c); }
    constexpr bool operator==(const Line& l) const { return a == l.a && b == l.b && c == l.c; }
};

struct Solver{
    int N, M, sx, sy, c, h, op_cnt;
    double eps, delta;
    vector<int> q;
    vector<pair<int, int>> dest;
    vector<Line> wall;

    Solver() {
        this->input();
        q.resize(N);
        op_cnt = 5000;
    }

    void input() {
        cin >> N >> M >> eps >> delta >> sx >> sy;
        rep(i, N) {
            int x, y; cin >> x >> y;
            dest.emplace_back(pair(x, y));
        }
        rep(i, M) {
            int lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
            wall.emplace_back(Line(P(lx, ly), P(rx, ry)));
        }
        return;
    }

    void solve() {
        // case A のみの貪欲解
        // 1. その位置から最も近い & 訪れたことのない dest に向かう加速度を壁衝突まで生成
        // 2. 10 回 sample を取った平均を xy 方向にやって平均を現在位置にする

        if( M == 0 ) caseA();
        else caseB();
    }

    void caseA() {
        int vis_cnt = 0;
        double now_x = 0, now_y = 0;
        vector<bool> visited(N, false);

        while( true ) {
            // ===== 1. その位置から最も近い & 未訪問の dest に向かう加速度を壁衝突まで生成 =====
            double min_dist = 1e9;
            int min_idx = -1;
            rep(i, N) {
                if( visited[i] ) continue;
                auto &&[x, y] = dest[i];
                double dist = sqrt((x - now_x)*(x - now_x) + (y - now_y)*(y - now_y));
                if( dist < min_dist ) {
                    min_dist = dist;
                    min_idx = i;
                }
            }
            auto &&[nearest_x, nearest_y] = dest[min_idx];
            double ax = nearest_x - now_x, ay = nearest_y - now_y;

            c = 0, h = 0;
            while( c == 0 ) {
                double norm = sqrt(ax*ax + ay*ay);
                ax /= norm, ay /= norm;
                double ratio = min(min_dist, 500.0-1.0);
                ax *= ratio, ay *= ratio;
                cout << "A " << (int)ax << " " << (int)ay << endl << flush;
                cin >> c >> h;
                cerr << "c: " << c << " h: " << h << endl;
                rep(i, h) {
                    int place; cin >> place;
                    visited[place] = true;
                    vis_cnt++;
                    if( vis_cnt == N ) return;
                }
                op_cnt--;
                if( op_cnt <= 0 ) return;
            }
            // cerr << endl;

            // ===== 2. xy 方向に measure 回ずつ計測して現在位置にする =====
            cout << "S " << 1 << " " << 0 << endl << flush;
            cin >> now_x;
            cin >> c >> h;
            // cerr << "c: " << c << " h: " << h << endl;
            rep(i, h) {
                int place; cin >> place;
                visited[place] = true;
                vis_cnt++;
                if( vis_cnt == N ) return;
            }
            op_cnt--;
            if( op_cnt <= 0 ) return;

            cout << "S " << 0 << " " << 1 << endl << flush;
            cin >> now_y;
            cin >> c >> h;
            // cerr << "c: " << c << " h: " << h << endl;
            rep(i, h) {
                int place; cin >> place;
                visited[place] = true;
                vis_cnt++;
                if( vis_cnt == N ) return;
            }
            op_cnt--;
            if( op_cnt <= 0 ) return;

            // cerr << "now_x: " << now_x << " now_y: " << now_y << endl;
            now_x = (100000.0 - now_x);
            now_y = (100000.0 - now_y);
        }
        return;
    }

    void caseB() {
        // 199*2 * 199*2 の Grid と見なして一番良い経路を導き出す
        vector<vector<vector<bool>>> edge(199*2, vector(199*2, vector<bool>(DIR_NUM, false)));
        bool f = true;
        rep(i,199*2) rep(j,199*2) {
            rep(d,DIR_NUM) {
                int ni = i + dx[d], nj = j + dy[d];
                if( ni < 0 || ni >= 199*2 || nj < 0 || nj >= 199*2 ) continue;

                int x = (i+1)*500 - 100000, y = (j+1)*500 - 100000;
                int nx = (ni+1)*500 - 100000, ny = (nj+1)*500 - 100000;
                
                bool isWall = false;
                rep(k,M) {
                    auto [lx, ly] = wall[k].p1;
                    auto [rx, ry] = wall[k].p2;
                    int max_x = max(lx, rx), min_x = min(lx, rx);
                    int max_y = max(ly, ry), min_y = min(ly, ry);
                    if( x < min_x && nx < min_x ) continue;
                    if( x > max_x && nx > max_x ) continue;
                    if( y < min_y && ny < min_y ) continue;
                    if( y > max_y && ny > max_y ) continue;

                    if( (wall[k].isUpper(P(x, y)) && wall[k].isLower(P(nx, ny))) || (wall[k].isLower(P(x, y)) && wall[k].isUpper(P(nx, ny))) ) {
                        isWall = true;
                        break;
                    }
                }
                if( isWall ) continue;
                edge[i][j][d] = true;
            }
        }

        // BFS を N 回行う
        vector<vector<bool>> visited;
        vector<bool> vis_dest(N, false);
        vector<vector<pair<int, int>>> prev;
        queue<pair<int,int>> pq;
        int now_x = (sx+100000) / 500 + 1, now_y = (sy+100000) / 500 + 1, dest_cnt = 0;

        vector<bool> dest_vis(N, false);

        rep(i,N) {
            visited.assign(199*2, vector<bool>(199*2, false));
            prev.assign(199*2, vector<pair<int, int>>(199*2, pair(-1, -1)));
            pq.push(pair(now_x, now_y));
            visited[now_x][now_y] = true;
            int now_dest = -1, sx = -1, sy = -1;

            cerr << "i = " << i << endl;
            cerr << "now: " << now_x << " " << now_y << endl;

            while( !pq.empty() ) {
                auto [x, y] = pq.front(); pq.pop();
                // もしどこかの目的地と距離が 500 以下になったら強制終了
                rep(j,N) {
                    if( dest_vis[j] ) continue;
                    auto [nx, ny] = dest[j];
                    long double real_x = (x+1)*500 - 100000, real_y = (y+1)*500 - 100000;
                    long double dist = sqrt((nx - real_x)*(nx - real_x) + (ny - real_y)*(ny - real_y));
                    if( dist <= 500.0 ) {
                        now_dest = j;
                        sx = x, sy = y;
                        cerr << "sx: " << sx << " sy: " << sy << endl;
                        cerr << "dest: " << " " << nx << " " << ny << " " << now_dest << endl;
                        cerr << "real: " << real_x << " " << real_y << endl;
                        dest_vis[j] = true;
                        break;
                    }
                }
                if( now_dest != -1 ) break;

                rep(d,DIR_NUM) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if( nx < 0 || nx >= 199*2 || ny < 0 || ny >= 199*2 ) continue;
                    if( visited[nx][ny] ) continue;
                    if( !edge[x][y][d] ) continue;

                    visited[nx][ny] = true;
                    prev[nx][ny] = pair(x, y);
                    pq.push(pair(nx, ny));
                }
            }
            while( !pq.empty() ) pq.pop();
            if( now_dest == -1 ) {
                cerr << "Error: No Route\n";
                return;
            }

            // 最短経路をたどる
            vector<pair<int, int>> route;
            while( sx != -1 ) {
                route.emplace_back(pair(sx, sy));
                auto [nx, ny] = prev[sx][sy];
                sx = nx, sy = ny;
            }
            reverse(route.begin(), route.end());

            // たどった経路を実行
            int pre_d = 4;
            cerr << "route: " << route.size() << endl;
            rep(j,route.size()-1) {
                auto [x, y] = route[j];
                auto [nx, ny] = route[j+1];
                // 方向を確認
                int d = ( x < nx ? 0 : ( x > nx ? 2 : ( y < ny ? 3 : 1 ) ) );
                if( d == pre_d ) {
                    // 同じ方向なら適当に計測
                    cout << "S " << 0 << " " << 1 << endl << flush;
                    int tmp; cin >> tmp;
                    cin >> c >> h;
                    op_cnt--;
                    if( op_cnt <= 0 ) return;
                } else {
                    // 違う方向なら方向転換
                    if( pre_d != 4 ) {
                        cout << "A " << dx[(pre_d+2)%DIR_NUM]*500 << " " << dy[(pre_d+2)%DIR_NUM]*500 << endl << flush;
                        cin >> c >> h;
                        rep(k,h) {
                            int place; cin >> place;
                            vis_dest[place] = true;
                            dest_cnt++;
                            if( dest_cnt == N ) return;
                        }
                        op_cnt--;
                        if( op_cnt <= 0 ) return;
                    }
                    cout << "A " << dx[d]*500 << " " << dy[d]*500 << endl << flush;
                    cin >> c >> h;
                    rep(k,h) {
                        int place; cin >> place;
                        vis_dest[place] = true;
                        dest_cnt++;
                        if( dest_cnt == N ) return;
                    }
                    op_cnt--;
                    if( op_cnt <= 0 ) return;
                }
                pre_d = d;
            }
            if( pre_d != 4 ) {
                cout << "A " << dx[(pre_d+2)%DIR_NUM]*500 << " " << dy[(pre_d+2)%DIR_NUM]*500 << endl << flush;
                cin >> c >> h;
                rep(k,h) {
                    int place; cin >> place;
                    vis_dest[place] = true;
                    dest_cnt++;
                    if( dest_cnt == N ) return;
                }
                op_cnt--;
                if( op_cnt <= 0 ) return;
            }
            auto [gx, gy] = route.back();
            now_x = gx, now_y = gy;

            // cerr << endl;
        }

        while( true ) {
            cout << "S " << 0 << " " << 1 << endl << flush;
            cin >> now_x;
            cin >> c >> h;
            rep(i, h) {
                int place; cin >> place;
                vis_dest[place] = true;
                dest_cnt++;
                if( dest_cnt == N ) return;
            }
            op_cnt--;
            if( op_cnt <= 0 ) return;
        }

        return;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Solver solver;
    solver.solve();
    
    return 0;
}