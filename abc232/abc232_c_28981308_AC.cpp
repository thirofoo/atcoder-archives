/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc232/submissions/28981308
 * Submitted at: 2022-02-01 02:15:19
 * Problem URL: https://atcoder.jp/contests/abc232/tasks/abc232_c
 * Result: AC
 * Execution Time: 7 ms
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
    int n,m; cin >> n >> m;
    vector<vector<bool>> takahashi(n,vector<bool>(n,false)),aoki(n,vector<bool>(n,false));
    rep(i,m){
      int a,b; cin >> a >> b;
      takahashi[a-1][b-1] = true;
      takahashi[b-1][a-1] = true;
    }
    rep(i,m){
      int c,d; cin >> c >> d;
      aoki[c-1][d-1] = true;
      aoki[d-1][c-1] = true;
    }
    vector<int> tmp(n);
    iota(tmp.begin(),tmp.end(),0);
    do{
      bool frag = true;
      rep(i,n){
        rep(j,n){
          if(takahashi[i][j] == aoki[tmp[i]][tmp[j]])continue;
          frag = false; break;
        }
        if(!frag)break;
      }
      if(frag)return cout << "Yes" << endl,0;
    }while(next_permutation(tmp.begin(),tmp.end()));
    cout << "No" << endl;
    return 0;
}