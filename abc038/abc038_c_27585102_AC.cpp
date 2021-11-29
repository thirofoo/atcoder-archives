/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc038/submissions/27585102
 * Submitted at: 2021-11-29 13:17:15
 * Problem URL: https://atcoder.jp/contests/abc038/tasks/abc038_c
 * Result: AC
 * Execution Time: 34 ms
 */

#include <bits/stdc++.h>
#include <cmath> //abs関数で絶対値を使える。
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
#define rep(i,n) for (ll i = 0; i < n; ++i)

// ABC038 C 「単調増加」　※尺取り法
int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i,N)cin >> a[i];
    long long res = 0;
    int right = 1; // [0, 1) は確実に条件を満たす
    for (int left = 0; left < N; ++left) {
        // right を 1 個進めたものが条件を満たすかどうか
        while (right < N && (right <= left || a[right - 1] < a[right])) {
            ++right;
        }
        res += right - left;
        if (left == right) ++right;
    }

    cout << res << endl;
    return 0;
}