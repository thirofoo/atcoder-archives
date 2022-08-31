/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc264/submissions/34474942
 * Submitted at: 2022-08-31 18:28:54
 * Problem URL: https://atcoder.jp/contests/abc264/tasks/abc264_d
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
typedef modint1000000007 mint;
#define rep(i, n) for(ll i = 0; i < n; i++)

ll invNum(vector<ll> a,ll n){
    ll inv = 0;
    fenwick_tree<ll> fw(n+1);
    rep(i,n){
        fw.add(a[i],1);
        inv += fw.sum(a[i]+1,n+1);
    }
    return inv;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string s; cin >> s;
    string a = "atcoder";
    vector<ll> tmp;
    rep(i,7)rep(j,7)if(s[i] == a[j])tmp.push_back(j);

    print(invNum(tmp,7));
    
    return 0;
}