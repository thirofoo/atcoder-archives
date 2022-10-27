/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc194/submissions/35997253
 * Submitted at: 2022-10-27 19:55:44
 * Problem URL: https://atcoder.jp/contests/abc194/tasks/abc194_e
 * Result: AC
 * Execution Time: 1744 ms
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
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    set<ll> st;
    vector<ll> cnt(n+1,0);
    rep(i,n+1)st.insert(i);
    rep(i,m){
        st.insert(a[i]);
        cnt[a[i]]++;
        st.erase(a[i]);
    }
    ll cand = 0,ans = LLONG_MAX;
    while(cnt[cand])cand++;
    ans = cand;

    ll left = 0,right = m;
    while(right != n){
        cnt[a[left]]--;
        cnt[a[right]]++;
        if(cnt[a[left]] == 0)st.insert(a[left]);
        st.erase(a[right]);
        ans = min(*st.lower_bound(0),ans);
        right++;
        left++;
    }
    print(ans);
    
    return 0;
}