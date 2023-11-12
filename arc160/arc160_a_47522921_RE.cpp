/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc160/submissions/47522921
 * Submitted at: 2023-11-12 15:02:09
 * Problem URL: https://atcoder.jp/contests/arc160/tasks/arc160_a
 * Result: RE
 * Execution Time: 81 ms
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
        cnt[a[i]] += (n-1-i)*(n-2-i)/2 + n-i;
        for(ll j=i+1; j<n; j++) cnt[a[j]]++;
        ll num = 0, cand = n;
        for(ll j=1; j<=n; j++) {
            if( num+cnt[j] >= k ) {
                cand = j;
                break;
            }
            num += cnt[j];
            // cerr << num << " ";
        }
        cerr << endl;
        k -= num+1;
        // cerr << num << " " << cand << " " << k << endl;
        if( cand != a[i] ) {
            vector<vector<ll>> ans;
            for(ll j=i+1; j<n; j++) {
                if( a[j] != cand ) continue;
                vector<ll> tmp = a;
                reverse(tmp.begin()+i, tmp.begin()+j+1);
                ans.emplace_back(tmp);
            }
            sort(ans.begin(), ans.end());
            a = ans[k];
            break;
        }
    }
    rep(i,n) cout << a[i] << " ";
    cout << endl;
    
    return 0;
}