/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc269/submissions/34930716
 * Submitted at: 2022-09-17 21:17:15
 * Problem URL: https://atcoder.jp/contests/abc269/tasks/abc269_c
 * Result: AC
 * Execution Time: 15 ms
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
ll x,digit;
void dfs(ll dig,ll now){
    if(dig == digit){
        ans.push_back(now);
        return;
    }

    dfs(dig+1,now);
    if(x & (1LL << dig))dfs(dig+1,now | (1LL << dig));
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(x);
    if(x == 0)return print(0),0;
    digit = log2(x)+2;
    dfs(0,0);
    sort(ans.begin(),ans.end());
    rep(i,ans.size())print(ans[i]);
    
    return 0;
}