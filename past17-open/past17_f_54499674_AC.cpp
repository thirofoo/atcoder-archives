/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/past17-open/submissions/54499674
 * Submitted at: 2024-06-13 17:41:25
 * Problem URL: https://atcoder.jp/contests/past17-open/tasks/past17_f
 * Result: AC
 * Execution Time: 65 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<char, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<vector<ll>> Graph(n);
    vector<string> s(n);
    rep(i, n-1) {
        ll p; cin >> p; p--;
        Graph[p].emplace_back(i+1);
    }
    rep(i, n) cin >> s[i];
    auto dfs = [&](auto self, ll now) -> mint {
        if(s[now] == "+") return self(self, Graph[now][0]) + self(self, Graph[now][1]);
        if(s[now] == "x") return self(self, Graph[now][0]) * self(self, Graph[now][1]);
        return mint(stoll(s[now]));
    };
    cout << dfs(dfs, 0).val() << endl;
    
    return 0;
}