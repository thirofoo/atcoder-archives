/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc012/submissions/32980990
 * Submitted at: 2022-07-04 17:22:42
 * Problem URL: https://atcoder.jp/contests/ahc012/tasks/ahc012_a
 * Result: AC
 * Execution Time: 1411 ms
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
    return (double)(rand_int()%100000)/100000;
}

//温度関数
#define TIME_LIMIT 2900
inline double temp() {
    //時間が過ぎる程温度は低くなる → 採用率down
    double start_temp = 10000,end_temp = 1000;
    return start_temp + (end_temp-start_temp)*(utility::mytm.elapsed()/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int now,int next) {
    //next > now なら必ず1以上になる。
    //逆ならnow-nextが小さい程、指数部が0に近い負の数になる → 採用率up
    //また、tempが大きい程、指数部が0に近い負の数になる → 採用率up
    return exp((double)(next - now) / temp());
}

//-----------------以下から実装部分-----------------//

#define LINE 25
//line1 : 垂直な直線 line2 : 水平な直線
vector<T> line1,line2;
vector<int> a(10);
vector<P> stro;
const int square = 20000/LINE;
int n,k,size1 = 0,size2 = 0,total = 0;

int CalcScore(){
    //課題1：何故か精度が不正確
    //課題2：遅い

    int ans = 0,px = -10000,py = -10000;
    vector<int> p_cnt(n,0);
    for(auto [x1,y1,w1,z1]:line1){
        for(auto [x2,y2,w2,z2]:line2){
            int mem = 0;
            rep(l,n){
                auto [x,y] = stro[l];
                if(px < x && x < x1 && py < y && y < y2)mem++;
            }
            if(1 <= mem && mem <= 10)p_cnt[mem-1]++;
            py = y2;
        }
        px = x1;
    }
    rep(i,10)ans += min(a[i],p_cnt[i])-abs(a[i]-p_cnt[i]);
    return ans*1e6/total;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    cin >> n >> k;
    rep(i,10){
        cin >> a[i];
        total += a[i];
    }
    rep(i,n){
        int x,y; cin >> x >> y;
        stro.push_back(P(x,y));
    }

    utility::mytm.CodeStart();

    //縦横垂直切り作戦 => 辺追加・削除・移動等で点数を上げる
    
    //まず格子状にLINE*LINE位に区切る
    int start = -10000;
    rep(i,LINE-1){
        line1.push_back(T(start+square*(i+1),0,start+square*(i+1),1));
        line2.push_back(T(0,start+square*(i+1),1,start+square*(i+1)));
        k -= 2;
    }

    int best_score = CalcScore();
    int cnt = 0;

    //横線を追加part
    while(utility::mytm.elapsed() <= 1400){
        if(k == 0)break;
        cnt++;
        // cout << cnt << " " << flush;

        int y = (int)(rand_int()%20000)-10000;
        line2.push_back(T(0,y,1,y));
        sort(line2.begin(),line2.end());
        size2++;
        int now_score = CalcScore();
        if(best_score < now_score){
            // cout << "ok : " << cnt << " " << best_score << " " << now_score << endl << flush;
            best_score = now_score;
            k--;
        }
        else{
            line2.erase(lower_bound(line2.begin(),line2.end(),T(0,y,1,y)));
            // cout << "no : " << cnt << " " << tmp << " " << p  << " " << best_score << " " << now_score << endl << flush;
        }
    }
    // cout << endl;

    // //時間が余ってたら移動part
    // while(utility::mytm.elapsed() <= 2950){
    //     cnt++;
    //     // cout << cnt << " " << flush;
    //     //どの線を選ぶか
    //     int l = rand_int()%100,add = (int)(rand_int()%500)-250;
    //     auto [x1,y1,x2,y2] = line2[l];
    //     if(y1+add < -10000 || 10000 < y1+add)continue;

    //     line2[l] = T(x1,y1+add,x2,y2+add);
    //     sort(line2.begin(),line2.end());

    //     int now_score = CalcScore();

    //     if(best_score < now_score){
    //         cout << "ok : " << cnt << " " << best_score << " " << now_score << endl << flush;
    //         best_score = now_score;
    //     }
    //     else{
    //         double tmp = rand_double();
    //         double p = prob(best_score,now_score);
    //         if(tmp < p){
    //             cout << "ok : " << cnt << " " << tmp << " " << p  << " " << best_score << " " << now_score << endl << flush;
    //             best_score = now_score;
    //         }
    //         else{
    //             cout << "no : " << cnt << " " << tmp << " " << p  << " " << best_score << " " << now_score << endl << flush;
    //             line2[l] = T(x1,y1,x2,y2);
    //         }
    //     }
    // }

    cout << 100-k << endl;
    for(auto [x1,y1,x2,y2]:line1){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    for(auto [x1,y1,x2,y2]:line2){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    // cout << cnt << endl;
    
    return 0;
}