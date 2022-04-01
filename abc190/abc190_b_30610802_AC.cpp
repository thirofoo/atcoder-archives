/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc190/submissions/30610802
 * Submitted at: 2022-04-01 23:45:25
 * Problem URL: https://atcoder.jp/contests/abc190/tasks/abc190_b
 * Result: AC
 * Execution Time: 10 ms
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
    int n,s,d; cin >> n >> s >> d;
    ll ans = 0;
    rep(i,n){
        int x,y; cin >> x >> y;
        if(x < s && y > d)ans += y;
    }
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}