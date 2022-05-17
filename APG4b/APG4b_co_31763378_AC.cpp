/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/31763378
 * Submitted at: 2022-05-17 18:58:02
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_co
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
  int p;
  cin >> p;
 
  // パターン1
  if (p == 1) {
    int price,n;
    cin >> price >> n;
    cout << price*n << endl;
  }
 
  // パターン2
  if (p == 2) {
    string text;
    int price,n;
    cin >> text >> price >> n;
    cout << text << "!" << endl;
    cout << n*price << endl;
  }
}