/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc087/submissions/28244786
 * Submitted at: 2021-12-31 01:35:25
 * Problem URL: https://atcoder.jp/contests/abc087/tasks/abc087_b
 * Result: AC
 * Execution Time: 8 ms
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
    int a,b,c,x,count = 0; cin >> a >> b >> c >> x;
    rep(i,a+1){
        rep(j,b+1){
            rep(k,c+1){
                if(500*i+100*j+50*k == x){
                    count++;
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}