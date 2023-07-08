/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc309/submissions/43358671
 * Submitted at: 2023-07-08 21:25:42
 * Problem URL: https://atcoder.jp/contests/abc309/tasks/abc309_c
 * Result: AC
 * Execution Time: 82 ms
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
    
    ll n,k; input(n,k);
    vector<P> med;
    ll med_num = 0;
    rep(i,n){
        ll a,b; input(a,b);
        med.push_back(P(a,b));
        med_num += b;
    }
    if( med_num <= k ){
        print(1);
        return 0;
    }
    sort(med.begin(), med.end());
    ll ans = 0;
    rep(i,med.size()){
        auto [a,b] = med[i];
        ans = a+1;
        med_num -= b;
        if( med_num <= k )break;
    }
    print(ans);
    
    return 0;
}