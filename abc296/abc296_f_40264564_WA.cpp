/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc296/submissions/40264564
 * Submitted at: 2023-04-01 22:39:30
 * Problem URL: https://atcoder.jp/contests/abc296/tasks/abc296_f
 * Result: WA
 * Execution Time: 122 ms
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

    // 同じ数字が複数ない && 偶数ループが奇数個存在 → No(?)
    rep(i,n){
        if(a[i] != b[i]){
            a1.push_back(P(a[i],i));
            b1.push_back(P(b[i],i));
        }
    }
    sort(a1.begin(),a1.end());
    sort(b1.begin(),b1.end());
    dsu uf(2*n+10);
    rep(i,a1.size()){
        auto &&[ele1,idx1] = a1[i];
        auto &&[ele2,idx2] = b1[i];
        uf.merge(idx1,n+idx2);
    }
    vector group = uf.groups(); 
    ll cnt = 0;
    for(auto g:group){
        if(g.size() == 1)continue;
        if(g.size()%4 == 0)cnt++;
    }
    print( cnt%2 == 1 ? "No" : "Yes" );
    
    return 0;
}