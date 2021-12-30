/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc150/submissions/28236367
 * Submitted at: 2021-12-30 18:30:07
 * Problem URL: https://atcoder.jp/contests/abc150/tasks/abc150_b
 * Result: AC
 * Execution Time: 7 ms
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
    int n,count = 0; string s; cin >> n >> s;
    while(s.find("ABC") != s.npos){
        count++;
        s.erase(s.find("ABC"),3);
    }
    cout << count << endl;
    return 0;
}