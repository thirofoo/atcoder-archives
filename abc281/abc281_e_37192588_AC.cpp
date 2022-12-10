/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc281/submissions/37192588
 * Submitted at: 2022-12-11 02:11:20
 * Problem URL: https://atcoder.jp/contests/abc281/tasks/abc281_e
 * Result: AC
 * Execution Time: 131 ms
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
    
    ll n,m,k; input(n,m,k);
    vector<ll> a(n),b;
    rep(i,n){
		input(a[i]);
		if(i < m)b.push_back(a[i]);
	}
	sort(b.begin(),b.end());

	ll ans = 0;
    multiset<ll> l,r;
	rep(i,m){
		if(i < k){
			l.insert(b[i]);
			ans += b[i];
		}
		else r.insert(b[i]);
	}
	print(ans);

	rep(i,n-m){
		auto itr1 = l.lower_bound(a[i]);
		if(itr1 == l.end())r.erase(r.find(a[i]));
		else {
			ans -= a[i];
			l.erase(l.find(a[i]));
		}
		auto itr2 = l.lower_bound(a[i+m]);
		if(itr2 == l.end())r.insert(a[i+m]);
		else {
			ans += a[i+m];
			l.insert(a[i+m]);
		}
		
		ll size = l.size();
		if(size < k){
			while(size != k){
				ans += *r.begin();
				l.insert(*r.begin());
				r.erase(r.begin());
				size++;
			}
		}
		if(size > k){
			while(size != k){
				auto tmp = l.end(); tmp--;
				ans -= *tmp;
				r.insert(*tmp);
				l.erase(tmp);
				size--;
			}
		}
		print(ans);
	}

    return 0;
}