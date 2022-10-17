/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc272/submissions/35742921
 * Submitted at: 2022-10-17 10:42:39
 * Problem URL: https://atcoder.jp/contests/abc272/tasks/abc272_c
 * Result: AC
 * Execution Time: 43 ms
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
    vector<ll> even,odd;
    rep(i,n){
        ll tmp; input(tmp);
        if(tmp%2 == 0)even.push_back(tmp);
        else odd.push_back(tmp);
    }
    sort(even.begin(),even.end(),[](ll a,ll b){
        return a > b;
    });
    sort(odd.begin(),odd.end(),[](ll a,ll b){
        return a > b;
    });
    ll ans = -1;
    if(even.size() >= 2)ans = max(ans,even[0]+even[1]);
    if(odd.size() >= 2)ans = max(ans,odd[0]+odd[1]);
    print(ans);
    
    return 0;
}