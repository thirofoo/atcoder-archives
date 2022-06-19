/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc256/submissions/32581881
 * Submitted at: 2022-06-19 11:29:21
 * Problem URL: https://atcoder.jp/contests/abc256/tasks/abc256_d
 * Result: AC
 * Execution Time: 113 ms
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
        a[l]++; a[r]--;
    }
    rep(i,1e6)a[i+1] += a[i];
    int cnt = 0,left = -1;
    rep(i,1e6){
        if(a[i] && cnt%2 == 0){
            left = i;
            cnt++; 
        }
        else if(!a[i] && cnt%2 == 1){
            cout << left << " " << i << endl;
            cnt++;
        }
    }

    return 0;
}