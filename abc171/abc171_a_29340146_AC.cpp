/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc171/submissions/29340146
 * Submitted at: 2022-02-14 23:48:46
 * Problem URL: https://atcoder.jp/contests/abc171/tasks/abc171_a
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    char a; cin >> a;
    if('a' <= a && a <= 'z')cout << "a" << endl;
    else cout << "A" << endl; 
    return 0;
}