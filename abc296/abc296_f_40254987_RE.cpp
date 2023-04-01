/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc296/submissions/40254987
 * Submitted at: 2023-04-01 22:18:09
 * Problem URL: https://atcoder.jp/contests/abc296/tasks/abc296_f
 * Result: RE
 * Execution Time: 152 ms
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
    vector<ll> a(n),b(n),cnt1(n+1,0),cnt2(n+1,0);
    vector<P> a1,b1;
    rep(i,n){
        input(a[i]);
        cnt1[a[i]]++;
    }
    rep(i,n){
        input(b[i]);
        cnt2[b[i]]++;
    }
    if(cnt1 != cnt2)return print("No"),0;
    rep(i,n)if(cnt1[i+1] >= 2)return print("Yes"),0;
    // 1 , 2 , 3
    // 3 , 2 , 1 は無理

    // 1 , 2 , 3
    // 3 , 1 , 2 はいける

    // 同じ数字が複数ない && 偶数ループが存在
    rep(i,n){
        if(a[i] != b[i]){
            a1.push_back(P(a[i],i));
            b1.push_back(P(b[i],i));
        }
    }
    sort(a1.begin(),a1.end());
    sort(b1.begin(),b1.end());
    dsu uf(2*n);
    rep(i,n){
        uf.merge(i,n+i);
        auto &&[ele1,idx1] = a1[i];
        auto &&[ele2,idx2] = b1[i];
        uf.merge(idx1,n+idx2);
    }
    vector group = uf.groups(); 
    for(auto g:group){
        if(g.size()%4 == 0)return print("No"),0;
    }
    print("Yes");
    
    return 0;
}