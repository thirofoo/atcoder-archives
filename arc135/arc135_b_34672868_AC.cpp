/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc135/submissions/34672868
 * Submitted at: 2022-09-07 19:54:19
 * Problem URL: https://atcoder.jp/contests/arc135/tasks/arc135_b
 * Result: AC
 * Execution Time: 64 ms
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
    vector<ll> s(n);
    rep(i,n)input(s[i]);
    if(n == 1)return cout << "Yes" << endl << 0 << " " << 0 << " " << s[0] << endl,0;
    ll m1 = 0,m2 = 0,m3 = 0;
    ll now = 0;
    for(ll i=1;i<n;i+=3){
        now += s[i]-s[i-1];
        m1 = min(m1,now);
    }
    now = 0;
    for(ll i=2;i<n;i+=3){
        now += s[i]-s[i-1];
        m2 = min(m2,now);
    }
    now = 0;
    for(ll i=3;i<n;i+=3){
        now += s[i]-s[i-1];
        m3 = min(m3,now);
    }
    if(m1+m2+m3+s[0] < 0)return print("No"),0;
    print("Yes");
    vector<ll> a;
    a.push_back(-m1);
    a.push_back(-m2);
    a.push_back(s[0]+m1+m2);
    for(int i=1;i<n;i++){
        a.push_back(s[i]-s[i-1]+a[i-1]);
    }
    for(auto ele:a)cout << ele << " ";
    print();
    
    return 0;
}