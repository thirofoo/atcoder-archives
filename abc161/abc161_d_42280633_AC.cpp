/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc161/submissions/42280633
 * Submitted at: 2023-06-15 23:55:20
 * Problem URL: https://atcoder.jp/contests/abc161/tasks/abc161_d
 * Result: AC
 * Execution Time: 420 ms
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
    
    ll k; input(k);
    vector<set<ll>> run(13);
    rep(i,9)run[1].insert(i+1);
    for(ll i=2;i<13;i++){
        ll rui = 1;
        for(auto ele:run[i-1]){
            for(ll j=max(0ll,(ele%10)-1);j<=min(9ll,(ele%10)+1);j++){
                run[i].insert(ele*10 + j);
            }
        }
    }
    ll cnt = 1;
    for(auto v:run){
        for(auto ele:v){
            if(cnt == k){
                print(ele);
                return 0;
            }
            cnt++;
        }
    }
    
    return 0;
}