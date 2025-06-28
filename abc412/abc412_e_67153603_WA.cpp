/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc412/submissions/67153603
 * Submitted at: 2025-06-28 22:04:41
 * Problem URL: https://atcoder.jp/contests/abc412/tasks/abc412_e
 * Result: WA
 * Execution Time: 181 ms
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

vector<bool> flags;
void eratosthenes(ll n) {
  flags.assign(n, true);
  flags[0]        = false;
  flags[1]        = false;
  const ll sqrt_n = ceil(sqrt(n) + 0.1);
  for(ll i = 2; i < sqrt_n; i++) {
    if(!flags[i]) continue;
    for(ll j = i * i; j < n; j += i) {
      flags[j] = false;
    }
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  ll l, r;
  cin >> l >> r;
  ll ans = 1;
  if(l == 1) {
    l++;
    ans++;
  }

  // ※ ======= https://algo-method.com/tasks/332/editorial を参考にしました
  // 入力が 32 ビット整数型に収まらないので long long 型
  // √B 以下の素数を炙り出すための篩
  // ここでは大きめにサイズ 1100000 まで確保しておく
  vector<bool> isprime(1e7 + 1, true);
  // A 以上 B 以下の整数 v が素数かどうか
  // その答えは isprime2[v-A] に格納される
  vector<bool> isprime2(r - l + 1, true);
  // ふるい
  for(long long p = 2; p * p <= r; ++p) {
    // すでに合成数であるものはスキップする
    if(!isprime[p]) continue;
    // p 以外の p の倍数から素数ラベルを剥奪
    for(long long q = p * 2; q * q <= r; q += p) {
      isprime[q] = false;
    }
    // start: l 以上の最小の p の倍数
    long long start = (l + p - 1) / p * p;
    if(start == p) start = p * 2;
    // l 以上 r 以下の整数のうち、p の倍数をふるう
    for(long long q = start; q <= r; q += p) {
      isprime2[q - l] = false;
    }
  }
  // 答え
  for(long long q = l; q <= r; ++q) {
    if(isprime2[q - l]) ans++;
  }
  // cerr << "ans: " << ans << endl;

  eratosthenes(1e7 + 1);
  rep(i, 1e7 + 1) {
    if(!flags[i]) continue;
    __int128_t v1 = 1;
    ll cnt1       = 0;
    while(v1 < l) {
      v1 *= (__int128_t) i;
      if(v1 == (__int128_t) l) {
        ans--;
        // cerr << "v1: " << (long long) v1 << endl;
      }
      cnt1++;
    }
    __int128_t v2 = 1;
    ll cnt2       = 0;
    while(v2 <= r) {
      v2 *= (__int128_t) i;
      cnt2++;
    }
    ans += (cnt2 - cnt1);
    // cerr << "i: " << i << ", cnt1: " << cnt1 << ", cnt2: " << cnt2 << ", ans: " << ans << endl;
    if(v1 == (__int128_t) i && v1 <= r) ans--;
  }
  cout << ans << endl;

  return 0;
}