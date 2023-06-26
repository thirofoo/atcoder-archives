/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc021/submissions/42972516
 * Submitted at: 2023-06-26 13:08:24
 * Problem URL: https://atcoder.jp/contests/ahc021/tasks/ahc021_a
 * Result: AC
 * Execution Time: 19 ms
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
inline double prob(int best,int now,int start) {
    return exp((double)(now - best) / temp(start));
}

//-----------------以下から実装部分-----------------//

vector<int> dx = {-1,-1, 0, 0, 1, 1};
vector<int> dy = {-1, 0,-1, 1, 0, 1};
vector<int> row = {1,3,6,10,15,21,28,36,45,55,66,78,91,105,120,136,153,171,190,210,231,253,276,300,325,351,378,406,435,465};

struct State{
    int n, px1, py1, px2, py2, parent1, parent2;
    vector<vector<int>> ball;
    vector<T> operation;
    vector<P> place;

    State() : n(30){ }
    State(vector<vector<int>> _ball){
        n = 30;
        ball = _ball;
        place.assign(n*(n+1)/2,P(-1,-1));
        int cnt = 0;
        rep(i,n){
            for(ll j=0;j<=i;j++){
                place[ball[i][j]] = P(i,j);
                cnt++;
            }
        }
        init();
    }

    void init(){
        // 初期解生成
        // 小さいballから愚直に上げる (親の内大きい方を選択)
        rep(i,n*(n+1)/2){
            auto [x,y] = place[i];
            while(true){
                // 左上 & 右上
                px1 = x + dx[0]; py1 = y + dy[0];
                px2 = x + dx[1]; py2 = y + dy[1];

                parent1 = ( outField(px1,py1) ? -1 : ball[px1][py1]);
                parent2 = ( outField(px2,py2) ? -1 : ball[px2][py2]);

                if( parent1 < i && parent2 < i )break;

                if( parent1 > parent2 ){
                    operation.push_back(T(x,y,px1,py1));
                    swap(place[ball[x][y]],place[ball[px1][py1]]);
                    swap(ball[x][y],ball[px1][py1]);
                    x = px1; y = py1;
                }
                else{
                    operation.push_back(T(x,y,px2,py2));
                    swap(place[ball[x][y]],place[ball[px2][py2]]);
                    swap(ball[x][y],ball[px2][py2]);
                    x = px2; y = py2;
                }
            }
        }
    }

    inline bool outField(int i, int j){
        return ( j < 0 || i+1 <= j );
    }
};

struct Solver{
    int n;
    State field;


    Solver(){
        n = 30;
    }

    void input(){
        vector<vector<int>> ball(n,vector<int>(n,-1));
        rep(i,30){
            for(ll j=0;j<=i;j++){
                cin >> ball[i][j];
            }
        }
        field = State(ball);
    }

    void output(){
        cout << field.operation.size() << endl;
        rep(i,field.operation.size()){
            auto [x,y,z,w] = field.operation[i];
            cout << x << " " << y << " " << z << " " << w << endl;
        }
    }

    void solve(){

    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Solver solver;
    solver.input();
    solver.solve();
    solver.output();
    
    return 0;
}