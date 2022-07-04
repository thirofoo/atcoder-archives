/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc012/submissions/32979798
 * Submitted at: 2022-07-04 16:18:55
 * Problem URL: https://atcoder.jp/contests/ahc012/tasks/ahc012_a
 * Result: AC
 * Execution Time: 2922 ms
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
#define LINE 24

//line1 : 垂直な直線 line2 : 水平な直線
vector<T> line1,line2;
vector<int> a(10);
vector<P> stro;
const int square = 20000/LINE;
int n,k,size1 = 0,size2 = 0;


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

inline double temp() {
  return pow(0.8, utility::mytm.elapsed() / 2500.0);
}

inline double prob(int now,int next) {
  if (next > now)return 1.0;
  return exp((double)(next - now) / temp());
}

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
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    cin >> n >> k;
    rep(i,10)cin >> a[i];
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

    while(utility::mytm.elapsed() <= 2900){
        if(k == 0)break;
        cnt++;
        // cout << cnt << " " << flush;

        //横線を追加part
        int y = (int)(rand_int()%20000)-10000;
        line2.push_back(T(0,y,1,y));
        sort(line2.begin(),line2.end());
        size2++;
        int now_score = CalcScore();
        if(best_score < now_score){
            // cout << "ok : " << cnt << endl << flush;
            best_score = now_score;
            k--;
        }
        else{
            double tmp = rand_double();
            double p = prob(best_score,now_score);
            if(tmp < p){
                // cout << "ok : " << cnt << " " << tmp << " " << p << endl << flush;
                best_score = now_score;
                k--;
            }
            else{
                line2.erase(lower_bound(line2.begin(),line2.end(),T(0,y,1,y)));
                // cout << "no : " << cnt << " " << tmp << " " << p << endl << flush;
            }
        }
    }
    cout << endl;

    //時間が余ってたら移動part
    while(utility::mytm.elapsed() <= 2900){
        //どの線を選ぶか
        int l = rand_int()%100;
    }

    cout << line1.size() + line2.size() << endl;
    for(auto [x1,y1,x2,y2]:line1){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    for(auto [x1,y1,x2,y2]:line2){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    // cout << cnt << endl;
    
    return 0;
}