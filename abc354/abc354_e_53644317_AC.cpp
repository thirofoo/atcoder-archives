/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc354/submissions/53644317
 * Submitted at: 2024-05-19 00:25:34
 * Problem URL: https://atcoder.jp/contests/abc354/tasks/abc354_e
 * Result: AC
 * Execution Time: 532 ms
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// std::vector<std::pair<int, int>>のハッシュ関数
struct vector_pair_hash {
    size_t operator()(const vector<pair<int, int>>& v) const {
        size_t hash = 0;
        for (const auto& p : v) {
            hash ^= hash_combine(p.first) ^ hash_combine(p.second);
        }
        return hash;
    }
    
private:
    size_t hash_combine(int x) const {
        return hash<int>()(x);
    }
};

// 状態のメモ化用テーブル
unordered_map<vector<pair<int, int>>, bool, vector_pair_hash> memo;

// 再帰関数：現在のカード状態で高橋君が勝てるかどうかを返す
bool canTakahashiWin(vector<pair<int, int>>& cards) {
    if (cards.empty()) return false;

    // メモ化チェック
    if (memo.find(cards) != memo.end()) return memo[cards];

    int n = cards.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (cards[i].first == cards[j].first || cards[i].second == cards[j].second) {
                vector<pair<int, int>> nextCards;
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) {
                        nextCards.push_back(cards[k]);
                    }
                }
                // 相手が勝てない場合、自分が勝てる
                if (!canTakahashiWin(nextCards)) {
                    memo[cards] = true;
                    return true;
                }
            }
        }
    }
    memo[cards] = false;
    return false;
}

int main() {
    int N;
    cin >> N;
    vector<pair<int, int>> cards(N);
    for (int i = 0; i < N; ++i) {
        cin >> cards[i].first >> cards[i].second;
    }
    
    // 初期状態で高橋君が勝てるかを判定
    if (canTakahashiWin(cards)) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }
    
    return 0;
}
