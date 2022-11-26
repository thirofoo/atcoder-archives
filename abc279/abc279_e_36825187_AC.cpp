/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc279/submissions/36825187
 * Submitted at: 2022-11-26 22:31:55
 * Problem URL: https://atcoder.jp/contests/abc279/tasks/abc279_e
 * Result: AC
 * Execution Time: 46 ms
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
    vector<ll> a(m),tmp(n);
    rep(i,m){
        input(a[i]);
        a[i]--;
    }
    iota(tmp.begin(),tmp.end(),1);
    for(int i=1;i<m;i++)swap(tmp[a[i]],tmp[a[i]+1]);
    vector<ll> memory(n+1);
    rep(i,n)memory[tmp[i]] = i;

    ll idx = 0;
    vector<ll> base(n);
    iota(base.begin(),base.end(),1);
    rep(i,m){
        // rep(i,n)cout << base[tmp[i]-1] << " ";
        // print();
        print(memory[idx+1]+1);
        if(a[i] == idx)idx = a[i]+1;
        else if(a[i]+1 == idx)idx = a[i];
        // print(base[tmp[i]]);
        if(i != m-1){
            swap(base[a[i]],base[a[i]+1]);
            swap(tmp[memory[a[i+1]+1]],tmp[memory[a[i+1]+2]]);
            swap(memory[a[i+1]+1],memory[a[i+1]+2]);
        }
    }
    // rep(i,n)cout << tmp[i] << " ";
    // print();
    
    return 0;
}