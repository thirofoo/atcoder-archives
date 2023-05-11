/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc061/submissions/41304680
 * Submitted at: 2023-05-11 18:43:55
 * Problem URL: https://atcoder.jp/contests/abc061/tasks/abc061_b
 * Result: AC
 * Execution Time: 6 ms
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
    vector<ll> cnt(n);
    rep(i,m){
        ll a,b; input(a,b);
        cnt[a-1]++;
        cnt[b-1]++;
    }
    rep(i,n)cout << cnt[i] << " ";
    print();
    
    return 0;
}