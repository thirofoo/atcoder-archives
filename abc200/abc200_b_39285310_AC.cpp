/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc200/submissions/39285310
 * Submitted at: 2023-02-27 14:32:41
 * Problem URL: https://atcoder.jp/contests/abc200/tasks/abc200_b
 * Result: AC
 * Execution Time: 16 ms
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
    rep(i,k){
        if(n%200 == 0){
            n /= 200;
        }
        else{
            n = n*1000 + 200;
        }
    }
    print(n);
    
    return 0;
}