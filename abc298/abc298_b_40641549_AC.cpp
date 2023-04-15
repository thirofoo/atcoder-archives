/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc298/submissions/40641549
 * Submitted at: 2023-04-15 21:09:20
 * Problem URL: https://atcoder.jp/contests/abc298/tasks/abc298_b
 * Result: AC
 * Execution Time: 10 ms
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

ll n;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(n);
    vector<vector<ll>> a(n,vector<ll>(n)),b(n,vector<ll>(n));
    rep(i,n)rep(j,n)input(a[i][j]);
    rep(i,n)rep(j,n)input(b[i][j]);

    bool f = true;
    rep(t,4){
        ll nx,ny;
        bool f = true;
        rep(i,n){
            rep(j,n){
                nx = i, ny = j;
                rep(k,t){
                    ll tmp = ny;
                    ny = nx;
                    nx = n-1-tmp;
                }
                if(a[i][j] && !b[nx][ny])f = false;
            }
        }
        if(f){
            print("Yes");
            return 0;
        }
    }
    print("No");

    
    return 0;
}