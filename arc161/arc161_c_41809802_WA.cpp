/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc161/submissions/41809802
 * Submitted at: 2023-05-28 22:05:47
 * Problem URL: https://atcoder.jp/contests/arc161/tasks/arc161_c
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

bool f;
string ans;
ll dfs(vector<vector<ll>> &Graph, string &s, ll now, ll pre){
    ll b = 0, w = 0;
    for(auto to:Graph[now]){
        if(to == pre)continue;
        ll tmp = dfs(Graph,s,to,now);
        if(tmp == 1)b++;
        else if(tmp == 0)w++;
    }

    // 葉の時
    if(b == 0 && w == 0)return (s[now] == 'B' ? 1 : 0);

    // 節の時
    if(b && w)f = false;
    ans[now] = (b ? 'B' : 'W');
    return -1;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; input(t);
    while(t--){
        ll n; input(n);
        vector<vector<ll>> Graph(n);
        rep(i,n-1){
            ll a,b; input(a,b);
            a--; b--;
            Graph[a].push_back(b);
            Graph[b].push_back(a);
        }
        string s; input(s);
        f = true;
        ans = "";
        rep(i,n)ans += "-";
        dfs(Graph,s,0,-1);

        vector<ll> dig(n,0);
        rep(i,n){
            if(ans[i] == '-'){
                ans[i] = (s[Graph[i][0]] == 'B' ? 'B' : 'W');
            }
        }
        rep(i,n){
            for(auto to:Graph[i]){
                if(ans[to] == 'B')dig[i]++;
                else dig[i]--;
            }
            if( (dig[i] > 0 && s[i] == 'W') || (dig[i] < 0 && s[i] == 'B') )f = false;
        }
        print( (f ? ans : "-1") );
    }
    
    return 0;
}