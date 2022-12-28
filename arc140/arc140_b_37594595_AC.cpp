/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc140/submissions/37594595
 * Submitted at: 2022-12-28 15:58:19
 * Problem URL: https://atcoder.jp/contests/arc140/tasks/arc140_b
 * Result: AC
 * Execution Time: 15 ms
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
    
    ll n; string s; input(n,s);
    priority_queue<ll> pq;
    ll stock = 0;
    rep(i,n){
        if(s[i] == 'R'){
            ll l = i-1,r = i+1,lc = 0,rc = 0;
            while(l >= 0 && s[l--] == 'A')lc++;
            while(r < n && s[r++] == 'C')rc++;
            if(min(lc,rc) == 1)stock++;
            else pq.push(min(lc,rc));
        }
    }
    ll ans = 0;
    while(!pq.empty()){
        ll t = pq.top(); pq.pop();
        if(!t)continue;
        if(ans%2 == 0){
            if(t == 2)stock++;
            else pq.push(t-1);
        }
        else{
            if(stock != 0){
                stock--;
                pq.push(t);
            }
        }
        ans++;
    }
    print(ans+stock);
    
    return 0;
}