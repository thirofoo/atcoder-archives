/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/32541438
 * Submitted at: 2022-06-18 21:03:46
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_b
 * Result: WA
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    reverse(a.begin(),a.end());
    rep(i,n-1)a[i+1] += a[i];
    int ans = 0;
    rep(i,n)if(a[i] <= 4)ans++;
    cout << n-ans << endl;
    return 0;
}