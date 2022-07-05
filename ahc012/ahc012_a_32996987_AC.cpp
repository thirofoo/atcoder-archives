/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc012/submissions/32996987
 * Submitted at: 2022-07-05 15:48:41
 * Problem URL: https://atcoder.jp/contests/ahc012/tasks/ahc012_a
 * Result: AC
 * Execution Time: 2959 ms
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

#define C_NUM 10
#define R_NUM 70
//line1 : 垂直な直線 line2 : 水平な直線
vector<T> line1,line2;
vector<int> a(10);
vector<P> straw1;
vector<int> now_cnt(10,0);
vector<vector<int>> straw2;
//各区画内にある苺の数
vector<vector<int>> straw3(R_NUM+5,vector<int>(C_NUM+5,0));
int b = 20000/C_NUM,h = 20000/R_NUM;
int n,k,size1 = 0,size2 = 0,total = 0,l,add,best_score,cnt = 0;

void CalcDiff(int l,int add){
    auto [X,y1,XX,XXX] = line2[l];
    if(y1+add < -10000 || 10000 < y1+add)return;
    vector<int> cand_cnt = now_cnt;
    vector<int> near_x;
    for(int y=y1;y<=y1+add;y++){
        for(auto x:straw2[y+10000]){
            near_x.push_back(x);
            int c1 = straw3[l+1][x/b];
            int c2 = straw3[l][x/b];
            //苺の区画移動
            straw3[l+1][x/b]--;
            straw3[l][x/b]++;
            //各区画における苺の数の更新
            if(1 <= c1 && c1 <= 10)cand_cnt[c1-1]--;
            if(2 <= c1 && c1 <= 11)cand_cnt[c1-1-1]++;
            if(1 <= c2 && c2 <= 10)cand_cnt[c2-1]--;
            if(0 <= c2 && c2 <= 9)cand_cnt[c2-1+1]++;
        }
    }
    int cand_score = 0;
    rep(i,10)cand_score += min(a[i],cand_cnt[i]);
    cand_score *= 1e6; cand_score /= total;

    if(best_score < cand_score){
        best_score = cand_score;
        now_cnt = cand_cnt;
        line2[l] = T(X,y1+add,XX,XXX+add);
    }
    else{
        // double tmp = rand_double();
        // double p = prob(best_score,cand_score,0);
        // if(tmp < p){
        //     best_score = cand_score;
        //     now_cnt = cand_cnt;
        //     line2[l] = T(X,y1+add,XX,XXX+add);
        // }
            //straw3を元に戻す
        // else{
        for(auto x:near_x){
            straw3[l+1][x/b]++;
            straw3[l][x/b]--;
        }
        // }
    }
    // if(cnt <= 100){
    //     rep(i,10)cout << now_cnt[i] << " " << flush;
    //     cout << endl;
    //     rep(i,10)cout << cand_cnt[i] << " " << flush;
    //     cout << endl;
    //     cout << best_score << " " << cand_score << endl << endl;
    // }
}

int CalcScore(){
    int ans = 0,px = -10000,py = -10000;
    for(auto [x1,y1,w1,z1]:line1){
        for(auto [x2,y2,w2,z2]:line2){
            int mem = 0;
            rep(l,n){
                auto [x,y] = straw1[l];
                if(px < x && x < x1 && py < y && y < y2)mem++;
            }
            if(1 <= mem && mem <= 10)now_cnt[mem-1]++;
            py = y2;
        }
        px = x1;
    }
    rep(i,10)ans += min(a[i],now_cnt[i]);
    return ans*1e6/total;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    cin >> n >> k;
    rep(i,10){
        cin >> a[i];
        total += a[i];
    }

    straw2.assign(20100,vector<int>(0));
    rep(i,n){
        int x,y; cin >> x >> y;
        straw1.push_back(P(x,y));
        straw2[y+10000].push_back(x+10000);
        straw3[(y+10000)/h][(x+10000)/b]++;
    }

    utility::mytm.CodeStart();

    //縦横垂直切り作戦 => 辺追加・削除・移動等で点数を上げる
    //まず格子状にLINE*LINE位に区切る
    int start = -10000;
    rep(i,C_NUM)line1.push_back(T(start+b*(i+1),-1e7,start+b*(i+1)+1,1e7));
    rep(i,R_NUM)line2.push_back(T(-1e7,start+h*(i+1),1e7,start+h*(i+1)+1));

    best_score = CalcScore();
    // rep(i,10)cout << now_cnt[i] << " " << flush;
    // cout << endl << endl;

    //直線移動part
    while(true){
        //どの線を選ぶか
        l = rand_int()%69,add = (int)(rand_int()%(20000/70));
        
        CalcDiff(l,add);
        cnt++;
        if(cnt%1000 == 0 && utility::mytm.elapsed() >= 2950)break;
    }

    cout << R_NUM + C_NUM << endl;
    for(auto [x1,y1,x2,y2]:line1){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    for(auto [x1,y1,x2,y2]:line2){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    // cout << cnt << endl;
    
    return 0;
}
