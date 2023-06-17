/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc306/submissions/42324435
 * Submitted at: 2023-06-17 21:04:29
 * Problem URL: https://atcoder.jp/contests/abc306/tasks/abc306_c
 * Result: AC
 * Execution Time: 45 ms
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
    vector<ll> a(3*n), cnt(n,0), ans;
    rep(i,3*n){
        input(a[i]);
        cnt[a[i]-1]++;
        if(cnt[a[i]-1] == 2){
            ans.push_back(a[i]);
        }
    }
    rep(i,n)cout << ans[i] << " ";
    print();
    
    return 0;
}