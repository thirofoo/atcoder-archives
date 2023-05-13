/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc301/submissions/41348720
 * Submitted at: 2023-05-13 21:05:08
 * Problem URL: https://atcoder.jp/contests/abc301/tasks/abc301_b
 * Result: AC
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
    
    ll n; input(n);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    cout << a[0] << " ";
    rep(i,n-1){
        if(a[i] < a[i+1]){
            for(ll j=a[i]+1;j<=a[i+1];j++)cout << j << " ";
        }
        if(a[i] > a[i+1]){
            for(ll j=a[i]-1;j>=a[i+1];j--)cout << j << " ";
        }
    }
    print();
    
    return 0;
}