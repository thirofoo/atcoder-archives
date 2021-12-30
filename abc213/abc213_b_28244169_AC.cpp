/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc213/submissions/28244169
 * Submitted at: 2021-12-31 01:13:06
 * Problem URL: https://atcoder.jp/contests/abc213/tasks/abc213_b
 * Result: AC
 * Execution Time: 79 ms
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
    ll n; cin >> n;
    vector<P> score(0);
    rep(i,n){
        ll a;
        cin >> a;
        score.push_back(P(a,i+1));
    }
    sort(score.begin(),score.end());
    cout << score[n-2].second << endl;
    return 0;
}