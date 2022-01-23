/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc172/submissions/28715516
 * Submitted at: 2022-01-23 19:22:31
 * Problem URL: https://atcoder.jp/contests/abc172/tasks/abc172_b
 * Result: AC
 * Execution Time: 19 ms
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
    int count = 0;
    string s,t; cin >> s >> t;
    rep(i,s.size()){
        if(s[i] != t[i])count++;
    }
    cout << count << endl;
    return 0;
}