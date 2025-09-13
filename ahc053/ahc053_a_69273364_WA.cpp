/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc053/submissions/69273364
 * Submitted at: 2025-09-13 19:12:26
 * Problem URL: https://atcoder.jp/contests/ahc053/tasks/ahc053_a
 * Result: WA
 * Execution Time: 2 ms
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <chrono>

using namespace std;

// ----------------- ユーティリティ (問題文より) ----------------- //
namespace utility {
    struct timer {
        chrono::system_clock::time_point start;
        void CodeStart() {
            start = chrono::system_clock::now();
        }
        double elapsed() const {
            using namespace std::chrono;
            return (double)duration_cast<milliseconds>(system_clock::now() - start).count();
        }
    } mytm;
}

inline unsigned int rand_int() {
    static unsigned int tx = 123456789, ty = 362436069, tz = 521288629, tw = 88675123;
    unsigned int tt = (tx ^ (tx << 11));
    tx = ty, ty = tz, tz = tw;
    return (tw = (tw ^ (tw >> 19)) ^ (tt ^ (tt >> 8)));
}

inline double rand_double() {
    return (double)(rand_int() % (int)1e9) / 1e9;
}
// ----------------- ここまで ----------------- //


// -----------------以下から実装部分-----------------//

int N_val, M_val;
long long L_val, U_val;
vector<long long> A;
vector<long long> B;

struct Solver {
    vector<int> assignment;
    vector<long long> current_S;
    long long current_error;

    vector<int> best_assignment;
    long long best_error;

    Solver() {
        this->input();
    }

    void input() {
        cin >> N_val >> M_val >> L_val >> U_val;
        A.resize(N_val);
        B.resize(M_val);
        assignment.resize(N_val);
        current_S.resize(M_val + 1);
    }

    void solve() {
        // --- フェーズ 1: A_i の決定と出力 ---
        const int cards_per_set = N_val / M_val;
        long double avg_B = (L_val / 2.0L) + (U_val / 2.0L);
        long double sum_power_of_2 = (1LL << cards_per_set) - 1;
        long long base_k = round(avg_B / sum_power_of_2);
        if (base_k == 0) base_k = 1;

        for (int i = 0; i < N_val; ++i) {
            long long power_of_2 = 1LL << (i % cards_per_set);
            unsigned __int128 val = (unsigned __int128)base_k * power_of_2;
            if (val == 0) {
                A[i] = 1;
            } else if (val > U_val) {
                A[i] = U_val;
            } else {
                A[i] = val;
            }
        }

        for (int i = 0; i < N_val; ++i) {
            cout << A[i] << endl;
        }

        // --- フェーズ 2: B_j の入力と割り当て探索 ---
        for (int j = 0; j < M_val; ++j) {
            cin >> B[j];
        }

        utility::mytm.CodeStart();

        // --- 焼きなまし法 ---
        // 初期解: ランダム割り当て
        fill(current_S.begin(), current_S.end(), 0LL);
        for (int i = 0; i < N_val; i++) {
            assignment[i] = rand_int() % (M_val + 1);
            if (assignment[i] != 0) {
                current_S[assignment[i]] += A[i];
            }
        }

        current_error = 0;
        for (int j = 1; j <= M_val; j++) {
            current_error += abs(current_S[j] - B[j - 1]);
        }

        best_assignment = assignment;
        best_error = current_error;

        // 温度設定
        const double START_TEMP = 5e13;
        const double END_TEMP = 1e10;
        const double TIME_LIMIT_MS = 1950.0;

        while (utility::mytm.elapsed() < TIME_LIMIT_MS) {
            int card_idx = rand_int() % N_val;
            int current_yama_id = assignment[card_idx];
            int next_yama_id = rand_int() % (M_val + 1);
            if (current_yama_id == next_yama_id) continue;

            // 差分計算による高速化
            long long error_diff = 0;
            if (current_yama_id != 0) {
                error_diff -= abs(current_S[current_yama_id] - B[current_yama_id - 1]);
                error_diff += abs(current_S[current_yama_id] - A[card_idx] - B[current_yama_id - 1]);
            }
            if (next_yama_id != 0) {
                error_diff -= abs(current_S[next_yama_id] - B[next_yama_id - 1]);
                error_diff += abs(current_S[next_yama_id] + A[card_idx] - B[next_yama_id - 1]);
            }

            // 温度計算と遷移判定
            double progress = utility::mytm.elapsed() / TIME_LIMIT_MS;
            double temp = START_TEMP * pow(END_TEMP / START_TEMP, progress);

            if (error_diff <= 0 || exp(-(double)error_diff / temp) > rand_double()) {
                if (current_yama_id != 0) current_S[current_yama_id] -= A[card_idx];
                if (next_yama_id != 0)    current_S[next_yama_id] += A[card_idx];
                assignment[card_idx] = next_yama_id;
                current_error += error_diff;

                if (current_error < best_error) {
                    best_error = current_error;
                    best_assignment = assignment;
                }
            }
        }
    }

    void output() {
        for (int i = 0; i < N_val; ++i) {
            cout << best_assignment[i] << (i == N_val - 1 ? "" : " ");
        }
        cout << endl;
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
