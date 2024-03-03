/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc343/submissions/50862701
 * Submitted at: 2024-03-03 13:12:19
 * Problem URL: https://atcoder.jp/contests/abc343/tasks/abc343_g
 * Result: TLE
 * Execution Time: 5521 ms
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

using ull = unsigned long long;
class RollingHash {
    public:
    static const ull Mod = (1LL << 61) - 1;
    ull base;  // 基数

    RollingHash() {}
    explicit RollingHash(const string &s, ull _base = 0) {
        if( _base == 0 ) {
            // base を 2^61-1の原始根 & 1e9以上 で初期化
            random_device rnd;
            mt19937 mt(rnd());
            uniform_int_distribution<ull> rand(1,INT_MAX);
            while( true ) {
                ull k = rand(mt);
                _base = modPow(37,k);
                if(euclid(Mod-1,k) == 1 && base > 1e9) break;
            }
        }
        base = _base;
        powr.assign(1,1);
        int size = s.size();
        hash.assign(size+1,0);
        // 左端~の hash 前計算
        for(int i=0; i<size; i++) {
            hash[i+1] = mulMod(hash[i],base) + s[i];
            hash[i+1] = getMod(hash[i+1]);
        }
    }

    ull get(int l, int r) {
        ull res = hash[r] - mulMod(hash[l],getPow(r-l));
        return getMod(res + Positivizer);
    }

    private:
    static const ull Positivizer = Mod * 7;
    vector<ull> hash; // hash の cash
    vector<ull> powr; // 基数の累乗

    ull getPow(int n) {
        while(powr.size() <= n) {
            // 次の基数の累乗を求める
            powr.emplace_back(mulMod(powr.back(), base));
        }
        return powr[n];
    }

    ull mulMod(ull x,ull y) {
        // Fermatの小定理 & 2進数のmod を利用
        __int128_t t = (__int128_t) x*y;
        t = (t >> 61) + (t & Mod);
        if(t >= Mod)t -= Mod;
        return (ull)t;
    }

    ull getMod(ull val) {
        val = (val >> 61) + (val & Mod);
        if(val >= Mod)val -= Mod;
        return (ull)val;
    }

    ull euclid(ull a,ull b) {
        if(b != 0)return euclid(b,a%b);
        else return a;
    }

    ull modPow(ull a, ull b) {
        ll res= 1;
        for(; b; a=getMod(a*a), b>>=1) {
            if(b & 1)res = getMod(res*a);
        }
        return res;
    }
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // RollingHahs で前後の重なり前計算 ⇒ bitDP
    ll n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    vector<RollingHash> rh(n);
    rh[0] = RollingHash(s[0]); // base を統一する為 1 つ目は先に計算
    reps(i,1,n) rh[i] = RollingHash(s[i], rh[0].base);

    vector<vector<ll>> duplicate(n+1,vector<ll>(n+1,0));
    // duplicate[i][j] = i ⇒ j の重なりの最大長
    rep(i,n) rep(j,n) {
        if( i == j ) continue;
        reps(k,1,min(s[i].size(),s[j].size())+1) {
            if( rh[i].get(s[i].size()-k,s[i].size()) != rh[j].get(0,k) ) continue;
            duplicate[i+1][j+1] = k;
        }
        // 完全包含かどうかも確認
        rep(k, abs((ll)s[i].size()-(ll)s[j].size())+1) {
            if( s[i].size() < s[j].size() && rh[j].get(k,k+s[i].size()) == rh[i].get(0,s[i].size()) ) {
                duplicate[i+1][j+1] = s[i].size();
                break;
            }
            if( s[i].size() > s[j].size() && rh[i].get(k,k+s[j].size()) == rh[j].get(0,s[j].size()) ) {
                duplicate[i+1][j+1] = s[j].size();
                break;
            }
        }
    }
    vector<vector<ll>> dp(1ll << n,vector<ll>(n+1,1e16));
    dp[0][0] = 0;
    rep(i, (1ll << n)-1) rep(j,n+1) {
        if( dp[i][j] == 1e16 ) continue;
        rep(k,n) {
            if( i & (1ll << k) ) continue;
            dp[i | 1 << k][k+1] = min(dp[i | 1 << k][k+1], dp[i][j] + (ll)s[k].size() - duplicate[j][k+1]);
        }
    }
    ll ans = 1e16;
    reps(i,1,n+1) ans = min(ans, dp[(1ll << n)-1][i]);
    cout << ans << endl;
    
    return 0;
}