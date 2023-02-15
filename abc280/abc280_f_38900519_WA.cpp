/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc280/submissions/38900519
 * Submitted at: 2023-02-15 15:13:57
 * Problem URL: https://atcoder.jp/contests/abc280/tasks/abc280_f
 * Result: WA
 * Execution Time: 63 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b){cout << a;(cout << ... << (cout << ' ', b));cout << '\n';}
template<class... T> void input(T&... a){(cin >> ... >> a);}
void print(){cout << '\n';}
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

struct weighted_dsu {
    // ACLよりUF写経
    public:
    // expricit：コンストラクタに付与で暗黙の型変換無向化
    weighted_dsu() : _n(0) {}
    explicit weighted_dsu(int n) : _n(n), parent_or_size(n, -1), diff_weight(n,0) {}

    int merge(int a, int b, int w) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);

        // weight[b] = weight[a] + w となるようにmerge
        // ※ 連結成分のmergeだから weightの差分が重みに反映
        w += weight(a); w -= weight(b);

        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y), w = -w;
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;

        diff_weight[y] = w;

        // 連結成分が大きい方のleaderが返り値
        return x;
}

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    // 親ノードに行くまでがO(α(n))
    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        int r = leader(parent_or_size[a]);
        diff_weight[a] += diff_weight[parent_or_size[a]];
        return parent_or_size[a] = r;
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    int weight(int x){
        leader(x); // 経路圧縮 ( diffを現在の状態に反映 )
        return diff_weight[x];
    }

    int diff(int x,int y){
        return weight(y)-weight(x);
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                          [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

    private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size,diff_weight;
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 重み付きUF解法
    // 行き方が1通り → wuf.diff()
    // 行き方が複数通り → 
    //   距離が同じ → 1通りと同じく
    //   距離が違う → inf
    // 非連結(行けない) → nan

    ll n,m,q; input(n,m,q);
    weighted_dsu wuf(n);
    set<ll> ng_v;
    rep(i,m){
        ll a,b,c; input(a,b,c);
        a--; b--;
        if(wuf.same(a,b) && wuf.diff(a,b) != c)ng_v.insert(a);
        else wuf.merge(a,b,c);
    }
    vector<vector<int>> g = wuf.groups();
    vector<int> inf_v(n,0);
    rep(i,g.size()){
        bool f = false;
        for(auto ele:g[i]){
            f |= ng_v.count(ele);
            if(f)break;
        }
        if(f){
            for(auto ele:g[i]){
                inf_v[ele] = i+1;
            }   
        }
    }
    while(q--){
        ll x,y; input(x,y);
        x--; y--;
        if(!wuf.same(x,y))print("nan");
        else if(inf_v[x] && inf_v[x] == inf_v[y])print("inf");
        else print(wuf.diff(x,y));
    }
    
    return 0;
}