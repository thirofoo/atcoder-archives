/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc277/submissions/36432915
 * Submitted at: 2022-11-12 21:48:25
 * Problem URL: https://atcoder.jp/contests/abc277/tasks/abc277_d
 * Result: WA
 * Execution Time: 219 ms
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
    map<int,P> mp;
    vector<int> a(n),b;
    rep(i,n){
        input(a[i]);
        auto [f,num] = mp[a[i]%m];
        if(a[i] == f)mp[a[i]%m].second++;
        else if(a[i] > num*f)mp[a[i]%m] = P(a[i],1);
        total += a[i];
    }
    for(auto p:mp)b.push_back(p.first);
    int size = b.size();
    rep(i,size)b.push_back(b[i]);

    ll ans = -LLONG_MAX,now = -2,tmp = 0;
    rep(i,2*size){
        auto [f,num] = mp[b[i]];
        if(b[i] == (now+1)%m){
            now = b[i];
            tmp += f*num;
        }
        else{
            ans = max(ans,tmp);
            tmp = f*num;
            now = b[i];
        }
    }
    print(total-ans);
    
    return 0;
}