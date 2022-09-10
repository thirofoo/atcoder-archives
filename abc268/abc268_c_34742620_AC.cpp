/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc268/submissions/34742620
 * Submitted at: 2022-09-10 21:35:59
 * Problem URL: https://atcoder.jp/contests/abc268/tasks/abc268_c
 * Result: AC
 * Execution Time: 31 ms
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
    vector<ll> p(n);
    rep(i,n){
        input(p[i]);
        p[i] = ((p[i]-i)%n+n)%n;
    }
    vector<ll> cnt(n,0);
    rep(i,n)cnt[p[i]]++;
    ll tmp = cnt[0]+cnt[1]+cnt[2],ans = tmp;
    rep(i,n){
        tmp -= cnt[i];
        tmp += cnt[(i+3)%n];
        ans = max(ans,tmp);
    }
    print(ans);
    
    return 0;
}