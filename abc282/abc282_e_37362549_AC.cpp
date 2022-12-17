/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc282/submissions/37362549
 * Submitted at: 2022-12-17 23:59:26
 * Problem URL: https://atcoder.jp/contests/abc282/tasks/abc282_e
 * Result: AC
 * Execution Time: 92 ms
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
    
    // ×解答
    ll n,m; input(n,m);
    vector<ll> a(n),used(n,0);
    rep(i,n)input(a[i]);
    vector<vector<ll>> rui(n,vector<ll>(70,0));
    rep(i,n){
        rui[i][0] = a[i];
        rep(j,69){
            rui[i][j+1] = rui[i][j]*rui[i][j];
            rui[i][j+1] %= m;
        }
    }

    priority_queue<T> p;
    rep(i,n){
        for(ll j=i+1;j<n;j++){
            ll tmp1 = 1,tmp2 = 1,ele = a[j],cnt = 0;
            while(ele){
                if(ele & 1){
                    tmp1 *= rui[i][cnt];
                    tmp1 %= m;
                }
                cnt++;
                ele = (ele >> 1LL);
            }
            ele = a[i],cnt = 0;
            while(ele){
                if(ele & 1){
                    tmp2 *= rui[j][cnt];
                    tmp2 %= m;
                }
                cnt++;
                ele = (ele >> 1LL);
            }
            p.push(T((tmp1+tmp2)%m,i,j));
            // print(tmp1,tmp2,i,j);
        }
    }

    dsu uf(n);
    ll ans = 0;
    while(!p.empty()){
        auto[tmp,i,j] = p.top(); p.pop();
        // print(tmp,i,j);
        if(uf.same(i,j))continue;
        ans += tmp;
        uf.merge(i,j);
    }
    print(ans);
    
    return 0;
}