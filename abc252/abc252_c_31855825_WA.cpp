/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc252/submissions/31855825
 * Submitted at: 2022-05-21 21:32:57
 * Problem URL: https://atcoder.jp/contests/abc252/tasks/abc252_c
 * Result: WA
 * Execution Time: 11 ms
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
    }


    rep(i,10){
        int pre = INT_MAX,cand = 0;
        for(auto k:a[i]){
            if(pre == INT_MAX){
                pre = k;
                cand = k;
            }
            else{
                if(pre == k)cand += 10;
                else if(pre < k){
                    pre = k;
                    cand = k;
                }
                else{
                    cand += 10-pre + k;
                    pre = k;
                }
            }
        }
        ans = min(ans,cand);
    }
    cout << ans << endl;

    return 0;
}