/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc220/submissions/29045752
 * Submitted at: 2022-02-05 00:01:02
 * Problem URL: https://atcoder.jp/contests/abc220/tasks/abc220_c
 * Result: AC
 * Execution Time: 40 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,idx = 0; cin >> n;
    ll x,count = 0,ans = 0;
    vector<int> a(n);
    rep(i,n){
        cin >> a[i];
        count += a[i];
    }
    cin >> x; ans += a.size()*(x/count);
    x %= count; count = 0;
    while(count + a[idx] <= x){
        count += a[idx]; idx++; ans++;
    }
    cout << ans+1 << endl;
    return 0;
}