/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc061/submissions/38850249
 * Submitted at: 2023-02-13 00:31:58
 * Problem URL: https://atcoder.jp/contests/agc061/tasks/agc061_a
 * Result: WA
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

bool is_nCk_odd(int n, int k){
    if(n <= 1)return 1;
    return (n&k)==k;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // shuffle(1,n)のi番目の数 → shuffle(1,n-1)のi-1番目の数+1番目 に移動

    ll t; input(t);
    while(t--){
        ll n,k; input(n,k);
        if(k == 1)print(2);
        else if(n%2 == 0){
            if(is_nCk_odd(n/2-1,(k-1)/2)){
                if(k%2 == 0)print(k-1);
                else print(k+1);
            }
            else{
                print(k);
            }
        }
        else{
            ll p;
            k--;
            if(is_nCk_odd((n-1)/2-1,(k-1)/2)){
                if(k%2 == 0)p = k-1;
                else p = k+1;
                // cout << "odd ";
            }
            else{
                p = k;
                // cout << "even ";
            }
            // cout << p << " ";
            p++;
            // cout << p << " ";
            if((n-1)/2-1 >= (p-1)/2 && is_nCk_odd((n-1)/2-1,(p-1)/2)){
                if(p%2 == 0)print(p-1);
                else print(p+1);
            }
            else{
                print(p);
            }
        }
    }
    
    return 0;
}