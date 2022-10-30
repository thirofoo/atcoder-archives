/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc015/submissions/36096966
 * Submitted at: 2022-10-30 18:39:03
 * Problem URL: https://atcoder.jp/contests/ahc015/tasks/ahc015_a
 * Result: AC
 * Execution Time: 17 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int,vector<vector<int>>,char> T;
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

int su = 0,pa = 0,st = 0,total = 0,nowp,nx,ny,cnt = 0;
vector<vector<bool>> visited;
vector<vector<int>> field(10,vector<int>(10,0));
vector<int> f(100,0);
vector<char> d = {'L','R','F','B'};
priority_queue<T> choice;
queue<P> todo;
// 右下左上の順番
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

void input(){
    rep(i,100)cin >> f[i];
    return;
}

vector<vector<int>> updateField(vector<vector<int>> pf,int dir){
    if(dir == 0){
        rep(h,10){
            rep(w,10){
                nowp = w;
                if(nowp == 0 || pf[h][nowp-1] != 0)continue;
                while(nowp != 0 && pf[h][nowp-1] == 0){
                    swap(pf[h][nowp-1],pf[h][nowp]);
                    nowp--;
                }
            }
        }
    }
    else if(dir == 1){
        rep(h,10){
            for(int w=9;w>=0;w--){
                nowp = w;
                if(nowp == 9 || pf[h][nowp+1] != 0)continue;
                while(nowp != 9 && pf[h][nowp+1] == 0){
                    swap(pf[h][nowp+1],pf[h][nowp]);
                    nowp++;
                }
            }
        }
    }
    else if(dir == 2){
        rep(w,10){
            rep(h,10){
                nowp = h;
                if(nowp == 0 || pf[nowp-1][w] != 0)continue;
                while(nowp != 0 && pf[nowp-1][w] == 0){
                    swap(pf[nowp-1][w],pf[nowp][w]);
                    nowp--;
                }
            }
        }
    }
    else{
        rep(w,10){
            for(int h=9;h>=0;h--){
                nowp = h;
                if(nowp == 9 || pf[nowp+1][w] != 0)continue;
                while(nowp != 9 && pf[nowp+1][w] == 0){
                    swap(pf[nowp+1][w],pf[nowp][w]);
                    nowp++;
                }
            }
        }
    }
    return pf;
}

int calcScore(vector<vector<int>> &p){
    int score = 0,tmp;
    visited.assign(10,vector<bool>(10,false));
    rep(h,10){
        rep(w,10){
            if(p[h][w] == 0 || visited[h][w])continue;
            tmp = 0;
            todo.push(P(h,w));
            while(!todo.empty()){
                auto [x,y] = todo.front(); todo.pop();
                if(p[x][y] != p[h][w] || visited[x][y])continue;
                visited[x][y] = true;
                tmp++;
                rep(i,4){
                    nx = x+dx[i],ny = y+dy[i];
                    if(nx < 0 || nx >= 10 || ny < 0 || ny >= 10)continue;
                    todo.push(P(nx,ny));
                }
            }
            score += tmp*tmp;
        }
    }
    score *= 1000000;
    score /= total;
    return score;
}

void solve(){
    rep(i,100){
        if(f[i] == 1)su++;
        else if(f[i] == 2)pa++;
        else st++;

        int p; cin >> p;
        cnt = 0;
        rep(h,10){
            rep(w,10){
                if(field[h][w] == 0)cnt++;
                if(cnt == p){
                    field[h][w] = f[i];
                    break;
                }
            }
            if(cnt == p)break;
        }
        total = su*su + pa*pa + st*st;

        rep(j,4){
            auto nf = updateField(field,j);
            // if(i == 99){
            //     rep(h,10){
            //         rep(w,10){
            //             cerr << nf[h][w] << " ";
            //         }
            //         cerr << endl;
            //     }
            //     cerr << endl;
            // }
            choice.push(T(calcScore(nf),nf,d[j]));
        }

        auto [score,nf,dir] = choice.top();
        field = nf;
        cout << dir << endl;
        cout << flush;

        while(!choice.empty()){
            // auto [x,y,z] = choice.top();
            // cerr << x << " : " << z << endl;
            choice.pop();
        }
        // cerr << endl;
        // cerr << flush;
    }
    return;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    // 入力受付part
    input();

    // 解答part
    solve();

    return 0;
}