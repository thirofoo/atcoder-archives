/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc150/submissions/37459135
 * Submitted at: 2022-12-23 19:47:23
 * Problem URL: https://atcoder.jp/contests/abc150/tasks/abc150_d
 * Result: AC
 * Execution Time: 33 ms
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

ll euclid(ll a,ll b){
	if(b != 0)return euclid(b,a%b);
	else return a;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m; input(n,m);
	vector<ll> a(n);
	rep(i,n){
		input(a[i]);
		a[i] /= 2;
	}
	ll lcm = a[0];
	rep(i,n)lcm = lcm * a[i] / euclid(lcm,a[i]);
	rep(i,n)if((lcm/a[i])%2 == 0)return print(0),0;
	print((m/lcm + 1)/2); // lcm * 奇数倍 毎に題意を満たす数学が来る為 ~+1)/2
    
    return 0;
}