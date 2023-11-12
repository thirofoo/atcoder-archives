/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc160/submissions/47525039
 * Submitted at: 2023-11-12 16:14:36
 * Problem URL: https://atcoder.jp/contests/arc160/tasks/arc160_a
 * Result: AC
 * Execution Time: 70 ms
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
    
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n-1) {
        vector<ll> cnt(n+1,0);
        cnt[a[i]] += (n-1-i)*(n-2-i)/2 + n;
        for(ll j=i+1; j<n; j++) cnt[a[j]]++;
        ll num = 0, cand = 0;
        for(ll j=1; j<=n; j++) {
            if( num+cnt[j] >= k ) {
                cand = j;
                break;
            }
            num += cnt[j];
        }
        k -= num;
        cerr << k << " " << num << " " << cand << endl;
        if( k == 1 ) {
            for(ll j=i+1; j<n; j++) {
                if( a[j] != cand ) continue;
                reverse(a.begin()+i, a.begin()+j+1);
                break;
            }
            break;
        }
    }
    rep(i,n) cout << a[i] << " ";
    cout << endl;
    
    return 0;
}