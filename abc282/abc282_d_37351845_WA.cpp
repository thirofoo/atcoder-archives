/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc282/submissions/37351845
 * Submitted at: 2022-12-17 22:15:07
 * Problem URL: https://atcoder.jp/contests/abc282/tasks/abc282_d
 * Result: WA
 * Execution Time: 120 ms
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
    
    ll n,m; cin >> n >> m;
    vector<ll> dig(n,0);
    vector<vector<ll>> Graph(n);
    rep(i,m){
        ll a,b; cin >> a >> b;
        a--; b--;
        Graph[a].push_back(b);
        Graph[b].push_back(a);
        dig[a]++;        
        dig[b]++;        
    }

    vector<ll> d(n,-1);
    queue<P> todo;
    ll ans = 0;
    rep(i,n){
        if(d[i] != -1)continue;
        todo.push(P(0,-1));

        vector<ll> ele;
        ll odd = 0,even = 0;

        while(!todo.empty()){
            auto [now,pre] = todo.front(); todo.pop();
            if(d[now] != -1)continue;
            ele.push_back(now);

            if(pre == -1)d[now] = 0;
            else d[now] = (d[pre] + 1)%2;

            if(d[now]%2 == 0)even++;
            else odd++;

            for(auto to:Graph[now]){
                if(to == pre)continue;
                if(d[now] != -1 && d[now] == d[to])return print(0),0;
                if(d[to] == -1)todo.push(P(to,now));
            }
        }

        if(odd == 0 && even == 0){
            ans += n-1;
            continue;
        }

        ll size = ele.size();
        for(auto v:ele){
            // 連結成分内でのokな辺数
            ans += (d[v]%2 == 0 ? odd : even) - dig[v];
            // 連結成分外でのokな辺数
            ans += n-size;
        }
    }

    print(ans/2);
    
    return 0;
}