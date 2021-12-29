/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/28218592
 * Submitted at: 2021-12-29 17:32:01
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_a
 * Result: AC
 * Execution Time: 45 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
  #include <atcoder/all>
using namespace atcoder;
#endif
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,l,k; cin >> n >> l >> k;
    vector<ll> cut(n);
    rep(i,n)cin >> cut[i];
    ll le = 0,r = cut[n-1];
    while(r-le > 1){
    	ll mid = (r+le)/2,count = 0,tmp = 0;		
 	   	for(int i=0;i<n;i++){
			if(count == k)break;
			if(cut[i]-tmp >= mid){
				count++;
				tmp = cut[i];
			}
    	}
		if(count == k && l-tmp >= mid)le = mid;
		else r = mid;
    }
	cout << le << endl;
    return 0;
}