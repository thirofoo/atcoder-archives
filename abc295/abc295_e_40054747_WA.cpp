/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc295/submissions/40054747
 * Submitted at: 2023-03-25 22:39:49
 * Problem URL: https://atcoder.jp/contests/abc295/tasks/abc295_e
 * Result: WA
 * Execution Time: 22 ms
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
typedef modint998244353 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m,k; input(n,m,k);
    vector<ll> a(n);

    vector<mint> cnt(m+1,0);
    rep(i,n){
        input(a[i]);
        cnt[a[i]]++;
    }
    mint z_cnt = cnt[0];

    mint ans = 0;
    mint ika = 0;
    for(ll i=1;i<=m;i++){
        ika += cnt[i];

        if(ika.val() > k)continue;
        if(ika.val()+1 > k && cnt[i] == 0)continue;
        if( (ika + z_cnt).val() < k)continue;

        mint t1 = 1, t2 = 1;
        if( (k-ika).val() != 0 ){
            rep(j,( k-ika - (cnt[i] == 0 ? 1 : 0) ).val()){
                t1 *= i;
            }
        }
        if( (z_cnt-(k-ika)).val() != 0 ){
            rep(j,( z_cnt-(k-ika) - (cnt[i] == 0 ? 1 : 0) ).val()){
                t2 *= (m-i+1);
            }
        }

        ans += t1 * t2 * i;

        print( (k-ika).val(),t1.val(), t2.val(), i , " : ",(t1 * t2 * i).val() );
        // print(ans.val());
    }


    mint t3 = 1;
    rep(i,z_cnt.val())t3 *= m;
    print( (ans/t3).val() );
    
    return 0;
}