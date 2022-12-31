/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc179/submissions/37655329
 * Submitted at: 2022-12-31 17:22:41
 * Problem URL: https://atcoder.jp/contests/abc179/tasks/abc179_e
 * Result: AC
 * Execution Time: 12 ms
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
    
    ll n,x,m; input(n,x,m);
    // time[i] : iに何回目に訪れたか
    // rui[i]  : iに訪れるまでの累積和
    vector<ll> time(m,0),rui(m,0);
    ll cnt = 1;
    time[x] = cnt;
    while(true){
        rui[x] += x;
        n--;
        if(!n)return print(rui[x]),0;

        if(time[(x*x)%m])break;
        cnt++;
        time[(x*x)%m] = cnt;
        rui[(x*x)%m] += rui[x];
        x = (x*x)%m;
    }
    ll ans = rui[x],T = time[x] - time[(x*x)%m] + 1,Tc = rui[x] - rui[(x*x)%m] + (x*x)%m;
    ans += (n/T)*Tc;
    n %= T;
    x = (x*x)%m;
    rep(i,n){
        ans += x;
        x = (x*x)%m;
    }
    print(ans);
    
    return 0;
}