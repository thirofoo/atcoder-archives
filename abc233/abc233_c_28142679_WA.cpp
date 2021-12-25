/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc233/submissions/28142679
 * Submitted at: 2021-12-25 22:20:07
 * Problem URL: https://atcoder.jp/contests/abc233/tasks/abc233_c
 * Result: WA
 * Execution Time: 21 ms
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
    ll n,x;
    cin >> n >> x;
    vector<vector<ll>> ball(n,vector<ll>(0));
    rep(i,n){
      ll l; cin >> l;
      rep(j,l){
        int a; cin >> a;
        ball[i].push_back(a);
      }
    }
    vector<vector<int>> seki(n,vector<int>(0));
    for(auto a:ball[0])seki[0].push_back(a);
    for(int i=1;i<n;i++){
        for(auto a:ball[i]){
          for(auto b:seki[i-1]){
            if(a*b > x)continue;
            seki[i].push_back(a*b);
          }
        }
    }
    cout << count(seki[n-1].begin(),seki[n-1].end(),x) << endl;;
    return 0;
}