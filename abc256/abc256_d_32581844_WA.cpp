/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/32581844
 * Submitted at: 2022-06-19 11:27:12
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_d
 * Result: WA
 * Execution Time: 67 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> T;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    //imos法解法
    int n; cin >> n;
    vector<int> a(1e6,0);
    rep(i,n){
        int l,r; cin >> l >> r;
        a[l]++; a[r+1]--;
    }
    rep(i,1e6)a[i+1] += a[i];
    int cnt = 0,left = -1;
    rep(i,1e6){
        if(a[i] && cnt%2 == 0){
            left = i;
            cnt++; 
        }
        else if(!a[i] && cnt%2 == 1){
            cout << left << " " << i-1 << endl;
            cnt++;
        }
    }

    return 0;
}