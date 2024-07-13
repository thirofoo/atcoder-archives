/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc362/submissions/55559574
 * Submitted at: 2024-07-13 22:07:01
 * Problem URL: https://atcoder.jp/contests/abc362/tasks/abc362_g
 * Result: TLE
 * Execution Time: 3344 ms
 */

#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    ll q;
    cin >> q;
    // 長さの種類は高々 √N 通り？
    // ⇒ 長さ毎に行うと実は愚直が間に合う？
    vector<deque<char>> t(q);
    vector<vector<ll>> idx(s.size() + 1);
    rep(i, q) {
        string st;
        cin >> st;
        deque<char> tmp;
        for(auto &&c : st)
            tmp.emplace_back(c);
        t[i] = tmp;
        idx[st.size()].emplace_back(i);
    }
    vector<ll> ans(q, 0);
    for(int i = 1; i <= s.size(); i++) {
        auto &&v = idx[i];
        if(v.empty()) continue;
        deque<char> now;
        rep(j, i) now.emplace_back(s[j]);
        for(ll j = i; j <= s.size(); j++) {
            for(auto &&k : v)
                if(now == t[k]) ans[k]++;
            now.pop_front();
            now.emplace_back(s[j]);
        }
    }
    for(auto &&i : ans)
        cout << i << endl;

    return 0;
}