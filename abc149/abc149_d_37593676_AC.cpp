/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc149/submissions/37593676
 * Submitted at: 2022-12-28 15:10:44
 * Problem URL: https://atcoder.jp/contests/abc149/tasks/abc149_d
 * Result: AC
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
    
    ll n,k,r,s,p; input(n,k,r,s,p);
    string t; input(t);
    ll ans = 0;
    vector<char> h(n);
    rep(i,n){
        if(i-k < 0){
            if(t[i] == 'r'){
                ans += p;
                h[i] = 'p';
            }
            if(t[i] == 's'){
                ans += r;
                h[i] = 'r';
            }
            if(t[i] == 'p'){
                ans += s;
                h[i] = 's';
            }
        }
        else{
            if(t[i] == 'r'){
                if(h[i-k] == 'p'){
                    if(i+k < n && t[i+k] == 's')h[i] = 's';
                    else h[i] = 'r';
                }
                else{
                    ans += p;
                    h[i] = 'p';
                }
            }
            else if(t[i] == 's'){
                if(h[i-k] == 'r'){
                    if(i+k < n && t[i+k] == 'p')h[i] = 'p';
                    else h[i] = 's';
                }
                else{
                    ans += r;
                    h[i] = 'r';
                }
            }
            else {
                if(h[i-k] == 's'){
                    if(i+k < n && t[i+k] == 'r')h[i] = 'r';
                    else h[i] = 'p';
                }
                else{
                    ans += s;
                    h[i] = 's';
                }
            }
        }
    }
    // rep(i,n)cout << h[i] << " ";
    // print();
    print(ans);
    
    return 0;
}