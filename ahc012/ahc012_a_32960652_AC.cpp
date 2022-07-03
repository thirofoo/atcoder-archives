/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc012/submissions/32960652
 * Submitted at: 2022-07-03 18:16:32
 * Problem URL: https://atcoder.jp/contests/ahc012/tasks/ahc012_a
 * Result: AC
 * Execution Time: 2915 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

//line1 : 垂直な直線 line2 : 水平な直線
vector<T> line1,line2;
vector<int> a(10);
vector<P> stro;
const int square = 20000/18;
int n,k,s1 = 0,s2 = 0,lorc;

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

unsigned int rand_int() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}

ll CalcScore(){
    //課題1：何故か精度が不正確
    //課題2：遅い

    ll ans = 0,px = -10000,py = -10000;
    //円とか関係なく18*18で確認
    vector<int> p_cnt(10,0);

    ll ax,ay;
    if(lorc == 1){
        auto [a1,a2,a3,a4] = line1.back();
        // cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
        ax = a1;
    }
    else{
        auto[a1,a2,a3,a4] = line2.back();
        // cout << a1 << " " << a2 << " " << a3 << " " << a4 << endl;
        ay = a2;
    }
    bool f1 = true,f2 = true;

    rep(i,s1+1){
        auto [x1,y1,w1,z1] = line1[i];
        if(lorc == 1 && f1){
            if(x1 > ax){
                auto [a1,a2,a3,a4] = line1.back();
                x1 = a1; i--;
                f1 = false;
            }
        }
        rep(j,s2+1){
            auto [x2,y2,w2,z2] = line2[j];
            if(lorc == 0 && f2){
                if(y2 > ay){
                    auto [a1,a2,a3,a4] = line2.back();
                    y2 = a2; j--;
                    f2 = false;
                }
            }
            // cout << i << " " << j << endl;
            ll mem = 0;

            rep(l,n){
                auto [x,y] = stro[l];
                if(px < x && x < x1 && py < y && y < y2){
                    mem++;
                }
            }
            if(1 <= mem && mem <= 10){
                p_cnt[mem-1]++;
            }
            py = y2;
        }
        px = x1;
    }
    rep(i,10){
        ans += min(a[i],p_cnt[i]);
        // cout << i+1 << " : " << a[i] << " " << p_cnt[i] << endl;
    }
    
    // cout << endl;
    return ans;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    cin >> n >> k;
    rep(i,10)cin >> a[i];
    rep(i,n){
        int x,y; cin >> x >> y;
        stro.push_back(P(x,y));
    }

    utility::mytm.CodeStart();

    //縦横垂直切り作戦 => 辺追加・削除・移動等で点数を上げる
    //calcscore も作りやすそう
    
    //まず格子状に18*18位に区切る(単純計算で1区画9個くらいに分かれる)
    int start = -10000;
    rep(i,17){
        line1.push_back(T(start+square*(i+1),0,start+square*(i+1),1));
        line2.push_back(T(0,start+square*(i+1),1,start+square*(i+1)));
        k -= 2; s1++; s2++;
    }

    ll score = CalcScore();
    ll cnt = 0;

    while(utility::mytm.elapsed() <= 2900){
        cnt++;
        // cout << "unti" << " " << flush;
        if(k == 0)break;
        //縦か横か
        line1.push_back(T(10000,0,10000,1));
        line2.push_back(T(0,10000,1,10000));

        lorc = rand_int()%2;
        if(lorc == 1){
            //縦
            ll x = (int)(rand_int()%20000)-10000;
            // cout << "x : " << x << endl;

            line1.push_back(T(x,0,x,1));
            ll now_score = CalcScore();
            if(score >= now_score){
                line1.pop_back();
            }
            else{
                sort(line1.begin(),line1.end());
                score = now_score;
                k--; s1++;
            }
        }
        else{
            //横
            ll y = (int)(rand_int()%20000)-10000;
            // cout << "y : " << y << endl;
            line2.push_back(T(0,y,1,y));
            ll now_score = CalcScore();
            if(score >= now_score){
                line2.pop_back();
            }
            else{
                sort(line2.begin(),line2.end());
                score = now_score;
                k--; s2++;
            }
        }

        line1.pop_back();
        line2.pop_back();

        // if(cnt)break;
    }

    cout << line1.size() + line2.size() << endl;
    for(auto [x1,y1,x2,y2]:line1){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    // cout << endl;
    for(auto [x1,y1,x2,y2]:line2){
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    }
    // cout << cnt << endl;
    
    return 0;
}