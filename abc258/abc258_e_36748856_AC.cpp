/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/36748856
 * Submitted at: 2022-11-24 12:10:45
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_e
 * Result: AC
 * Execution Time: 385 ms
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
    
    ll n,q,x,total = 0; input(n,q,x);
    vector<ll> w(n);
    rep(i,n){
        input(w[i]);
        total += w[i];
    }

    // d[i][j] : j個目のジャガイモから2^i箱目まで埋めた時の箱のidx
    vector<vector<ll>> d(65,vector<ll>(n,0));
    vector<ll> box(n,0);
    // syakutori
    ll n_total = x/total*n , rest = x%total , right = 0;
    rep(l,n){
        while(true){
            if(rest > 0){
                rest -= w[right%n];
                right++;
                n_total++;
            }
            else break;
        }
        d[0][l] = (n_total+l)%n;
        box[l] = n_total;
        n_total--;
        rest += w[l];
    }
    for(int i=1;i<65;i++){
        rep(j,n)d[i][j] = d[i-1][d[i-1][j]];
    }

    while(q--){
        ll k; input(k); k--;
        ll idx = 0,cnt = 0;
        while(k){
            if(k & 1)idx = d[cnt][idx];
            k >>= 1;
            cnt++;
        }
        print(box[idx]);
    }
    
    return 0;
}