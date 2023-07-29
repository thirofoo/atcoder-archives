/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc312/submissions/44089596
 * Submitted at: 2023-07-30 01:59:46
 * Problem URL: https://atcoder.jp/contests/abc312/tasks/abc312_g
 * Result: AC
 * Execution Time: 114 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> cnt(n,0);
    vector<vector<ll>> Graph(n);
    rep(i,n-1) {
        ll a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    
    vector<ll> parent(n,-1);
    // 部分木の要素数を求める
    auto f1 = [&](auto self, ll now, ll pre) -> ll {
        cnt[now]++;
        parent[now] = pre;
        for (auto to : Graph[now]) {
            if( to == pre ) continue;
            cnt[now] += self(self, to, now);
        }
        return cnt[now];
    };
    f1(f1, 0, -1);

    // 答え候補
    // 1. 部分木から2つ + 親以上から1つ
    // 2. 部分木から3つ
    ll ans = 0;
    rep(i,n) {
        // sum : ∑(部分木の要素数) ※ 自分を除く
        // cand1 : 部分木から2つ選ぶ場合の数
        // cand2 : 部分木から3つ選ぶ場合の数
        ll cand1 = 0, cand2 = 0, sum = 0;
        for(auto to:Graph[i]) {
            if( to == parent[i] ) continue;
            cand2 += cand1 * cnt[to];
            cand1 += sum * cnt[to];    
            sum += cnt[to];
        }
        ans += cand1 * (n - cnt[i]) + cand2;
    }
    cout << ans << endl;
    
    return 0;
}