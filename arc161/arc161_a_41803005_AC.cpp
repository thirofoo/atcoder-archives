/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc161/submissions/41803005
 * Submitted at: 2023-05-28 21:16:37
 * Problem URL: https://atcoder.jp/contests/arc161/tasks/arc161_a
 * Result: AC
 * Execution Time: 114 ms
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
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    if(n == 1)return print("Yes"),0;

    sort(a.begin(),a.end());
    map<ll,ll> mp;
    rep(i,n)mp[a[i]]++;
    rep(i,n){
        if(i <= n/2 && mp[a[i]] > n/2 + 1){
            print("No");
            return 0;
        }
        if(i > n/2 && mp[a[i]] > n/2){
            print("No");
            return 0;
        }
    }
    print("Yes");
    
    return 0;
}