/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc225/submissions/43405685
 * Submitted at: 2023-07-09 12:38:38
 * Problem URL: https://atcoder.jp/contests/abc225/tasks/abc225_e
 * Result: AC
 * Execution Time: 137 ms
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
typedef pair<ld, ld> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    
    ll n; input(n);
    vector<P> angle;
    rep(i,n){
        ld x, y; input(x,y);
        angle.push_back( P( atan2l( (y-1), x ), atan2l( y, (x-1) ) ) );
    }
    sort( angle.begin(), angle.end(), [](P &p1, P &p2){
        return p1.second < p2.second;
    } );
    ld now = 0.0;
    ll ans = 0;
    rep(i,n){
        auto [bottom, top] = angle[i];
        if( now <= bottom ){
            now = top;
            ans++;
        }
    }
    print(ans);
    
    return 0;
}