/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc157/submissions/39185510
 * Submitted at: 2023-02-25 21:33:38
 * Problem URL: https://atcoder.jp/contests/arc157/tasks/arc157_b
 * Result: WA
 * Execution Time: 10 ms
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
    
    ll n,k; string s; input(n,k,s);
    ll cnt = 0;
    rep(i,n)if(s[i] == 'X')cnt++;
    ll ans = 0;
    if(k <= cnt){
        // xを裏返す
        ll l = 0, r = 0;
        cnt = 0; // 現在のXの数
        while(l < n){
            if(r == n || (cnt == k && s[r] == 'X')){
                if(s[l] == 'X')cnt--;
                ++l;
            }
            else{
                ++r;
                if(s[r] == 'X')cnt++;
            }
            ans = max(ans,r-l-1);
        }
    }
    else{
        k = n-k;
        rep(i,n){
            if(s[i] == 'X')s[i] = 'Y';
            else s[i] = 'X';
        }
        // yを裏返す
        ll l = 0, r = 0;
        cnt = 0; // 現在のXの数
        while(l < n){
            if(r == n || (cnt == k && s[r] == 'Y')){
                if(s[l] == 'Y')cnt--;
                ++l;
            }
            else{
                if(s[r] == 'Y')cnt++;
                ++r;
            }
            ans = max(ans,r-l-1);
        }
    }
    print(ans);
    
    return 0;
}