/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc363/submissions/55827512
 * Submitted at: 2024-07-21 01:40:01
 * Problem URL: https://atcoder.jp/contests/abc363/tasks/abc363_f
 * Result: AC
 * Execution Time: 48 ms
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

  // 解説AC : 再起関数
  // 文字列を返すと計算量重くならないかと思ったが、最終的な文字列長は O(logN) なので大丈夫
  // → 普通にメモ化が OK なので、再帰関数で実装

  ll n;
  cin >> n;
  map<ll, string> memo;

  auto check = [&](ll x) -> bool {
    // 回文判定
    string s = to_string(x);
    for(ll i = 0; i < s.size() / 2; i++) {
      if(s[i] != s[s.size() - i - 1]) return false;
    }
    return true;
  };

  auto dfs = [&](auto f, ll rest) -> string {
    if(memo.count(rest)) return memo[rest];
    // 回文数の場合はそのまま返す
    // ※ 今回 0 は使用不可なので注意
    if(to_string(rest).find('0') == string::npos && check(rest)) return to_string(rest);

    for(ll i = 2; i * i <= rest; i++) {
      if(rest % i != 0 || to_string(i).find('0') != string::npos) continue;
      string tmp = to_string(i);
      reverse(tmp.begin(), tmp.end());
      ll rev = stoll(tmp);

      if(rest % (i * rev) != 0) continue;
      ll next    = rest / i / rev;
      string res = f(f, next);
      if(res != "") {
        string req = to_string(i) + "*" + res + "*" + to_string(rev);
        memo[rest] = req;
        return req;
      }
    }
    return "";
  };
  cout << (dfs(dfs, n) != "" ? dfs(dfs, n) : "-1") << endl;

  return 0;
}