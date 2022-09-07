/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc139/submissions/34671488
 * Submitted at: 2022-09-07 18:21:32
 * Problem URL: https://atcoder.jp/contests/abc139/tasks/abc139_c
 * Result: AC
 * Execution Time: 21 ms
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
    int now = INT_MAX,ans = 0,tmp = 0;
    rep(i,n){
        if(h[i] <= now){
            now = h[i];
            tmp++;
        }
        else{
            now = h[i];
            ans = max(ans,tmp-1);
            tmp = 1;
        }
    }
    print(max(ans,tmp-1));
    
    return 0;
}