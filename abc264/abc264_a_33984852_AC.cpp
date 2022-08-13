/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc264/submissions/33984852
 * Submitted at: 2022-08-13 21:01:15
 * Problem URL: https://atcoder.jp/contests/abc264/tasks/abc264_a
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll l,r; cin >> l >> r;
    string a = "atcoder";
    for(int i=l-1;i<r;i++)cout << a[i];
    cout << endl;
    
    return 0;
}