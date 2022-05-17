/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/APG4b/submissions/31763338
 * Submitted at: 2022-05-17 18:55:38
 * Problem URL: https://atcoder.jp/contests/APG4b/tasks/APG4b_cp
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
  // 変数a,b,cにtrueまたはfalseを代入してAtCoderと出力されるようにする。
  bool a = true; // true or false
  bool b = false; // true or false
  bool c = true; // true or false
 
  // ここから先は変更しないこと
 
  if (a) {
    cout << "At";
  }
  else {
    cout << "Yo";
  }
 
  if (!a && b) {
    cout << "Bo";
  }
  else if (!b || c) {
    cout << "Co";
  }
 
  if (a && b && c) {
    cout << "foo!";
  }
  else if (true && false) {
    cout << "yeah!";
  }
  else if (!a || c) {
    cout << "der";
  }
 
  cout << endl;
}