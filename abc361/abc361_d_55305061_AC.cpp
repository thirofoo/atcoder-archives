/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc361/submissions/55305061
 * Submitted at: 2024-07-06 22:13:20
 * Problem URL: https://atcoder.jp/contests/abc361/tasks/abc361_d
 * Result: AC
 * Execution Time: 124 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
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
    // string を 2 進数で持つ
    ll tll = 0, sll = 0;
    rep(i, s.size()) {
        if(t[i] == 'W') tll += (1ll << i);
        if(s[i] == 'W') sll += (1ll << i);
    }

    set<P> memo;
    queue<T> q;
    q.push(T(0, n, tll));
    while(!q.empty()) {
        auto [cnt, idx, now] = q.front(); q.pop();
        if(memo.count(P(idx, now))) continue;
        memo.insert(P(idx, now));
        if(P(idx, now) == P(n, sll)) {
            cout << cnt << endl;
            return 0;
        }
        rep(i, n+1) {
            if(idx-1 <= i && i <= idx+1) continue;
            ll next = now;
            if(now & (1ll << i)) {
                next -= (1ll << i);
                next += (1ll << idx);
            }
            if(now & (1ll << (i+1))) {
                next -= (1ll << (i+1));
                next += (1ll << (idx+1));
            }
            if(!memo.count(P(i, next))) q.push(T(cnt+1, i, next));
        }
    }
    cout << -1 << endl;
    
    return 0;
}