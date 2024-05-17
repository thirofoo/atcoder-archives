/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc352/submissions/53550141
 * Submitted at: 2024-05-17 19:05:28
 * Problem URL: https://atcoder.jp/contests/abc352/tasks/abc352_f
 * Result: AC
 * Execution Time: 1048 ms
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

    ll weight(ll x) {
        leader(x); // 経路圧縮 ( diffを現在の状態に反映 )
        return diff_weight[x];
    }

    ll diff(ll x, ll y) {
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
            result[leader_buf[i]].emplace_back(i);
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

    // 解説 AC
    // 同連結成分の要素は一つが決まれば他も決まる
    // ⇒ 各連結成分の配置パターンが有り得るかを bitDP で判定
    // ⇒ 有り得るパターンが 1 通りならその連結成分内の要素は全てそれで確定
    
    ll n, m; cin >> n >> m;
    vector<ll> a(m), b(m), c(m);
    weighted_dsu uf(n);
    rep(i, m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        uf.merge(b[i], a[i], c[i]);
    }
    vector g = uf.groups();
    vector<ll> g_bit(g.size(), 0ll);
    rep(i, g.size()) {
        auto &&group = g[i];
        vector<ll> diff(group.size());
        map<ll, ll> mp;
        ll min_diff = INF;
        rep(i, group.size()) {
            diff[i] = uf.diff(group[0], group[i]);
            min_diff = min(min_diff, diff[i]);
            mp[group[i]] = i;
        }
        rep(j, group.size()) {
            diff[j] -= min_diff;
            g_bit[i] |= (1ll << diff[j]);
        }
        sort(g[i].begin(), g[i].end(), [&](ll x, ll y) {
            return diff[mp[x]] < diff[mp[y]];
        });
    }

    vector<ll> ans(n, -1);
    ll bit_mask = (1LL << n) - 1;
    rep(i, g.size()) {
        vector dp(g.size()+1, vector<bool>(1ll << n, false));
        dp[0][0] = true;
        rep(j, g.size()) {
            if( j == i ) {
                rep(k, (1LL << n)) {
                    dp[j+1][k] = (dp[j][k] || dp[j+1][k]);
                }
            }
            else {
                rep(k, (1LL << n)) rep(l, n) {
                    ll n_bit = (g_bit[j] << l);
                    if( n_bit > bit_mask ) continue;
                    if( k & n_bit ) continue;
                    dp[j+1][k | n_bit] = (dp[j][k] || dp[j+1][k | n_bit]);
                }
            }
        }
        ll cand_bit = -1;
        bool is_unique = true;
        rep(j, (1LL << n)) {
            if( !dp[g.size()][j] ) continue;
            rep(k, n) {
                ll n_bit = (g_bit[i] << k);
                if( (j | n_bit) == bit_mask ) {
                    is_unique = (cand_bit == -1);
                    cand_bit = n_bit;
                }
            }
        }
        if( !is_unique ) continue;
        ll gi_idx = 0;
        rep(j, n) {
            if( !(cand_bit & (1ll << j)) ) continue;
            ans[g[i][gi_idx]] = j+1;
            gi_idx++;
        }
    }
    rep(i, n) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}