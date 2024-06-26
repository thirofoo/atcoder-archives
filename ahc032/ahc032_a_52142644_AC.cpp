/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc032/submissions/52142644
 * Submitted at: 2024-04-07 19:18:51
 * Problem URL: https://atcoder.jp/contests/ahc032/tasks/ahc032_a
 * Result: AC
 * Execution Time: 1 ms
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

static constexpr int MOD = 998244353;

struct State{

    State() {

    }
};

struct Solver{
    int n, m, k;
    vector<vector<int>> a;
    vector<vector<vector<int>>> stamp;
    vector<tuple<int,int,int>> ans;

    Solver() {
        this->input();
    }

    void input() {
        cin >> n >> m >> k;  
        a.resize(n, vector<int>(n));      
        rep(i,n) rep(j,n) cin >> a[i][j];
        rep(i,m) {
            vector<vector<int>> s(3, vector<int>(3));
            rep(j,3) rep(k,3) cin >> s[j][k];
            stamp.emplace_back(s);
        }
        return;
    }

    void output() {
        cout << ans.size() << endl;
        for(auto [x,y,z] : ans) cout << x << " " << y << " " << z << endl;
        return;
    }

    void solve() {
        // 貪欲解法
        rep(i,n-2) rep(j,n-2) {
            int max_v = a[i][j], op = -1;
            rep(k,m) {
                if( max_v < a[i][j] + stamp[k][0][0] ) {
                    max_v = a[i][j] + stamp[k][0][0];
                    op = k;
                }
            }
            if( op == -1 ) continue;
            ans.emplace_back(tuple(op,i,j));
            rep(k,3) rep(l,3) a[i+k][j+l] += stamp[op][k][l];
        }
        return;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Solver solver;
    solver.solve();
    solver.output();
    
    return 0;
}