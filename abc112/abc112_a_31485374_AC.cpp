/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc112/submissions/31485374
 * Submitted at: 2022-05-07 17:54:50
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
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    if(n == 1)cout << "Hello World" << endl;
    else {
        int a,b; cin >> a >> b;
        cout << a+b << endl;
    }
    return 0;
}