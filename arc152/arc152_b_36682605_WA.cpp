/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc152/submissions/36682605
 * Submitted at: 2022-11-20 22:53:15
 * Problem URL: https://atcoder.jp/contests/arc152/tasks/arc152_b
 * Result: WA
 * Execution Time: 44 ms
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
    
    ll n,l; input(n,l);
    vector<ll> a(n+2,0),b,c;
    rep(i,n)input(a[i+1]);
    a[n+1] = l;
    rep(i,n+1)b.push_back((a[i+1]-a[i])*(i == 0 || i == n ? 2 : 1));
    for(int i=n-1;i>0;i--)b.push_back(b[i]);
    c = b;
    c.push_back(b.front());
    c.erase(c.begin());

    int s1 = b.size();
    rep(i,s1)b.push_back(b[i]);

    ll ans = 0,t = LLONG_MAX,total = 0;
    for(auto g:b){
        total += g;
        if(abs(total - (2*l-total)) < t){
            t = abs(total - (2*l-total));
            ans = 2*l + t;
        }
    }
    print(ans);
    
    return 0;
}