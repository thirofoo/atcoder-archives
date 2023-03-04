/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc292/submissions/39414716
 * Submitted at: 2023-03-04 21:09:56
 * Problem URL: https://atcoder.jp/contests/abc292/tasks/abc292_c
 * Result: AC
 * Execution Time: 982 ms
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
    
    ll n; input(n);
    ll ans = 0;
    for(ll cd=1;cd<n;cd++){
        vector<P> pf1 = factorize(cd),pf2 = factorize(n-cd);
        ll t1 = 1,t2 = 1;
        for(auto [num,c]:pf1)t1 *= c+1;
        for(auto [num,c]:pf2)t2 *= c+1;
        ans += t1*t2;
    }
    print(ans);
    
    return 0;
}