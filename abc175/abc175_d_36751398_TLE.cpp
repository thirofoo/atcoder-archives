/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc175/submissions/36751398
 * Submitted at: 2022-11-24 15:37:37
 * Problem URL: https://atcoder.jp/contests/abc175/tasks/abc175_d
 * Result: TLE
 * Execution Time: 3308 ms
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
    vector<ll> p(n),c(n);
    rep(i,n){
        input(p[i]);
        p[i]--;
    }
    rep(i,n)input(c[i]);

    ll ans = -LLONG_MAX;
    rep(i,n){
        ans = max(ans,c[i]);

        ll now = p[i],cycle_sum = c[i],T = 1;
        while(now != i){
            cycle_sum += c[now];
            now = p[now];
            T++;
        }

        // 周期ラスト一週分だけ全探索
        ll cnt = 1,rest_total = 0;
        now = p[i];
        while(k >= cnt){
            rest_total += c[now];
            ans = max(ans,max(0LL,cycle_sum)*((k-cnt)/T)+rest_total);
            now = p[now];
            cnt++;
        }
    }
    print(ans);
    
    return 0;
}