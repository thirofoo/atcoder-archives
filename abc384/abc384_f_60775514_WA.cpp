/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc384/submissions/60775514
 * Submitted at: 2024-12-14 22:39:35
 * Problem URL: https://atcoder.jp/contests/abc384/tasks/abc384_f
 * Result: WA
 * Execution Time: 650 ms
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

  ll n;
  cin >> n;
  vector<ll> a(n);
  ll max_ele = 0, r = 1;
  rep(i, n) {
    cin >> a[i];
    max_ele = max(max_ele, a[i]);
  }
  max_ele *= 2;
  while(r < max_ele) r *= 2;
  ll ans = 0, over = 0;
  vector<ll> cnt(r, 0), sum(r, 0);
  rep(i, n) {
    cnt[a[i] % r]++;
    sum[a[i] % r] += a[i];
  }

  while(true) {
    ll tmp = 0;
    rep(i, r) {
      ll other = (r - i) % r;
      if(i > other || cnt[i] == 0 || cnt[other] == 0) continue;
      ll add = sum[i] * cnt[other] + sum[other] * cnt[i];
      // if(i == other) add /= 4;
      // else add /= 2;
      tmp += add / 2;
    }
    tmp /= r;
    // cerr << "r: " << r << '\n';
    // cerr << "over: " << over << '\n';
    // cerr << "tmp: " << tmp << "\n\n";

    if(tmp - over < 0) break;
    ans += tmp - over;
    over += tmp;
    over *= 2;
    if(r <= 2) break;
    vector<ll> next_cnt(r / 2, 0), next_sum(r / 2, 0);
    rep(i, n) {
      next_cnt[a[i] % (r / 2)]++;
      next_sum[a[i] % (r / 2)] += a[i];
    }
    // rep(i, r / 2) cerr << next_cnt[i] << ' ';
    // cerr << '\n';
    // rep(i, r / 2) cerr << next_sum[i] << ' ';
    // cerr << '\n';

    swap(cnt, next_cnt);
    swap(sum, next_sum);
    r /= 2;
  }
  cout << ans << '\n';

  return 0;
}
