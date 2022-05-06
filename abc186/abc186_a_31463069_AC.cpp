/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc186/submissions/31463069
 * Submitted at: 2022-05-06 12:32:39
 * Problem URL: https://atcoder.jp/contests/abc186/tasks/abc186_a
 * Result: AC
 * Execution Time: 3 ms
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
    
    int n,w; cin >> n >> w;
    cout << n/w << endl;
    return 0;
}