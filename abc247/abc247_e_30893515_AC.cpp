/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc247/submissions/30893515
 * Submitted at: 2022-04-10 23:01:24
 * Problem URL: https://atcoder.jp/contests/abc247/tasks/abc247_e
 * Result: AC
 * Execution Time: 66 ms
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
    ll n,x,y,ans = 0; cin >> n >> x >> y;
    vector<int> a(n);
    vector<vector<int>> b;
    rep(i,n)cin >> a[i];
    rep(i,n){
        vector<int> tmp;
        while(i < n && y <= a[i] && a[i] <= x)tmp.push_back(a[i]),i++;
        b.push_back(tmp);
    }

    int size = b.size();
    rep(i,size){
        vector<int> tmp1,tmp2;
        int t = b[i].size();
        rep(j,t){
            if(b[i][j] == x)tmp1.push_back(j);
            if(b[i][j] == y)tmp2.push_back(j);
        }
        rep(j,t){
            auto m1 = lower_bound(tmp1.begin(),tmp1.end(),j);
            auto m2 = lower_bound(tmp2.begin(),tmp2.end(),j);
            if(m1 == tmp1.end() || m2 == tmp2.end())continue;
            ans += t-max(*m1,*m2);
        }
    }
    cout << ans << endl;
    
    return 0;
}