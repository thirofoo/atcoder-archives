/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc179/submissions/35629157
 * Submitted at: 2022-10-14 01:18:40
 * Problem URL: https://atcoder.jp/contests/abc179/tasks/abc179_e
 * Result: AC
 * Execution Time: 249 ms
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
    
    ll n,x,m; input(n,x,m);
    // table[i][j] : 初項i から2^j項の区間和
    // next [i][j] : 初項i から2^j先の項
    vector<vector<ll>> table(m,vector<ll>(50,0)),next(m,vector<ll>(50,0));
    rep(i,m)table[i][0] = i;
    rep(i,m)next[i][0] = (i*i)%m;

    rep(i,49){
        rep(j,m){
            next[j][i+1] = next[next[j][i]][i];
            table[j][i+1] = table[j][i] + table[next[j][i]][i];
        }
    }
    ll ans = 0,now = x;
    rep(i,50){
        if(n & (1LL << i)){
            ans += table[now%m][i];
            now = next[now%m][i];
        }
    }
    print(ans);
    
    return 0;
}