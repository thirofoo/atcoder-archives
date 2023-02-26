/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc291/submissions/39249898
 * Submitted at: 2023-02-26 21:37:13
 * Problem URL: https://atcoder.jp/contests/abc291/tasks/abc291_e
 * Result: AC
 * Execution Time: 108 ms
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
    vector<vector<ll>> Graph(n);
    vector<ll> dig(n,0);
    rep(i,m){
        ll x,y; input(x,y);
        x--; y--;
        Graph[x].push_back(y);
        dig[y]++;
    }
    vector<ll> ans;
    queue<ll> todo;
    bool f = false;
    rep(i,n)if(dig[i] == 0)todo.push(i);
    if(todo.size() > 1){
        return print("No"),0;
    }
    while(!todo.empty()){
        ll now = todo.front(); todo.pop();
        ans.push_back(now+1);
        ll cnt = 0;
        for(auto to:Graph[now]){
            dig[to]--;
            if(dig[to] == 0){
                todo.push(to);
                cnt++;
            }
        }
        f |= (cnt >= 2);
    }
    if(f || ans.size() != n){
        print("No");
        return 0;
    }
    print("Yes");
    vector<ll> a(n,0);
    rep(i,n)a[ans[i]-1] = i+1;
    rep(i,n)cout << a[i] << " ";
    print();
    
    return 0;
}