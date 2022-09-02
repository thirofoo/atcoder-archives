/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc179/submissions/34507577
 * Submitted at: 2022-09-02 16:41:57
 * Problem URL: https://atcoder.jp/contests/abc179/tasks/abc179_e
 * Result: AC
 * Execution Time: 8 ms
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,x,m,l,r = 0; input(n,x,m);
    vector<ll> c(m+5,0),visited(m+5,0);
    for(ll i=1;i<=n;i++){
        if(visited[x]){
            l = visited[x];
            r = i-1;
            break;
        }
        visited[x] = i;
        c[i] = c[i-1]+x;
        x = (x*x)%m;
        l = i;
    }

    if(r == 0)print(c[l]);
    else{
        //周期T
        ll T = r-l+1;
        print(c[l-1] + (n-l)/T*(c[r]-c[l-1]) + c[l+(n-l)%T]-c[l-1]);
    }
    
    return 0;
}