/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc189/submissions/30787675
 * Submitted at: 2022-04-08 17:00:25
 * Problem URL: https://atcoder.jp/contests/abc189/tasks/abc189_c
 * Result: AC
 * Execution Time: 56 ms
 */

#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
	int n;
	cin >> n;
	for(int i=0;i<n;i++)cin >> a[i];
	int ans=0;
	for(int l=0;l<n;l++){
		int x=a[l];
		for(int r=l;r<n;r++){
			x=min(x,a[r]);
			ans=max(ans,x*(r-l+1));
		}
	}
	cout << ans;
}