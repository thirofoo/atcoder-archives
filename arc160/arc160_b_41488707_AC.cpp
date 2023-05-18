/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc160/submissions/41488707
 * Submitted at: 2023-05-18 11:49:43
 * Problem URL: https://atcoder.jp/contests/arc160/tasks/arc160_b
 * Result: AC
 * Execution Time: 54 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll t; input(t);
    while(t--){
        ll n; input(n);
        // max(x,y,z) <= √n の時 → どんな組もok
        mint ans = (ll)sqrt(n);
        ans *= ans*ans;

        // max(x,y,z) > √n の時 → 最大値は1要素のみ & 他2つは√n以下の整数のいずれか
        mint tmp = 0;
        // 最大値を決めた時の他2つの内の1つを全探索
        for(ll y=1;y<=(ll)sqrt(n);y++){
            // x > y >= z と仮定
            // y < z の時 → (z候補)*(x候補)*3!(並べ方)
            tmp += (n/y - (ll)sqrt(n))*(y-1)*6;
            // y = z の時 → (z候補)*(x候補)*3_C_1(並べ方)
            tmp += (n/y - (ll)sqrt(n))*3;
        }
        ans += tmp;
        print(ans.val());
    }
    
    return 0;
}