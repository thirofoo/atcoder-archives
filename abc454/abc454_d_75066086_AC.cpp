/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc454/submissions/75066086
 * Submitted at: 2026-04-18 21:33:22
 * Problem URL: https://atcoder.jp/contests/abc454/tasks/abc454_d
 * Result: AC
 * Execution Time: 124 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
using ll  = long long;
using ull = unsigned long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
constexpr ll INF = ((1LL << 61) + (1LL << 30) - 1);

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll t;
  cin >> t;
  while(t--) {
    string a, b;
    cin >> a >> b;

    auto f = [&](string s) -> string {
      string res = "";
      stack<ll> p;
      p.push(0);
      ll phase = 0;

      for(char c: s) {
        if(phase == 0) {
          phase = (c == '(' ? 1 : 0);
          res += c;
        } else if(phase == 1 || phase == 2) {
          if(c == 'x') phase++;
          else phase = (c == '(' ? 1 : 0);
          res += c;
        } else {
          if(c == ')') {
            res.pop_back();
            res.pop_back();
            res.pop_back();
            p.pop();
            p.pop();
            p.pop();
            phase = p.top();

            auto add_x = [&]() {
              if(phase == 1 || phase == 2) phase++;
              else phase = 0;
              res += 'x';
              p.push(phase);
            };

            add_x();
            add_x();
            continue;
          } else {
            phase = (c == '(' ? 1 : 0);
            res += c;
          }
        }
        p.push(phase);
        // cerr << "c: " << c << ", phase: " << phase << ", res: " << res << endl;
      }
      return res;
    };

    string fa = f(a);
    // cerr << endl;
    string fb = f(b);
    // cerr << "fa: " << fa << ", fb: " << fb << endl;
    cout << (fa == fb ? "Yes" : "No") << endl;
  }

  return 0;
}