/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc240/submissions/38942164
 * Submitted at: 2023-02-17 18:22:14
 * Problem URL: https://atcoder.jp/contests/abc240/tasks/abc240_f
 * Result: WA
 * Execution Time: 86 ms
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
    
    ll t; input(t);
    while(t--){
        // 候補は高々N個。
        ll n,m; input(n,m);
        vector<ll> rui(n+1,0),ruirui(n+1,0),xx,yy;
        rep(i,n){
            ll x,y; input(x,y);
            xx.emplace_back(x);
            yy.emplace_back(y);
            rui[i+1] = rui[i] + x*y;
            ruirui[i+1] = ruirui[i] + (rui[i]+x)*y + y*(y-1)*x/2;
        }
        ll ans = -LLONG_MAX;
        // 累積和が正の時、後ろの何項目まで単調増加か。
        rep(i,n){
            ans = max(ans,xx[i]);
            if(rui[i] >= 0 && rui[i+1] < 0){
                ll d = xx[i];
                ll tn = rui[i]/abs(xx[i]);
                ll a1 = rui[i]+xx[i];
                ans = max(ans,ruirui[i] + a1*tn + tn*(tn-1)*d/2);
            }
        }
        ans = max(ans,ruirui[n]);
        print(ans);
    }
    
    return 0;
}