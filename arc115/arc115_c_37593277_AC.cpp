/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc115/submissions/37593277
 * Submitted at: 2022-12-28 14:44:19
 * Problem URL: https://atcoder.jp/contests/arc115/tasks/arc115_c
 * Result: AC
 * Execution Time: 200 ms
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

//約数列挙ver(1,nも含む)
vector<ll> divisor(ll n){
    vector<ll> div;
    for(ll i=1;i*i<=n;i++){
        if(n%i)continue;
        div.push_back(i);
        if(i != n/i)div.push_back(n/i);
    }
    return div;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> a(n+1,1);
    for(ll i=2;i<=n;i++){
        vector<ll> pf = divisor(i);
        ll tmp = 1;
        for(auto num:pf){
            tmp = max(tmp,a[num]);
        }
        a[i] = tmp+1;
    }
    rep(i,n)cout << a[i+1] << " ";
    print();
    
    return 0;
}