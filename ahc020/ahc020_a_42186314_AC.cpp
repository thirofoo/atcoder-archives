/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc020/submissions/42186314
 * Submitted at: 2023-06-11 15:52:57
 * Problem URL: https://atcoder.jp/contests/ahc020/tasks/ahc020_a
 * Result: AC
 * Execution Time: 1927 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<int, int, ll> T;
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
#define TIME_LIMIT 1900
inline double temp(int start) {
    double start_temp = 100,end_temp = 1;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int best,int now,int start) {
    return exp((double)(now - best) / temp(start));
}

//-----------------以下から実装部分-----------------//

struct State{
    // State内で用いる変数等の定義

    State(){
        // コンストラクタ(初期化)
        
    }
};

struct Solver{
    // State内で用いる変数等の定義
    int n, m, k, place, query;
    ll ele_power;
    ld best_score, cand_score, score, num;
    vector<P> broad, residents;
    vector<T> edge;
    vector<ll> power;
    vector<bool> onoff;

    Solver(){
        // コンストラクタ(初期化)
    }

    void input(){
        cin >> n >> m >> k;
        rep(i,n){
            int x,y; cin >> x >> y;
            broad.push_back(P(x,y));
        }
        rep(i,m){
            int u,v,w; cin >> u >> v >> w;
            u--; v--;
            edge.push_back(T(u,v,w));
        }
        rep(i,k){
            int a,b; cin >> a >> b;
            residents.push_back(P(a,b));
        }
        power.assign(n,5000);
        onoff.assign(m,true);
    }

    void output(){
        rep(i,n)cout << power[i] << " ";
        cout << endl;
        rep(i,m)cout << onoff[i] << " ";
        cout << endl;
    }

    void solve(){
        utility::mytm.CodeStart();

        ld best_score = calcScore();
        // 全部覆いきれてないなら 全power max
        // cerr << best_score << endl;
        // cerr << flush;
        if(best_score <= 1000005)return;

        // 山登り法
        while(utility::mytm.elapsed() <= TIME_LIMIT){
            // query 候補
            // 1. power調整
            // 2. 辺追加・削除

            // query = rand_int()%2;
            // if(query == 0){

            // }
            // else{

            // }

            place = rand_int()%n;
            ele_power = rand_int()%5001;
            swap(power[place], ele_power);

            cand_score = calcScore();
            if(best_score < cand_score){
                best_score = cand_score;
            }
            else{
                swap(power[place], ele_power);
            }
        }
    }

    ld calcScore(){
        set<int> st;
        score = 0;
        rep(i,n){
            auto &&[x,y] = broad[i];
            score += power[i] * power[i];
            rep(j,k){
                if(st.count(j))continue;
                auto [a,b] = residents[j];
                if( (a-x)*(a-x) + (b-y)*(b-y) <= power[i]*power[i] ){
                    st.insert(j);
                }
            }
        }
        rep(i,m){
            if(onoff[i]){
                auto &&[u,v,w] = edge[i];
                score += w;
            }
        }
        num = st.size();
        // cerr << num << endl;
        // cout << flush;

        score = 1.0 + 100000000.0 / ( score + 10000000.0 );
        score *= 1000000.0;
        return (num == k ? score : 1000000 * (num+1) / (ld)k );
    }

    // ld calcDiff(){
        
    // }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Solver solver;
    solver.input();
    solver.solve();
    solver.output();
    
    return 0;
}