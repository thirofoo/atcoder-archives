/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc175/submissions/36748967
 * Submitted at: 2022-11-24 12:21:58
 * Problem URL: https://atcoder.jp/contests/abc175/tasks/abc175_b
 * Result: AC
 * Execution Time: 6 ms
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
    vector<ll> l(n);
    rep(i,n)input(l[i]);
    sort(l.begin(),l.end());
    ll ans = 0;
    rep(i,n){
        for(int j=i+1;j<n;j++){
            if(l[i] == l[j])continue;
            for(int k=j+1;k<n;k++){
                if(l[i] == l[k] || l[j] == l[k])continue;
                if(l[k] < l[i]+l[j])ans++;
            }
        }
    }
    print(ans);
    
    return 0;
}