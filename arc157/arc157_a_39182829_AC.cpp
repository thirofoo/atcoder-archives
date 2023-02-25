/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc157/submissions/39182829
 * Submitted at: 2023-02-25 21:19:46
 * Problem URL: https://atcoder.jp/contests/arc157/tasks/arc157_a
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll n,a,b,c,d; input(n,a,b,c,d);
    if(n == 1){
        print("Yes");
        return 0;
    }
    if(a == n-1 || d == n-1){
        print("Yes");
        return 0;
    }
    if(abs(b-c) <= 1 && a+d != n-1)print("Yes");
    else print("No");
    
    return 0;
}