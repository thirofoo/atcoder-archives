/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/31860315
 * Submitted at: 2022-05-21 21:45:53
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_c
 * Result: AC
 * Execution Time: 6 ms
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
    
    int n,ans = INT_MAX; cin >> n;
    map<int,vector<int>> a;
    rep(i,n){
        string s; cin >> s;
        int size = s.size();
        rep(j,size){
            a[s[j]-'0'].push_back(j);
        }
    }

    rep(i,10){
        sort(a[i].begin(),a[i].end());

        vector<int> cnt(10,0);
        for(auto k:a[i])cnt[k]++;
        int tmp = cnt[0],m = 0;
        rep(i,9){
            if(cnt[i+1] >= tmp){
                m = i+1;
                tmp = cnt[m];
            }
        }

        ans = min(ans,(cnt[m]-1)*10+m);
    }
    cout << ans << endl;
 
    return 0;
}