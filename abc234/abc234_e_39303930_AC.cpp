/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc234/submissions/39303930
 * Submitted at: 2023-02-28 11:29:05
 * Problem URL: https://atcoder.jp/contests/abc234/tasks/abc234_e
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll x; input(x);
    ll dig = 0,tx = x;
    while(tx != 0){
        dig++;
        tx /= 10;
    }
    // print(x,log10(x),(int)(log10(x)+1),(int)log10(x)+1,dig);
    ll ans = LLONG_MAX;
    for(ll i=1;i<=9;i++){
        for(ll d=-9;d<=9;d++){
            // Xと同じ桁の等差数全列挙
            bool f = false;
            ll cand1 = 0;
            rep(j,dig){
                cand1 *= 10;
                if(i+d*j < 0 || 9 < i+d*j){
                    f = true;
                    break;
                }
                cand1 += i+d*j;
            }
            if(!f && cand1 >= x){
                ans = min(ans,cand1);
            }
        }
    }
    print(ans);
    
    return 0;
}