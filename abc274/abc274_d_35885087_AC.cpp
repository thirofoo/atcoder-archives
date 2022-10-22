/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc274/submissions/35885087
 * Submitted at: 2022-10-22 21:49:30
 * Problem URL: https://atcoder.jp/contests/abc274/tasks/abc274_d
 * Result: AC
 * Execution Time: 68 ms
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
    
    ll n,x,y; input(n,x,y);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    vector<vector<bool>> dpx(n+1,vector<bool>(30000,false)),dpy(n+1,vector<bool>(30000,false));
    dpx[1][15000+a[0]] = true;
    dpy[0][15000] = true;
    ll cx = 1,cy = 0;
    for(int i=1;i<n;i++){
        if(i%2 == 0)cx++;
        else cy++;
        rep(j,30000){
            if(i%2 == 0){
                if(!dpx[cx-1][j])continue;
                dpx[cx][j-a[i]] = true;
                dpx[cx][j+a[i]] = true;
            }   
            else{
                if(!dpy[cy-1][j])continue;
                dpy[cy][j-a[i]] = true;
                dpy[cy][j+a[i]] = true;
            }
        }
    }
    print( (dpx[cx][15000+x] && dpy[cy][15000+y] ? "Yes" : "No") );
    
    return 0;
}