/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54509464
 * Submitted at: 2024-06-14 00:29:01
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_f
 * Result: AC
 * Execution Time: 51 ms
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    long long mod = 998244353;
    vector<vector<int>> Graph(n);
    vector<string> s(n);
    for(int i = 0; i < n-1; i++) {
        int p; cin >> p; p--;
        Graph[p].emplace_back(i+1);
    }
    for(int i = 0; i < n; i++) cin >> s[i];
    auto dfs = [&](auto self, int now) -> long long {
        if(s[now] == "+") return (self(self, Graph[now][0]) + self(self, Graph[now][1])) % mod;
        if(s[now] == "x") return (self(self, Graph[now][0]) * self(self, Graph[now][1])) % mod;
        return stoll(s[now]);
    };
    cout << dfs(dfs, 0) << endl;
    return 0;
}