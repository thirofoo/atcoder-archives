/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/54946843
 * Submitted at: 2024-06-26 18:44:00
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ae
 * Result: AC
 * Execution Time: 62 ms
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
    // mex も上限が決まっているなら O(NlogN) でなく O(N) で出来る
    ll n; cin >> n;
    vector<ll> w(n), b(n);
    rep(i, n) cin >> w[i];
    rep(i, n) cin >> b[i];
    vector<vector<ll>> memo(51, vector<ll>(50*(50+1)/2 + 1, -1));
    auto f = [&](auto self, ll white, ll blue) -> ll {
        if(memo[white][blue] != -1) return memo[white][blue];
        vector<bool> mex(blue/2+1 + 1 + 1, 0);
        if(white >= 1) {
            // white 削除遷移
            ll grundy = self(self, white-1, blue+white);
            if(grundy < mex.size()) mex[grundy] = 1;
        }
        reps(i, 1, blue/2 + 1) {
            // blue 削除遷移
            ll grundy = self(self, white, blue-i);
            if(grundy < mex.size()) mex[grundy] = 1;
        }
        ll res = 0;
        while(mex[res]) res++;
        return memo[white][blue] = res;
    };
    memo[0][0] = 0, memo[0][1] = 0;
    ll ans = 0;
    rep(i, n) ans ^= f(f, w[i], b[i]);
    cout << (ans > 0 ? "First" : "Second") << endl;
    
    return 0;
}