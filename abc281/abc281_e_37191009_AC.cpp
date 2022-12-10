/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc281/submissions/37191009
 * Submitted at: 2022-12-11 00:50:19
 * Problem URL: https://atcoder.jp/contests/abc281/tasks/abc281_e
 * Result: AC
 * Execution Time: 159 ms
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
    
    ll n,m,k; input(n,m,k);
    vector<ll> a(n),comp,b(n),c;

    // 座標圧縮
    rep(i,n){
        input(a[i]);
        comp.push_back(a[i]);
        c.push_back(a[i]);
    }
    sort(comp.begin(),comp.end());
    sort(c.begin(),c.end());
    comp.erase( unique(comp.begin(),comp.end()), comp.end() );
    rep(i,n)b[i] = lower_bound(comp.begin(),comp.end(),a[i])-comp.begin();

    ll ans = 0;
    fenwick_tree<ll> fw1(n),fw2(n);
    rep(i,m){
        fw1.add(b[i],a[i]);
        fw2.add(b[i],1);
    }

    ll left = 0,right = n;
    while(right-left > 1){
        ll mid = (right+left)/2;
        if(fw2.sum(0,mid) <= k)left = mid;
        else right = mid;
    }
    print(fw1.sum(0,left) + (k-fw2.sum(0,left))*comp[left]);

    rep(i,n-m){
        fw1.add(b[i],-a[i]);
        fw1.add(b[i+m],a[i+m]);
        fw2.add(b[i],-1);
        fw2.add(b[i+m],1);

        left = 0,right = n;
        while(right-left > 1){
            ll mid = (right+left)/2;
            if(fw2.sum(0,mid) <= k)left = mid;
            else right = mid;
        }
        // rep(i,n)cout << fw1.sum(i,i+1) << " ";
        // print();
        // rep(i,n)cout << fw2.sum(i,i+1) << " ";
        // print();

        // print("left : ",left);

        // print(fw1.sum(0,left),(k-fw2.sum(0,left))*comp[left]);
        print(fw1.sum(0,left) + (k-fw2.sum(0,left))*comp[left]);
        // print();
    }
    
    return 0;
}
