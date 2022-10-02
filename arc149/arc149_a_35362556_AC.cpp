/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc149/submissions/35362556
 * Submitted at: 2022-10-03 01:47:16
 * Problem URL: https://atcoder.jp/contests/arc149/tasks/arc149_a
 * Result: AC
 * Execution Time: 35 ms
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
    vector<vector<ll>> mod(n+1,vector<ll>(10,0));
    ll ans1 = -1,ans2 = -1;
    rep(i,n){
        for(int j=1;j<10;j++){
            mod[i+1][j] = (mod[i][j]*10+j)%m;
            if(mod[i+1][j] == 0){
                ans1 = i+1;
                ans2 = j;
            }
        }
    }
    if(ans1 == -1)print(-1);
    else{
        rep(i,ans1)cout << ans2;
        print();
    }
    
    return 0;
}