/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/41926542
 * Submitted at: 2023-06-03 15:53:44
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_bh
 * Result: AC
 * Execution Time: 92 ms
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

vector<ll> LIS(vector<ll> a){
    ll n = a.size();
    vector<ll> ans(n,LLONG_MAX);
    vector<ll> res;
    rep(i,n){
        auto itr = lower_bound(ans.begin(),ans.end(),a[i]);
        *itr = a[i];
        res.push_back(lower_bound(ans.begin(),ans.end(),LLONG_MAX)-ans.begin());
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n; input(n);
    vector<ll> a(n);
    rep(i,n)input(a[i]);
    // 境界全探索 → 左右のLIS + 1
    ll ans = 0;
    vector<ll> LIS1 = LIS(a);
    reverse(a.begin(),a.end());
    vector<ll> LIS2 = LIS(a);
    reverse(LIS2.begin(),LIS2.end());
    rep(i,n){
        ll cand = LIS1[i] + LIS2[i] - 1;
        ans = max(ans,cand);
    }
    print(ans);

    return 0;
}