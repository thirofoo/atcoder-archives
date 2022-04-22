/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/future-contest-2018-qual/submissions/31156801
 * Submitted at: 2022-04-22 22:28:20
 * Problem URL: https://atcoder.jp/contests/future-contest-2018-qual/tasks/future_contest_2018_qual_a
 * Result: AC
 * Execution Time: 2015 ms
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

//山を形成する時の遷移。右上→右下→左下→左上の移動を表している。
vector<int> dx = {1,-1,-1,1};
vector<int> dy = {1,1,-1,-1};

namespace utility {
    struct timer {
        chrono::system_clock::time_point start;
 
        // 開始時間を記録
        void CodeStart() {
            start = chrono::system_clock::now();
        }
 
        // 経過時間 (s) を返す
        ll elapsed() const {
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

bool out_field(int nx,int ny){
    return (0 <= nx && nx < 100 && 0 <= ny && ny < 100 ? false : true);
}

ll CalcScore(vector<T>& query,vector<vector<int>>& field){
    ll score = 200000000,q_size = query.size();
    vector<vector<int>> myF(100,vector<int>(100,0));
    rep(i,q_size){
        auto [x,y,z] = query[i];
        myF[x][y] += z;
        rep(j,z-1){
            //始点座標。◇の左の頂点から時計回りに回る感じで山を形成。
            int nx = x,ny = y-(z-1-j);
            rep(k,4){
                rep(l,z-1-j){
                    if(!out_field(nx,ny)) myF[nx][ny] += j+1;
                    nx += dx[k]; ny += dy[k];
                }
            }
        }
    }
    rep(i,100)rep(j,100){
        score -= abs(field[i][j]-myF[i][j]);
    }
    return score;
}

int main() {
    //入力受付
    utility::mytm.CodeStart();
    vector<vector<int>> field(100,vector<int>(100,0));
    vector<T> best_query;
    rep(i,100)rep(j,100)cin >> field[i][j];
    ll best_score = 0;

    //処理パート
    while(utility::mytm.elapsed() <= 2000){
        vector<T> tmp;
        rep(i,1000){
            int x = randInt()%100;
            int y = randInt()%100;
            int z = randInt()%100 + 1;
            tmp.push_back(T(x,y,z));
        }
        ll score = CalcScore(tmp,field);
        if(score > best_score){
            best_score = score;
            best_query = tmp;
        }
    }

    //出力
    int size = best_query.size();
    cout << size << endl;
    rep(i,size){
        auto [x,y,z] = best_query[i];
        cout << x << " " << y << " " << z << endl;
    }

    return 0;
}
