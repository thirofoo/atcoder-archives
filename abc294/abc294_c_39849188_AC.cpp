/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc294/submissions/39849188
 * Submitted at: 2023-03-19 21:06:58
 * Problem URL: https://atcoder.jp/contests/abc294/tasks/abc294_c
 * Result: AC
 * Execution Time: 67 ms
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
    vector<ll> st;
    vector<ll> a(n),b(m);
    rep(i,n){
        input(a[i]);
        st.push_back(a[i]);
    }
    rep(i,m){
        input(b[i]);
        st.push_back(b[i]);
    }
    sort(st.begin(),st.end());
    rep(i,n)cout << lower_bound(st.begin(),st.end(),a[i])-st.begin()+1 << " ";
    print();
    rep(i,m)cout << lower_bound(st.begin(),st.end(),b[i])-st.begin()+1 << " ";
    print();
    
    return 0;
}