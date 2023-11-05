/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc026/submissions/47301837
 * Submitted at: 2023-11-05 16:50:38
 * Problem URL: https://atcoder.jp/contests/ahc026/tasks/ahc026_a
 * Result: WA
 * Execution Time: 2 ms
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
#define TIME_LIMIT 2950
inline double temp(double start) {
    double start_temp = 100,end_temp = 1;
    return start_temp + (end_temp-start_temp)*((utility::mytm.elapsed()-start)/TIME_LIMIT);
}

//焼きなましの採用確率
inline double prob(int best,int now,int start) {
    return exp((double)(now - best) / temp(start));
}

//-----------------以下から実装部分-----------------//

struct State{

    State(){

    }
};

struct Solver{
    int n, m;
    bool f;
    vector<int> max_v, p_v;
    vector<vector<int>> box;
    vector<deque<int>> store;

    Solver(){
        this->input();

    }

    void input(){
        cin >> n >> m;
        p_v.assign(n,-1);
        max_v.assign(m,-1);
        store.assign(m,{});
        box.assign(m,vector<int>(n/m));
        rep(i,m) {
            rep(j,n/m) {
                cin >> box[i][j]; box[i][j]--;
                p_v[box[i][j]] = i;
                max_v[i] = max(max_v[i], box[i][j]);
            }
        }
        return;
    }

    void solve(){
        // まずは貪欲 (山を操作するついでに単調負減少の山にする)
        int now_box = 0, turn = 0;
        cerr << "now_box: " << now_box << "\n";
        while( now_box < n ) {

            // now_box が潜む山を単調減少山に変更する
            int op = p_v[now_box];
            deque<int> tmp;
            while( !box[op].empty() ) {
                int top = box[op].back(); box[op].pop_back();
                if( tmp.empty() || tmp[0] > top ) tmp.push_front(top);
                else {
                    int size_max = 1e9, size_idx = -1;
                    f = false;
                    rep(i,m) {
                        if( i == op ) continue;
                        if( size_max > (int)store[i].size() ) {
                            size_max = (int)store[i].size();
                            size_idx = i;
                        }
                        if( store[i].empty() || store[i].back() < tmp[0] ) {
                            // 予定通り山を除ける
                            cout << tmp[0]+1 << " " << i+1 << '\n' << flush;
                            while( !tmp.empty() ) {
                                store[i].emplace_back(tmp.front());
                                tmp.pop_front();
                            }
                            // rep(i,m) {
                            //     cerr << i+1 << ": ";
                            //     for(auto ele:store[i]) cerr << ele << " ";
                            //     cerr << '\n';
                            // }
                            f = true;
                            break;
                        }
                    }

                    // 置ける山が無い場合 ⇒ 一番小さい sotre の山と合成
                    if( !f ) {
                        // op でも size_idx でも無い山に一次退避
                        int avoid = 0, pre_size;
                        if( op == 0 || size_idx == 0 ) avoid++;
                        if( avoid == 1 && (op == 1 || size_idx == 1) ) avoid++;
                        pre_size = store[avoid].size();
                        while( !store[size_idx].empty() || !tmp.empty() ) {
                            if( store[size_idx].empty() ) {
                                cout << tmp.back()+1 << " " << avoid+1 << '\n' << flush;
                                store[avoid].emplace_back(tmp.back());
                                tmp.pop_back();
                            }
                            else if( tmp.empty() ) {
                                cout << store[size_idx].back()+1 << " " << avoid+1 << '\n' << flush;
                                store[avoid].emplace_back(store[size_idx].back());
                                store[size_idx].pop_back();
                            }
                            else {
                                if( store[size_idx].back() > tmp.back() ) {
                                    cout << store[size_idx].back()+1 << " " << avoid+1 << '\n' << flush;
                                    store[avoid].emplace_back(store[size_idx].back());
                                    store[size_idx].pop_back();
                                }
                                else {
                                    cout << tmp.back()+1 << " " << avoid+1 << '\n' << flush;
                                    store[avoid].emplace_back(tmp.back());
                                    tmp.pop_back();
                                }
                            }
                        }
                        // reverse して 合成元の山 に戻す
                        while( store[avoid].size() > pre_size ) {
                            cout << store[avoid].back()+1 << " " << size_idx+1 << '\n' << flush;
                            store[size_idx].emplace_back(store[avoid].back());
                            store[avoid].pop_back();
                        }
                    }
                    tmp = {top};
                }
            }

            if( !tmp.empty() ) {
                int size_max = 1e9, size_idx = -1;
                f = false;
                rep(i,m) {
                    if( i == op ) continue;
                    if( size_max > (int)store[i].size() ) {
                        size_max = (int)store[i].size();
                        size_idx = i;
                    }
                    if( store[i].empty() || store[i].back() < tmp[0] ) {
                        // 予定通り山を除ける
                        cout << tmp[0]+1 << " " << i+1 << '\n' << flush;
                        while( !tmp.empty() ) {
                            store[i].emplace_back(tmp.front());
                            tmp.pop_front();
                        }
                        // rep(i,m) {
                        //     cerr << i+1 << ": ";
                        //     for(auto ele:store[i]) cerr << ele << " ";
                        //     cerr << '\n';
                        // }
                        f = true;
                        break;
                    }
                }

                // 置ける山が無い場合 ⇒ 一番小さい sotre の山と合成
                if( !f ) {
                    // op でも size_idx でも無い山に一次退避
                    int avoid = 0, pre_size;
                    if( op == 0 || size_idx == 0 ) avoid++;
                    if( avoid == 1 && (op == 1 || size_idx == 1) ) avoid++;
                    pre_size = store[avoid].size();
                    while( !store[size_idx].empty() || !tmp.empty() ) {
                        if( store[size_idx].empty() ) {
                            cout << tmp.back()+1 << " " << avoid+1 << '\n' << flush;
                            store[avoid].emplace_back(tmp.back());
                            tmp.pop_back();
                        }
                        else if( tmp.empty() ) {
                            cout << store[size_idx].back()+1 << " " << avoid+1 << '\n' << flush;
                            store[avoid].emplace_back(store[size_idx].back());
                            store[size_idx].pop_back();
                        }
                        else {
                            if( store[size_idx].back() > tmp.back() ) {
                                cout << store[size_idx].back()+1 << " " << avoid+1 << '\n' << flush;
                                store[avoid].emplace_back(store[size_idx].back());
                                store[size_idx].pop_back();
                            }
                            else {
                                cout << tmp.back()+1 << " " << avoid+1 << '\n' << flush;
                                store[avoid].emplace_back(tmp.back());
                                tmp.pop_back();
                            }
                        }
                    }
                    // reverse して 合成元の山 に戻す
                    while( store[avoid].size() > pre_size ) {
                        cout << store[avoid].back()+1 << " " << op+1 << '\n' << flush;
                        store[size_idx].emplace_back(store[avoid].back());
                        store[avoid].pop_back();
                    }
                }
            }

            // cerr << "Yeaah!\n";
            // rep(i,m) {
            //     for(auto ele:store[i]) cerr << ele << " ";
            //     cerr << '\n';
            // }
            // cerr << endl;

            // のけたおいた山を単調減少山に復元
            int empty_num = 0;
            rep(i,m) empty_num += (store[i].empty());
            while( empty_num < m ) {
                int m_v = -1, m_idx = -1;
                rep(i,m) {
                    if( store[i].empty() ) continue;
                    if( m_v < store[i].back() ) {
                        m_v = store[i].back();
                        m_idx = i;
                    }
                }
                cout << store[m_idx].back()+1 << " " << op+1 << '\n' << flush;
                box[op].emplace_back(store[m_idx].back());
                store[m_idx].pop_back();
                if( store[m_idx].empty() ) empty_num++;
            }

            if( turn == 100 ) {
                cerr << "Yeaaah!\n";
                for(auto ele:box[op]) cerr << ele << " ";
                cerr << endl;
            }

            
            // 先頭に目標の箱がある場合は常に操作2
            while( true ) {
                if( now_box == n ) break;
                bool f = false;
                rep(i,m) {
                    if( !box[i].empty() && box[i].back() == now_box )  {
                        cout << now_box+1 << " " << 0 << '\n' << flush;
                        box[i].pop_back();
                        now_box++;
                        f = true;
                        cerr << "now_box: " << now_box << "\n";
                        break;
                    }
                }
                if( !f ) break;
            }

            turn++;
        }
        return;
    }
};

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    Solver solver;
    solver.solve();
    
    return 0;
}