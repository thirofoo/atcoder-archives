/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc017/submissions/31333250
 * Submitted at: 2022-04-29 10:48:18
 * Problem URL: https://atcoder.jp/contests/arc017/tasks/arc017_1
 * Result: AC
 * Execution Time: 7 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

//Miller-Rabin法
struct prime_test{
    unsigned int rand() {
        static unsigned int tx = 123456789, ty=362436069, tz=521288629, tw=88675123;
        unsigned int tt = (tx^(tx<<11));
        tx = ty; ty = tz; tz = tw;
        return ( tw=(tw^(tw>>19))^(tt^(tt>>8)) );
    }

    ll mod_pow(ll a,ll b,int mod){
        ll cnt = 1,ans = 1;
        vector<ll> b_mod;
        b_mod.push_back(a%mod);
        while(b >= (1LL << cnt)){
            b_mod.push_back((b_mod[cnt-1]*b_mod[cnt-1])%mod);
            cnt++;
        }
        cnt = 0;
        while(true){
            if(b < (1LL << cnt))break;
            if(b & (1LL << cnt)){
                ans *= b_mod[cnt]; 
                ans %= mod;
            }
            cnt++;
        }
        return ans;
    }

    bool is_prime(ll n){
        if(n == 2)return true;
        if(n == 1 || (n&1) == 0)return false;
        ll tmp  = n-1;
        while(tmp%2 == 0)tmp >>= 1;
        rep(i,100){
            ll a = rand()%(n-1) + 1,d = tmp;
            ll y = mod_pow(a,tmp,n);
            while(d != n-1 && y != 1 && y != n-1){
                y = (y*y)%n; d <<= 1;
            }
            if(y != n-1 && (d&1) == 0)return false;
        }
        return true;
    }
} pt;

int main() {
    ll n; cin >> n;
    if(pt.is_prime(n))cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}