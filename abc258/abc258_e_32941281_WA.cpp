/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc258/submissions/32941281
 * Submitted at: 2022-07-03 00:23:31
 * Problem URL: https://atcoder.jp/contests/abc258/tasks/abc258_e
 * Result: WA
 * Execution Time: 2208 ms
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
    
    ll n,q,x,total = 0; cin >> n >> q >> x;
    vector<int> w(n);
    rep(i,n){
        cin >> w[i];
        total += w[i];
    }
    vector<vector<int>> doubling(100,vector<int>(n,0));

    ll tmp = x%total,cnt = 0;
    while(tmp > 0){
        tmp -= w[cnt%n];cnt++;
    }
    doubling[0][0] = cnt%n;

    for(int i=1;i<n;i++){
        ll tmp = w[i-1],cnt = doubling[0][i-1];
        while(tmp > 0){
            tmp -= w[cnt%n];
            cnt++;
        }
        doubling[0][i] = cnt%n;
    }

    for(int i=1;i<100;i++)rep(j,n){
        doubling[i][j] = doubling[i-1][doubling[i-1][j]];
    }

    //そもそもここがO(QN)になっててTLE
    while(q--){
        ll k,now = 0; cin >> k; k--;
        for(int i=0;i<64;i++){
            if(k & (1LL << i)){
                now = doubling[i][now%n];
            }
        }
        ll tmp = x%total,ans = x/total*n;
        while(tmp > 0){
            tmp -= w[((now%n)+n)%n];
            ans++; now++;
        }
        cout << ans << endl;
    }
    
    return 0;
}