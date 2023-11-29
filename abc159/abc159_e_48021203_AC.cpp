/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc159/submissions/48021203
 * Submitted at: 2023-11-29 10:36:24
 * Problem URL: https://atcoder.jp/contests/abc159/tasks/abc159_e
 * Result: AC
 * Execution Time: 8 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w, k; cin >> h >> w >> k;
    vector<string> s(h);
    rep(i,h) cin >> s[i];
    ll ans = 1e16;

    // 行分割全探索
    rep(i,(1LL << (h-1))) {
        vector<ll> idx = {0};
        rep(j,h) if(i & (1LL << j)) idx.emplace_back(j+1);
        idx.emplace_back(h);
        ll cand = idx.size()-2, now = 0;

        bool f = false;
        ll plus = 0, best = 0;
        vector<ll> cnt(idx.size()-1, 0);

        rep(m,w) {
            rep(j,idx.size()-1) {
                for(ll l=idx[j]; l<idx[j+1]; l++) {
                    cnt[j] += (s[l][m] == '1');
                    best = max(best, cnt[j]);
                }
            }
            if( best > k ) {
                cand++;
                best = 0;
                rep(j,idx.size()-1) {
                    cnt[j] = 0;
                    for(ll l=idx[j]; l<idx[j+1]; l++) {
                        cnt[j] += (s[l][m] == '1');
                        best = max(best, cnt[j]);
                    }
                }
                if( best > k ) {
                    f = true;
                    break;
                }
            }
        }
        if( !f ) ans = min(ans, cand);
    }
    cout << ans << endl;
    
    return 0;
}