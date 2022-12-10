/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc281/submissions/37183258
 * Submitted at: 2022-12-10 22:39:08
 * Problem URL: https://atcoder.jp/contests/abc281/tasks/abc281_e
 * Result: RE
 * Execution Time: 174 ms
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
    set<ll> st;
    fenwick_tree<ll> fw1(2*n),fw2(2*n);
    rep(i,m){
        st.insert(a[i]);
        fw1.add(b[i],a[i]);
        fw2.add(b[i],1);
    }

    ll itr = 0;
    while(true){
        if(fw2.sum(0,itr+1) > k)break;
        itr++;
    }
    print(fw1.sum(0,itr)+(k-fw2.sum(0,itr))*c[fw2.sum(0,itr)]);

    rep(i,n-m){
        fw1.add(b[i],-a[i]);
        fw1.add(b[i+m],a[i+m]);
        fw2.add(b[i],-1);
        fw2.add(b[i+m],1);

        if(fw2.sum(0,itr+1) > k){
            while(true){
                if(fw2.sum(0,itr) <= k)break;
                itr--;
            }
        }
        else{
            while(true){
                if(fw2.sum(0,itr+1) > k)break;
                itr++;
            }
        }
        print(fw1.sum(0,itr)+(k-fw2.sum(0,itr))*c[fw2.sum(0,itr)]);
    }
    
    return 0;
}