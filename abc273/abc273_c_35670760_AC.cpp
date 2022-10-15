/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc273/submissions/35670760
 * Submitted at: 2022-10-15 21:15:06
 * Problem URL: https://atcoder.jp/contests/abc273/tasks/abc273_c
 * Result: AC
 * Execution Time: 164 ms
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
    
    ll n; input(n);
    vector<ll> a,b(n),ans(n,0);
    set<ll> st;
    rep(i,n){
        ll tmp; input(tmp);
        b[i] = tmp;
        if(!st.count(tmp)){
            st.insert(tmp);
            a.push_back(tmp);
        }
    }
    sort(a.begin(),a.end());
    rep(i,n){
        auto itr = upper_bound(a.begin(),a.end(),b[i]);
        ans[a.end()-itr]++;
    }
    rep(i,n)print(ans[i]);
    
    return 0;
}