/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc124/submissions/41495198
 * Submitted at: 2023-05-18 18:25:17
 * Problem URL: https://atcoder.jp/contests/abc124/tasks/abc124_b
 * Result: AC
 * Execution Time: 8 ms
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
    vector<ll> h(n);
    rep(i,n)input(h[i]);
    ll now = 0, ans = 0;
    rep(i,n){
        if(now <= h[i]){
            now = h[i];
            ans++;
        }
    }
    print(ans);
    
    return 0;
}