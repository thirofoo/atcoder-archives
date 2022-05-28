/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/ahc011/submissions/31987294
 * Submitted at: 2022-05-28 12:05:18
 * Problem URL: https://atcoder.jp/contests/ahc011/tasks/ahc011_a
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n,t; cin >> n >> t;
    vector<string> field(n);
    rep(i,n)cin >> field[i];

    return 0;
}