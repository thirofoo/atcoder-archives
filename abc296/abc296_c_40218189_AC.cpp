/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc296/submissions/40218189
 * Submitted at: 2023-04-01 21:09:28
 * Problem URL: https://atcoder.jp/contests/abc296/tasks/abc296_c
 * Result: AC
 * Execution Time: 46 ms
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
    
    ll n,x; input(n,x);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    sort(a.begin(),a.end());

    bool ans = false;
    ll l = 0, r = 0;
    while(l < n){
        if(r == n || a[r]-a[l] > x){
            ++l;
        }
        else{
            if(a[r]-a[l] == x)ans = true;
            ++r;
        }
    }
    print( (ans ? "Yes" : "No") );
    
    return 0;
}