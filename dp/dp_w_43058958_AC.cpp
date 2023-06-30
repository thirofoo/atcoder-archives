/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/43058958
 * Submitted at: 2023-06-30 13:55:43
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_w
 * Result: AC
 * Execution Time: 212 ms
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

// S が data, F が lazy
using S = ll;
using F = ll;
// operator(作用素)
S op(S a,S b){
    return max(a, b);
}
// 遅延データ反映
S mapping(F f,S x){
    return f + x;
}
// 遅延データ作用
F composition(F f,F g){
    return f + g;
}
S e(){ return -1e16; } // 単位元 (op(e, a) = op(a, e) = a)
F id(){ return 0; } // mapping(id, a) = a

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC (天才)
    // 1. 何文字目を見てるか と 最後に現れた1のindex を保持したくなる(らしい)
    // 2. 今見てる文字までで完全包含されてる区間のみを考慮する (でないと複数回同じ区間をカウントしてしまう)
    // 3. dp遷移を考える
    // ・今考慮してる最後尾の文字が1 (i == j) の時 → 過去[0,i)の区間のmax + 最後尾を1にして増えた区間
    // ・↑でない時 → 完全包含された区間が増えた時を考慮 (右端がi & jがその区間内にある ものを考慮して足す)

    // point. 区間数え上げは右端 or 左端で管理すると重複せずにカウント可
    // → あらたに加わる区間を考えれば良いだけになる！

    ll n,m; input(n,m);
    lazy_segtree<S,op,e,F,mapping,composition,id> dp(n);
    rep(i,n)dp.set(i,0);

    vector<vector<P>> section(n);
    vector<ll> cost_sum(n,0);
    rep(i,m){
        ll l,r,a; input(l,r,a);
        l--; r--;
        section[r].push_back(P(l,a));
        cost_sum[r] += a;
    }
    rep(i,n){
        // i文字目までを考慮
        dp.set(i,dp.prod(0,i+1) + cost_sum[i]);
        
        if( section[i].empty() )continue;

        // 新たに加わる区間を考慮
        for(auto [l,cost]:section[i]){
            dp.apply(l,i,cost);
        }
    }
    print( max(dp.all_prod(),0ll) );
    
    return 0;
}