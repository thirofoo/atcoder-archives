/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc249/submissions/31220899
 * Submitted at: 2022-04-24 10:10:24
 * Problem URL: https://atcoder.jp/contests/abc249/tasks/abc249_c
 * Result: AC
 * Execution Time: 28 ms
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
    int n,k; cin >> n >> k;
    vector<string> s(n);
    rep(i,n)cin >> s[i];
    vector<vector<bool>> ch(n,vector<bool>(26,false));
    rep(i,n){
        int tmp = s[i].size();
        rep(j,tmp){
            ch[i][s[i][j]-'a'] = true;
        }
    }
    
    int ans = 0;
    for(int i=1;i<(1 << n);i++){
        int cand = 0;
        rep(j,26){
            int tmp = 0;
            rep(l,n){
                if( !(i & (1 << l)) )continue;
                if(ch[l][j])tmp++;
            }
            if(tmp == k)cand++;
        }
        ans = max(ans,cand);
    }
    cout << ans << endl;
    return 0;
}