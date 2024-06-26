/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/54946284
 * Submitted at: 2024-06-26 18:21:08
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ae
 * Result: TLE
 * Execution Time: 3315 ms
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
    vector<ll> w(n), b(n);
    rep(i, n) cin >> w[i];
    rep(i, n) cin >> b[i];
    // 各山を全て青に還元しても高々青の数は 50*51/2 + 50 ＝ 1325 程度 ?
    // ⇒ そこまで状態数が多く無さそうなので memo 化で Grundy 数が求まりそう
    // ※ 1325 を上限とすると青を取り除く遷移は 1~662 まで（多めにして 670）
    map<P, ll> memo;
    ll MAX_GRUNDY = 670, grundy;
    auto f = [&](auto self, ll white, ll blue) -> ll {
        if(memo.count(P(white, blue))) return memo[P(white, blue)];
        set<ll> st;
        rep(i, MAX_GRUNDY) st.insert(i);
        // white 削除遷移
        if(white  > 0) {
            grundy = self(self, white-1, blue+white);
            st.erase(grundy);
        }
        // blue 削除遷移
        reps(i, 1, blue/2 + 1) {
            grundy = self(self, white, blue-i);
            st.erase(grundy);
        }
        return memo[P(white, blue)] = *st.begin();
    };
    memo[P(0, 0)] = 0, memo[P(0, 1)] = 0;
    ll ans = 0;
    rep(i, n) ans ^= f(f, w[i], b[i]);
    cout << (ans > 0 ? "First" : "Second") << endl;
    
    return 0;
}