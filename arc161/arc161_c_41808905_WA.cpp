/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc161/submissions/41808905
 * Submitted at: 2023-05-28 21:58:25
 * Problem URL: https://atcoder.jp/contests/arc161/tasks/arc161_c
 * Result: WA
 * Execution Time: 99 ms
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
        rep(i,n){
            if(ans[i] == '-'){
                ans[i] = (s[Graph[i][0]] == 'B' ? 'B' : 'W');
            }
        }
        print( (f ? ans : "-1") );
    }
    
    return 0;
}