/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/28392509
 * Submitted at: 2022-01-08 21:15:56
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_b
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
    cout << fixed << setprecision(10);
    int n; cin >> n;
    double ans = 0;
    vector<P> place;
    rep(i,n){
        int a,b; cin >> a >> b;
        place.push_back(P(a,b));
    }
    rep(i,n){
      rep(j,n){
        if(i == j)continue;
        double  x = pow(place[i].first-place[j].first,2);
        double  y = pow(place[i].second-place[j].second,2);
        double  dis = sqrt(x+y);
        ans = max(ans,dis);
      }
    }
    cout << ans << endl;
    return 0;
}