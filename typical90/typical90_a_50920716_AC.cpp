/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/50920716
 * Submitted at: 2024-03-05 16:30:06
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_a
 * Result: AC
 * Execution Time: 25 ms
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
    
    ll n, l, k; cin >> n >> l >> k;
    vector<ll> a(n+1,0);
    rep(i, n) cin >> a[i+1];
    a.emplace_back(l);

    ll left = 0, right = l+1;
    while( right-left > 1 ) {
        ll mid = (left+right)/2;
        ll cnt = 0;
        auto itr = a.begin();
        while( itr != a.end() ) {
            itr = lower_bound(itr, a.end(), *itr+mid);
            if( itr != a.end() ) cnt++;
        }
        cnt--;
        if( cnt >= k ) left = mid;
        else right = mid;
    }
    cout << left << endl;
    
    return 0;
}