/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc270/submissions/35118805
 * Submitted at: 2022-09-24 21:46:48
 * Problem URL: https://atcoder.jp/contests/abc270/tasks/abc270_d
 * Result: WA
 * Execution Time: 7 ms
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

ll n,k,ans = 0;
vector<ll> a;
void dfs(int p,int now){
    if(a[0] > now)return;
    auto itr = upper_bound(a.begin(),a.end(),now);
    itr--;

    if(p%2 == 0)ans += *itr;
    dfs(p+1,now-*itr);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    input(n,k);
    a.assign(k,0);
    sort(a.begin(),a.end());
    rep(i,k)input(a[i]);
    dfs(0,n);
    print(ans);
    
    return 0;
}