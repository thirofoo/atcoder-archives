/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc306/submissions/42362474
 * Submitted at: 2023-06-17 22:31:59
 * Problem URL: https://atcoder.jp/contests/abc306/tasks/abc306_e
 * Result: WA
 * Execution Time: 682 ms
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
    
    ll n,k,q; input(n,k,q);

    ll ans = 0;
    ll k_num = 0;
    fenwick_tree<ll> fw1(2*q+4),fw2(2*q+4);
    fw1.add(1,n);
    
    // 座標圧縮
    vector<ll> x(q),y(q),comp,a(n+1,0);
    comp.push_back(0);
    comp.push_back(-1);
    rep(i,q){
        input(x[i],y[i]);
        comp.push_back(x[i]);
        comp.push_back(y[i]);
    }
    sort(comp.begin(),comp.end());
    comp.erase( unique(comp.begin(),comp.end()), comp.end() );

    rep(i,q){
        // print();
        ll idx1 = lower_bound(comp.begin(),comp.end(),a[x[i]])-comp.begin();
        ll idx2 = lower_bound(comp.begin(),comp.end(),y[i])-comp.begin();

        fw1.add(idx1,-1);
        fw2.add(idx1,-comp[idx1]);
        a[x[i]] = y[i];
        fw1.add(idx2,1);
        fw2.add(idx2,comp[idx2]);

        ll left = 0,right = 2*q+4;
        while(right-left > 1){
            ll mid = (right+left)/2;
            if(fw1.sum(0,mid) <= k-1)left = mid;
            else right = mid;
        }
        // print(left,right);
        // cout << flush;
        // rep(i,2*n+2)cout << fw1.sum(i,i+1) << " ";
        // print();
        // rep(i,2*n+2)cout << fw2.sum(i,i+1) << " ";
        // print();

        ll ans = fw2.sum(left,2*q+4);
        // print(ans);
        ans -= (fw1.sum(left,2*q+4) - k) * comp[left];
        print(ans);
    }
    
    return 0;
}