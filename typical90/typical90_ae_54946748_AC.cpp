/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/54946748
 * Submitted at: 2024-06-26 18:40:06
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ae
 * Result: AC
 * Execution Time: 306 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 二次元配列でメモ化するとより綺麗に書ける（解説より）
    ll n; cin >> n;
    vector<ll> w(n), b(n);
    rep(i, n) cin >> w[i];
    rep(i, n) cin >> b[i];
    vector<vector<ll>> memo(51, vector<ll>(50*(50+1)/2 + 1, -1));
    auto f = [&](auto self, ll white, ll blue) -> ll {
        if(memo[white][blue] != -1) return memo[white][blue];
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
        return memo[white][blue] = res;
    };
    memo[0][0] = 0, memo[0][1] = 0;
    ll ans = 0;
    rep(i, n) ans ^= f(f, w[i], b[i]);
    cout << (ans > 0 ? "First" : "Second") << endl;
    
    return 0;
}