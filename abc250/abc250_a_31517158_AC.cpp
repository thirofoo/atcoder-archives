/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc250/submissions/31517158
 * Submitted at: 2022-05-08 21:05:49
 * Problem URL: https://atcoder.jp/contests/abc250/tasks/abc250_a
 * Result: AC
 * Execution Time: 6 ms
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
    
    int h,w,r,c; cin >> h >> w >> r >> c;
    if(h == 1 && w == 1)cout << 0 << endl;
    else if(h == 1) cout << 2 + (c == 1 || c == w ? -1 : 0) << endl;
    else if(w == 1) cout << 2 + (r == 1 || r == h ? -1 : 0) << endl;
    else cout << 4 + (r == 1 || r == h ? -1 : 0) + (c == 1 || c == w ? -1 : 0) << endl;
    return 0;
}