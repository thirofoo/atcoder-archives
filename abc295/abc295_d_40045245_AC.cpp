/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc295/submissions/40045245
 * Submitted at: 2023-03-25 21:50:29
 * Problem URL: https://atcoder.jp/contests/abc295/tasks/abc295_d
 * Result: AC
 * Execution Time: 54 ms
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
    
    string s; input(s);
    ll n = s.size();
    vector<vector<ll>> a(10,vector<ll>(n+1,0));
    rep(i,n)a[s[i]-'0'][i+1]++;
    rep(i,10)rep(j,n){
        a[i][j+1] += a[i][j];
        a[i][j+1] %= 2;
    }
    vector<ll> cnt(2000,0);
    rep(j,n+1){
        ll now = 0;
        rep(i,10){
            now *= 2;
            if(a[i][j])now++;
        }
        cnt[now]++;
    }
    ll ans = 0;
    rep(i,2000)ans += cnt[i]*(cnt[i]-1)/2;
    print(ans);
    
    return 0;
}