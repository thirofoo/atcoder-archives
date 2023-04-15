/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc298/submissions/40643986
 * Submitted at: 2023-04-15 21:13:53
 * Problem URL: https://atcoder.jp/contests/abc298/tasks/abc298_c
 * Result: AC
 * Execution Time: 154 ms
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
    
    ll n,q; input(n,q);
    vector<set<ll>> num(200005);
    vector<multiset<ll>> box(200005);
    while(q--){
        ll t; input(t);
        if(t == 1){
            ll i,j; input(i,j);
            num[i].insert(j);
            box[j].insert(i);
        }
        else if(t == 2){
            ll i; input(i);
            for(auto ele:box[i])cout << ele << " ";
            print();
        }
        else{
            ll i; input(i);
            for(auto ele:num[i])cout << ele << " ";
            print();
        }
    }
    
    return 0;
}