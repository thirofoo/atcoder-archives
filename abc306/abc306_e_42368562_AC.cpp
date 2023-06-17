/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc306/submissions/42368562
 * Submitted at: 2023-06-17 23:45:37
 * Problem URL: https://atcoder.jp/contests/abc306/tasks/abc306_e
 * Result: AC
 * Execution Time: 1545 ms
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
    vector<ll> a(n+1);
    multiset<ll> st1, st2;
    rep(i,n){
        if(i < k)st1.insert(0);
        else st2.insert(0);
    }
    ll ans = 0;
    rep(i,q){
        ll x,y; input(x,y);
        if(st1.size() == 0 || *st1.rbegin() < a[x]){
            auto itr = st2.lower_bound(a[x]);
            st2.erase(itr);
            ans -= a[x];
        }
        else{
            auto itr = st1.lower_bound(a[x]);
            st1.erase(itr);
        }
        a[x] = y;
        if(st1.size() == 0 || *st1.rbegin() < a[x]){
            st2.insert(a[x]);
            ans += a[x];
        }
        else{
            st1.insert(a[x]);
        }

        while(st2.size() > k){
            ans -= *st2.begin();
            st1.insert(*st2.begin());
            st2.erase(st2.begin());
        }
        while(st1.size() > n-k){
            ans += *st1.rbegin();
            st2.insert(*st1.rbegin());
            auto tmp = st1.end();
            tmp--;
            st1.erase(tmp);
        }
        print(ans);
        cout << flush;
    }
    
    return 0;
}