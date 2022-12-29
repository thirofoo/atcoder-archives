/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc024/submissions/37609344
 * Submitted at: 2022-12-29 12:37:57
 * Problem URL: https://atcoder.jp/contests/agc024/tasks/agc024_b
 * Result: AC
 * Execution Time: 29 ms
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
    vector<ll> p(n),idx(n);
    rep(i,n){
        input(p[i]);
        idx[p[i]-1] = i;
    }
    ll ans = -1,now = -1,cand = 0;
    rep(i,n){
        if(now < idx[i]){
            now = idx[i];
            cand++;
        }
        else{
            ans = max(cand,ans);
            cand = 1;
            now = idx[i];
        }
    }
    ans = max(cand,ans);
    print(n-ans);
    
    return 0;
}