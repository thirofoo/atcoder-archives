/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc277/submissions/36448553
 * Submitted at: 2022-11-12 22:38:20
 * Problem URL: https://atcoder.jp/contests/abc277/tasks/abc277_d
 * Result: WA
 * Execution Time: 307 ms
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
    
    ll n,m,total = 0; input(n,m);
    map<ll,vector<ll>> mp;
    vector<ll> a(n);
    vector<P> b;
    rep(i,n){
        input(a[i]);
        mp[a[i]%m].push_back(a[i]);
        total += a[i];
    }
    for(auto p:mp){
        ll num = 0,tmp = 0,r = 0;
        sort(mp[p.first].begin(),mp[p.first].end());
        for(auto next:mp[p.first]){
            if(r == next)tmp += next;
            else{
                num = max(num,tmp);
                tmp = next;
                r = next;
            }
        }
        num = max(num,tmp);
        b.push_back(P(p.first,num));
    }
    ll size = b.size();
    rep(i,size)b.push_back(b[i]);
    rep(i,size)b.push_back(b[i]);
    rep(i,size)b.push_back(b[i]);
    rep(i,size)b.push_back(b[i]);
    rep(i,size)b.push_back(b[i]);
    rep(i,size)b.push_back(b[i]);
    rep(i,size)b.push_back(b[i]);
    rep(i,size)b.push_back(b[i]);
    rep(i,size)b.push_back(b[i]);
    rep(i,size)b.push_back(b[i]);
    rep(i,size)b.push_back(b[i]);

    ll ans = -LLONG_MAX,now = -2,tmp = 0;
    rep(i,10*size){
        auto [idx,num] = b[i];
        if(idx == (now+1)%m){
            tmp += num;
            now = idx;
        }
        else{
            ans = max(ans,tmp);
            now = idx;
            tmp = num;
        }
    }
    print(total-ans);
    
    return 0;
}