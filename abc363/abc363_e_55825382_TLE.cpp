/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc363/submissions/55825382
 * Submitted at: 2024-07-21 00:08:37
 * Problem URL: https://atcoder.jp/contests/abc363/tasks/abc363_e
 * Result: TLE
 * Execution Time: 2212 ms
 */

#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
template <class T, class... Ts>
void println(const T& a, const Ts&... b) {
    cout << a;
    (void)(cout << ... << (cout << ' ', b));
    cout << '\n';
}
template <class T>
void printv(const T& a, string sep = " ", string end = "\n") {
    for (auto x : a) {
        (void)(cout << x << sep);
    }
    cout << end;
}
void println() { cout << '\n'; }
template <class T, class... Ts>
void eprintln(const T& a, const Ts&... b) {
    cerr << a;
    (void)(cerr << ... << (cerr << ' ', b));
    cerr << '\n';
}
template <class T>
void eprintv(const T& a, string sep = " ", string end = "\n") {
    for (auto x : a) {
        (void)(cerr << x << sep);
    }
    cerr << end;
}
void eprintln() { cerr << '\n'; }
template <class... T>
void input(T&... a) { (cin >> ... >> a); }
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i <= n; i++)
#define yesno(a) cout << (a ? "Yes" : "No") << '\n';
#define YESNO(a) cout << (a ? "YES" : "NO") << '\n';

struct phash {
    inline size_t operator()(const pair<int, int>& p) const {
        const auto h1 = hash<int>()(p.first);
        const auto h2 = hash<int>()(p.second);
        return h1 ^ (h2 << 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(15);

    int h, w, y;
    input(h, w, y);

    vector<vector<int>> A(h, vector<int>(w));
    rep(i, h) rep(j, w) input(A[i][j]);

    unordered_set<pair<int, int>, phash> visited;
    int left = h * w;
    int cur = 0;

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> next;

    for (int j = 0; j < w; j++) {
        next.push({A[0][j], {0, j}});
        next.push({A[h - 1][j], {h - 1, j}});
    }
    for (int i = 1; i < h - 1; i++) {
        next.push({A[i][0], {i, 0}});
        next.push({A[i][w - 1], {i, w - 1}});
    }

    while (y--) {
        cur++;
        // i==0ori==h-1 or j==0 or j==w-1かつA[i][j]がcur以下のものをqueueに入れる
        queue<pair<int, int>> q;
        // keyがcur以下のものをnextから取り出してqueueに入れる
        while (!next.empty()) {
            auto [key, value] = next.top();
            if (key <= cur) {
                q.push(value);
                next.pop();
            } else {
                break;
            }
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if (visited.count({i, j})) {
                continue;
            }
            if (A[i][j] > cur) {
                next.push({A[i][j], {i, j}});
                continue;
            }
            visited.insert({i, j});
            left--;
            if (i > 0 && !visited.count({i - 1, j})) {
                q.push({i - 1, j});
            }
            if (i < h - 1 && !visited.count({i + 1, j})) {
                q.push({i + 1, j});
            }
            if (j > 0 && !visited.count({i, j - 1})) {
                q.push({i, j - 1});
            }
            if (j < w - 1 && !visited.count({i, j + 1})) {
                q.push({i, j + 1});
            }
        }

        println(left);
    }

    return 0;
}
