/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc251/submissions/31655023
 * Submitted at: 2022-05-14 21:01:16
 * Problem URL: https://atcoder.jp/contests/abc251/tasks/abc251_a
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
    
    string s; cin >> s;
    if(s.size() == 3)cout << s << s << endl;
    else if(s.size() == 2)cout << s << s << s << endl;
    else cout << s << s << s << s << s << s << endl;
    return 0;
}