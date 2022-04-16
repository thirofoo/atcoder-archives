/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc248/submissions/31003360
 * Submitted at: 2022-04-16 21:01:26
 * Problem URL: https://atcoder.jp/contests/abc248/tasks/abc248_a
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
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    string s; cin >> s;
    map<char,int> a;
    rep(i,9)a[s[i]-'0']++;
    rep(i,9)if(a[i+1] == 0)cout << i+1 << endl;
    return 0;
}