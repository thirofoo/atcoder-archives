/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/28415825
 * Submitted at: 2022-01-08 22:39:39
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_d
 * Result: WA
 * Execution Time: 2207 ms
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
    int n,k,count = 0; cin >> n >> k;
    vector<int> num;
    rep(i,k){
        int a; cin >> a;
        num.push_back(a);
    }
    sort(num.begin(),num.end());
    int ans = num[0];
    cout << ans << endl;
    rep(i,n-k){
      int a; cin >> a;
      int place = lower_bound(num.begin(),num.end(),a)-num.begin();
      num.insert(lower_bound(num.begin(),num.end(),a),a);
      cout << num[num.size()-1-k] << endl;
    }
    return 0;
}