/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc134/submissions/43672758
 * Submitted at: 2023-07-16 22:07:29
 * Problem URL: https://atcoder.jp/contests/abc134/tasks/abc134_e
 * Result: TLE
 * Execution Time: 2205 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n);
    multiset<ll> min_ele;
    rep(i,n) cin >> a[i];
    for(ll i=n-1;i>=0;i--){
        auto itr = upper_bound(min_ele.begin(), min_ele.end(), a[i]);
        if( itr != min_ele.end() ) min_ele.erase(itr);
        min_ele.insert(a[i]);
    }
    cout << min_ele.size() << endl;
    
    return 0;
}