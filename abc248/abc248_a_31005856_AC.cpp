/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/31005856
 * Submitted at: 2022-04-16 21:02:45
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_a
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
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    string s; cin >> s;
    map<char,int> a;
    rep(i,9)a[s[i]-'0']++;
    rep(i,10)if(a[i] == 0)cout << i << endl;
    return 0;
}