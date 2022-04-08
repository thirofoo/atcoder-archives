/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc189/submissions/30786906
 * Submitted at: 2022-04-08 16:08:57
 * Problem URL: https://atcoder.jp/contests/abc189/tasks/abc189_b
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
    cout << fixed << setprecision(10);
    int n,x; cin >> n >> x;
    double now = 0;
    rep(i,n){
        double v,p; cin >> v >> p;
        now += v*(p/100);
        if(x < now)return cout << i+1 << endl,0;
    }
    cout << -1 << endl;
    return 0;
}