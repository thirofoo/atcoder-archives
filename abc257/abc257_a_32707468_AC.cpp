/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc257/submissions/32707468
 * Submitted at: 2022-06-25 21:01:38
 * Problem URL: https://atcoder.jp/contests/abc257/tasks/abc257_a
 * Result: AC
 * Execution Time: 5 ms
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
    
    int n,x; cin >> n >> x;
    cout << (char)('A'+(x-1)/n) << endl;

    return 0;
}