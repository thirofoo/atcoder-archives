/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc153/submissions/38004884
 * Submitted at: 2023-01-14 21:09:21
 * Problem URL: https://atcoder.jp/contests/arc153/tasks/arc153_a
 * Result: AC
 * Execution Time: 6 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
template<class T, class... Ts> void print(const T& a, const Ts&... b) { cout << a;(cout << ... << (cout << ' ', b));cout << '\n'; }
template<class... T> void input(T&... a) { (cin >> ... >> a); }
void print() { cout << '\n'; }
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
    n--;
    vector<ll> ans;
    ll s1 = n/100000 + 1;
    ll s = n%100000;
    rep(i,5){
        ans.push_back(s%10);
        s /= 10;
    }
    cout << s1 << s1 << ans[4] << ans[3] << ans[2] << ans[2] << ans[1] << ans[0] << ans[1] << endl;

    return 0;
}