/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc165/submissions/36921024
 * Submitted at: 2022-12-02 10:27:12
 * Problem URL: https://atcoder.jp/contests/abc165/tasks/abc165_c
 * Result: AC
 * Execution Time: 24 ms
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
typedef tuple<int, int, int, int> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int n,m,q,ans = 0;
vector<T> edge;
void dfs(int idx,vector<int> v){
    if(idx == n){
        int cand = 0;
        rep(i,q){
            auto [a,b,c,d] = edge[i];
            if(v[b]-v[a] == c)cand += d;
        }
        ans = max(ans,cand);
        return;
    }
    for(int i=(idx == 0 ? 1 : v[idx-1]);i<=m;i++){
        v.push_back(i);
        dfs(idx+1,v);
        v.pop_back();
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // 解説AC
    // => Aは広義単調増加列より　(n+8)_C_8 個(重複組合せ分)存在する。
    // => max 43578 (n = 10) しかない！
    // => Aを全探索可能！(順列(10^10個)より遥かに少ない)
    input(n,m,q);
    rep(i,q){
        int a,b,c,d; input(a,b,c,d); a--; b--;
        edge.push_back(T(a,b,c,d));
    }
    dfs(0,{});
    print(ans);
    
    return 0;
}