/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc017/submissions/38641893
 * Submitted at: 2023-02-05 16:59:26
 * Problem URL: https://atcoder.jp/contests/ahc017/tasks/ahc017_a
 * Result: TLE
 * Execution Time: 6616 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
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
#define TIME_LIMIT 59000
inline double temp(int start) {
    double start_temp = 300,end_temp = 100;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(ll now,ll next,int start) {
    return exp((double)(now - next) / temp(start));
}

//-----------------以下から実装部分-----------------//

struct Solver{
    // 入力変数
    int n, m, d, k, u, v, w, x, y;
    vector<vector<int>> edge_idx;
    vector<T> vertex1, vertex2;

    int cnt, turn, start_time, e1, e2;
    ll now_score, tmp_score, prelim_score, cand_score, djk_score, start_size;

    // 評価関数系
    double tmp_rate, rate;
    priority_queue<P,vector<P>,greater<P>> todo;
    vector<int> ans, op, start_v, day_cnt, cost;
    vector<ll> now_day_score, best_day_score;
    vector<vector<P>> Graph;

    Solver(){
        // 初期入力 & 準備part
        cin >> n >> m >> d >> k;
        edge_idx.assign(n,vector<int>(n,-1));
        best_day_score.assign(d,LLONG_MAX);
        now_day_score.assign(d,LLONG_MAX);
        day_cnt.assign(d,0);
        Graph.assign(n,{});
        ans.assign(m,0);
        op.assign(d,1);
        rep(i,m){
            u,v,w; cin >> u >> v >> w;
            u--; v--;
            Graph[u].emplace_back(P(v,w));
            Graph[v].emplace_back(P(u,w));
            edge_idx[v][u] = i;
            edge_idx[u][v] = i;
        }
        rep(i,n){
            x,y; cin >> x >> y;
            vertex1.emplace_back(T(x,y,i));
            vertex2.emplace_back(T(y,x,i));
        }
        sort(vertex1.begin(),vertex1.end());
        sort(vertex2.begin(),vertex2.end());

        // 初期解策定part
        vector<bool> ok(m,false);
        vector<set<int>> used_edge(n);
        cnt = 0;
        int sv1,now1 = 1e9;
        int sv2,now2 = 1e9;
        int sv3,now3 = 1e9;
        int sv4,now4 = 1e9;
        int sv5,now5 = 1e9;
        rep(i,n){
            auto [x1,y1,idx1] = vertex1[i];
            auto [y2,x2,idx2] = vertex2[i];
            if(i == n-1){
                sv1 = idx2;
            }
            if(abs(x1-50)+abs(y1-650) < now2){
                now2 = abs(x1-50)+abs(y1-650);
                sv2 = idx1;
            }
            if(abs(x1-950)+abs(y1-650) < now3){
                now3 = abs(x1-950)+abs(y1-650);
                sv3 = idx1;
            }
            if(abs(x1-150)+abs(y1-150) < now4){
                now4 = abs(x1-150)+abs(y1-150);
                sv4 = idx1;
            }
            if(abs(x1-850)+abs(y1-150) < now5){
                now5 = abs(x1-850)+abs(y1-150);
                sv5 = idx1;
            }
            for(auto [to,w]:Graph[idx1]){
                int ei = edge_idx[idx1][to];
                if(ok[ei])continue;
                ok[ei] = true;

                // d次以上の頂点がある時は例外
                bool f = (used_edge[to].size() >= d);
                if(f) while(day_cnt[cnt%d] >= k)cnt++;
                else  while(used_edge[to].count((cnt%d) + 1) || day_cnt[cnt%d] >= k)cnt++;

                used_edge[idx1].insert(cnt%d + 1);
                used_edge[to].insert(cnt%d + 1);
                ans[ei] = cnt%d + 1;
                day_cnt[cnt%d]++;
                cnt++;
            }
        }
        start_v.emplace_back(sv1);
        start_v.emplace_back(sv2);
        start_v.emplace_back(sv3);
        start_v.emplace_back(sv4);
        start_v.emplace_back(sv5);
        // for(auto ele:start_v)cerr << ele << " ";
        // cerr << endl;

        // Let's Start!!
        turn = 0;
        start_size = start_v.size();
        now_score = calcScore();
        best_day_score = now_day_score;
        utility::mytm.CodeStart();
    }

    void solve(){
        start_time = utility::mytm.elapsed();

        // 焼きなまし法
        while(utility::mytm.elapsed() <= TIME_LIMIT){
            // 操作 : swap
            e1 = rand_int()%m;
            e2 = rand_int()%m;
            while(ans[e1] == ans[e2])e2 = rand_int()%m;
            swap(ans[e1],ans[e2]);
            op[ans[e1]-1]++;
            op[ans[e2]-1]++;

            tmp_score = calcScore();
            tmp_rate = prob(now_score,tmp_score,start_time);
            rate = rand_double();
            if(tmp_rate >= rate){
                now_score = tmp_score;
                swap(best_day_score,now_day_score);
            }
            else{
                // 時を戻そう
                swap(ans[e1],ans[e2]);
            }
        }
        cerr << now_score << endl;
    }

    ll calcScore(){
        prelim_score = 0;
        rep(i,d){
            if(!op[i]){
                prelim_score += best_day_score[i];
                now_day_score[i] = best_day_score[i];
                continue;
            }
            cand_score = 0;
            rep(j,start_size)cand_score += dijkstra(start_v[j],i+1);
            cand_score /= start_size;

            now_day_score[i] = cand_score;
            prelim_score += cand_score;
            op[i] = 0;
        }
        prelim_score *= 1000;
        prelim_score /= (n*d);
        return prelim_score;
    }

    inline ll dijkstra(const int &s, const int &day){
        djk_score = 0;
        todo.push(P(0,s));
        cost.assign(n,1e9);

        // dijkstra
        while(!todo.empty()){
            auto [c,now] = todo.top(); todo.pop();
            if(cost[now] <= c)continue;
            cost[now] = c;
            for(auto [to,w]:Graph[now]){
                if(cost[to] <= c+w || ans[edge_idx[now][to]] == day)continue;
                todo.push(P(c+w,to));
            }
        }
        rep(j,n)djk_score += cost[j];
        return djk_score;
    }

    inline void output(){
        rep(i,m)cout << ans[i] << " ";
        cout << '\n';
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Solver solver;
    solver.solve();
    solver.output();
    
    return 0;
}