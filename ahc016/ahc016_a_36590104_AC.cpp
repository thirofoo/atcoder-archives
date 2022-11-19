/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc016/submissions/36590104
 * Submitted at: 2022-11-19 15:10:34
 * Problem URL: https://atcoder.jp/contests/ahc016/tasks/ahc016_a
 * Result: AC
 * Execution Time: 4885 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
#define rep(i, n) for(int i = 0; i < n; i++)

struct Timer {
    timespec start;
 
    void begin() {
        clock_gettime(CLOCK_REALTIME, &start);
    }
 
    double stopwatch() {
        timespec end;
        clock_gettime(CLOCK_REALTIME, &end);
        double sec = end.tv_sec - start.tv_sec;
        double nsec = end.tv_nsec - start.tv_nsec;
        return sec + 1e-9 * nsec;
    }
};

inline unsigned int rand_int() {
    static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
    unsigned int tt = (tx^(tx<<11));
    tx = ty; ty = tz; tz = tw;
    return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
}

inline double rand_double() {
    return (double)(rand_int()%(int)1e9)/1e9;
}

// #define TIME_LIMIT 100.92000000
#define TIME_LIMIT 4.92000000

//-----------------以下から実装部分-----------------//

// ε = 0の時の理論値
// m<=12:n=4,  m<=31:n=5,  m<=102:n=6
vector<vector<string>> theoretical_value_string = {
    {},
    {},
    {},
    {},
    {"000000","100000","110000","111000","110100","001100","101100","111100","011110","111110","111111",},
    {"0000000000","1000000000","1100000000","1110000000","1111000000","1100100000","0010100000","1010100000","1110100000","0011100000","1011100000","1111100000","0110110000","1110110000","0101110000","1101110000","0111110000","1111110000","0111111000","1111111000","1110110100","1101110100","1111110100","1111001100","0011101100","1111101100","0111111100","1111111100","1111011110","1111111110","1111111111",},
    {"000000000000000","100000000000000","110000000000000","111000000000000","111100000000000","111110000000000","110001000000000","001001000000000","101001000000000","111001000000000","001101000000000","101101000000000","111101000000000","001111000000000","101111000000000","111111000000000","011001100000000","111001100000000","010101100000000","110101100000000","011101100000000","111101100000000","000111100000000","100111100000000","010111100000000","110111100000000","011111100000000","111111100000000","011101110000000","111101110000000","011011110000000","111011110000000","011111110000000","111111110000000","011111111000000","111111111000000","111001100100000","110101100100000","111101100100000","000111100100000","110111100100000","111111100100000","111100010100000","000010010100000","111110010100000","001101010100000","111101010100000","110011010100000","001111010100000","111111010100000","011101110100000","111101110100000","011011110100000","111011110100000","010111110100000","110111110100000","011111110100000","111111110100000","011110011100000","111110011100000","001111011100000","011111011100000","111111011100000","011111111100000","111111111100000","111100110110000","111110110110000","111101110110000","111011110110000","001111110110000","101111110110000","111111110110000","000110101110000","111110101110000","110111101110000","001111101110000","111111101110000","011110111110000","111110111110000","011111111110000","111111111110000","001110111111000","101110111111000","111110111111000","111111111111000","111101110110100","111011110110100","111111110110100","111011101110100","111111101110100","011111111110100","111111111110100","111111111001100","111110011101100","011111111101100","111111111101100","111110111111100","111111111111100","011111111011110","111111111011110","111111111111110","111111111111111",},
};
vector<vector<vector<int>>> theoretical_value_dig = {
    {},
    {},
    {},
    {},
    {{0,0,0,0},{0,0,1,1},{0,1,1,2},{1,1,1,3},{0,2,2,2},{1,1,1,1},{1,1,2,2},{1,2,2,3},{2,2,2,2},{2,2,3,3},{3,3,3,3},},
    {{0,0,0,0,0},{0,0,0,1,1},{0,0,1,1,2},{0,1,1,1,3},{1,1,1,1,4},{0,0,2,2,2},{0,1,1,1,1},{0,1,1,2,2},{0,1,2,2,3},{1,1,1,1,2},{1,1,1,2,3},{1,1,2,2,4},{0,2,2,2,2},{0,2,2,3,3},{1,1,2,2,2},{1,1,2,3,3},{1,2,2,2,3},{1,2,2,3,4},{2,2,2,3,3},{2,2,2,4,4},{0,3,3,3,3},{1,2,3,3,3},{1,3,3,3,4},{2,2,2,2,4},{2,2,2,2,2},{2,2,3,3,4},{2,3,3,3,3},{2,3,3,4,4},{3,3,3,3,4},{3,3,4,4,4},{4,4,4,4,4},},
    {{0,0,0,0,0,0},{0,0,0,0,1,1},{0,0,0,1,1,2},{0,0,1,1,1,3},{0,1,1,1,1,4},{1,1,1,1,1,5},{0,0,0,2,2,2},{0,0,1,1,1,1},{0,0,1,1,2,2},{0,0,1,2,2,3},{0,1,1,1,1,2},{0,1,1,1,2,3},{0,1,1,2,2,4},{1,1,1,1,1,3},{1,1,1,1,2,4},{1,1,1,2,2,5},{0,0,2,2,2,2},{0,0,2,2,3,3},{0,1,1,2,2,2},{0,1,1,2,3,3},{0,1,2,2,2,3},{0,1,2,2,3,4},{1,1,1,1,2,2},{1,1,1,1,3,3},{1,1,1,2,2,3},{1,1,1,2,3,4},{1,1,2,2,2,4},{1,1,2,2,3,5},{0,2,2,2,3,3},{0,2,2,2,4,4},{1,1,2,2,3,3},{1,1,2,2,4,4},{1,2,2,2,3,4},{1,2,2,2,4,5},{2,2,2,2,4,4},{2,2,2,2,5,5},{0,0,3,3,3,3},{0,1,2,3,3,3},{0,1,3,3,3,4},{1,1,2,2,2,2},{1,1,2,3,3,4},{1,1,3,3,3,5},{0,2,2,2,2,4},{1,1,1,1,1,1},{1,2,2,2,2,5},{0,2,2,2,2,2},{0,2,2,3,3,4},{1,1,1,3,3,3},{1,2,2,2,2,3},{1,2,2,3,3,5},{0,2,3,3,3,3},{0,2,3,3,4,4},{1,1,3,3,3,3},{1,1,3,3,4,4},{1,2,2,3,3,3},{1,2,2,3,4,4},{1,2,3,3,3,4},{1,2,3,3,4,5},{2,2,2,2,2,4},{2,2,2,2,3,5},{2,2,2,2,3,3},{2,2,2,3,3,4},{2,2,2,3,4,5},{2,2,3,3,4,4},{2,2,3,3,5,5},{0,3,3,3,3,4},{1,3,3,3,3,5},{0,3,3,4,4,4},{1,2,3,4,4,4},{1,3,3,3,3,3},{1,3,3,3,4,4},{1,3,3,4,4,5},{2,2,2,2,2,2},{2,2,3,3,3,5},{2,2,2,4,4,4},{2,2,3,3,3,3},{2,2,3,4,4,5},{2,3,3,3,3,4},{2,3,3,3,4,5},{2,3,3,4,4,4},{2,3,3,4,5,5},{3,3,3,3,3,3},{3,3,3,3,4,4},{3,3,3,4,4,5},{3,3,3,5,5,5},{0,4,4,4,4,4},{1,3,4,4,4,4},{1,4,4,4,4,5},{2,2,4,4,4,4},{2,3,4,4,4,5},{2,4,4,4,4,4},{2,4,4,4,5,5},{3,3,3,3,5,5},{3,3,3,3,3,5},{3,3,4,4,4,4},{3,3,4,4,5,5},{3,4,4,4,4,5},{3,4,4,5,5,5},{4,4,4,4,4,4},{4,4,4,4,5,5},{4,4,5,5,5,5},{5,5,5,5,5,5},},
};

constexpr int query = 100;
constexpr int test = 2000;

struct State{
    int n,edge;
    ld score,tmp;
    string graph;
    double edge_rate,err;
    vector<int> dig,after_dig;

    State(const int use_edge,const int n,const double err){
        this->n = n;
        this->err = err;
        graph = "";
        edge = n*(n-1)/2;
        dig.assign(n,0);
        edge_rate = use_edge*(1-err) + (edge-use_edge)*err;

        if(err <= 0.02){
            graph = theoretical_value_string[n][use_edge];
            return;
        }
        
        rep(i,n){
            for(int j=i+1;j<n;j++){
                if(i <= use_edge || j <= use_edge){
                    graph.push_back('1');
                    this->dig[i]++;
                    this->dig[j]++;
                }
                else graph.push_back('0');
            }
        }
    }

    ld calcScore(const vector<P> &reverse,const vector<int> &dig){
        after_dig = this->dig;
        for(auto [i,j]:reverse){
            if(graph[calcIdx(i,j)] == '0'){
                after_dig[i]++;
                after_dig[j]++;
            }
            else{
                after_dig[i]--;
                after_dig[j]--;
            }
        }
        sort(after_dig.begin(),after_dig.end());

        score = 0;
        rep(i,n){
            // 差分の4乗で計算
            tmp = (after_dig[i]-dig[i]);
            score += tmp*tmp*tmp*tmp;
        }
        return score;
    }

    inline int calcIdx(const int i,const int j){
        return (n-1)*i - i*(i-1)/2 + j-i-1;
    }
};


struct Solver{
    Timer timer;
    int m,n,edge,cnt,ans;
    ld tmp1_score,tmp2_score,tmp;
    double err,rest_time,end_time,rate;
    string t;
    vector<int> dig;
    vector<State> state;
    vector<vector<P>> tests;

    Solver(){timer.begin();}

    void input(){
        cin >> m >> err;
        cnt = 0;
        n = m;

        if(err <= 0.02){
            n = 6;
            if(m <= 31)n = 5;
            if(m <= 12)n = 4;
            rep(i,m)state.emplace_back(State(i,n,err));
            return;
        }
        else if(err < 0.10)while(n++ < 99 && cnt++ < err*100 + (m >= 40 ? 10 : 0));
        else if(err < 0.15)while(n++ < 99 && cnt++ < 19 + (m >= 70 ? 10 : 0));
        else if(err < 0.20)while(n++ < 99 && cnt++ < 29 + (m >= 70 ? 10 : 0));
        else if(err < 0.25)while(n++ < 99 && cnt++ < 39 + (m >= 70 ? 10 : 0));
        else if(err < 0.30)while(n++ < 99 && cnt++ < 59 + (m >= 70 ? 10 : 0));
        else n = 100;
        n = min(100,n);

        edge = n*(n-1)/2;
        rep(i,m)state.emplace_back(State(i,n,err));

        // 反転場所の乱択ケース作成part
        rep(i,test){
            vector<P> tmp;
            rep(j,n){
                for(int k=j+1;k<n;k++){
                    if(rand_double() <= err*(0.85))tmp.emplace_back(P(j,k));
                }
            }
            tests.emplace_back(tmp);
        }
    }

    void output(){
        cout << n << '\n' << flush;
        rep(i,m)cout << state[i].graph << '\n' << flush;
    }

    void solve(){
        rep(i,query){
            cin >> t;

            rate = 0;
            dig.assign(n,0);
            rep(j,n){
                for(int k=j+1;k<n;k++){
                    if(t[calcIdx(j,k)] == '1'){
                        dig[j]++;
                        dig[k]++;
                        rate++;
                    }
                }
            }
            sort(dig.begin(),dig.end());

            // err <= 0.02 の例外
            if(err <= 0.02){
                bool f = true;
                rep(j,m){
                    if(dig == theoretical_value_dig[n][j]){
                        cout << j << '\n' << flush;
                        f = false;
                        break;
                    }
                }
                if(f)cout << rand_int()%m << '\n' << flush;   
                continue;
            }

            // else : 乱択テストscore平均が最も高いもの
            ans = 0;

            // スコア関数を三分探索
            int left = -1,right = m;
            while(right-left > 2){
                int m1 = (left+right)/2,m2 = m1+1;

                rest_time = TIME_LIMIT - timer.stopwatch();
                end_time = timer.stopwatch() + rest_time / ((query-i-1)*log2(m)*2 + 20);

                cnt = test-1;
                tmp1_score = 0;
                while(timer.stopwatch() <= end_time && cnt--){
                    tmp = state[m1].calcScore(tests[cnt],dig);
                    tmp1_score += tmp;
                }
                tmp1_score /= (ld)(test-cnt);


                rest_time = TIME_LIMIT - timer.stopwatch();
                end_time = timer.stopwatch() + rest_time / ((query-i-1)*log2(m)*2 + 20);

                cnt = test-1;
                tmp2_score = 0;
                while(timer.stopwatch() <= end_time && cnt--){
                    tmp = state[m2].calcScore(tests[cnt],dig);
                    tmp2_score += tmp;
                }
                tmp2_score /= (ld)(test-cnt);


                // cerr << test-cnt << " " << flush;
                if(tmp1_score < tmp2_score)right = m2;
                else if(tmp1_score == tmp2_score){
                    if(abs(rate-state[m1].edge_rate) < abs(rate-state[m2].edge_rate))right = m2;
                    else left = m1;
                }
                else left = m1;
            }
            cout << left+1 << '\n' << flush;
        }
        cerr << "finish time : " << timer.stopwatch() << "ms" << endl;
        return;
    }

    inline int calcIdx(const int i,const int j){
        return (n-1)*i - i*(i-1)/2 + j-i-1;
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