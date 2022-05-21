/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/31835361
 * Submitted at: 2022-05-21 21:01:32
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_a
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
    
    int n; cin >> n;
    cout << (char)('a' + (n-97)) << endl;
    return 0;
}