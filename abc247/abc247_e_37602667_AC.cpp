/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc247/submissions/37602667
 * Submitted at: 2022-12-28 23:17:08
 * Problem URL: https://atcoder.jp/contests/abc247/tasks/abc247_e
 * Result: AC
 * Execution Time: 28 ms
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
    
    ll n,x,y; input(n,x,y);
    vector<ll> a(n);
    rep(i,n)input(a[i]);

    ll r = 0,ans = 0;

    // [l,r)のx,yのidx
    queue<ll> xi,yi;
    rep(l,n){
        // [l,r)
        for(r;r<n;r++){
            if(r == n || a[r] < y || a[r] > x)break;
            if(a[r] == x)xi.push(r);
            if(a[r] == y)yi.push(r);
        }
        if(xi.empty() || yi.empty()){
            while(!xi.empty())xi.pop();
            while(!yi.empty())yi.pop();
            l = r;
            r = l+1;
            continue;
        }

        ans += r - max(xi.front(),yi.front());

        if(a[l] == y)yi.pop();
        if(a[l] == x)xi.pop();
        if(l == r)r++;
    }
    print(ans);
    
    return 0;
}