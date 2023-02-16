/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/agc020/submissions/38921392
 * Submitted at: 2023-02-16 16:47:02
 * Problem URL: https://atcoder.jp/contests/agc020/tasks/agc020_c
 * Result: RE
 * Execution Time: 295 ms
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
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    // bitset64倍高速化
    ull n,sum = 0; input(n);
    vector<ull> a(n);
    rep(i,n){
        input(a[i]);
        sum += a[i];
    }
    vector<ull> dp1(sum/64+3,0),dp2(sum/64+3,0);
    dp1[0] = 1;
    rep(i,n){
        rep(j,sum/64+1){
            dp2[j] |= dp1[j];
            ull shift = a[i]%64;
            ull nj = j + a[i]/64;
            dp2[nj] |= (dp1[j] << shift);
            dp2[nj+1] |= (dp1[j] >> (64-shift));
        }
        swap(dp2,dp1);
    }

    ull ans;
    for(ull i=sum/2;i<=sum;i++){
        ull shift = i%64;
        ull next = i/64;
        if(dp1[next] & (1ULL << shift)){
            ans = i;
            break;
        }
    }
    print(ans);
    
    return 0;
}