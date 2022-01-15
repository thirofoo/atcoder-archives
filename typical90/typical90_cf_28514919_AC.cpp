/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28514919
 * Submitted at: 2022-01-15 10:31:56
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_cf
 * Result: AC
 * Execution Time: 32 ms
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
    int n; string s; cin >> n >> s;
    ll ans = 0;
    int left = 0,right = 0;
    for(left;left<n;left++){
        while(right != n && s[right] == s[left]) right++;
        if(right == n)break;
        ans += (n-right);
    }
    cout << ans << endl;
    return 0;
}