/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc250/submissions/38903677
 * Submitted at: 2023-02-15 18:37:44
 * Problem URL: https://atcoder.jp/contests/abc250/tasks/abc250_e
 * Result: AC
 * Execution Time: 506 ms
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
    
    ll n; input(n);
	set<ll> ast,bst;
	Zobrist_hash_set<ll> zh;
	vector<ll> hash_a,hash_b;
	rep(i,n){
		ll a; input(a);
		// 以前出た数字は弾くの忘れずに。
		if(!ast.count(a))zh.flip(a);
		hash_a.emplace_back(zh.get());
		ast.insert(a);
	}
	zh.init();
	rep(i,n){
		ll b; input(b);
		if(!bst.count(b))zh.flip(b);
		hash_b.emplace_back(zh.get());
		bst.insert(b);
	}
	ll q; input(q);
	while(q--){
		ll x,y; input(x,y);
		x--; y--;
		if(hash_a[x] == hash_b[y])print("Yes");
		else print("No");
	}
    
    return 0;
}