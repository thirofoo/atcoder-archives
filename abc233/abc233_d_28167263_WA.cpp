/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc233/submissions/28167263
 * Submitted at: 2021-12-26 18:26:06
 * Problem URL: https://atcoder.jp/contests/abc233/tasks/abc233_d
 * Result: WA
 * Execution Time: 2205 ms
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
    ll n,k,tmp = 0,j = 0,count = 0;
    cin >> n >> k;
    vector<int> sum(n+1,0);
    rep(i,n){
		ll a; cin >> a;
		tmp += a; sum[i+1] = tmp;
    }
	rep(i,n+1){
		rep(j,n+1){
			if(k == sum[j]-sum[i]) count++;
		}
		j = i+1;
	}
	cout << count << endl;
}