/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc146/submissions/34178109
 * Submitted at: 2022-08-20 22:38:03
 * Problem URL: https://atcoder.jp/contests/arc146/tasks/arc146_b
 * Result: WA
 * Execution Time: 670 ms
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
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll n,m,k,mask = (1LL << 62)-1; cin >> n >> m >> k;
    vector<ll> a(n),b;
    rep(i,n)cin >> a[i];

    //デカいbitを優先的に考える。
    ll ans = 0,rest = -1;
    for(ll i=61;i>=0;i--){
        vector<ll> tmp;
        rep(j,n)tmp.push_back(a[j]&mask);
        sort(tmp.begin(),tmp.end());
        reverse(tmp.begin(),tmp.end());
        ll num = 0,cnt = 0;

        //デカいk個目までが条件を満たすか
        rep(j,k){
            if(tmp[j] >= (1LL << i))num++;
            else cnt += (1LL << i)-tmp[j];
            if(m < cnt)break;
        }
        if(m >= cnt){
            rep(j,k)b.push_back(max(tmp[j],(1LL << i)));
            mask ^= (1LL << i);
            ans = (1LL << i);
            rest = i-1;
            m -= cnt;
            break;
        }
        mask ^= (1LL << i);
    }

    //残りのmで最大化を図る
    for(ll i=rest;i>=0;i--){
        ll tmp = 0;
        rep(j,k){
            b[j] &= mask;
            if(b[j] < (1LL << i))tmp += (1LL << i)-b[j];
        }
        if(m >= tmp){
            rep(j,k)b[j] = max(b[j],(1LL << i));
            ans += (1LL << i);
            m -= tmp;
        }
        mask ^= (1LL << i);
    }
    cout << ans << endl;
    
    return 0;
}