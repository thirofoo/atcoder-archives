/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc187/submissions/31338837
 * Submitted at: 2022-04-29 16:07:34
 * Problem URL: https://atcoder.jp/contests/abc187/tasks/abc187_b
 * Result: AC
 * Execution Time: 12 ms
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
    int n,ans = 0; cin >> n;
    vector<P> vertex;
    rep(i,n){
        int x,y; cin >> x >> y;
        vertex.push_back(P(x,y));
    }
    rep(i,n){
        for(int j=i+1;j<n;j++){
               auto [x1,y1] = vertex[i]; 
               auto [x2,y2] = vertex[j]; 
               if(-abs(x1-x2) <= y1-y2 && y1-y2 <= abs(x1-x2))ans++;
        }
    }
    cout << ans << endl;
    return 0;
}