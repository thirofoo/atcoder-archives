/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc331/submissions/48154284
 * Submitted at: 2023-12-03 02:09:50
 * Problem URL: https://atcoder.jp/contests/abc331/tasks/abc331_f
 * Result: AC
 * Execution Time: 576 ms
 */

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
#include <atcoder/all>
using namespace atcoder;
// using mint = modint1000000007;
#define rep(i, n) for(ll i = 0; i < n; i++)

using ull = unsigned long long;
vector<ull> powr; // 基数の累乗

class RollingHash {
    public:
    RollingHash() : base(0) {}
    explicit RollingHash(const string &s) {
        if(base == 0){
            // base を 2^61-1の原始根 & 1e9以上 で初期化
            random_device rnd;
            mt19937 mt(rnd());
            uniform_int_distribution<ull> rand(1,INT_MAX);
            while(1){
                ull k = rand(mt);
                base = modPow(37,k);
                if(euclid(Mod-1,k) == 1 && base > 1e9)break;
            }
        }
        powr.assign(1,1);
        int size = s.size();
        hash.assign(size+1,0);
        // 左端~の hash 前計算
        for(int i=0; i<size; i++){
            hash[i+1] = mulMod(hash[i],base) + s[i];
            hash[i+1] = getMod(hash[i+1]);
        }
    }

    ull get(int l, int r){
        ull res = hash[r] - mulMod(hash[l],getPow(r-l));
        return getMod(res + Positivizer);
    }

    ull modPow(ull a, ull b) {
        ll res= 1;
        for(; b; a=getMod(a*a), b>>=1) {
            if(b & 1) res = getMod(res*a);
        }
        return res;
    }

    ull getMod(ull val){
        val = (val >> 61) + (val & Mod);
        if(val >= Mod)val -= Mod;
        return (ull)val;
    }

    ull mulMod(ull x,ull y){
        // Fermatの小定理 & 2進数のmod を利用
        __int128_t t = (__int128_t) x*y;
        t = (t >> 61) + (t & Mod);
        if(t >= Mod)t -= Mod;
        return (ull)t;
    }
    ull base;  // 基数
    const ull Positivizer = Mod * 7;

    private:
    static const ull Mod = (1LL << 61) - 1;
    vector<ull> hash; // hash の cash
    ull getPow(int n){
        while(powr.size() <= n){
            // 次の基数の累乗を求める
            powr.push_back(mulMod(powr.back(), base));
        }
        return powr[n];
    }

    static ull euclid(ull a,ull b){
        if(b != 0)return euclid(b,a%b);
        else return a;
    }
};

RollingHash rh("");

//セグ木状に乗せる型。
using S = struct {
    ull hash, r_hash, pw;
};

S op(S l,S r){
    return S{rh.getMod(l.hash+rh.mulMod(r.hash,l.pw)), rh.getMod(r.r_hash+rh.mulMod(l.r_hash,r.pw)), rh.mulMod(l.pw,r.pw)};
} // operator(作用素)
S e(){
    return S{0,0,1};
} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n, q; string s; cin >> n >> q >> s;
    segtree<S,op,e> sg(n);
    rep(i,n) sg.set(i,S{(ull)s[i],(ull)s[i],rh.base});

    while( q-- ) {
        ll t; cin >> t;
        if( t == 1 ) {
            ll x; char c; cin >> x >> c;
            sg.set(x-1, S{(ull)c,(ull)c,rh.base});
        }
        else {
            ll l, r; cin >> l >> r;
            cout << (sg.prod(l-1,r).hash == sg.prod(l-1,r).r_hash ? "Yes" : "No") << endl;
        }
    }
    
    return 0;
}