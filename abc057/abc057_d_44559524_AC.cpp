/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc057/submissions/44559524
 * Submitted at: 2023-08-13 20:52:40
 * Problem URL: https://atcoder.jp/contests/abc057/tasks/abc057_d
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 }, dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };
const long long mod = 998244353;
const ll inf = 1LL << 60;
const int Inf = 5e8;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), greater<ll>());

    ll s = 0;
    for (int i = 0; i < a; i++)
        s += v[i];

    ld ans = (ld)s / a;
    printf("%.18Lf", ans);
    cout << endl;

    vector<ll> vec;
    int pre = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == v[a - 1])
            vec.push_back(v[i]);
        if (v[i] > v[a - 1])
            pre++;
    }
    int sz = vec.size();

    vector dp(sz + 1, vector<ll>(sz + 1));
    dp[0][0] = 1;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j <= sz; j++) {
            if (dp[i][j] == 0)
                continue;
            dp[i + 1][j] += dp[i][j];
            if (j + 1 <= sz)
                dp[i + 1][j + 1] += dp[i][j];
        }
    }

    if (pre) {
        cout << dp[sz][a - pre] << endl;
    } else {
        ll cnt = 0;
        for (int i = a; i <= min(sz, b); i++)
            cnt += dp[sz][i];
        cout << cnt << endl;
    }
}