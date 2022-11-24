/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc137/submissions/36751689
 * Submitted at: 2022-11-24 15:56:14
 * Problem URL: https://atcoder.jp/contests/abc137/tasks/abc137_d
 * Result: AC
 * Execution Time: 35 ms
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
    
    ll n,m; input(n,m);
    vector<vector<ll>> work(1e5+5,vector<ll>{});
    rep(i,n){
        ll a,b; input(a,b);
        work[a].push_back(b);
    }

    // 残りi日残ってる中での一番稼げるバイトを貪欲
    priority_queue<ll> todo;
    ll ans = 0;
    for(int i=1;i<=m;i++){
        for(auto money:work[i])todo.push(money);
        if(!todo.empty()){
            ans += todo.top();
            todo.pop();
        }
    }
    print(ans);
    
    return 0;
}