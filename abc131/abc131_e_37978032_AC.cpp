/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc131/submissions/37978032
 * Submitted at: 2023-01-13 18:50:35
 * Problem URL: https://atcoder.jp/contests/abc131/tasks/abc131_e
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
    
    ll n,k; input(n,k);
    if(k > (n-1)*(n-2)/2)return print(-1),0;
    vector<vector<ll>> Graph(n);
    for(ll i=1;i<n;i++)Graph[0].push_back(i);

    ll rest = (n-1)*(n-2)/2-k;
    for(ll i=1;i<n;i++){
        for(ll j=i+1;j<n;j++){
            if(!rest)break;
            Graph[i].push_back(j);
            rest--;
        }
        if(!rest)break;
    }

    ll m = 0;
    rep(i,n)m += Graph[i].size();
    print(m);
    rep(i,n)for(auto ele:Graph[i])print(i+1,ele+1);
    
    return 0;
}