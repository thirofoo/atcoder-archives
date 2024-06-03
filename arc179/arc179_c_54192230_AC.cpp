/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc179/submissions/54192230
 * Submitted at: 2024-06-03 11:19:02
 * Problem URL: https://atcoder.jp/contests/arc179/tasks/arc179_c
 * Result: AC
 * Execution Time: 96 ms
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

bool compare(const ll &a, const ll &b) {
    cout << "? " << a << " " << b << endl << flush;
    ll res; cin >> res;
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説 AC : bool operator を定義してラムダ式内でクエリをはたくようにしても AC 可能
    ll n; cin >> n;
    vector<ll> idx(n,0);
    iota(idx.begin(), idx.end(), 1);
    sort(idx.begin(), idx.end(), compare);

    while( idx.size() > 1 ) {
        cout << "+ " << idx.front() << " " << idx.back() << endl << flush;
        idx.erase(idx.begin());
        idx.pop_back();
        ll res; cin >> res;
        auto itr = lower_bound(idx.begin(), idx.end(), res, compare);
        idx.insert(itr, res);
    }
    cout << "!" << endl << flush;
    
    return 0;
}