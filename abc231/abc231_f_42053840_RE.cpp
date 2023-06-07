/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc231/submissions/42053840
 * Submitted at: 2023-06-07 15:44:46
 * Problem URL: https://atcoder.jp/contests/abc231/tasks/abc231_f
 * Result: RE
 * Execution Time: 2206 ms
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
    vector<ll> A,B,comp;
    vector<P> happy;
    rep(i,n){
        ll a; input(a);
        A.push_back(a);
        comp.push_back(a);
    }
    rep(i,n){
        ll b; input(b);
        B.push_back(b);
        comp.push_back(b);
    }
    // 座圧
    sort(comp.begin(),comp.end());
    comp.erase( unique(comp.begin(),comp.end()), comp.end() );
    rep(i,n){
        A[i] = lower_bound(comp.begin(),comp.end(),A[i])-comp.begin();
        B[i] = lower_bound(comp.begin(),comp.end(),B[i])-comp.begin();
    }
    rep(i,n)happy.push_back(P(A[i],B[i]));
    sort(happy.begin(),happy.end(),[](auto a, auto b){
        if(a.first != b.first)return a.first < b.first;
        else return a.second >= b.second;
        // sortは交換則が成り立つものだと無限に繰り返してTLEするっぽい…？
    });

    // 高橋君のプレゼント全探索
    // → sort済だから、今のidxより手前なら高橋君は嫉妬しない
    // → 青木君は 0~idxまでで、idxの嬉しさ以上のものなら嫉妬しない
    ll ans = 0;
    fenwick_tree<ll> fw(2*n+1);
    rep(i,n){
        auto [a,b] = happy[i];
        fw.add(b,1);
        ans += fw.sum(b,2*n+1);
    }
    map<P,ll> mp;
    rep(i,n)mp[happy[i]]++;
    for(auto [key,v]:mp)ans += (v-1)*v/2;
    print(ans);
    
    return 0;
}