/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41927782
 * Submitted at: 2023-06-03 16:46:39
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ay
 * Result: AC
 * Execution Time: 286 ms
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
    
    // 半分全列挙
    ll n,k,p; input(n,k,p);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    vector<vector<ll>> v1(n/2+1,vector<ll>{}),v2(n-n/2+1,vector<ll>{});
    rep(i,(1LL << n/2)){
        ll cnt = 0, total = 0;
        rep(j,n/2){
            if(i & (1LL << j)){
                total += a[j];
                cnt++;
            }
        }
        v1[cnt].push_back(total);
    }
    rep(i,(1LL << (n-n/2))){
        ll cnt = 0, total = 0;
        rep(j,(n-n/2)){
            if(i & (1LL << j)){
                total += a[j+n/2];
                cnt++;
            }
        }
        v2[cnt].push_back(total);
    }
    rep(i,n/2+1)sort(v1[i].begin(),v1[i].end());
    rep(i,n-n/2+1)sort(v2[i].begin(),v2[i].end());
    ll ans = 0;
    rep(i,n/2+1){
        if( k-i < 0 || n-n/2 < k-i)continue;
        for(auto ele:v1[i]){
            auto itr = upper_bound(v2[k-i].begin(),v2[k-i].end(),p-ele);
            ans += itr - v2[k-i].begin();
        }
    }
    print(ans);
    
    return 0;
}