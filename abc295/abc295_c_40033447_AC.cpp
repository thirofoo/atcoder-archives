/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc295/submissions/40033447
 * Submitted at: 2023-03-25 21:16:19
 * Problem URL: https://atcoder.jp/contests/abc295/tasks/abc295_c
 * Result: AC
 * Execution Time: 154 ms
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
    vector<ll> a(n),uni;
    rep(i,n){
        input(a[i]);
        uni.push_back(a[i]);
    }
    sort(uni.begin(),uni.end());
    uni.erase(unique(uni.begin(),uni.end()),uni.end());
    rep(i,n){
        auto itr = lower_bound(uni.begin(),uni.end(),a[i]);
        a[i] = itr-uni.begin();
    }
    vector<ll> cnt(n,0);
    rep(i,n)cnt[a[i]]++;
    ll ans = 0;
    rep(i,n)ans += cnt[i]/2;
    print(ans);
    
    return 0;
}