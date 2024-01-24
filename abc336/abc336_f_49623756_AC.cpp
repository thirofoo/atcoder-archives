/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc336/submissions/49623756
 * Submitted at: 2024-01-24 19:10:29
 * Problem URL: https://atcoder.jp/contests/abc336/tasks/abc336_f
 * Result: AC
 * Execution Time: 931 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)

template <class S>
struct Zobrist_hash_set {
    public:
    Zobrist_hash_set() : v(0) {
        mt.seed(rand());
        rnd = uniform_int_distribution<ll>(-LLONG_MAX, LLONG_MAX);
   }

    void flip(const S& x) {
        // x 初出現 → 新hash値を割当
        if (!x_to_hash.count(x)) x_to_hash[x] = rnd(mt);
        // 状態のhash値更新
        v ^= x_to_hash[x];
    }

    void init() { v = 0; } // hash初期化
    ll get() { return v; } // 現時点の状態hash値を返す．
    
    private:
    ll v; // hash値
    unordered_map<S, ll> x_to_hash; // 各 x ∈ X に対するハッシュの割当
    mt19937_64 mt;
    uniform_int_distribution<ll> rnd;
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // ~~ 半分全列挙 ~~ //
    // 1. 開始・終了の状態からそれぞれ10手分の状態を全列挙
    // 2. その状態を Hash で管理し、半分全列挙をして Hash が一致すれば OK

    ll h, w; cin >> h >> w;
    vector<vector<ll>> s1(h,vector<ll>(w)), s2(h,vector<ll>(w));
    rep(i,h) rep(j,w) {
        cin >> s1[i][j];
        s2[i][j] = i*w + j + 1;
    }
    ll env;
    vector<vector<bool>> vis(h,vector<bool>(w,false));
    vector<set<ll>> start(11), end(11);
    auto update = [&](ll sx, ll sy, Zobrist_hash_set<ll> &hash, vector<vector<ll>> &s) -> void {
        bool init = vis[sx][sy], f = false;
        rep(i,h-1) {
            rep(j,w-1) {
                ll i1 = sx + i, j1 = sy + j, i2 =  sx + (h-1)-i-1, j2 = sy + (w-1)-j-1;
                if( vis[i1][j1] != init ) {
                    f = true;
                    break;
                }
                hash.flip((i1*w+j1)*h*w + s[i1][j1]);
                hash.flip((i2*w+j2)*h*w + s[i2][j2]);
                swap(s[i1][j1], s[i2][j2]);
                hash.flip((i1*w+j1)*h*w + s[i1][j1]);
                hash.flip((i2*w+j2)*h*w + s[i2][j2]);
                vis[i1][j1] = !init, vis[i2][j2] = !init;
            }
            if( f ) break;
        }
        rep(i,h) vis[i][(sy == 0 ? w-1 : 0)] = !init;
        rep(i,w) vis[(sx == 0 ? h-1 : 0)][i] = !init;
    };

    auto dfs = [&](auto self, Zobrist_hash_set<ll> &hash, vector<vector<ll>> &s, int time, int pre) -> void {
        ( env == 0 ? start[time] : end[time] ).insert(hash.get());
        if( time == 10 ) return;
        // d = 0 ~ 4 : (0,0), (0,1), (1,0), (1,1) を左上として π 回転
        rep(sx,2) rep(sy,2) {
            if( sx*2 + sy == pre ) continue;
            update(sx, sy, hash, s);
            self(self, hash, s, time+1, sx*2 + sy);
            update(sx, sy, hash, s); // 巻き戻し
        }
        return;
    };

    Zobrist_hash_set<ll> zsh; 

    zsh.init();
    rep(i,h) rep(j,w) zsh.flip((i*w+j)*h*w + s1[i][j]);
    env = 0, dfs(dfs, zsh, s1, 0, -1);

    zsh.init();
    rep(i,h) rep(j,w) zsh.flip((i*w+j)*h*w + s2[i][j]);
    env = 1, dfs(dfs, zsh, s2, 0, -1);

    // 半分全列挙 part
    ll ans = 1e9;
    rep(i,11) for(auto hs:start[i]) {
        rep(j,11) {
            auto itr = end[j].lower_bound(hs);
            if( itr == end[j].end() || *itr != hs ) continue;
            ans = min(ans, i+j);
        }
    }
    cout << (ans > 20 ? -1 : ans) << endl;
    
    return 0;
}