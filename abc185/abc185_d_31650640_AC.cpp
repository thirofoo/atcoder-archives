/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc185/submissions/31650640
 * Submitted at: 2022-05-14 17:48:46
 * Problem URL: https://atcoder.jp/contests/abc185/tasks/abc185_d
 * Result: AC
 * Execution Time: 1235 ms
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
    
    int n,m; cin >> n >> m;
    vector<bool> flag(n,true);
    rep(i,m){
        int a; cin >> a;
        flag[a-1] = false;
    }

    vector<int> parts;
    int cnt = 0;
    rep(i,n){
        if(flag[i])cnt++;
        else if(cnt){
            parts.push_back(cnt);
            cnt = 0;
        }
    }
    if(cnt)parts.push_back(cnt);

    int size = parts.size();
    if(size == 0)return cout << 0 << endl,0;
    int ans = 0,ma = parts[0];
    rep(i,size)ma = min(ma,parts[i]);

    rep(i,size)ans += ceil((double)parts[i]/ma);
    cout << ans << endl;
    return 0;
}