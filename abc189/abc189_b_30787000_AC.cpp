/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc189/submissions/30787000
 * Submitted at: 2022-04-08 16:15:06
 * Problem URL: https://atcoder.jp/contests/abc189/tasks/abc189_b
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
    int n,x,now = 0; cin >> n >> x;
    x *= 100;
    rep(i,n){
        int v,p; cin >> v >> p;
        now += v*p;
        if(x < now)return cout << i+1 << endl,0;
    }
    cout << -1 << endl;
    return 0;
}