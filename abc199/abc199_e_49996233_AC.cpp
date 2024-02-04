/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc199/submissions/49996233
 * Submitted at: 2024-02-04 17:30:30
 * Problem URL: https://atcoder.jp/contests/abc199/tasks/abc199_e
 * Result: AC
 * Execution Time: 32 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説 AC
    // 普通に bitDP 書いたら O(2^N * M) になりそうと思ったが、実はならない。
    // 最悪ケースは全ての条件の X = N/2 の時？
    // N/2 個の集合 N!/((N/2)!*(N-N/2)!) 個、条件 M 個、N = 18, M = 100 の時を考えると…
    // 18!/(9!9!) * 100 = 4862000 (回)
    // → 
    ll n, m; cin >> n >> m;
    vector<vector<P>> cond(n+1);
    rep(i,m) {
        ll x, y, z; cin >> x >> y >> z;
        cond[x].emplace_back(P(y,z));
    }
    vector dp(1LL << n, 0LL), cnt(n+1,0LL);
    dp[0] = 1;
    for(ll i=1; i<1LL << n; i++) {
        ll pop_cnt = 0;
        cnt.assign(n+1,0LL);
        rep(j,n) {
            if( i & (1LL << j) ) cnt[j+1]++, pop_cnt++;
            cnt[j+1] += cnt[j];
        }
        bool f = true;
        for(auto [y,z]:cond[pop_cnt]) f &= (cnt[y] <= z);
        if( !f ) continue;
        rep(j,n) {
            if( !(i & (1LL << j)) ) continue;
            ll pre = i ^ (1LL << j);
            dp[i] += dp[pre];
        }
    }
    cout << dp.back() << endl;
    
    return 0;
}