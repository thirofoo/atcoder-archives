/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc293/submissions/39648111
 * Submitted at: 2023-03-12 00:07:28
 * Problem URL: https://atcoder.jp/contests/abc293/tasks/abc293_e
 * Result: AC
 * Execution Time: 584 ms
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
    
    ll a,x,m; input(a,x,m);
    vector<ll> r(60,0);
    r[0] = a;
    for(ll i=1;i<60;i++)r[i] = (r[i-1]*r[i-1])%m;

    ll root = sqrt(x);
    ll ans = 0,kaidan = 0;
    vector<ll> k(root+1,0);
    k[0] = 1;
    rep(i,root)k[i+1] = (k[i]*a)%m;
    rep(i,root)kaidan = (kaidan+k[i])%m;
    ll cnt = 0;
    while(root*(cnt+1) < x){
        ll tmp = root*cnt;
        ll t = 1;
        rep(i,60){
            if(tmp & (1LL << i)){
                t *= r[i];
                t %= m;
            }
        }
        t = (t*kaidan)%m;
        ans += t;
        ans %= m;
        cnt++;
    }
    ll now = cnt*root;
    while(now < x){
        ll tmp = 1;
        rep(i,60){
            if(now & (1LL << i)){
                tmp *= r[i];
                tmp %= m;
            }
        }
        ans += tmp;
        ans %= m;
        now++;
    }
    print(ans);
    
    return 0;
}