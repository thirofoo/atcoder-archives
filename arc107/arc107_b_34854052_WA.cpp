/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc107/submissions/34854052
 * Submitted at: 2022-09-14 20:09:04
 * Problem URL: https://atcoder.jp/contests/arc107/tasks/arc107_b
 * Result: WA
 * Execution Time: 13 ms
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
    ll ans = 0;
    //a+bを全探索
    for(ll e=2;e<=2*n;e++){
        ll f = k+e-1;
        if(f < 2 || f > 2*n)continue;
        if(f%2 == 0){
            if(f <= n)ans += f*(e-1);
            else ans += (min(f,2*n-f)) * (min(e-1,2*n-e+1));
        }
        else{
            if(f <= n)ans += f*(e-1);
            else ans += (min(f,2*n-f)) * (min(e-1,2*n-e+1));
        }
    }
    print(ans);
    
    return 0;
}