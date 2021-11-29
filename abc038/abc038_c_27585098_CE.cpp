/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc038/submissions/27585098
 * Submitted at: 2021-11-29 13:16:54
 * Problem URL: https://atcoder.jp/contests/abc038/tasks/abc038_c
 * Result: CE
 * Execution Time: None ms
 */

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