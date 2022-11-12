/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc016/submissions/36397719
 * Submitted at: 2022-11-12 14:58:33
 * Problem URL: https://atcoder.jp/contests/ahc016/tasks/ahc016_a
 * Result: WA
 * Execution Time: 34 ms
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
    double start_temp = 100,end_temp = 1;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int now,int next,int start) {
    return exp((double)(next - now) / temp(start));
}

//-----------------以下から実装部分-----------------//

constexpr int test = 100;

struct State{
    // State内で用いる変数等の定義
    int n;
    string graph;
    vector<int> dig;

    State(int num,int z,int m,int err){
        n = z;
        graph = "";
        dig.assign(n,0);
        queue<char> q;

        if(m >= 30 && err >= 0.15){
            graph = "000000";
            return;
        }
        if(err <= 0.02){
            rep(i,num)graph += '1';
            rep(i,n*(n-1)/2-num)graph += '0';
            return;
        }
        
        rep(i,n){
            for(int j=i+1;j<n;j++){
                if(i <= num && j <= num){
                    graph.push_back('1');
                    dig[i]++;
                    dig[j]++;
                }
                else graph.push_back('0');
            }
        }
    }

    int calcScore(const vector<int> &d){
        int score = 0;
        vector<int> td1 = dig,td2 = d;
        sort(td1.begin(),td1.end());
        sort(td2.begin(),td2.end());

        rep(i,n)score -= abs(td1[i]-td2[i]);
        return score;
    }
};

struct Solver{
    // Solve内で用いる変数等の定義
    int m,n;
    double err;
    vector<State> state;

    Solver(){
        n = 4;
    }

    void input(){
        cin >> m >> err;

        if(m >= 30 && err >= 0.15)n = 4;
        else if(err <= 0.02){
            while(n*(n-1)/2 < m)n++;
        }
        else n = m;

        rep(i,m)state.emplace_back(State(i,n,m,err));
    }

    void output(){
        cout << n << '\n';
        rep(i,m)cout << state[i].graph << '\n' << flush;
    }

    void solve(){
        rep(i,test){
            string t; cin >> t;

            if(m >= 30 && err >= 0.15){
                cout << 0 << '\n' << flush;
                continue;
            }

            if(err <= 0.00){
                int cnt = 0;
                rep(i,n*(n-1)/2)cnt += (t[i] == '1');
                cout << min(m-1,max(0,cnt)) << '\n' << flush;
                continue;
            }

            vector<int> dig(n,0);
            int now = 0;
            rep(j,n){
                for(int k=j+1;k<n;k++){
                    if(t[now+k-(j+1)] == '1'){
                        dig[j]++;
                        dig[k]++;
                    }
                }
                now += n-(j+1);
            }
            int ans =0,md = -INT_MAX;
            rep(j,m){
                int score = state[j].calcScore(dig);
                if(score > md){
                    md = score;
                    ans = j;
                    // cout << j << " " << md << endl;
                }
            }
            cout << ans << '\n';
            cout << flush;
        }
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    // NとM個のグラフ出力part
    Solver solver;
    solver.input();
    solver.output();

    // 正しいグラフに読み直しpart
    solver.solve();
    
    return 0;
}