/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/m-solutions2019/submissions/37610233
 * Submitted at: 2022-12-29 13:51:40
 * Problem URL: https://atcoder.jp/contests/m-solutions2019/tasks/m_solutions2019_d
 * Result: AC
 * Execution Time: 14 ms
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
    vector<vector<ll>> Graph(n);
    vector dig(n,0);
    rep(i,n-1){
        ll a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        dig[a]++;
        dig[b]++;
    }

    ll ans{0};
    vector<ll> p(n);
    rep(i,n){
        input(p[i]);
        ans += p[i];
    }
    sort(p.begin(),p.end());
    reverse(p.begin(),p.end());
    ans -= p[0];
    queue<ll> todo;
    ll dig_max{0},idx{-1};
    rep(i,n){
        if(dig_max < dig[i]){
            dig_max = dig[i];
            idx = i;
        }
    }

    ll ai = 0;
    vector visited(n,-1);
    todo.push(idx);
    while(!todo.empty()){
        ll now = todo.front(); todo.pop();
        if(visited[now] != -1)continue;
        visited[now] = p[ai];
        ai++;
        for(auto to:Graph[now]){
            if(visited[to] == -1)todo.push(to);
        }
    }
    print(ans);
    rep(i,n)cout << visited[i] << " ";
    print();
    
    return 0;
}