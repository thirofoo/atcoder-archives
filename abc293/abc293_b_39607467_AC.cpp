/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc293/submissions/39607467
 * Submitted at: 2023-03-11 21:07:29
 * Problem URL: https://atcoder.jp/contests/abc293/tasks/abc293_b
 * Result: AC
 * Execution Time: 40 ms
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
    vector<ll> cnt(n,0);
    vector<bool> v(n,false);
    rep(i,n){
        ll a; input(a);
        if(v[i])continue;
        cnt[a-1]++;
        v[a-1] = true;
    }
    queue<ll> ans;
    rep(i,n)if(!cnt[i])ans.push(i+1);
    print(ans.size());
    while(!ans.empty()){
        cout << ans.front() << " ";
        ans.pop();
    }
    print();
    
    return 0;
}