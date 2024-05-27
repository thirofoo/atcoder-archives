/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc354/submissions/53961499
 * Submitted at: 2024-05-28 03:29:40
 * Problem URL: https://atcoder.jp/contests/abc354/tasks/abc354_f
 * Result: AC
 * Execution Time: 416 ms
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

void LIS(vector<ll> &a, vector<ll> &cnt) {
    ll n = a.size();
    vector<ll> ans(n,LLONG_MAX);
    rep(i,n) {
        auto itr = lower_bound(ans.begin(),ans.end(),a[i]);
        *itr = a[i];
        cnt[i] = itr - ans.begin() + 1;
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; cin >> t;
    while( t-- ) {
        ll n; cin >> n;
        vector<ll> a(n), cnt1(n,0), cnt2(n,0);
        rep(i,n) cin >> a[i];
        LIS(a, cnt1);
        reverse(a.begin(), a.end());
        rep(i,n) a[i] *= -1;
        LIS(a, cnt2);
        reverse(cnt2.begin(), cnt2.end());

        vector<ll> ans;
        ll lis = 0;
        rep(i,n) lis = max({lis, cnt1[i], cnt2[i]});
        rep(i,n) {
            if( cnt1[i] + cnt2[i] - 1 == lis ) {
                ans.emplace_back(i);
            }
        }
        cout << ans.size() << endl;
        for(auto x : ans) cout << x+1 << " ";
        cout << endl;
    }
    
    return 0;
}