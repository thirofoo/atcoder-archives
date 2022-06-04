/*
 * Author: through
 * Submission URL: https://atcoder.jp/contests/abc254/submissions/32227090
 * Submitted at: 2022-06-04 21:43:46
 * Problem URL: https://atcoder.jp/contests/abc254/tasks/abc254_d
 * Result: AC
 * Execution Time: 185 ms
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

void factorize(int n,vector<P>& fact){
    int a = n;
    for(int i=2;i*i<=n;i++){
        int cnt = 0;
        if(a%i)continue;
        while(a%i == 0){
            cnt++; a /= i;
        }
        fact.push_back(P(i,cnt));
    }
    if(a != 1)fact.push_back(P(a,1));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    ll n,ans = 0; cin >> n;
    for(int i=1;i<=n;i++){
        vector<P> fact;
        factorize(i,fact);
        int p = 1;
        for(auto k:fact)if(k.second%2)p *= k.first;

        ll left = 1,right = n;
        while(right-left > 1){
            ll mid = (right+left)/2;
            if(p*mid*mid <= n)left = mid;
            else right = mid;
        }
        ans += left;
    }
    cout << ans << endl;

    return 0;
}