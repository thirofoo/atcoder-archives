/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc336/submissions/49622873
 * Submitted at: 2024-01-24 18:22:05
 * Problem URL: https://atcoder.jp/contests/abc336/tasks/abc336_f
 * Result: AC
 * Execution Time: 796 ms
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

template <class S>
struct Zobrist_hash_set {
    public:
    Zobrist_hash_set() : v(0) {
        mt.seed(rand());
        rnd = uniform_int_distribution<ll>(-LLONG_MAX, LLONG_MAX);
   }

    // 64bit整数値でhashを取る → max(N) = 2^20 = 104856 ≒ 1e6 の時
    // hash衝突確率p :
    // 1-p <= ( (2^64-n)/2^64 )^n ≒ 0.99999994039
    // p ≒ 1e(-7) (宝くじ1等の当選確率位)

    // 盤面のhashに関しても同様
    // → 調べたい盤面が高々1e6位の時は基本衝突しない。

    // 今現在の状態をvとして、xのhashをxorしてあげる
    void flip(const S& x) {
        // x 初出現 → 新hash値を割当
        if (!x_to_hash.count(x)) {
            x_to_hash[x] = rnd(mt);
        }
    
        // 状態のhash値更新
        v ^= x_to_hash[x];
    }
    
    // hash初期化
    void init() { v = 0; }
    
    // 現時点の状態hash値を返す．
    ll get() { return v; }
    
    private:
    // hash値
    ll v;

    // 各 x ∈ X に対するハッシュの割当
    unordered_map<S, ll> x_to_hash;
    mt19937_64 mt;
    uniform_int_distribution<ll> rnd;
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll h, w; cin >> h >> w;
    vector<vector<ll>> s1(h,vector<ll>(w)), s2(h,vector<ll>(w));
    rep(i,h) rep(j,w) {
        cin >> s1[i][j];
        s2[i][j] = i*w + j + 1;
    }
    // ~~ 半分全列挙 ~~ //
    // 1. 開始・終了の状態からそれぞれ10手分の状態を全列挙
    // 2. その状態を Hash で管理し、半分全列挙をして Hash が一致すれば OK
    int env;
    vector<set<ll>> start(11), end(11);
    auto f = [&](auto self, Zobrist_hash_set<ll> &hash, vector<vector<ll>> &s, int time, int pre) -> void {
        ( env == 0 ? start[time] : end[time] ).insert(hash.get());
        if( time == 10 ) return;
        // d = 0 ~ 4 : (0,0), (0,1), (1,0), (1,1) を左上として π 回転
        rep(d,4) {
            if( d == pre ) continue;
            ll dx = (d >= 2), dy = (d % 2);
            rep(i,(h-1)/2) rep(j,w-1) {
                ll i1 = i+dx, j1 = j+dy, i2 = (h-1)-i-1+dx, j2 = (w-1)-j-1+dy;
                hash.flip((i1*w+j1)*h*w + s[i1][j1]);
                hash.flip((i2*w+j2)*h*w + s[i2][j2]);
                swap(s[i1][j1], s[i2][j2]);
                hash.flip((i1*w+j1)*h*w + s[i1][j1]);
                hash.flip((i2*w+j2)*h*w + s[i2][j2]);
            }
            if( (h-1)%2 ) {
                rep(j,(w-1)/2) {
                    ll i1 = (h-1)/2+dx, j1 = j+dy, i2 = (h-1)/2+dx, j2 = (w-1)-j-1+dy;
                    hash.flip((i1*w+j1)*h*w + s[i1][j1]);
                    hash.flip((i2*w+j2)*h*w + s[i2][j2]);
                    swap(s[i1][j1], s[i2][j2]);
                    hash.flip((i1*w+j1)*h*w + s[i1][j1]);
                    hash.flip((i2*w+j2)*h*w + s[i2][j2]);
                }
            }
            // if( time == 0 ) {
            //     cerr << endl;
            //     rep(i,h) {
            //         rep(j,w) cerr << s1[i][j] << (s1[i][j] < 10 ? " " : "") << " ";
            //         cerr << " | ";
            //         rep(j,w) cerr << s2[i][j] << (s2[i][j] < 10 ? " " : "") << " ";
            //         cerr << endl;
            //     }
            // }
            self(self, hash, s, time+1, d);
            rep(i,(h-1)/2) rep(j,w-1) {
                ll i1 = i+dx, j1 = j+dy, i2 = (h-1)-i-1+dx, j2 = (w-1)-j-1+dy;
                hash.flip((i1*w+j1)*h*w + s[i1][j1]);
                hash.flip((i2*w+j2)*h*w + s[i2][j2]);
                swap(s[i1][j1], s[i2][j2]);
                hash.flip((i1*w+j1)*h*w + s[i1][j1]);
                hash.flip((i2*w+j2)*h*w + s[i2][j2]);
            }
            if( (h-1)%2 ) {
                rep(j,(w-1)/2) {
                    ll i1 = (h-1)/2+dx, j1 = j+dy, i2 = (h-1)/2+dx, j2 = (w-1)-j-1+dy;
                    hash.flip((i1*w+j1)*h*w + s[i1][j1]);
                    hash.flip((i2*w+j2)*h*w + s[i2][j2]);
                    swap(s[i1][j1], s[i2][j2]);
                    hash.flip((i1*w+j1)*h*w + s[i1][j1]);
                    hash.flip((i2*w+j2)*h*w + s[i2][j2]);
                }
            }
        }
        return;
    };

    Zobrist_hash_set<ll> zsh; zsh.init();
    rep(i,h) rep(j,w) zsh.flip((i*w+j)*h*w + s1[i][j]);
    env = 0, f(f, zsh, s1, 0, -1);
    zsh.init();
    rep(i,h) rep(j,w) zsh.flip((i*w+j)*h*w + s2[i][j]);
    env = 1, f(f, zsh, s2, 0, -1);

    // 半分全列挙 part
    ll ans = 1e9;
    rep(i,11) {
        for(auto hs:start[i]) {
            rep(j,11) {
                auto itr = end[j].lower_bound(hs);
                if( itr == end[j].end() || *itr != hs ) continue;
                ans = min(ans, i+j);
            }
        }
    }
    cout << (ans > 20 ? -1 : ans) << endl;
    
    return 0;
}