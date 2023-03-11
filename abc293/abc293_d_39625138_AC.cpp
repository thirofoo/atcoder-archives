/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc293/submissions/39625138
 * Submitted at: 2023-03-11 21:43:42
 * Problem URL: https://atcoder.jp/contests/abc293/tasks/abc293_d
 * Result: AC
 * Execution Time: 67 ms
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
    
    ll n,m; input(n,m);
    vector<bool> used(2*n,false);
    dsu uf(2*n);
    ll ans = 0;
    rep(i,n)uf.merge(i,i+n);
    rep(i,m){
        ll a,c; char bb,dd; input(a,bb,c,dd);
        ll b = (bb == 'R'),d = (dd == 'R');
        a--; c--;
        if(used[a+b*n] || used[c+d*n])continue;
        if(uf.same(a+b*n,c+d*n)){
            ans++;
        }
        else{
            uf.merge(a+b*n,c+d*n);
        }
        used[a+b*n] = true;
        used[c+d*n] = true;
    }
    vector g = uf.groups();
    print(ans,g.size()-ans);
    
    return 0;
}