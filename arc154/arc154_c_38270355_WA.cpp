/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc154/submissions/38270355
 * Submitted at: 2023-01-23 00:33:05
 * Problem URL: https://atcoder.jp/contests/arc154/tasks/arc154_c
 * Result: WA
 * Execution Time: 71 ms
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
    
    ll t; input(t);
    while(t--){
        ll n; input(n);
        vector<ll> a(n),b(n);
        rep(i,n)input(a[i]);
        rep(i,n)input(b[i]);
        rep(i,n)b.push_back(b[i]);

        bool f = false;
        rep(i,n){
            ll si = 0,sj = 0;
            while(si != n && sj != n){
                if(a[si] == b[sj+i])sj++;
                else si++;
            }
            f |= (sj == n);
            if(f)break;
        }
        print(f ? "Yes" : "No");
    }
    
    return 0;
}