/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc276/submissions/36227995
 * Submitted at: 2022-11-05 21:05:29
 * Problem URL: https://atcoder.jp/contests/abc276/tasks/abc276_b
 * Result: AC
 * Execution Time: 67 ms
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
    vector<vector<ll>> Graph(n+1);
    rep(i,m){
        ll a,b; input(a,b);
        Graph[a].push_back(b);
        Graph[b].push_back(a);
    }
    rep(i,n){
        cout << Graph[i+1].size() << " ";
        sort(Graph[i+1].begin(),Graph[i+1].end());
        for(auto to:Graph[i+1])cout << to << " ";
        print();
    }
    
    return 0;
}