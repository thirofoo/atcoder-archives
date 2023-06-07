/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc157/submissions/42056964
 * Submitted at: 2023-06-07 18:05:31
 * Problem URL: https://atcoder.jp/contests/abc157/tasks/abc157_d
 * Result: AC
 * Execution Time: 53 ms
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

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m,k; input(n,m,k);
    vector<ll> dig(n,0);
    vector<P> edge;
    dsu uf(n);
    rep(i,m){
        ll u,v; input(u,v);
        u--; v--;
        dig[u]++;
        dig[v]++;
        uf.merge(u,v);
    }
    rep(i,k){
        ll u,v; input(u,v);
        u--; v--;
        edge.push_back(P(u,v));
    }
    vector g = uf.groups();
    vector<ll> ans(n,0);
    for(auto vec:g){
        for(auto ele:vec)ans[ele] = vec.size()-dig[ele]-1;
    }
    // 最後にblock分だけ除く
    for(auto [u,v]:edge){
        if(uf.same(u,v)){
            ans[u]--;
            ans[v]--;
        }
    }
    rep(i,n)cout << ans[i] << " ";
    print();
    
    return 0;
}