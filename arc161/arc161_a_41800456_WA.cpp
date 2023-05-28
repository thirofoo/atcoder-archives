/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc161/submissions/41800456
 * Submitted at: 2023-05-28 21:04:36
 * Problem URL: https://atcoder.jp/contests/arc161/tasks/arc161_a
 * Result: WA
 * Execution Time: 42 ms
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
    sort(a.begin(),a.end());
    ll cnt = 0;
    while(cnt < n){
        ll now = a[cnt];
        cnt++;
        while(cnt < n){
            if(a[cnt] == now)cnt++;
            else break;
        }
        if(cnt == n/2 + 1){
            print("Yes");
            return 0;
        }
    }
    print("No");
    
    return 0;
}