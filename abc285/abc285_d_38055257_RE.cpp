/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc285/submissions/38055257
 * Submitted at: 2023-01-15 21:23:02
 * Problem URL: https://atcoder.jp/contests/abc285/tasks/abc285_d
 * Result: RE
 * Execution Time: 442 ms
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

    vector<string> ss,tt;
    map<string,ll> idx;
    ll now = 0;
    rep(i,n){
        string s,t; input(s,t);
        ss.push_back(s);
        tt.push_back(t);
        if(!idx.count(s)){
            idx[s] = now;
            now++;
        }
        if(!idx.count(t)){
            idx[t] = now;
            now++;
        }
    }

    vector<ll> cnt(2*n,0);
    vector<vector<ll>> Graph(2*n);
    rep(i,n){
        cnt[idx[ss[i]]]++;
        cnt[idx[tt[i]]]++;
        Graph[idx[ss[i]]].push_back(idx[tt[i]]);
        Graph[idx[tt[i]]].push_back(idx[ss[i]]);
    }

    vector<bool> visited(n,false);
    queue<ll> todo;
    rep(i,2*n){
        if(cnt[i] == 0)visited[i] = true;
        else if(cnt[i] == 1) todo.push(i);
    }
    while(!todo.empty()){
        ll here = todo.front(); todo.pop();
        if(visited[here])continue;
        visited[here] = true;

        for(auto to:Graph[here]){
            if(visited[to])continue;
            cnt[to]--;
            if(cnt[to] == 1)todo.push(to);
        }
    }
    bool f = true;
    rep(i,n)f &= visited[i];
    print(f ? "Yes" : "No");
    
    return 0;
}