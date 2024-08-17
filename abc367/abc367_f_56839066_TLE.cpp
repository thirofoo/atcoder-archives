/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc367/submissions/56839066
 * Submitted at: 2024-08-18 00:10:34
 * Problem URL: https://atcoder.jp/contests/abc367/tasks/abc367_f
 * Result: TLE
 * Execution Time: 2212 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

template<class S>
struct Zobrist_hash_set {
  Zobrist_hash_set(): v(0) {
    mt.seed(rand());
    rnd = uniform_int_distribution<ll>(-LLONG_MAX, LLONG_MAX);
  }

  void flip(const S &x) {
    if(!x_to_hash.count(x)) x_to_hash[x] = rnd(mt);
    v ^= x_to_hash[x];
  }
  
  void init() { v = 0; }
  ll get() { return v; }

  ll v; // hash値
  unordered_map<S, ll> x_to_hash;
  mt19937_64 mt;
  uniform_int_distribution<ll> rnd;
};

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> A(N), B(N);
  for(ll i = 0; i < N; i++) cin >> A[i];
  for(ll i = 0; i < N; i++) cin >> B[i];

  vector<pair<ll, ll>> queries1, queries2;
  for(ll i = 0; i < Q; i++) {
    ll li, ri, Li, Ri;
    cin >> li >> ri >> Li >> Ri;
    queries1.emplace_back(li - 1, ri);
    queries2.emplace_back(Li - 1, Ri);
  }

  ll T = 200000;
  vector<ll> freqA(T + 1, 0), freqB(T + 1, 0);
  Zobrist_hash_set<ll> z;
  z.init();

  auto addL = [&](ll value, vector<ll> &freq) {
    z.flip(value * (T + 1) + freq[value]);
    freq[value]--;
    z.flip(value * (T + 1) + freq[value]);
  };
  auto delL = [&](ll value, vector<ll> &freq) {
    z.flip(value * (T + 1) + freq[value]);
    freq[value]++;
    z.flip(value * (T + 1) + freq[value]);
  };
  auto addR = [&](ll value, vector<ll> &freq) {
    z.flip(value * (T + 1) + freq[value]);
    freq[value]++;
    z.flip(value * (T + 1) + freq[value]);
  };
  auto delR = [&](ll value, vector<ll> &freq) {
    z.flip(value * (T + 1) + freq[value]);
    freq[value]--;
    z.flip(value * (T + 1) + freq[value]);
  };

  vector<ll> q_idx1(Q), q_idx2(Q);
  long long sq = sqrt(N);
  iota(q_idx1.begin(), q_idx1.end(), 0);
  sort(q_idx1.begin(), q_idx1.end(), [&](ll &i1, ll &i2) {
    auto &&[l1, r1] = queries1[i1];
    auto &&[l2, r2] = queries1[i2];
    if(l1 / sq != l2 / sq) return l1 < l2;
    if(l1 / sq % 2 == 1) return r1 > r2;
    return r1 < r2;
  });
  iota(q_idx2.begin(), q_idx2.end(), 0);
  sort(q_idx2.begin(), q_idx2.end(), [&](ll &i1, ll &i2) {
    auto &&[l1, r1] = queries2[i1];
    auto &&[l2, r2] = queries2[i2];
    if(l1 / sq != l2 / sq) return l1 < l2;
    if(l1 / sq % 2 == 1) return r1 > r2;
    return r1 < r2;
  });

  long long l = 0, r = 0;
  vector<ll> ret1(Q), ret2(Q);
  for(int i = 0; i < Q; i++) {
    auto &&[L, R] = queries1[q_idx1[i]];
    while(r < R) addR(A[r++], freqA);
    while(l < L) addL(A[l++], freqA);
    while(l > L) delL(A[--l], freqA);
    while(r > R) delR(A[--r], freqA);
    ret1[q_idx1[i]] = z.get();
  }

  z.init();
  l = 0, r = 0;
  for(int i = 0; i < Q; i++) {
    auto &&[L, R] = queries2[q_idx2[i]];
    while(r < R) addR(B[r++], freqB);
    while(l < L) addL(B[l++], freqB);
    while(l > L) delL(B[--l], freqB);
    while(r > R) delR(B[--r], freqB);
    ret2[q_idx2[i]] = z.get();
  }

  for(int i = 0; i < Q; i++) cout << (ret1[i] == ret2[i] ? "Yes" : "No") << '\n';

  return 0;
}
