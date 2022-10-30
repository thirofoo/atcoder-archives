/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc015/submissions/36093895
 * Submitted at: 2022-10-30 17:35:24
 * Problem URL: https://atcoder.jp/contests/ahc015/tasks/ahc015_a
 * Result: TLE
 * Execution Time: 2206 ms
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

vector<vector<int>> field(10,vector<int>(10,0));
vector<int> f(100,0);

void input(){
    rep(i,100)cin >> f[i];
    return;
}

void solve(){
    rep(i,100){
        int p; cin >> p;
        if(f[i] == 1)cout << 'L' << '\n';
        else if(f[i] == 2)cout << 'R' << '\n';
        else cout << 'F' << '\n';
    }
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(6) << fixed;
    
    // 入力受付part
    input();

    // 解答part
    solve();

    return 0;
}