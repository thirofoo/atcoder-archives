/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc178/submissions/36944558
 * Submitted at: 2022-12-03 18:36:18
 * Problem URL: https://atcoder.jp/contests/abc178/tasks/abc178_d
 * Result: AC
 * Execution Time: 5 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll s; input(s);
    vector<mint> kaizyo(2*s,0);
    kaizyo[0] = 1;
    for(int i=1;i<2*s;i++)kaizyo[i] = kaizyo[i-1]*i;

    mint ans = 0;
    ll border = 0; // 仕切りの個数
    while((border+1)*3 <= s){
        ll rest = s-(border+1)*3;
        ans += kaizyo[rest+border] / kaizyo[border] / kaizyo[rest];
        border++;
    }
    print(ans.val());
    
    return 0;
}