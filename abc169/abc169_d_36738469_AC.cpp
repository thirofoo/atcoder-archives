/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc169/submissions/36738469
 * Submitted at: 2022-11-23 19:55:20
 * Problem URL: https://atcoder.jp/contests/abc169/tasks/abc169_d
 * Result: AC
 * Execution Time: 19 ms
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

//素因数列挙ver(圧縮ver)
vector<P> factorize(ll n){
    vector<P> pf;
    ll a = n;
    for(ll i=2;i*i<=n;i++){
        ll cnt = 0;
        if(a%i)continue;
        while(a%i == 0){
            cnt++; a /= i;
        }
        pf.push_back(P(i,cnt));
    }
    if(a != 1)pf.push_back(P(a,1));
    return pf;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,ans = 0; input(n);
    vector<P> pf = factorize(n);
    for(auto [num,cnt]:pf){
        ll tmp = 1;
        while(true){
            if(cnt >= tmp){
                cnt -= tmp;
                tmp++;
            }
            else break;
        }
        ans += tmp-1;
    }
    print(ans);

    return 0;
}