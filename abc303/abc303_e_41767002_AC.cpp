/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc303/submissions/41767002
 * Submitted at: 2023-05-27 22:20:46
 * Problem URL: https://atcoder.jp/contests/abc303/tasks/abc303_e
 * Result: AC
 * Execution Time: 87 ms
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
    
    ll n; input(n);
    vector<ll> dig(n,0);
    vector<vector<ll>> Graph(n);
    rep(i,n-1){
        ll u,v; input(u,v);
        u--; v--;
        dig[u]++;
        dig[v]++;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }
    vector<ll> ans;
    ll cnt = 0;
    rep(i,n){
        if(dig[i] >= 3){
            ans.push_back(Graph[i].size());
            cnt += Graph[i].size()+1;
            for(auto to:Graph[i]){
                dig[i]--;
                dig[to]--;
            }
        }
    }

    cnt = n-cnt;
    while(cnt > 0){
        cnt -= 3;
        ans.push_back(2);
    }

    sort(ans.begin(),ans.end());
    for(auto a:ans)cout << a << " ";
    
    return 0;
}