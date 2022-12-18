/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc157/submissions/37380590
 * Submitted at: 2022-12-18 22:42:35
 * Problem URL: https://atcoder.jp/contests/abc157/tasks/abc157_e
 * Result: AC
 * Execution Time: 460 ms
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

//セグ木状に乗せる型。
using S = struct{
    array<int,26> cnt;
    int num;
};

S op(S a,S b){
    auto [cnt1,num1] = a;
    auto [cnt2,num2] = b;
    array<int,26> cnt;
    int num = 0;
    rep(i,26){
        cnt[i] = cnt1[i] + cnt2[i];
        if(cnt[i])num++;
    }
    return S{cnt,num};
}

S e(){
    array<int,26> cnt;
    rep(i,26)cnt[i] = 0;
    int num = 0;
    return S{cnt,num};
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,q; string s; input(n,s,q);
    segtree<S,op,e> sg(n);
    array<int,26> tmp;
    rep(i,26)tmp[i] = 0;

    rep(i,n){
        tmp[s[i]-'a']++;
        sg.set(i,S{tmp,1});
        tmp[s[i]-'a']--;
    }

    while(q--){
        ll t; input(t);
        if(t == 1){
            ll i; char c; input(i,c); i--;
            s[i] = c;
            tmp[s[i]-'a']++;
            sg.set(i,S{tmp,1});
            tmp[s[i]-'a']--;
        }
        else{
            ll l,r; input(l,r);
            print(sg.prod(l-1,r).num);
        }
    }
    
    return 0;
}