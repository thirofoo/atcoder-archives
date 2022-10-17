/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc272/submissions/35744844
 * Submitted at: 2022-10-17 12:59:53
 * Problem URL: https://atcoder.jp/contests/abc272/tasks/abc272_e
 * Result: AC
 * Execution Time: 659 ms
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
    
    ll n,m; input(n,m);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    vector<set<ll>> num(m+1);
    rep(i,n){
        // 各値がl回目の操作で条件を満たすかを考える。
        // どんな配列でもaの後半はすぐに条件外に出てしまう。
        // => total 調和級数個分位考えるだけで良くなると目途が立つ。(NlogN個位)

        // left : a[i]が条件を満たし始める時。
        // right : a[i]が条件を満たさなくなる時。
        ll left = (a[i]+(i+1) >= 0 ? 1 : -(   a[i] -   (i+1 - 1))/(i+1));
        ll right = (a[i]+(i+1) > n ? 1 : (n+1 - a[i] + (i+1 - 1))/(i+1));
        left = min(left,m+1);
        right = min(right,m+1);
        for(int j=left;j<right;j++)num[j].insert(a[i]+(i+1)*j);
    }
    rep(i,m){
        ll ans = 0;
        for(auto k:num[i+1]){
            if(ans == k)ans++;
            else break;
        }
        print(ans);
    }
    
    return 0;
}