/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc015/submissions/36099371
 * Submitted at: 2022-10-30 19:53:48
 * Problem URL: https://atcoder.jp/contests/ahc015/tasks/ahc015_a
 * Result: AC
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

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int su = 0,pa = 0,st = 0,most = 0;
    vector<int> a(100),c(3);
    vector<P> b;
    rep(i,100){
        cin >> a[i];
        if(a[i] == 1)su++;
        else if(a[i] == 2)pa++;
        else st++;
    }
    b.push_back(P(su,1));
    b.push_back(P(pa,2));
    b.push_back(P(st,3));
    sort(b.begin(),b.end());
    rep(i,3){
        auto [num,fru] = b[i];
        c[i] = fru;
    }

    bool up = false;
    rep(i,99){
        int p; cin >> p;
        if(a[i+1] == c[0]){
            cout << 'F' << endl;
            up = true;
        }
        else if(a[i+1] == c[1]){
            if(up){
                cout << 'B' << endl;
                up = false;
            }
            else cout << 'R' << endl;
        }
        else{
            if(up){
                cout << 'B' << endl;
                up = false;
            }
            else cout << 'L' << endl;
        }
    }
    cout << 'F' << endl;
}