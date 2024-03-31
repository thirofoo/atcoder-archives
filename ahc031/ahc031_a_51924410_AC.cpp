/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc031/submissions/51924410
 * Submitted at: 2024-04-01 02:14:40
 * Problem URL: https://atcoder.jp/contests/ahc031/tasks/ahc031_a
 * Result: AC
 * Execution Time: 20 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int, int> T;
#define rep(i, n) for(int i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

namespace utility {
    struct timer {
        chrono::system_clock::time_point start;
        // 開始時間を記録
        void CodeStart() {
            start = chrono::system_clock::now();
        }
        // 経過時間 (ms) を返す
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
#define TIME_LIMIT 2800
inline double temp(double start) {
    double start_temp = 100,end_temp = 1;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int best,int now,int start) {
    return exp((double)(now - best) / temp(start));
}

//-----------------以下から実装部分-----------------//

// global で管理したい基本情報
int w, d, n;

struct Line{
    int row_idx;
    vector<tuple<int,int,int>> columns;
    // tuple( 本来の区切り位置, 追加で割り当てた空きスペース, 本来必要な列数 )

    Line() : row_idx(0), columns({}) {}
    explicit Line(const int row_idx, const vector<tuple<int,int,int>> &columns) : row_idx(row_idx), columns(columns) {}
};

struct Answer {
    long long score;
    vector<vector<Line>> rows; // rows[day][row] = {columns}

    Answer() : score(0), rows({}) {}
    explicit Answer(const vector<vector<Line>> &rows) : rows(rows) {
        score = calcScore();
    }

    inline void colSwap(const int day, const int row1, const int col1, const int row2, const int col2) {
        // day 日目の row1 行目の col1 番目の区間と row2 行目の col2 番目の区間を swap
        return;
    }

    inline void colMove(const int day, const int row1, const int col, const int row2) {
        // day 日目の row1 行目の col 番目の区間を row2 行目に移動
        return;
    }

    inline void optimize(const int day, const int row_idx) {
        auto [last, __, _] = rows[day][row_idx].columns.back();
        int rest = w - last;
        // 出来るだけ前日の列と被るように rest を割当
        // dp[i][j][k] : 今日の i 列目, 昨日の j 列目, 残り k ある時の動かさない列の最大値
        int today = rows[day][row_idx].columns.size(), yesterday = rows[day-1][row_idx].columns.size();
        vector dp(today+1, vector(yesterday+1, vector<int>(rest+1, -10)));
        vector pre(today+1, vector(yesterday+1, vector<tuple<int,int,int>>(rest+1, {-1,-1,-1})));

        dp[0][0][rest] = 0;
        // cerr << "day: " << day << " row: " << row_idx << " today: " << today << " yesterday: " << yesterday << " rest: " << rest << endl;
        
        rep(i,today) {
            auto [y1, add1, _] = rows[day][row_idx].columns[i];
            y1 += add1;

            rep(j,yesterday+1) {
                auto [y2, add2, __] = rows[day-1][row_idx].columns[j];
                y2 += add2;

                rep(k,rest+1) {
                    if( dp[i+1][j][k] < dp[i][j][k] ) {
                        dp[i+1][j][k] = dp[i][j][k];
                        pre[i+1][j][k] = {i,j,k};
                    }
                    if( j != yesterday && dp[i][j+1][k] < dp[i][j][k] ) {
                        dp[i][j+1][k] = dp[i][j][k];
                        pre[i][j+1][k] = {i,j,k};
                    }
                    // 過去に rest-k の空白を追加しているのでその分 y1 はずれる
                    if( j == yesterday || y2-(y1+rest-k) < 0 || y2-(y1+rest-k) > k ) continue;

                    if( dp[i+1][j+1][k-(y2-(y1+rest-k))] < dp[i][j][k] + 1 ) {
                        dp[i+1][j+1][k-(y2-(y1+rest-k))] = dp[i][j][k] + 1;
                        pre[i+1][j+1][k-(y2-(y1+rest-k))] = {i,j,k};
                    }
                }
            }
        }

        // rep(i,today+1) {
        //     rep(j,yesterday+1) {
        //         rep(k,rest+1) cerr << dp[i][j][k] << " ";
        //         cerr << endl;
        //     }
        //     cerr << endl;
        // }

        int max_cnt = 0;
        tuple start = tuple(0,0,0);
        rep(i,rest+1) {
            if( dp[today][yesterday][i] <= max_cnt ) continue;
            max_cnt = dp[today][yesterday][i];
            start = tuple(today, yesterday, i);
        }
        if( start == tuple(0,0,0) ) return;
        // cerr << "max_cnt: " << max_cnt << endl;
        
        vector<int> padding;
        while( true ) {
            auto [i, j, k] = start;
            // cerr << "i: " << i << " j: " << j << " k: " << k << endl;
            if( i <= 0 || j <= 0 ) break;
            auto [pi, pj, pk] = pre[i][j][k];

            if( i != pi && pi != -1 && pj != -1 ) {
                // 空白を追加する場合
                auto [y1, add1, need] = rows[day][row_idx].columns[i-1];
                auto [y2, add2, __] = rows[day-1][row_idx].columns[j-1];
                padding.emplace_back( pk-k );
            }
            start = pre[i][j][k];
        }
        while( padding.size() != today ) padding.emplace_back(0);
        reverse(padding.begin(), padding.end());

        // cerr << "day: " << day << " row: " << row_idx << " padding: ";
        // for(auto p: padding) cerr << p << " ";
        // cerr << endl;

        rep(i,today) {
            auto [y1, add1, need] = rows[day][row_idx].columns[i];
            rows[day][row_idx].columns[i] = tuple(y1, add1 + padding[i], need);
        }
        return;
    }

    inline long long calcScore() {
        // Score 計算
        // ※ 前日と同じ行で同じ行がある場合は penalty 無
        score = 0;
        int size = rows.back().size();
        reps(i,1,d) {
            rep(j,rows[i].size()) {
                int pre_y = 0;
                rep(k,rows[i][j].columns.size()) {
                    auto itr = lower_bound(rows[i-1][j].columns.begin(), rows[i-1][j].columns.end(), rows[i][j].columns[k]);
                    if( itr != rows[i-1][j].columns.end() && *itr == rows[i][j].columns[k] ) continue;
                    auto [x, y, need] = rows[i][j].columns[k];
                    int height = n / size;
                    score += height * 2; // partiion 移動 score
                    score += max(0, need-(y-pre_y)) * height * 100; // 不足分 score
                    pre_y = y;
                }
            }
        }
        return score;
    }

    inline long long calcDiff() {
        // Coming soon ...
        return 0ll;
    }

    inline bool operator<(const Answer &a) const { return score < a.score; }
    inline bool operator>(const Answer &a) const { return score > a.score; }
};

struct Solver{
    vector<vector<int>> area;
    vector<int> line_row, line_col;
    priority_queue<Answer, vector<Answer>, greater<Answer>> pq;

    Answer best;

    Solver() {
        this->input();
    }

    void input() {
        cin >> w >> d >> n;
        area.assign(d, vector<int>(n, 0));
        rep(i,d) rep(j,n) cin >> area[i][j];
        return;
    }

    void output() {
        if( pq.empty() ) {
            cerr << "No Answer" << endl;
            return;
        }
        best = pq.top();
        for(auto day_row: best.rows) {
            vector<tuple<int,int,int,int,int>> ans;
            int size = day_row.size();
            rep(i,size) {
                auto &&row = day_row[i];
                int pre_y = 0, height = w / size, rui_add = 0;
                rep(j,row.columns.size()) {
                    auto [y, add, __] = row.columns[j];

                    if( y + rui_add + add < pre_y || y + rui_add + add > w ) {
                        // output が場外を指している場合
                        cerr << "Error: Output is out of range" << endl;
                        cerr << "day: " << i << " row: " << j << endl;
                        cerr << "pre_y: " << pre_y << " y: " << y << " add: " << add << " rui_add: " << rui_add << endl;
                        exit(1);
                    }

                    rui_add += add;
                    y += rui_add;
                    if( j == row.columns.size()-1 ) y = w;
                    ans.emplace_back( tuple(height*(y-pre_y), height*i, pre_y, height*(i+1), y) );
                    pre_y = y;
                }
            }
            sort(ans.begin(), ans.end());
            for(auto [_, x1, y1, x2, y2]: ans) {
                cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
            }
        }
        return;
    }

    void solve() {
        utility::mytm.CodeStart();
        getTheoreticalAnswer();
        getGreedyAnswer();
        return;

        // 山登り法
        while( utility::mytm.elapsed() <= TIME_LIMIT ) {
            // 近傍
            // 1. 同じ日の乱択の 2 列の多い方から少ない方に 1 スペース移動
            // 2. 　　　　〃　　　　　を swap (同列内 swap も ok)
        }
        return;
    }

    void getGreedyAnswer() {
        // 初期貪欲解
        // 1. 各日を X 行に分割
        // 2. 各日に合わせて行に列の柵を追加

        int max_ele = 0;
        rep(i,d) max_ele = max(max_ele, area[i].back());
        // reps(X,1,w+1) {
        for(ll X=w; X>=1; X--) {
            // 行分割条件
            int height = w / X;
            if (height * w < max_ele) continue;

            Answer cand = Answer();
            // 2. 列生成
            rep(i,d) {
                priority_queue<pair<int,int>> row_rest; // {空列, 行番号}
                rep(i,X) row_rest.push(pair(w, i));

                bool flag = true;
                vector<Line> cols;
                rep(i,X) cols.emplace_back(Line(i, {}));

                // 大きい陣地から空きが多い行に割当
                // ※ 覆いきれない場合は残りの空列を全利用

                int rest_idx = n-1;
                for(int j=n-1; j>=0; j--) {
                    if( row_rest.empty() ) {
                        flag = false;
                        break;
                    }
                    auto [capasity, idx] = row_rest.top(); row_rest.pop();
                    int need = ((area[i][j]-1) / height) + 1;

                    cols[idx].columns.emplace_back( tuple( min(w-capasity+need, w), 0, need ) );
                    if( capasity > need ) row_rest.push( pair(capasity-need, idx) );
                    rest_idx--;
                }
                if( !flag ) {
                    // どこかの列の末尾を 1 列ずつ細分化して帳尻合わせ
                    for(int j=rest_idx; j>=0; j--) {
                        int need = ((area[i][j]-1) / height) + 1;
                        rep(j,cols.size()) {
                            auto [y1, _, j_need] = cols[j].columns[cols[j].columns.size()-1];
                            auto [y2, __, ___] = cols[j].columns[cols[j].columns.size()-2];
                            if( y1-y2 == 1 ) continue;
                            cols[j].columns.pop_back();
                            cols[j].columns.emplace_back( tuple( y1-1, 0, j_need ) );
                            cols[j].columns.emplace_back( tuple( y1, 0, need ) );
                            break;
                        }
                    }
                }
                cand.rows.emplace_back(cols);
            }
            reps(i,1,d) rep(j,X) cand.optimize(i,j);
            cand.calcScore();
            pq.push(cand);
            break;
        }
        return;
    }

    void getTheoreticalAnswer() {
        // 理論値 (cost = 1) が達成可能な場合を考慮
        // ※ 現段階では Seed = 32 のみ
        int max_ele = 0;
        rep(i,d) max_ele = max(max_ele, area[i].back());
        vector<int> max_area_per_rank(n, 0);
        rep(i,d) rep(j,n) max_area_per_rank[j] = max(max_area_per_rank[j], area[i][j]);

        reps(X,1,w+1) {
            // 行分割条件 check
            int height = w / X;
            if( height * w < max_ele ) break;

            // 2. 列の柵を立てる
            Answer cand = Answer();
            vector<Line> rows(X);
            priority_queue<P> row; // {空列, 行番号}
            rep(i,X) row.push({w, i});
            bool flag = true;
            
            for(int j=n-1; j>=0; j--) {
                if( row.empty() ) {
                    flag = false;
                    break;
                }
                auto [capasity, idx] = row.top(); row.pop();
                int need = ((max_area_per_rank[j]-1) / height) + 1;
                if( capasity < need ) {
                    flag = false;
                    break;
                }
                rows[idx].columns.emplace_back( tuple( min(w-capasity+need, w), 0, need ) );
                if( capasity > need ) row.push(P(capasity-need, idx));
            }
            if( !flag ) continue;
            rep(i,d) cand.rows.emplace_back(rows);
            cand.score = 1;
            pq.push(cand);
        }
        return;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Solver solver;
    solver.solve();
    solver.output();
    
    return 0;
}