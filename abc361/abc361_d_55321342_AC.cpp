/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc361/submissions/55321342
 * Submitted at: 2024-07-06 23:13:21
 * Problem URL: https://atcoder.jp/contests/abc361/tasks/abc361_d
 * Result: AC
 * Execution Time: 213 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using T = tuple<ll, ll, string>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    string s, t; cin >> s >> t;
    s += "..";
    t += "..";
    // 状態が少なさそう → メモ化 BFS？
    set<string> st;
    queue<T> q;
    q.push(T(0, n, t));
    while(!q.empty()) {
        auto [cnt, idx, now] = q.front(); q.pop();
        if(st.count(now)) continue;
        st.insert(now);
        if(now == s) {
            cout << cnt << endl;
            return 0;
        }
        rep(i, n+1) {
            if(idx-1 <= i && i <= idx+1) continue;
            swap(now[i], now[idx]);
            swap(now[i+1], now[idx+1]);
            if(!st.count(now)) q.push(T(cnt+1, i, now));
            swap(now[i], now[idx]);
            swap(now[i+1], now[idx+1]);
        }
    }
    cout << -1 << endl;
    
    return 0;
}