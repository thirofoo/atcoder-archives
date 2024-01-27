/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc203/submissions/49686220
 * Submitted at: 2024-01-27 17:12:20
 * Problem URL: https://atcoder.jp/contests/abc203/tasks/abc203_e
 * Result: AC
 * Execution Time: 236 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC : 考慮すべき点は M 個の黒ポーンのみ
    // ⇒ 上から差分更新で算出可能 (1つの黒ポーンにつき 3箇所のみ更新)

    ll n, m; cin >> n >> m;
    vector<ll> x(m), y(m);
    map<ll, set<ll>> mp;
    rep(i, m) {
        cin >> x[i] >> y[i];
        mp[x[i]].insert(y[i]);
    }
    set<ll> now = {n};
    for(auto &&[_, st] : mp) {
        set<ll> in, out;
        for(auto ele: st) {
            // ele が左・真ん中・右にいる時を考慮して差分更新
            if( now.count(ele) ) out.insert(ele);
            if( now.count(ele+1) ) in.insert(ele);
            if( now.count(ele-1) ) in.insert(ele);
        }
        for(auto ele: out) if( now.count(ele) ) now.erase(ele);
        for(auto ele: in) now.insert(ele);
    }
    cout << now.size() << endl;
    
    return 0;
}