/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/arc146/submissions/34174907
 * Submitted at: 2022-08-20 22:06:00
 * Problem URL: https://atcoder.jp/contests/arc146/tasks/arc146_b
 * Result: RE
 * Execution Time: 299 ms
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
    
    ll n,m,k,mask = (1LL << 31)-1; cin >> n >> m >> k;
    vector<ll> a(n),b;
    rep(i,n)cin >> a[i];

    //デカいbitを優先的に考える。
    ll ans = 0,rest;
    for(int i=30;i>=0;i--){
        vector<ll> tmp;
        rep(j,n)tmp.push_back(a[j]&mask);
        sort(tmp.begin(),tmp.end());
        reverse(tmp.begin(),tmp.end());
        ll num = 0,cnt = 0;
        //デカいk個目までが条件を満たすか
        // cout << i << " : ";
        rep(j,k){
            // cout << tmp[j] << " ";
            if(tmp[j] & (1LL << i))num++;
            else cnt += (1LL << i)-tmp[j];
        }
        // cout << "  " << cnt << endl;
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
    // cout << ans << " " << m << endl;

    //残りのmで最大化を図る
    for(int i=rest;i>=0;i--){
        int tmp = 0;
        rep(j,k){
            b[j] &= mask;
            // cout << b[j] << " : " << (b[j] & (1LL << i)) << endl;
            if(!(b[j] & (1LL << i)))tmp += (1LL << i)-b[j];
        }
        if(m >= tmp){
            // cout << i << " " << tmp << endl;
            ans += (1LL << i);
            m -= tmp;
            rep(j,k)if(!(b[j] & (1LL << i)))b[j] = (1LL << i);
        }
        // cout << m << " " << ans << endl << endl;
        mask ^= (1LL << i);
    }
    cout << ans << endl;
    
    return 0;
}