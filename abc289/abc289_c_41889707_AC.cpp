/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc289/submissions/41889707
 * Submitted at: 2023-06-01 19:02:30
 * Problem URL: https://atcoder.jp/contests/abc289/tasks/abc289_c
 * Result: AC
 * Execution Time: 7 ms
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
    
    ll n,m; input(n,m);
    vector<vector<ll>> a;
    rep(i,m){
        ll c; input(c);
        vector<ll> tmp(c);
        rep(j,c)input(tmp[j]);
        a.push_back(tmp);
    }
    ll ans = 0;
    rep(i,(1LL << m)){
        set<ll> st;
        rep(j,m){
            if(i & (1LL << j)){
                for(auto ele:a[j]){
                    st.insert(ele);
                }
            }
        }
        if(st.size() == n)ans++;
    }
    print(ans);
    
    return 0;
}