/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc010/submissions/31225737
 * Submitted at: 2022-04-24 15:12:28
 * Problem URL: https://atcoder.jp/contests/ahc010/tasks/ahc010_a
 * Result: AC
 * Execution Time: 5 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

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

//Xor-shift (超高速乱数生成)
unsigned int randInt() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}

int main() {
    utility::mytm.CodeStart();
    vector<string> field(30);
    rep(i,30)cin >> field[i];
    rep(i,30){
        rep(j,30){
            cout << randInt()%4;
        }
    }
    // while(utility::mytm.elapsed() <= 6000){

    // }
    return 0;
}