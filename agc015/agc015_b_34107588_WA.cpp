/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc015/submissions/34107588
 * Submitted at: 2022-08-17 19:07:09
 * Problem URL: https://atcoder.jp/contests/agc015/tasks/agc015_b
 * Result: WA
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
    
    string s; cin >> s;
    int ans = 0;
    for(int i=1;i<=s.size();i++){
        if(s[i-1] == 'U')ans += (s.size()-i + (i-1)*2);
        else ans += ((s.size()-i)*2 + (i-1));
    }
    cout << ans << endl;
    
    return 0;
}