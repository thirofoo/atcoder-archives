/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc271/submissions/35287906
 * Submitted at: 2022-10-01 21:24:26
 * Problem URL: https://atcoder.jp/contests/abc271/tasks/abc271_c
 * Result: AC
 * Execution Time: 216 ms
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
    
    ll n,now = 0; input(n);
    map<ll,ll> mp;
    vector<ll> a;
    rep(i,n){
        ll tmp; input(tmp);
        if(mp[tmp] == 0)a.push_back(tmp);
        mp[tmp]++;
    }
    sort(a.begin(),a.end());
    int size = a.size();
    rep(i,size){
        ll tmp = mp[a[i]]-1;
        while(tmp--)a.push_back(a[i]);
    }

    ll left = 0,right = n;
    while(left < right){
        if(a[left] == now+1){
            now++;
            left++;
        }
        else{
            right -= 2;
            if(left <= right)now++;
        }
    }
    print(now);
    
    return 0;
}