/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc240/submissions/38941915
 * Submitted at: 2023-02-17 18:07:30
 * Problem URL: https://atcoder.jp/contests/abc240/tasks/abc240_f
 * Result: WA
 * Execution Time: 91 ms
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
        ll right = 1;
        rep(i,n){
            right = max(right,i+1);
            if(rui[i+1] < 0)continue;
            ll cand = 0;
            while(right <= n && rui[right] >= 0)right++;
            if(right == n+1){
                ans = max(ans,ruirui[n]);
                break;
            }
            else{
                ll d = xx[right-1];
                ll total_n = rui[right-1]/abs(xx[right-1]);
                ll a1 = rui[right-1]+xx[right-1];
                ans = max(ans,ruirui[right-1] + a1*total_n + total_n*(total_n-1)*d/2);
                i = right-1;
            }
        }
        print(ans);
    }
    
    return 0;
}