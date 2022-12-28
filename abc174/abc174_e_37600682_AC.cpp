/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc174/submissions/37600682
 * Submitted at: 2022-12-28 21:42:19
 * Problem URL: https://atcoder.jp/contests/abc174/tasks/abc174_e
 * Result: AC
 * Execution Time: 73 ms
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
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    // 長さをmid以下に出来るかを決め打ち二分探索
    ll left = 0,right = 1e9;
    while(right-left > 1){
        ll mid = (right+left)/2;
        ll time = 0;
        rep(i,n)time += (a[i]-1)/mid;
        if(time <= k)right = mid;
        else left = mid;
    }
    print(right);
    
    return 0;
}