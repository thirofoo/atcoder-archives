/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/future-contest-2018-qual/submissions/31154889
 * Submitted at: 2022-04-22 20:52:46
 * Problem URL: https://atcoder.jp/contests/future-contest-2018-qual/tasks/future_contest_2018_qual_a
 * Result: WA
 * Execution Time: 10 ms
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

unsigned int randInt() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}

int main() {
    //入力受付
    auto start = chrono::system_clock::now();
    vector<vector<int>> field(100,vector<int>(100,0));
    vector<T> query;
    rep(i,100)rep(j,100)cin >> field[i][j];
    int cnt = 0;

    //処理パート
    rep(i,1000){
        int x = randInt()%100;
        int y = randInt()%100;
        int z = randInt()%100;
        query.push_back(T(x,y,z));
    }

    //出力
    cout << cnt << endl;
    rep(i,cnt){
        auto [x,y,h] = query[i];
        cout << x << " " << y << " " << h << endl;
    }
    auto end = chrono::system_clock::now();
    cout << "Passed time : " << chrono::duration_cast<chrono::milliseconds>(end-start).count() << "ms" << endl;

    return 0;
}
