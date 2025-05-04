/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc197/submissions/65512646
 * Submitted at: 2025-05-04 22:59:55
 * Problem URL: https://atcoder.jp/contests/arc197/tasks/arc197_d
 * Result: WA
 * Execution Time: 63 ms
 */

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint = modint998244353;
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
    ll n;
    cin >> n;
    vector<vector<ll>> a(n, vector<ll>(n));
    rep(i, n) rep(j, n) cin >> a[i][j];
    // warshall_floyd
    rep(k, n) rep(i, n) rep(j, n) a[i][j] = max({a[i][j], a[i][k] + a[k][j], 1LL});

    // warshall をした a[i][j] = 0 に辺を貼ったグラフにおいて、i (1 ~ N) 部グラフの塗り方の総和が答えっぽい？
    // ※ 連結成分ごとには総積をする

    vector<vector<ll>> graph(n);
    rep(i, n) rep(j, n) if(a[i][j] == 0) graph[i].emplace_back(j);
    mint ans = 0;
    for(ll i = 1; i <= n; i++) {
      // i 部グラフの塗り方の総和を求める
      vector<ll> visited(n, -1);
      mint add = 1;
      rep(j, n) {
        if(visited[j] == -1) {
          queue<ll> que;
          que.push(j);
          visited[j] = 0;
          mint cand  = 1;
          // 行先の mex を取ってその頂点を塗る
          while(!que.empty()) {
            ll now = que.front();
            que.pop();
            cand *= max(i - visited[now], 0LL);

            for(auto next: graph[now]) {
              if(visited[next] == -1) {
                que.push(next);
                vector<ll> tonari;
                for(auto next: graph[now])
                  if(visited[next] != -1) tonari.emplace_back(next);
                sort(tonari.begin(), tonari.end());
                ll mex = 0;
                rep(k, tonari.size()) {
                  if(tonari[k] == mex) mex++;
                  else break;
                }
                visited[now] = mex;
              }
            }
          }
          add *= cand;
        }
      }
      ans += add;
    }
    cout << ans.val() << '\n';
  }

  return 0;
}