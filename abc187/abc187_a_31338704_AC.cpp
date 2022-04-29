/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc187/submissions/31338704
 * Submitted at: 2022-04-29 16:00:59
 * Problem URL: https://atcoder.jp/contests/abc187/tasks/abc187_a
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
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int s(string n){
    return n[0]-'0'+n[1]-'0'+n[2]-'0';
}

int main() {
    string a,b; cin >> a >> b;
    if(s(a) >= s(b))cout << s(a) << endl;
    else cout << s(b) << endl;
    return 0;
}