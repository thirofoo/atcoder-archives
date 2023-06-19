/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc146/submissions/42737668
 * Submitted at: 2023-06-19 13:23:29
 * Problem URL: https://atcoder.jp/contests/abc146/tasks/abc146_f
 * Result: AC
 * Execution Time: 31 ms
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

//セグ木状に乗せる型。
using S = int;

S op(S a,S b){return min(a,b);} // operator(作用素)
S e(){return 1e9;} // 単位元 (op(e,a) = a)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    // 解説AC
    // startから求めると値はdpで求まるが、辞書順最小の経路は復元出来ない
    // ( 大きい区間を辿るように goal → start に行く経路が辞書順最小になる訳では無い )
    // → goalからの最短手数を求めるdpをすれば、startから直感的に復元出来る！
    
    ll n,m; input(n,m);
    string s; input(s);
    reverse(s.begin(),s.end());

    segtree<S,op,e> dp(n+1);
    dp.set(0,0);
    for(ll i=1;i<=n;i++){
        if(s[i] == '1')continue;
        ll pre = dp.prod(max(0ll,i-m),i);
        if(pre >= 1e9)continue;
        dp.set(i,pre+1);
    }
    if(dp.get(n) >= 1e9){
        print(-1);
        return 0;
    }

    ll dis = 1, pre = 0;
    vector<vector<ll>> idx(dp.get(n)+1,vector<ll>{});
    for(ll i=n;i>=0;i--){
        if(dp.get(i) >= idx.size())continue;
        idx[dp.get(n)-dp.get(i)].push_back(n-i);
    }
    while(dis <= dp.get(n)){
        auto itr = upper_bound(idx[dis].begin(),idx[dis].end(),pre);
        cout << (*itr) - pre << " ";
        pre = (*itr);
        dis++;
    }
    print();
    
    return 0;
}