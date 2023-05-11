/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc018/submissions/41304732
 * Submitted at: 2023-05-11 18:47:17
 * Problem URL: https://atcoder.jp/contests/abc018/tasks/abc018_1
 * Result: AC
 * Execution Time: 8 ms
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
    
    ll a,b,c; input(a,b,c);
    vector<P> ans;
    ans.push_back(P(a,0));
    ans.push_back(P(b,1));
    ans.push_back(P(c,2));
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    vector<ll> zyuni(3,0);
    zyuni[ans[0].second] = 1;
    zyuni[ans[1].second] = 2;
    zyuni[ans[2].second] = 3;
    rep(i,3)print(zyuni[i]);
    
    return 0;
}