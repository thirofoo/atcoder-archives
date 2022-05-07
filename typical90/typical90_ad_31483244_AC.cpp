/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/typical90/submissions/31483244
 * Submitted at: 2022-05-07 15:57:37
 * Problem URL: https://atcoder.jp/contests/typical90/tasks/typical90_ad
 * Result: AC
 * Execution Time: 235 ms
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

vector<bool> flags;
void Eratosthenes(ll n){
    flags.assign(n,true);
    flags[0] = false; flags[1] = false;
    const ll sqrt_n = ceil(sqrt(n)+0.1);
    for(ll i = 2; i < sqrt_n; i++){
        if(!flags[i])continue;
        for(ll j = i*i; j < n; j += i){
            flags[j] = false;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,k; cin >> n >> k;
    Eratosthenes(n+5);
    vector<int> num(n+1,0);
    for(int i=2;i<=n;i++){
        if(!flags[i])continue;
        for(int j=i;j<=n;j+=i)num[j]++;
    }

    ll ans = 0;
    for(int i=2;i<=n;i++)if(num[i] >= k)ans++;
    cout << ans << endl;

    return 0;
}