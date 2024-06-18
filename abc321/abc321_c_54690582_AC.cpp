/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc321/submissions/54690582
 * Submitted at: 2024-06-18 18:27:51
 * Problem URL: https://atcoder.jp/contests/abc321/tasks/abc321_c
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll k; cin >> k;
    vector<ll> ans;
    reps(i, 1, (1LL << 10)) {
        ll num = 0;
        rep(j, 10) {
            if(i & (1LL << j)) {
                num *= 10;
                num += (9-j);
            }
        }
        ans.emplace_back(num);
    }
    sort(ans.begin(), ans.end());
    cout << ans[k] << endl;
    
    return 0;
}