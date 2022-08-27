/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc266/submissions/34368870
 * Submitted at: 2022-08-27 21:01:33
 * Problem URL: https://atcoder.jp/contests/abc266/tasks/abc266_a
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
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    int size = s.size();
    cout << s[size/2] << endl;
    
    return 0;
}