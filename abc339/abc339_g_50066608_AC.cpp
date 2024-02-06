/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc339/submissions/50066608
 * Submitted at: 2024-02-07 01:39:11
 * Problem URL: https://atcoder.jp/contests/abc339/tasks/abc339_g
 * Result: AC
 * Execution Time: 891 ms
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
#define rep(i, l, r) for(ll i = l; i < r; i++)

struct MergeSortTree{
    MergeSortTree() : n(0) {}
    explicit MergeSortTree(const vector<ll> &_data){
        n = _data.size();
        log2 = 0;
        while((1LL << log2) < n) log2++;
        size = 1LL << log2;
        data = vector(2*size,vector<ll>{-(1LL << 60)}); // 番兵
        rui = vector(2*size,vector<ll>{});
        // MergeSortTree 用ジャグ配列作成
        for(ll i=size; i<size+n; i++) {
            ll tree_idx = i;
            while(tree_idx >= 1) {
                data[tree_idx].emplace_back(_data[i-size]);
                tree_idx /= 2;
            }
        }
        for(ll i=1; i<2*size; i++) {
            sort(data[i].begin(), data[i].end());
            rui[i] = data[i], rui[i][0] = 0;
            for(ll j=1; j<data[i].size(); j++) rui[i][j] += rui[i][j-1];
        }
        return;
    }
  
    ll all_prod(ll x) { return op(1,x); }
  
    ll prod(ll l, ll r, ll x) { // [l,r)
        l += size, r += size;
        ll sml = 0, smr = 0;
        while( l < r ) {
            if( l & 1 ) sml += op(l++, x);
            if( r & 1 ) smr += op(--r, x);
            l /= 2, r /= 2;
        }
        return sml + smr;
    }

    ll op(ll idx, ll x) {
        ll r = upper_bound(data[idx].begin(), data[idx].end(), x) - data[idx].begin() - 1;
        return rui[idx][r];
    }
  
    private:
    ll n, log2, size;
    vector<vector<ll>> data, rui;
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; cin >> n;
    vector<ll> a(n);
    rep(i,0,n) cin >> a[i];
    MergeSortTree mgs(a);
    ll q, pre = 0; cin >> q;
    while( q-- ) {
        ll l, r, x; cin >> l >> r >> x;
        l ^= pre, r ^= pre, x ^= pre; l--;
        pre = mgs.prod(l,r,x);
        cout << pre << endl;
    }
    
    return 0;
}