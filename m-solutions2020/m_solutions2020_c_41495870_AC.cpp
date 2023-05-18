/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/m-solutions2020/submissions/41495870
 * Submitted at: 2023-05-18 18:55:41
 * Problem URL: https://atcoder.jp/contests/m-solutions2020/tasks/m_solutions2020_c
 * Result: AC
 * Execution Time: 38 ms
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

    for(ll i=k;i<n;i++){
        if(a[i] > a[i-k])print("Yes");
        else print("No");
    }
    
    return 0;
}