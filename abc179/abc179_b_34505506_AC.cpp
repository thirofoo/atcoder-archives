/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc179/submissions/34505506
 * Submitted at: 2022-09-02 14:34:10
 * Problem URL: https://atcoder.jp/contests/abc179/tasks/abc179_b
 * Result: AC
 * Execution Time: 6 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,cnt = 0; input(n);
    bool f = false;
    while(n--){
        ll d1,d2; input(d1,d2);
        if(d1 == d2)cnt++;
        else cnt = 0;
        if(cnt == 3)f = true;
    }
    if(f)print("Yes");
    else print("No");
    
    return 0;
}