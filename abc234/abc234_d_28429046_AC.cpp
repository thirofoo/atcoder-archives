/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/28429046
 * Submitted at: 2022-01-09 14:42:21
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_d
 * Result: AC
 * Execution Time: 905 ms
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
    int n,k; cin >> n >> k;
    priority_queue<int,vector<int>,greater<int>> num;
    rep(i,k){
        int a; cin >> a;
        num.push(a);
    }
    cout << num.top() << endl;
    rep(i,n-k){
        int a; cin >> a;
        num.push(a);
        num.pop();
        cout << num.top() << endl;
    }
    return 0;
}