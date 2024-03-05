/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/50918533
 * Submitted at: 2024-03-05 15:07:01
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_f
 * Result: WA
 * Execution Time: 762 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, l; cin >> n >> l;
    vector<ll> a(n+1,0);
    rep(i, n) cin >> a[i+1];
    sort(a.begin(), a.end());
    rep(i,n) a[i+1] += a[i];

    auto f = [&](auto self, ll left, ll right) -> ll {
        if( right-left <= 1 ) return 0;
        cerr << left << " " << right << endl;

        ll mid = (a[right]-a[left]) / 2;
        ll idx = lower_bound(a.begin(), a.end(), a[left]+mid) - a.begin();
        ll cut_idx, res = 0, min_cut = 1e16;
        reps(i,idx-5,idx+5) {
            if( i <= left || right <= i ) continue;
            ll cut = abs((a[i]-a[left])-(a[right]-a[i]));
            if( cut < min_cut ) {
                min_cut = cut;
                cut_idx = i;
            }
        }
        res += self(self, left, cut_idx);
        res += self(self, cut_idx, right);
        return res + a[right]-a[left];
    };
    cout << f(f, 0, n) + (l == a[n] ? 0 : l) << endl;
    
    return 0;
}