/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc106/submissions/37596610
 * Submitted at: 2022-12-28 17:46:20
 * Problem URL: https://atcoder.jp/contests/arc106/tasks/arc106_c
 * Result: WA
 * Execution Time: 39 ms
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
    if(m < 0)return print(-1),0;

    print(1,1000000000);
    n--;
    ll l = 2,cnt = -1;
    while(n > 0){
        if(cnt == m)break;
        print(l,l+1);
        l += 2;
        cnt++;
        n--;
    }
    ll left = 3,right = 999999999;
    while(n > 0){
        print(left,right);
        n--;
        left += 2;
        right--;
    }

    return 0;
}