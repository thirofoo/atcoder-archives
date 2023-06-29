/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/dp/submissions/43041343
 * Submitted at: 2023-06-29 15:34:58
 * Problem URL: https://atcoder.jp/contests/dp/tasks/dp_v
 * Result: AC
 * Execution Time: 109 ms
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
typedef modint mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC : 全方位木dp
    // ・simpleに全方位木dpするだけでは通らない
    // ・最後に各頂点を根とした時の部分木の総積を考えたい
    // しかし... 部分木を除算して除外する時に部分木が mod M で 0 だと NG
    // 1つの部分木を除外 → 部分木の集合において累積積 & 左右から挟む

    ll n,m; input(n,m);
    vector<vector<ll>> Graph(n);
    rep(i,n-1){
        ll x,y; input(x,y);
        x--; y--;
        Graph[x].push_back(y);
        Graph[y].push_back(x);
    }

    modint::set_mod(m);
    vector<bool> visited(n,false);

    // dp1[i][j] : 頂点iで (j == 0 ? 黒 : 白) で塗った時のパスの場合の数
    vector<mint> dp1(n,1);
    auto f1 = [&](auto self, ll now){
        if( visited[now] )return;
        visited[now] = true;
        for(ll to:Graph[now]){
            if( visited[to] )continue;
            self(self,to);
            // 部分木のdp1 + 部分木が全白の時
            dp1[now] *= (dp1[to]+1);
        }
        return;
    };
    f1(f1,0);
    // rep(i,n)cout << dp1[i].val() << " ";
    // print();

    // ↑の木dpの結果から各頂点での答えを求める
    vector<mint> ans(n,1);
    visited.assign(n,false);
    ans[0] = dp1[0];
    auto f2 = [&](auto self, ll now, mint par_sum){
        if( visited[now] )return;
        visited[now] = true;
        ans[now] = dp1[now] * par_sum;

        // cout << now << " : " << dp1[now].val() << " " << par_sum.val() << endl;

        ll size = Graph[now].size();
        // 左右からの累積積を持つことで高速化
        vector<mint> r1(size+2,1), r2(size+2,1);
        for(ll i=0;i<size;i++){
            r1[i+1] = r1[i];
            if( !visited[Graph[now][i]] )r1[i+1] *= (dp1[Graph[now][i]] + 1);
        }
        for(ll i=size-1;i>=0;i--){
            r2[i+1] = r2[i+2];
            if( !visited[Graph[now][i]] )r2[i+1] *= (dp1[Graph[now][i]] + 1);
        }

        for(ll i=0;i<size;i++){
            ll to = Graph[now][i];
            if( visited[to] )continue;
            mint n_par_sum = par_sum * r1[i] * r2[i+2] + 1;
            self(self, to, n_par_sum);
        }
        return;
    };
    f2(f2,0,1);

    rep(i,n)print(ans[i].val());
    
    return 0;
}