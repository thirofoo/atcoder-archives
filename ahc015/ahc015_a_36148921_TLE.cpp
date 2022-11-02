/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc015/submissions/36148921
 * Submitted at: 2022-11-02 11:57:31
 * Problem URL: https://atcoder.jp/contests/ahc015/tasks/ahc015_a
 * Result: TLE
 * Execution Time: 2205 ms
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
#define TIME_LIMIT 1950
inline double temp(int start) {
    double start_temp = 100,end_temp = 1;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int now,int next,int start) {
    return exp((double)(next - now) / temp(start));
}

//-----------------以下から実装部分-----------------//

constexpr int n = 10;
constexpr int tests = 800;
const string fblr = "FBLR";
// 右下左上の順番
vector<int> dx = {0,-1,0,1};
vector<int> dy = {-1,0,1,0};

struct State {
    vector<vector<int>> field;
    vector<vector<bool>> visited;
    queue<P> todo;

    State(){
        field.assign(n,vector<int>(n,0));
    }

    void put(int f,int p){
        rep(x,n){
            rep(y,n){
                if(field[x][y] == 0){
                    p--;
                    if(p == 0){
                        field[x][y] = f;
                        return;
                    }
                }
            }
        }
        cerr << "Error : p is invalid in State.put" << endl;
    }

    void move(char dir){
        int cnt = 0;
        if(dir == 'L'){
            // move left
            rep(h,10){
                rep(w,10){
                    cnt = w;
                    if(cnt == 0 || field[h][cnt-1] != 0)continue;
                    while(cnt != 0 && field[h][cnt-1] == 0){
                        swap(field[h][cnt-1],field[h][cnt]);
                        cnt--;
                    }
                }
            }
        }
        else if(dir == 'R'){
            // move right
            rep(h,n){
                for(int w=n-1;w>=0;w--){
                    cnt = w;
                    if(cnt+1 == n || field[h][cnt+1] != 0)continue;
                    while(cnt+1 != n && field[h][cnt+1] == 0){
                        swap(field[h][cnt+1],field[h][cnt]);
                        cnt++;
                    }
                }
            }
        }
        else if(dir == 'F'){
            // move front
            rep(w,10){
                rep(h,10){
                    cnt = h;
                    if(cnt == 0 || field[cnt-1][w] != 0)continue;
                    while(cnt != 0 && field[cnt-1][w] == 0){
                        swap(field[cnt-1][w],field[cnt][w]);
                        cnt--;
                    }
                }
            }
        }
        else if(dir == 'B'){
            // move back
            rep(w,n){
                for(int h=n-1;h>=0;h--){
                    cnt = h;
                    if(cnt+1 == n || field[cnt+1][w] != 0)continue;
                    while(cnt+1 != n && field[cnt+1][w] == 0){
                        swap(field[cnt+1][w],field[cnt][w]);
                        cnt++;
                    }
                }
            }
        }
        else cerr << "Error : unknown direction '" << dir << "'" << endl;
    }

    int calcScore() {
        int score = 0,tmp;
        visited.assign(n,vector<bool>(n,false));
        rep(h,n){
            rep(w,n){
                if(field[h][w] == 0 || visited[h][w])continue;
                tmp = 0;
                todo.push(P(h,w));
                while(!todo.empty()){
                    auto [x,y] = todo.front(); todo.pop();
                    if(field[x][y] != field[h][w] || visited[x][y])continue;
                    visited[x][y] = true;
                    tmp++;
                    rep(i,4){
                        if(x+dx[i] < 0 || x+dx[i] >= n || y+dy[i] < 0 || y+dy[i] >= n)continue;
                        todo.push(P(x+dx[i],y+dy[i]));
                    }
                }
                score += tmp*tmp;
            }
        }
        return score;
    }

    int simulate(char c, const vector<int> &fruit, const string &ans, int turn, const vector<int> &test){
        move(c);
        for(int i=turn+1;i<n*n-1;i++){
            put(fruit[i],test[i]);
            move(ans[i]);
        }
        return calcScore();
    }
};

struct Solver {
    vector<vector<int>> field,tester;
    vector<int> cnt,fruit;
    State state;
    string ans;
    bool flag = false;
    int left,right,front;

    Solver() {
        utility::mytm.CodeStart();
        cnt.assign(3,0);
        fruit.assign(n*n,0);
        field.assign(n,vector<int>(n,0));
        tester.assign(tests,{});
        // 乱択テスト生成
        rep(i,tests){
            rep(t,n*n){
                tester[i].push_back(rand_int()%(n*n-t)+1);
            }
        }
    }

    void input() {
        rep(i,n*n){
            cin >> fruit[i];
            cnt[fruit[i]-1]++;
        }
    }
    
    void output() {
        rep(i,n*n)cout << ans[i] << endl;
    }

    char monte_carlo_method(int turn, vector<bool> &skip) {
        vector<int> scores(4,0);
        double rest_time = TIME_LIMIT - utility::mytm.elapsed();
        double rate = (double)(n * n + 10 - turn) / ((n * n - turn) * (n * n + 21 - turn) / 2);
        double end_time = utility::mytm.elapsed() + rate * rest_time;
        int counter = tests-1;
        while (utility::mytm.elapsed() < end_time && counter) {
            rep(i,4){
                if (skip[i])continue;
                State branch = state;
                scores[i] += branch.simulate(fblr[i], fruit, ans, turn, tester[counter]);
            }
            counter--;
        }
        int best_direction = 0;
        for (int direction = 1; direction < 4; ++direction) {
            if (scores[best_direction] < scores[direction]) {
                best_direction = direction;
            }
        }
        return fblr[best_direction];
    }

    void solve() {
        // fruitの場所決めpart
        int min_d = *min_element(cnt.begin(),cnt.end());
        if(cnt[0] == min_d) {
            left = 2;
            right = 3;
            front = 1;
        }
        else if(cnt[1] == min_d) {
            left = 1;
            right = 3;
            front = 2;
        }
        else if(cnt[2] == min_d) {
            left = 1;
            right = 2;
            front = 3;
        }

        // 初期解作成part(貪欲)
        rep(i,n*n-1){
            if(fruit[i+1] == front){
                ans.push_back('B');
                flag = true;
                continue;
            }
            if(fruit[i+1] == left){
                if(flag){
                    ans.push_back('F');
                    flag = false;
                }
                else ans.push_back('R');
                continue;
            }
            if(fruit[i+1] == right){
                if(flag){
                    ans.push_back('F');
                    flag = false;
                }
                else ans.push_back('L');
                continue;
            }
            cerr << "Error : there is not the candy" << endl;
        }
        ans.push_back('F');

        // montecalro
        rep(i,n*n-1){
            int p; cin >> p;
            state.put(fruit[i],p);
            // 無駄な動きはskipする
            vector<bool> skip(4,false);
            if(fruit[i+1] == front){
                // skip[0] = true;
                ans[i] = monte_carlo_method(i,skip);
            }
            if(fruit[i+1] == left){
                // skip[2] = true;
                ans[i] = monte_carlo_method(i,skip);
            }
            if(fruit[i+1] == right){
                // skip[3] = true;
                ans[i] = monte_carlo_method(i,skip);
            }
            // Solveで管理してるStateを更新
            state.move(ans[i]);
        }
    }

};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    Solver solver;
    solver.input();
    solver.solve();
    solver.output();
}