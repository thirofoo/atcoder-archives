/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc167/submissions/35622297
 * Submitted at: 2022-10-13 18:56:28
 * Problem URL: https://atcoder.jp/contests/abc167/tasks/abc167_d
 * Result: AC
 * Execution Time: 179 ms
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

    ll n,k;
    input(n,k);
    vector<ll> a(n);
    vector<vector<ll>> table(100,vector<ll>(n,0));
    rep(i, n){
        input(a[i]);
        a[i]--;
        table[0][i] = a[i];
    }
    rep(i,99)rep(j,n)table[i+1][j] = table[i][table[i][j]];

    ll now = 0;
    rep(i,64)if(k & (1LL << i))now = table[i][now];
    print(now+1);
    
    return 0;
}