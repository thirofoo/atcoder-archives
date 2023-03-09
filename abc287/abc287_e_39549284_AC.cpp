/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc287/submissions/39549284
 * Submitted at: 2023-03-09 12:49:28
 * Problem URL: https://atcoder.jp/contests/abc287/tasks/abc287_e
 * Result: AC
 * Execution Time: 185 ms
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

vector<ll> ans;
vector<string> s;
void dfs(const vector<ll> &idx,ll k){
    vector n_idx(26,vector<ll>{});
    for(auto i:idx){
        if(s[i].size() == k)ans[i] = k;
        else{
            n_idx[s[i][k]-'a'].emplace_back(i);
        }
    }
    rep(i,26){
        if(n_idx[i].size() <= 1){
            for(auto i:n_idx[i])ans[i] = k;
        }
        else dfs(n_idx[i],k+1);
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    rep(i,n){
        string tmp; input(tmp);
        s.emplace_back(tmp);
    }
    vector<ll> idx(n);
    iota(idx.begin(),idx.end(),0);
    ans.assign(n,0);
    dfs(idx,0);
    rep(i,n)print(ans[i]);
    
    return 0;
}