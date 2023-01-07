/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc284/submissions/37846268
 * Submitted at: 2023-01-07 22:36:08
 * Problem URL: https://atcoder.jp/contests/abc284/tasks/abc284_f
 * Result: WA
 * Execution Time: 66 ms
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
    
    ll n; string t1; input(n,t1);

    vector<ll> cnt(26,0);
    rep(i,2*n)cnt[t1[i]-'a']++;
    rep(i,26)if(cnt[i]%2 == 1)return print("-1"),0;

    rep(i,n/2)swap(t1[n+i],t1[2*n-1-i]);
    vector<int> z = z_algorithm(t1);

    ll ans = 0;
    rep(i,n)if(ans < z[n+i])ans = z[n+i];

    rep(i,n/2)swap(t1[n+i],t1[2*n-1-i]);
    stack<char> st;
    rep(i,n)st.push(t1[ans+i]);
    while(!st.empty()){
        cout << st.top();
        st.pop();
    }
    print();
    print(ans);
    
    return 0;
}