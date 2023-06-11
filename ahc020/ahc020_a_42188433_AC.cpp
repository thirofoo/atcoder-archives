/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc020/submissions/42188433
 * Submitted at: 2023-06-11 16:39:01
 * Problem URL: https://atcoder.jp/contests/ahc020/tasks/ahc020_a
 * Result: AC
 * Execution Time: 1909 ms
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
typedef pair<ld, ll> P2;
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
    int n, m, k, place, query, change_edge, turn = 0;
    ll ele_power;
    ld best_score, cand_score, score, num, sum, now_power;
    vector<P> broad, residents;
    vector<T> edge;
    vector<ll> power;

    // 各放送局が網羅してる住民の P(距離^2, idx)
    vector<priority_queue<P2>> include;
    queue<P2> store;
    // 各住民が何個の放送局と繋がってるか
    vector<ll> res_cnt;
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
        include.assign(n,{});
        res_cnt.assign(k,0);
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
        cerr << best_score << endl;
        cerr << flush;
        if(best_score <= 1000005)return;

        // 山登り法
        while(utility::mytm.elapsed() <= TIME_LIMIT){
            // query 候補
            // 1. power調整
            // 2. 辺追加・削除

            // query = rand_int()%2;
            query = 0;
            if(query == 0){
                // query 1
                place = rand_int()%n;
                if(power[place] == 0)continue;
                // 現時点では増える方向は考慮しない
                ele_power = rand_int()%power[place];
                swap(power[place], ele_power);

                cand_score = calcDiff(place, ele_power);

                if(best_score < cand_score){
                    best_score = cand_score;
                    // cerr << best_score << endl;
                    // cerr << flush;
                    while(!store.empty())store.pop();
                }
                else{
                    swap(power[place], ele_power);
                    while(!store.empty()){
                        include[place].push(store.front());
                        res_cnt[store.front().second]++;
                        store.pop();
                    }
                    num = k;
                }
            }
            else{
                // query 2
                change_edge = rand_int()%m;
                onoff[change_edge] = !onoff[change_edge];
                cand_score = calcScore();
                if(best_score < cand_score){
                    best_score = cand_score;
                    cerr << best_score << endl;
                    cerr << flush;
                }
                else{
                    onoff[change_edge] = !onoff[change_edge];
                }
            }
            turn++;
        }
        cerr << turn << endl;
    }

    ld calcScore(){
        set<int> st;
        sum = 0;
        rep(i,n){
            auto &&[x,y] = broad[i];
            sum += power[i] * power[i];
            rep(j,k){
                auto &&[a,b] = residents[j];
                if( (a-x)*(a-x) + (b-y)*(b-y) <= power[i]*power[i] ){
                    include[i].push(P2((a-x)*(a-x) + (b-y)*(b-y), j));
                    res_cnt[j]++;
                    st.insert(j);
                }
            }
        }
        rep(i,m){
            if(onoff[i]){
                auto &&[u,v,w] = edge[i];
                sum += w;
            }
        }
        num = st.size();
        score = 1.0 + 100000000.0 / ( sum + 10000000.0 );
        score *= 1000000.0;
        return (num == k ? score : -1 );
    }

    ld calcDiff(ll idx, ll pre_power){
        now_power = power[idx] * power[idx];
        sum -= pre_power * pre_power;
        sum += now_power;

        while(!include[idx].empty()){
            auto [dis, i] = include[idx].top();
            if(dis <= now_power)break;

            // cerr << dis << " " << now_power << endl;
            // cerr << endl;

            store.push(include[idx].top());
            include[idx].pop();
            res_cnt[i]--;
            if(res_cnt[i] == 0)num--;
        }

        score = 1.0 + 100000000.0 / ( sum + 10000000.0 );
        score *= 1000000.0;
        
        ld tmp = (num == k ? score : -1 ); 
        if(turn <= 10)cerr << tmp << endl;

        return (num == k ? score : tmp );
    }
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