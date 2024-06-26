/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/54946631
 * Submitted at: 2024-06-26 18:35:13
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ae
 * Result: AC
 * Execution Time: 308 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 各山を全て青に還元しても高々青の数は 50 * (50+1) /2 + 50 ＝ 1325 程度
    // ⇒ 状態が少なそうなのでメモ化で Grundy 数が求まりそう
    ll n; cin >> n;
    vector<ll> w(n), b(n);
    rep(i, n) cin >> w[i];
    rep(i, n) cin >> b[i];
    vector<ll> memo(100000, -1);
    auto f = [&](auto self, ll white, ll blue) -> ll {
        if(memo[blue*60+white] != -1) return memo[blue*60+white];
        vector<ll> nums;
        if(white >= 1) {
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
    memo[0*60+0] = 0, memo[1*60+0] = 0;
    ll ans = 0;
    rep(i, n) ans ^= f(f, w[i], b[i]);
    cout << (ans > 0 ? "First" : "Second") << endl;
    
    return 0;
}