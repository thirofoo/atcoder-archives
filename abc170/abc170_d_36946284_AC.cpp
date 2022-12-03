/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc170/submissions/36946284
 * Submitted at: 2022-12-03 20:09:03
 * Problem URL: https://atcoder.jp/contests/abc170/tasks/abc170_d
 * Result: AC
 * Execution Time: 143 ms
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
    set<ll> a,b;
    rep(i,n){
        ll tmp; input(tmp);
        if(a.count(tmp))b.insert(tmp);
        else a.insert(tmp);
    }

    // cnt[i] : i以下でiの約数のものがあるか
    vector<bool>  cnt(1e6+5,false);
    ll ans = a.size()-b.size();
    for(auto ele:a){
        if(!b.count(ele))ans -= cnt[ele];
        for(ll j=ele;j<=1e6;j+=ele)cnt[j] = true;
    }
    print(ans);
    
    return 0;
}