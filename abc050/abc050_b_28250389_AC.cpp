/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc050/submissions/28250389
 * Submitted at: 2021-12-31 10:49:46
 * Problem URL: https://atcoder.jp/contests/abc050/tasks/abc050_b
 * Result: AC
 * Execution Time: 9 ms
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
    int n; cin >> n;
    vector<ll> time(n);
    rep(i,n)cin >> time[i];
    int m; cin >> m;
    vector<P> drink(0);
    rep(i,m){
        ll p,x; cin >> p >> x;
        drink.push_back(P(p,x));
    }
    rep(i,m){
        ll count = 0;
        ll tmp = time[drink[i].first-1];
        time[drink[i].first-1] = drink[i].second;
        rep(j,n)count += time[j];
        cout << count << endl;
        time[drink[i].first-1] = tmp;
    }
    return 0;
}