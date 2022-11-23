/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc169/submissions/36738872
 * Submitted at: 2022-11-23 20:13:57
 * Problem URL: https://atcoder.jp/contests/abc169/tasks/abc169_e
 * Result: WA
 * Execution Time: 74 ms
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
    
    ll n; input(n);
    vector<P> p1,p2;
    rep(i,n){
        ll a,b; input(a,b);
        p1.push_back(P(a,b));
    }
    p2 = p1;
    sort(p1.begin(),p1.end());
    sort(p2.begin(),p2.end(),[](P a,P b){
        return a.second > b.second;
    });
    if(n%2 == 1)print(p2[n/2].second-p1[n/2].first+1);
    else print((((double)p2[n/2-1].second+p2[n/2].second)/2 - ((double)p1[n/2-1].first+p1[n/2].first)/2)*2+1);
    
    return 0;
}