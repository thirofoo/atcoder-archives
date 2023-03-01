/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc240/submissions/39327974
 * Submitted at: 2023-03-01 14:09:24
 * Problem URL: https://atcoder.jp/contests/abc240/tasks/abc240_f
 * Result: WA
 * Execution Time: 80 ms
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
        ll n,m; input(n,m);
        vector<P> a;
        vector<ll> b(n+1,0),c(n+1,0);
        rep(i,n){
            ll x,y; input(x,y);
            a.push_back(P(x,y));
            b[i+1] = b[i] + x*y;
            c[i+1] = c[i] + (b[i+1] + b[i]+x)*y/2;
        }
        ll ans = b[0];
        rep(i,n){
            // b[i] == 0 を含めると 1項も無い時の総和(0) を考慮してしまう
            // → 本来の答えが負の時に0を取ってしまう
            if(b[i] > 0 && b[i+1] < 0){
                if(a[i].first == 0)ans = max(ans,c[i+1]);
                else{
                    ll x = b[i]/abs(a[i].first);
                    ll add = ( b[i]+a[i].first + b[i]+a[i].first*x )*x/2;
                    ans = max(ans,c[i] + add);
                }
            }
        }
        // 最後のbが正の時の処理
        ans = max(ans,c.back());
        print(ans);
    }
    
    return 0;
}