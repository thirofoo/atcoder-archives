/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/54990070
 * Submitted at: 2024-06-28 17:57:38
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_as
 * Result: AC
 * Execution Time: 281 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)
const ll INF = ((1LL << 62)-(1LL << 31));

inline void printInBase(ll number, ll base, ll digit) {
    // base 進数で number を digit 桁エラー出力
    vector<ll> res;
    while(number) {
        res.push_back(number % base);
        number /= base;
    }
    while(res.size() < digit) res.push_back(0);
    reverse(res.begin(), res.end());
    for(auto x : res) cerr << x;
    cerr << endl;
    return;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, k; cin >> n >> k;
    vector<ll> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    // 部分集合を O(3^N) で数え上げるテクニック使えば行けそう…？
    vector<ll> dist((1LL << n), 0);
    reps(i, 1, (1LL << n)) {
        rep(j, n) {
            reps(k, j+1, n) {
                if((i >> j) & 1 && (i >> k) & 1) {
                    dist[i] = max(dist[i], (x[j]-x[k])*(x[j]-x[k]) + (y[j]-y[k])*(y[j]-y[k]));
                }
            }
        }
    }

    // memo[i][j] := 集合 i に対して残り j 個の集合を選ぶときの最大値
    vector memo((1LL << n), vector<ll>(k+1, INF));
    memo[0][0] = 0;
    reps(now, 1, (1LL << n)) reps(time, 1, k+1){
        for(ll next=now; next > 0; next--, next &= now) {
            memo[now][time] = min(memo[now][time], max(memo[now^next][time-1], dist[next]));
        }
        // cerr << "now: ";
        // printInBase(now, 2, n);
        // cerr << "time: " << time << endl;
        // cerr << "memo: " << memo[now][time] << endl << endl;
    }
    cout << memo[(1LL << n)-1][k] << endl;
    
    return 0;
}