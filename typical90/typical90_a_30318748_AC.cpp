/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/30318748
 * Submitted at: 2022-03-21 12:17:40
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_a
 * Result: AC
 * Execution Time: 42 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    int n,l,k; cin >> n >> l >> k;
    vector<int> a(n+1,0);
    rep(i,n)cin >> a[i+1];
    a.push_back(l);

    int left = 0,right = l+1;
    while(right-left>1){
        int mid = (right+left)/2;
        ll tmp = 0,cnt = 0;
        rep(i,n+2){
            if(a[i]-a[tmp] >= mid){
                tmp = i; cnt++;
            }
        }
        if(cnt >= k+1)left = mid;
        else right = mid;
    }
    cout << left << endl;
    return 0;
}