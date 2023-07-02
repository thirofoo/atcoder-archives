/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc163/submissions/43194005
 * Submitted at: 2023-07-02 21:54:54
 * Problem URL: https://atcoder.jp/contests/arc163/tasks/arc163_b
 * Result: WA
 * Execution Time: 46 ms
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
    
    ll n,m; input(n,m);
    vector<ll> a;
    ll a1, a2;
    rep(i,n){
        ll ele; input(ele);
        if(i == 0)a1 = ele;
        else if(i == 1)a2 = ele;
        a.push_back(ele);
    }
    sort(a.begin(), a.end());

    ll cnt = 0;
    rep(i,n)if( a1 <= a[i] && a[i] <= a2 )cnt++;
    if( cnt >= m+2 ){
        print(0);
        return 0;
    }
    
    ll left = 0, right = m+1, ans = LLONG_MAX;
    while(true){
        if(right == n)break;
        ans = min(ans,abs(a1-a[left])+abs(a2-a[right]));
        left++; right++;
    }
    print(ans);
    
    return 0;
}