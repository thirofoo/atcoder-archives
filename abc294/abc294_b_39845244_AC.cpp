/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc294/submissions/39845244
 * Submitted at: 2023-03-19 21:03:32
 * Problem URL: https://atcoder.jp/contests/abc294/tasks/abc294_b
 * Result: AC
 * Execution Time: 5 ms
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
    
    ll h,w; input(h,w);
    vector<vector<ll>> a(h,vector<ll>(w));
    rep(i,h)rep(j,w)input(a[i][j]);
    rep(i,h){
        string ans = "";
        rep(j,w){
            if(a[i][j] == 0)ans += '.';
            else ans += 'A'+a[i][j]-1;
        }
        print(ans);
    }
    
    return 0;
}