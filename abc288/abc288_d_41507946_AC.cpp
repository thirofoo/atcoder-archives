/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc288/submissions/41507946
 * Submitted at: 2023-05-19 12:45:36
 * Problem URL: https://atcoder.jp/contests/abc288/tasks/abc288_d
 * Result: AC
 * Execution Time: 153 ms
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
    
    ll n,k; input(n,k);
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    vector<vector<ll>> rui(k,vector<ll>(n+1,0));
    rep(i,k){
        rep(j,n){
            rui[i][j+1] = rui[i][j] + (j%k == i ? a[j] : 0);
        }
    }

    ll q; input(q);
    while(q--){
        ll l,r; input(l,r);
        
        // 典型1 : 区間加算は端から貪欲
        // 典型2 : 区間加算は区間幅をKとすると idx%K が一致する場所の総和は不変

        // 今回はそもそも 典型2 より、
        // idx%K が一致する場所の総和が 少なくとも1つ以上不一致 
        // → どう捜査しても無理

        // idx%K が一致する場所の総和が 全て一致
        // → 左端から貪欲に0にするよう区間加算する
        // → idx%K が一致する場所の総和は操作前後で、全て一致することは変わらない
        // → 最後K個に同じ数が並ぶ (良い数列である)

        vector<ll> cand;
        rep(i,k)cand.push_back(rui[i][r]-rui[i][l-1]);
        ll ele = cand[0];
        bool f = true;
        rep(i,k)if(ele != cand[i])f = false;
        print( (f ? "Yes" : "No") );
    }
    
    return 0;
}