/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc297/submissions/40508147
 * Submitted at: 2023-04-10 15:00:32
 * Problem URL: https://atcoder.jp/contests/abc297/tasks/abc297_f
 * Result: AC
 * Execution Time: 161 ms
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
    
    ll h,w,k; input(h,w,k);
    ll n = h*w;
    // nCr
    vector<mint> fact(n+1,1);
    vector<mint> r_fact(n+1,1);
    for(int i=1;i<=n;i++){
        fact[i] = fact[i-1]*i;
        r_fact[i] = (mint)1/fact[i];
    }
    auto nCr = [&](ll n,ll r){
        return fact[n] * r_fact[r] * r_fact[n-r];
    };

    // 主客転倒 & 包除原理
    // = (全長方形) - (マスより上下左右にある最小長方形) + (ますより左上・左下・右上・右下にある最小長方形)

    mint ans = 0;
    for(ll i=1;i<=h;i++){
        for(ll j=1;j<=w;j++){
            ans += nCr(h*w,k); // 全部
            
            if(h*(j-1) >= k)ans -= nCr(h*(j-1),k); // 左
            if(h*(w-j) >= k)ans -= nCr(h*(w-j),k); // 右
            if((i-1)*w >= k)ans -= nCr((i-1)*w,k); // 上
            if((h-i)*w >= k)ans -= nCr((h-i)*w,k); // 下

            if((i-1)*(j-1) >= k)ans += nCr((i-1)*(j-1),k); // 左上
            if((h-i)*(j-1) >= k)ans += nCr((h-i)*(j-1),k); // 左下
            if((i-1)*(w-j) >= k)ans += nCr((i-1)*(w-j),k); // 右上
            if((h-i)*(w-j) >= k)ans += nCr((h-i)*(w-j),k); // 右下
        }
    }
    ans /= nCr(h*w,k);
    print(ans.val());
    
    return 0;
}