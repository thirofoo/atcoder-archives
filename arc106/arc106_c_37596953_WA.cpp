/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc106/submissions/37596953
 * Submitted at: 2022-12-28 18:02:44
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

    ll first = n+1;
    print(first,900000000);
    print(first+1,first+n+2);
    n -= 2;
    ll l = first+n+4,cnt = 0;
    while(n > 0){
        if(cnt == m)break;
        print(l,l+1);
        l += 2;
        cnt++;
        n--;
    }
    ll left = first+2,right = 900000002;
    while(n > 0){
        print(left,right);
        n--;
        left++;
        right++;
    }

    return 0;
}