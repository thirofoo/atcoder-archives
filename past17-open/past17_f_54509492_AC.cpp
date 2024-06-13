/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54509492
 * Submitted at: 2024-06-14 00:30:23
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_f
 * Result: AC
 * Execution Time: 47 ms
 */

#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<vector<int>> Graph(n);
    vector<string> s(n);
    for(int i = 0; i < n-1; i++) {
        int p; cin >> p; p--;
        Graph[p].emplace_back(i+1);
    }
    for(int i = 0; i < n; i++) cin >> s[i];

    vector<long long> memo(n, -1);

    function<long long(int)> dfs = [&](int now) -> long long {
        if (memo[now] != -1) return memo[now];
        if (s[now] == "+") 
            return memo[now] = (dfs(Graph[now][0]) + dfs(Graph[now][1])) % MOD;
        if (s[now] == "x") 
            return memo[now] = (dfs(Graph[now][0]) * dfs(Graph[now][1])) % MOD;
        return memo[now] = stoll(s[now]) % MOD;
    };
    
    cout << dfs(0) << endl;
    return 0;
}
