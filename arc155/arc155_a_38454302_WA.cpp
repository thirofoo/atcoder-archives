/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc155/submissions/38454302
 * Submitted at: 2023-01-29 21:35:29
 * Problem URL: https://atcoder.jp/contests/arc155/tasks/arc155_a
 * Result: WA
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
    
    ll t; input(t);
    while(t--){
        ll n,k; string s; input(n,k,s);
        k %= n;
        bool f = true;
        ll left = 0,right = n-k-1;
        while(left < right){
            f &= (s[left] == s[right]);
            left++;
            right--;
        }
        left = k,right = n-1;
        while(left < right){
            f &= (s[left] == s[right]);
            left++;
            right--;
        }
        rep(i,k)f &= (s[i] == s[n-k+i]);
        print(f ? "Yes" : "No");
    }
    
    return 0;
}