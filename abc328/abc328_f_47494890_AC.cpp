/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc328/submissions/47494890
 * Submitted at: 2023-11-11 22:11:16
 * Problem URL: https://atcoder.jp/contests/abc328/tasks/abc328_f
 * Result: AC
 * Execution Time: 52 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#define rep(i, n) for(ll i = 0; i < n; i++)

struct weighted_dsu {
    // ACLよりUF写経
    public:
    // expricit：コンストラクタに付与で暗黙の型変換無向化
    weighted_dsu() : _n(0) {}
    explicit weighted_dsu(ll n) : _n(n), parent_or_size(n, -1), diff_weight(n,0) {}

    ll merge(ll a, ll b, ll w) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);

        // weight[b] = weight[a] + w となるようにmerge
        // ※ 連結成分のmergeだから weightの差分が重みに反映
        w += weight(a); w -= weight(b);

        ll x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y), w = -w;
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;

        diff_weight[y] = w;

        // 連結成分が大きい方のleaderが返り値
        return x;
    }

    bool same(ll a, ll b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    // 親ノードに行くまでがO(α(n))
    ll leader(ll a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        ll r = leader(parent_or_size[a]);
        diff_weight[a] += diff_weight[parent_or_size[a]];
        return parent_or_size[a] = r;
    }

    ll size(ll a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    ll weight(ll x){
        leader(x); // 経路圧縮 ( diffを現在の状態に反映 )
        return diff_weight[x];
    }

    ll diff(ll x, ll y){
        return weight(y)-weight(x);
    }

    std::vector<std::vector<ll>> groups() {
        std::vector<ll> leader_buf(_n), group_size(_n);
        for (ll i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<ll>> result(_n);
        for (ll i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (ll i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                          [&](const std::vector<ll>& v) { return v.empty(); }),
            result.end());
        return result;
    }

    private:
    ll _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<ll> parent_or_size;
    std::vector<ll> diff_weight;
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q; cin >> n >> q;
    weighted_dsu dsu(n);
    vector<ll> ans;
    ll idx = 1;
    while( q-- ) {
        ll a, b, d; cin >> a >> b >> d;
        a--; b--;
        if( !dsu.same(a,b) || dsu.diff(a,b) == d ) {
            dsu.merge(a,b,d);
            ans.emplace_back(idx);
        }
        idx++;
    }
    for(auto ele:ans) cout << ele << " ";
    cout << endl;
    
    return 0;
}