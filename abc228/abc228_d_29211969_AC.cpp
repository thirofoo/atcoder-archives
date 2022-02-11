/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc228/submissions/29211969
 * Submitted at: 2022-02-11 13:25:09
 * Problem URL: https://atcoder.jp/contests/abc228/tasks/abc228_d
 * Result: AC
 * Execution Time: 638 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int n = (1 << 20);

int main() {
  int q;
  cin >> q;
  int n = 1 << 20;
  vector<ll> a(n, -1);
  set<int> m1;
  rep(i, n) m1.insert(i);
  rep(i, q) {
    ll t, x;
    cin >> t >> x;
    if (t == 1) {
      if (m1.count(x % n)) {
        m1.erase(x % n);
        a[x % n] = x;
      }
      else {
        auto itr = m1.upper_bound(x % n);
        if (itr == m1.end()) itr = m1.begin();
        a[*itr] = x;
        m1.erase(itr);
      }
    }
    else {
      cout << a[x % n] << endl;
    }
  }
  return 0;
    // int q; cin >> q;
    // vector<ll> a(n,-1);
    // vector<ll> seen(n,1);
    // rep(i,q){
    //     int t; ll x; cin >> t >> x;
    //     if(t == 1){
    //         if(a[x%n] == -1){
    //             a[x%n] = x;
    //             seen[x%n] = 0;
    //         }
    //         else{
    //             int itr1 = lower_bound(seen.begin()+x%n,seen.end(),1)-seen.begin();
    //             int itr2 = lower_bound(seen.begin(),seen.begin()+x%n,1)-seen.begin();
    //             cout << itr1 << endl;
    //             if(itr1 == n){
    //                 a[itr2] = x;
    //                 seen[itr2] = 0;
    //             }
    //             else{
    //                 a[itr1] = x;
    //                 seen[itr1] = 0;
    //             }
    //         }
    //     }
    //     else cout << a[x%n] << endl;
    // }
    // rep(i,5)cout << a[i] << " ";
    // cout << endl;
    // return 0;

    //lower_boundはあくまで二部探索であることに注意。
    //初めて値が第三引数以上になった時のindexではない！
    // vector<int> attempt = {0,0,0,1,1,0,0,1,1};
    // cout << lower_bound(attempt.begin(),attempt.end(),1)-attempt.begin() << endl;
}