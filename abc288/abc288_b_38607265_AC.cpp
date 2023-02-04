/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc288/submissions/38607265
 * Submitted at: 2023-02-04 21:08:32
 * Problem URL: https://atcoder.jp/contests/abc288/tasks/abc288_b
 * Result: AC
 * Execution Time: 16 ms
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
typedef pair<string, ll> P;
typedef tuple<ll, ll, ll> T;
// typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,k; input(n,k);
    vector<string> s(n),ans;
    rep(i,n){
        input(s[i]);
        if(i < k)ans.push_back(s[i]);
    }
    sort(ans.begin(),ans.end());
    rep(i,k)print(ans[i]);
    
    return 0;
}