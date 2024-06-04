/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc062/submissions/54236968
 * Submitted at: 2024-06-05 03:03:42
 * Problem URL: https://atcoder.jp/contests/abc062/tasks/arc074_b
 * Result: AC
 * Execution Time: 223 ms
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
    vector<ll> a(3*n);
    multiset<ll> lst1, lst2, rst1, rst2;
    ll l_sum = 0, r_sum = 0;
    rep(i, 3*n) {
        cin >> a[i];
        if(i < n) {
            lst1.insert(a[i]);
            l_sum += a[i];
        }
        else rst2.insert(a[i]);
    }
    rep(i,n) {
        r_sum += *rst2.begin();
        rst1.insert(*rst2.begin());
        rst2.erase(rst2.begin());
    }
    ll ans = l_sum - r_sum;
    reps(i,n,2*n) {
        // 前半部分
        lst1.insert(a[i]);
        l_sum += a[i];
        l_sum -= *lst1.begin();
        lst2.insert(*lst1.begin());
        lst1.erase(lst1.begin());

        // 後半部分
        if(rst1.find(a[i]) != rst1.end()) {
            rst1.erase(rst1.find(a[i]));
            r_sum -= a[i];
            r_sum += *rst2.begin();
            rst1.insert(*rst2.begin());
            rst2.erase(rst2.begin());
        }
        else {
            rst2.erase(rst2.find(a[i]));
        }
        ans = max(ans, l_sum - r_sum);
    }
    cout << ans << endl;
    
    return 0;
}