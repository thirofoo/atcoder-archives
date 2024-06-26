/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/54946514
 * Submitted at: 2024-06-26 18:30:33
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ae
 * Result: WA
 * Execution Time: 310 ms
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
    
    // 各山を全て青に還元しても高々青の数は 50*51/2 + 50 ＝ 1325 程度 ?
    // ⇒ そこまで状態数が多く無さそうなので memo 化で Grundy 数が求まりそう
    // ※ 1325 を上限とすると青を取り除く遷移は 1~662 まで（多めにして 670）

    ll n; cin >> n;
    vector<ll> w(n), b(n);
    rep(i, n) cin >> w[i];
    rep(i, n) cin >> b[i];
    vector<ll> memo(100000, -1);
    auto f = [&](auto self, ll white, ll blue) -> ll {
        if(memo[blue*60+white] != -1) return memo[blue*60+white];
        vector<ll> nums;
        if(white > 0) {
            // white 削除遷移
            nums.emplace_back(self(self, white-1, blue+white));
        }
        reps(i, 1, blue/2 + 1) {
            // blue 削除遷移
            nums.emplace_back(self(self, white, blue-i));
        }
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        ll res = 0;
        while(res < nums.size() && res == nums[res]) res++;
        return memo[blue*60+white] = res;
    };
    memo[0] = 0, memo[1] = 0;
    ll ans = 0;
    rep(i, n) ans ^= f(f, w[i], b[i]);
    cout << (ans > 0 ? "First" : "Second") << endl;
    
    return 0;
}