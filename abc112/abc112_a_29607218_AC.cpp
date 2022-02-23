/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc112/submissions/29607218
 * Submitted at: 2022-02-23 21:21:27
 * Problem URL: https://atcoder.jp/contests/abc112/tasks/abc112_a
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
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n; cin >> n;
    if(n == 1)cout << "Hello World" << endl;
    else{
        int a,b; cin >> a >> b;
        cout << a + b << endl;
    }
    return 0;
}