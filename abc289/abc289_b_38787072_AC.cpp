/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc289/submissions/38787072
 * Submitted at: 2023-02-11 21:09:09
 * Problem URL: https://atcoder.jp/contests/abc289/tasks/abc289_b
 * Result: AC
 * Execution Time: 11 ms
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
    
    ll n,m; input(n,m);
    vector<ll> a(m);
    rep(i,m)input(a[i]);
    rep(i,m)a[i]--;
    if(m == 0){
        rep(i,n)cout << i+1 << " ";
        print();
        return 0;
    }
    vector<ll> ans;
    vector<bool> used(n,false);
    ll re = 0;
    rep(i,n){
        if(used[i])continue;
        ll now = i;
        while(a[re] == now){
            now++;
            re++;
        }
        while(now != i){
            ans.push_back(now+1);
            used[now] = true;
            now--;
        }
        ans.push_back(i+1);
        used[i] = true;
    }
    rep(i,n)cout << ans[i] << " ";
    print(); 
    
    return 0;
}