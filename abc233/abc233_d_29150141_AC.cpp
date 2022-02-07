/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc233/submissions/29150141
 * Submitted at: 2022-02-07 23:14:18
 * Problem URL: https://atcoder.jp/contests/abc233/tasks/abc233_d
 * Result: AC
 * Execution Time: 197 ms
 */

#include <bits/stdc++.h>
using namespace std;
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
using namespace atcoder;
#endif
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for(ll i = 0; i < n; i++)

int main() {
    ll n,k,ans = 0; cin >> n >> k;
    vector<ll> s(n+1); s[0] = 0;
    cin >> s[1];
    for(int i=1;i<n;i++){
        int tmp; cin >> tmp;
        s[i+1] = s[i] + tmp;
    }
    //ここがN^2でTLE
    // rep(l,n+1){
    //     for(int r=l;r<n+1;r++){
    //         if(s[r]-s[l] == k){
    //             cout << l << " " << r << endl;
    //             ans++;
    //         }
    //     }
    // }
    map<ll,ll> mp;
    for(int r=1;r<=n;r++){
        //この操作でleftが累積和のr-1番目までのモノのインクリメント
        mp[s[r-1]]++; 
        //rightがr番目のもののうち、それ-5を満たす左端の数だけインクリメント。
        //左端は既に求まっているからこれで高速化可能。
        ans += mp[s[r]-k];
    }
    cout << ans << endl;
    return 0;
}