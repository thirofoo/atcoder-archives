/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/28409222
 * Submitted at: 2022-01-08 22:09:33
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_d
 * Result: TLE
 * Execution Time: 2205 ms
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
    sort(num.begin(),num.end(),[](int a,int b){
        return a > b;
    });
    int ans = num[k-1];
    cout << ans << endl;
    rep(i,n-k){
      int a; cin >> a;
      num.push_back(a);
      sort(num.begin(),num.end(),[](int a,int b){
        return a > b;
      });
      cout << num[k-1] << endl;
    }
    return 0;
}