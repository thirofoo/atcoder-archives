/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc352/submissions/53144779
 * Submitted at: 2024-05-04 23:27:19
 * Problem URL: https://atcoder.jp/contests/abc352/tasks/abc352_f
 * Result: WA
 * Execution Time: 2210 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint998244353;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define reps(i, l, r) for(ll i = l; i < r; i++)

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
    
    ll n, m; cin >> n >> m;
    vector<ll> a(m), b(m), c(m);
    rep(i,m) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
    }

    if( m < n/2 - 3 ) {
        vector<ll> ans(n, -1);
        rep(i,m) {
            if( c[i] == n-1 ) {
                ans[a[i]] = n;
                ans[b[i]] = 1;
            }
        }
        rep(i,n) cout << ans[i] << " ";
        cout << endl;
        return 0;
    }

    // 連結成分の順列全探索をすれば行けるのでは？
    dsu uf(n);
    weighted_dsu wuf(n);
    rep(i,m) {
        uf.merge(a[i], b[i]);
        wuf.merge(b[i], a[i], c[i]);
    }
    vector<vector<int>> gr = uf.groups();
    // 各グループごとに一番順位が低いものをリーダーとする
    vector<vector<ll>> diffs;
    vector<ll> leader(gr.size(),0);
    rep(i,gr.size()) {
        vector<int> v = gr[i]; 

        vector<ll> diff(v.size(),0);
        ll min_diff = 1e18;
        rep(j, v.size()) {
            diff[j] = wuf.diff(v[0], v[j]);
            min_diff = min(min_diff, diff[j]);
        }
        rep(j,v.size()) if( diff[j] == min_diff ) leader[i] = j;
        rep(j,v.size()) diff[j] = wuf.diff(v[leader[i]], v[j]);
        diffs.emplace_back(diff);
    }

    // debug
    // rep(i,gr.size()) {
    //     cerr << "leader: " << leader[i] << endl;
    //     rep(j,gr[i].size()) cerr << gr[i][j] << " " << diffs[i][j] << endl;
    //     cerr << endl;
    // }

    vector<ll> p(gr.size());
    vector<vector<bool>> g(n ,vector(n,false));
    iota(p.begin(), p.end(), 0);
    do {
        bool f = true;
        // 連結成分のリーダーが p の順に来る場合が成り立つか確認
        vector<ll> cnt(2*n, -1);
        ll start = 0;
        rep(i,gr.size()) {
            ll ni = p[i];
            rep(j,gr[p[i]].size()) cnt[diffs[p[i]][leader[p[i]]] + diffs[p[i]][j] + start] = gr[p[i]][j];
            while( cnt[start] != -1 ) start++;
            if( start >= n ) break;
        }
        rep(i,n) f &= ( cnt[i] != -1 );
        if( f ) {
            // rep(i,n) cerr << cnt[i] << " ";
            // cerr << endl;
            // 連結成分のリーダーが p の順に来る場合
            rep(j,n) g[cnt[j]][j] = true;
        }
    } while( next_permutation(p.begin(), p.end()) );

    vector<ll> ans(n, -1);
    rep(j,n) {
        vector<ll> cand;
        rep(i,n) if( g[i][j] ) cand.emplace_back(i);
        if( cand.size() == 1 ) ans[cand[0]] = j+1;
    }
    rep(i,n) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}
