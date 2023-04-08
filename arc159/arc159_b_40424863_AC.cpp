/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc159/submissions/40424863
 * Submitted at: 2023-04-08 22:41:23
 * Problem URL: https://atcoder.jp/contests/arc159/tasks/arc159_b
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

ll euclid(ll a,ll b){
    if(b != 0)return euclid(b,a%b);
    else return a;
}

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
    
    ll a,b; input(a,b);
    if(a < b)swap(a,b);

    vector<ll> div = divisor(a-b);
    sort(div.begin(),div.end());

    // 最終的には (a-b,0) で終わる
    // → a-b の約数が足す候補っぽい
    // M <= 1e12 で約数の個数の2乗は間に合うらしい。

    ll ans = 0, di = euclid(a,b);
    while(b > 0){
        ll min_d = LLONG_MAX;
        rep(j,div.size()){
            if(div[j] <= di)continue;

            if( (a%div[j])%di == 0 && (a%div[j])/di <= min_d ){
                min_d = (a%div[j])/di;
            }
        }
        if(min_d == LLONG_MAX)break;
        a -= min_d*di;
        b -= min_d*di;
        ans += min_d;
        di = euclid(a,b);
    }
    ans += b/di;
    print(ans);
    
    return 0;
}