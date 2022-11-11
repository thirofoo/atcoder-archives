/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc016/submissions/36383720
 * Submitted at: 2022-11-11 20:55:30
 * Problem URL: https://atcoder.jp/contests/ahc016/tasks/ahc016_a
 * Result: WA
 * Execution Time: 12 ms
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
    double start_temp = 100,end_temp = 1;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int now,int next,int start) {
    return exp((double)(next - now) / temp(start));
}

//-----------------以下から実装部分-----------------//

constexpr int test = 100;

struct State{
    // State内で用いる変数等の定義
    string graph;

    State(int num,int n){
        // コンストラクタ(初期化)
        graph = "";
        rep(i,n*(n-1)/2){
            if(i < num)graph.push_back('1');
            else graph.push_back('0');
        }
    }
};

struct Solver{
    // State内で用いる変数等の定義
    int m,err,n,one,edge;
    vector<State> state;

    Solver(){
        n = 10; // 現時点では不変
        edge = n*(n-1)/2;
    }

    void input(){
        cin >> m >> err;
        one = edge/m;
        if(one%2 == 0)one--;
        rep(i,m)state.emplace_back(State(one*(i+1),n));
    }

    void output(){
        cout << n << '\n';
        rep(i,m)cout << state[i].graph << '\n';
        cout << flush;
    }

    void solve(){
        rep(i,test){
            string t; cin >> t;
            int cnt = 0;
            rep(i,edge)cnt += (t[i] == '1');
            int c = ( cnt + (one-1)/2 )/one;
            cout << (c == 0 ? 1 : c)-1 << '\n';
            cout << flush;
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // NとM個のグラフ出力part
    Solver solver;
    solver.input();
    solver.output();

    // 正しいグラフに読み直しpart
    solver.solve();
    
    return 0;
}