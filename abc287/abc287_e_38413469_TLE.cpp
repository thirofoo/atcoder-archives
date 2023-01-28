/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc287/submissions/38413469
 * Submitted at: 2023-01-28 22:09:05
 * Problem URL: https://atcoder.jp/contests/abc287/tasks/abc287_e
 * Result: TLE
 * Execution Time: 2207 ms
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

using ull = unsigned long long;
vector<ull> powr; // 基数の累乗

class RollingHash {
    public:
    RollingHash(const string &s){
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

    private:
    static const ull Mod = (1LL << 61) - 1;
    static const ull Positivizer = Mod * 7;
    static ull base;  // 基数
    vector<ull> hash; // hash の cash

    static ull getPow(int n){
        while(powr.size() <= n){
            // 次の基数の累乗を求める
            powr.push_back(mulMod(powr.back(), base));
        }
        return powr[n];
    }

    static ull mulMod(ull x,ull y){
        // Fermatの小定理 & 2進数のmod を利用
        __int128_t t = (__int128_t) x*y;
        t = (t >> 61) + (t & Mod);
        if(t >= Mod)t -= Mod;
        return (ull)t;
    }

    static ull getMod(ull val){
        val = (val >> 61) + (val & Mod);
        if(val >= Mod)val -= Mod;
        return (ull)val;
    }

    static ull euclid(ull a,ull b){
        if(b != 0)return euclid(b,a%b);
        else return a;
    }

    static ull modPow(ull a, ull b) {
        ll res= 1;
        for(; b; a=getMod(a*a), b>>=1) {
            if(b & 1)res = getMod(res*a);
        }
        return res;
    }
};
ull RollingHash::base;


int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<string> str;
    vector<RollingHash> r;
    rep(i,n){
        string s; input(s);
        str.push_back(s);
        r.push_back(RollingHash(s));
    }

    rep(i,n){
        ll left = 0,right = str[i].size()+1;
        while(right-left > 1){
            ll mid = (right+left)/2;
            ll h = r[i].get(0,mid);
            bool f = false;
            rep(j,n){
                if(mid > str[j].size() || i == j)continue;
                f |= (h == r[j].get(0,mid));
            }
            if(f)left = mid;
            else right = mid;
        }
        print(left);
    }
    
    return 0;
}