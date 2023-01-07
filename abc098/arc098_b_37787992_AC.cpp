/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc098/submissions/37787992
 * Submitted at: 2023-01-07 19:19:25
 * Problem URL: https://atcoder.jp/contests/abc098/tasks/arc098_b
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
    
    // 解説AC 
    // 各位のbitが高々1個以下の時与式が成り立つ
    // => 単調性あり(あるところを堺に出来なくなる)

    // A+B = A∧B + A^B から A∧B = 0 の時行けるなってなるのが天才の思考

    ll n; input(n);
    vector<ll> r1(n+1,0),r2(n+1,0);
    rep(i,n){
        input(r1[i+1]);
        r2[i+1] = r1[i+1];
        r1[i+1] += r1[i];
        r2[i+1] ^= r2[i];
    }

    ll ans = 0;
    rep(i,n){
        ll left = i+1,right = n+1;
        while(right-left > 1){
            ll mid = (right+left)/2;
            ll t1 = r1[mid]-r1[i],t2 = r2[mid]^r2[i];
            if(t1 == t2)left = mid;
            else right = mid;
        }
        ans += left-i;
    }
    print(ans);
    
    return 0;
}